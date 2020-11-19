if (typeof(Module) === "undefined") Module = {};

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

  lock() {
    for(;;) {
      if (Atomics.compareExchange(this._mu, 0, UNLOCKED_FLAG, LOCKED_FLAG) == UNLOCKED_FLAG) {
        return;
      }
      Atomics.wait(this._mu, 0, LOCKED_FLAG);
    }
  }

  unlock() {
    if (Atomics.compareExchange(this._mu, 0, LOCKED_FLAG, UNLOCKED_FLAG) != LOCKED_FLAG) {
      throw new Error("Mutex is in inconsistent state: unlock on UNLOCKED_FLAG Mutex.");
    }
    Atomics.notify(this._mu, 0, 1);
  }
}

const CONSOLE_SAB_SIZE = 1024 * 4; /* 4096 U8Int */
const console_output_sab = new SharedArrayBuffer(CONSOLE_SAB_SIZE);
const console_output_sab_mutex = new Mutex(console_output_sab);
const console_input_sab = new SharedArrayBuffer(CONSOLE_SAB_SIZE);
const console_input_sab_mutex = new Mutex(console_input_sab);

const HARDDISK_SAB_SIZE = 1024 * 1024; /* 1Mb U8Int */
const harddisk_output_sab = new SharedArrayBuffer(HARDDISK_SAB_SIZE);
const harddisk_output_sab_mutex = new Mutex(harddisk_output_sab);
const harddisk_input_sab = new SharedArrayBuffer(HARDDISK_SAB_SIZE);
const harddisk_input_sab_mutex = new Mutex(harddisk_input_sab);

const ETHERNET_SAB_SIZE = 1024 * 16; /* 4096 U8Int */
const ethernet_output_sab = new SharedArrayBuffer(ETHERNET_SAB_SIZE);
const ethernet_output_sab_mutex = new Mutex(ethernet_output_sab);
const ethernet_input_sab = new SharedArrayBuffer(ETHERNET_SAB_SIZE);
const ethernet_input_sab_mutex = new Mutex(ethernet_input_sab);


Module["preInit"] = function() {
	/* Minimal FS */
    FS.createLazyFile('/', "rootfs.ext2", "/rootfs.ext2", true, false);
	/* Kernel */
    FS.createLazyFile('/', "vmlinux.bin", "/vmlinux.bin", true, false);
    /* For Driver Communication */
    self.postMessage({
    	  'type': 'console_output_sab',
        'buf': console_output_sab
    });
    self.postMessage({
        'type': 'console_input_sab',
        'buf': console_input_sab
    });
    self.postMessage({
        'type': 'harddisk_output_sab',
        'buf': harddisk_output_sab
    });
    self.postMessage({
        'type': 'harddisk_input_sab',
        'buf': harddisk_input_sab
    });
    self.postMessage({
        'type': 'ethernet_output_sab',
        'buf': ethernet_output_sab
    });
    self.postMessage({
        'type': 'ethernet_input_sab',
        'buf': ethernet_input_sab
    });
};


