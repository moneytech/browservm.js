const xterm = new Terminal({
	cursorBlink: true, 
    scrollback: 1000, 
    tabStopWidth: 8
});
xterm.open(document.getElementById('terminal'));

xterm.onKey(e => {
        writeConsole(e.key);
});

const LOCKED_FLAG = 1;
const UNLOCKED_FLAG = 0;
const HARDDISK_PAGE = 512;
class Mutex {
  /**
   * Instantiate Mutex.
   * If opt_sab is provided, the mutex will use it as a backing array.
   * @param {SharedArrayBuffer} opt_sab Optional SharedArrayBuffer.
   */
  constructor(opt_sab) {
    this._sab = opt_sab;
    this._mu = new Int32Array(this._sab);
  }

  try_lock() {
      if (Atomics.compareExchange(this._mu, 0, UNLOCKED_FLAG, LOCKED_FLAG) == UNLOCKED_FLAG) {
        return true;
      }
      return false;
  }

  unlock() {
    if (Atomics.compareExchange(this._mu, 0, LOCKED_FLAG, UNLOCKED_FLAG) != LOCKED_FLAG) {
      throw new Error("Mutex is in inconsistent state: unlock on UNLOCKED_FLAG Mutex.");
    }
    Atomics.notify(this._mu, 0, 1);
  }
}
let startTime = Date.now();
let console_output_sab = undefined;
let console_output_sab_mutex = undefined;
let console_input_sab = undefined;
let console_input_sab_mutex = undefined;

let harddisk_output_sab = undefined;
let harddisk_output_sab_mutex = undefined;
let harddisk_input_sab = undefined;
let harddisk_input_sab_mutex = undefined;

let ethernet_output_sab = undefined;
let ethernet_output_sab_mutex = undefined;
let ethernet_input_sab = undefined;
let ethernet_input_sab_mutex = undefined;

const emulatorWorker = new Worker('emulator.js');
emulatorWorker.onmessage = ev => {
	const data = ev['data'];
	if (data['type'] === 'console_output_sab') {
		console_output_sab = data['buf'];
		console_output_sab_mutex = new Mutex(console_output_sab);
	} else if (data['type'] === 'console_input_sab') {
		console_input_sab = data['buf'];
		console_input_sab_mutex = new Mutex(console_input_sab);
	} else if (data['type'] === 'harddisk_output_sab') {
		harddisk_output_sab = data['buf'];
		harddisk_output_sab_mutex = new Mutex(harddisk_output_sab);
	} else if (data['type'] === 'harddisk_input_sab') {
		harddisk_input_sab = data['buf'];
		harddisk_input_sab_mutex = new Mutex(harddisk_input_sab);
	} else if (data['type'] === 'ethernet_output_sab') {
		ethernet_output_sab = data['buf'];
		ethernet_output_sab_mutex = new Mutex(ethernet_output_sab);
	} else if (data['type'] === 'ethernet_input_sab') {
		ethernet_input_sab = data['buf'];
		ethernet_input_sab_mutex = new Mutex(ethernet_input_sab);
	}
};

const handleConsole = () => {
	if (console_output_sab_mutex.try_lock()) {
		const console_sab_i32a = new Int32Array(console_output_sab);
    	const console_sab_u8a = new Uint8Array(console_output_sab);
		const ulen = console_sab_i32a[1];
		if (ulen > 0) {
			const ustr = console_sab_u8a.slice(8, 8 + ulen);
			console_sab_i32a[1] = 0;
			xterm.write(ustr);
			// const test = new TextDecoder().decode(ustr);
			// if (test.includes('Buildroot')) {
			// 	console.error('Time ' + (Date.now() - startTime));
			// }
		}
	  	console_output_sab_mutex.unlock();
	}
}

const handleHarddisk = async () => {
	
	if (harddisk_output_sab_mutex.try_lock()) {
		const harddisk_sab_i32a = new Int32Array(harddisk_output_sab);
		const harddisk_sab_u8a = new Uint8Array(harddisk_output_sab);
		const readOrWrite = harddisk_sab_i32a[3];
		const sector = harddisk_sab_i32a[2];
		const n = harddisk_sab_i32a[1];
		if (n > 0) {
			if (readOrWrite) {
		      /* Write */
		      // console.log('writing ' + n);
		      for (let j = 0; j < n; j ++) {
		      	let targetSector = sector + j;
		      	let block = harddisk_sab_u8a.slice(16 + j * HARDDISK_PAGE, 16 + (j + 1) * HARDDISK_PAGE);
		      	await idbKeyval.set(`b${targetSector}`, block);
		      }
		      notifyHarddisk(n, readOrWrite);
		    } else {
		      /* read */
		      // console.log('reading ' + n);
		      const outptr = harddisk_sab_i32a[4];
		      const tmpData = new Uint8Array(n * HARDDISK_PAGE);
		      for (let j = 0; j < n; j ++) {
		      	let targetSector = sector + j;
		      	const block = await idbKeyval.get(`b${targetSector}`);
		      	if (block) {
		      		tmpData.set(block, j * HARDDISK_PAGE);
		      	}
		      }
		      notifyHarddisk(n, readOrWrite, outptr, tmpData);
		    }
		}
		harddisk_sab_i32a[1] = 0;
		harddisk_output_sab_mutex.unlock();
	}
}

const handleEthernet = async () => {
	if (ethernet_output_sab_mutex.try_lock()) {
		const ethernet_sab_i32a = new Int32Array(ethernet_output_sab);
		const ethernet_sab_u8a = new Uint8Array(ethernet_output_sab);
		const ulen = ethernet_sab_i32a[1];
		if (ulen > 0) {
			const ustr = ethernet_sab_u8a.slice(8, 8 + ulen);
			ethernet_sab_i32a[1] = 0;
			console.error('Sliently dropped, network not implemented yet');
		}
		ethernet_output_sab_mutex.unlock();
	}
};

const handleHardwareReq = async () => {

	if (!console_output_sab || !harddisk_output_sab || !ethernet_output_sab) {
		setTimeout(handleHardwareReq, 1000);
		return;
	}

	/* If we can hold the lock */
	handleConsole();
	
	await handleHarddisk();

	await handleEthernet();

	setTimeout(handleHardwareReq, 0);
};

/* Should never failed to lock */
const notifyHarddisk = (blockn, readOrWrite, outptr, data) => {
	if (harddisk_input_sab_mutex.try_lock()) {
		const harddisk_sab_i32a = new Int32Array(harddisk_input_sab);
    	const harddisk_sab_u8a = new Uint8Array(harddisk_input_sab);
		
		harddisk_sab_i32a[1] = blockn;
		harddisk_sab_i32a[2] = readOrWrite;
		if (!readOrWrite) {
			harddisk_sab_i32a[3] = outptr;
			harddisk_sab_u8a.set(data, 16);

		}
		// console.log('done ' + readOrWrite);
		harddisk_input_sab_mutex.unlock();
	} else {
		console.error('locking failed');
	}
}

const writeConsole = (key) => {
	if (console_input_sab_mutex.try_lock()) {
		const console_sab_i32a = new Int32Array(console_input_sab);
    	const console_sab_u8a = new Uint8Array(console_input_sab);
		let data = new Uint8Array(1);
		data[0] = key.charCodeAt(0);
		console_sab_i32a[1] = 1;
		console_sab_u8a.set(data, 8);
		console_input_sab_mutex.unlock();
	}
}

/* Kick out the event loop */
setTimeout(handleHardwareReq, 1000);