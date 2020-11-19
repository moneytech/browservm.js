mergeInto(LibraryManager.library, {
  lib_sleep: function() {
    const console_sab_i32a = new Int32Array(console_input_sab);
    Atomics.wait(console_sab_i32a, 0, 0, 5);
  },
  lib_poll_hardware: function() {
  	let ret = 0;
    const console_sab_i32a = new Int32Array(console_input_sab);
  	if (console_sab_i32a[1] > 0) {
  		ret += (1 << 0);
  	}

    const harddisk_sab_i32a = new Int32Array(harddisk_input_sab);
    if (harddisk_sab_i32a[1] > 0) {
      ret += (1 << 1);
    }

    const ethernet_sab_i32a = new Int32Array(ethernet_input_sab);
    if (ethernet_sab_i32a[1] > 0) {
          ret += (1 << 2);
    }
  	return ret;
  },
  lib_console_output: function(outs, len) {
    /* First lock the buffer */
    console_output_sab_mutex.lock();
    const console_sab_i32a = new Int32Array(console_output_sab);
    const console_sab_u8a = new Uint8Array(console_output_sab);
    const origin_len = console_sab_i32a[1];
    const ustr = HEAP8.slice(outs, outs + len);
    console_sab_u8a.set(ustr, 8 + origin_len);
    console_sab_i32a[1] = origin_len + len;
    console_output_sab_mutex.unlock();
    /* Finally unlock the buffer */
  },
  lib_console_input: function(ins, len) {
    /* First lock the buffer */
    console_input_sab_mutex.lock();
    const console_sab_i32a = new Int32Array(console_input_sab);
    const console_sab_u8a = new Uint8Array(console_input_sab);
    const ulen = console_sab_i32a[1];
    if (ulen > 0) {
      if (ulen > len) {
        ulen = len;
      }
      const ustr = console_sab_u8a.slice(8, 8 + ulen);
      HEAP8.set(ustr, ins);
      console_sab_i32a[1] = 0;
    }
    
    /* Finally unlock the buffer */
    console_input_sab_mutex.unlock();
    return ulen;
  },
  lib_harddisk_output: function(outs, sector, num, readOrWrite) {
    /* First lock the buffer */
    harddisk_output_sab_mutex.lock();
    const harddisk_sab_i32a = new Int32Array(harddisk_output_sab);
    const harddisk_sab_u8a = new Uint8Array(harddisk_output_sab);
    if (readOrWrite) {
      /* Write */
      const ustr = HEAP8.slice(outs, outs + num * HARDDISK_PAGE);
      harddisk_sab_u8a.set(ustr, 16);
    } else {
      harddisk_sab_i32a[4] = outs; /* Set the dest ptr, so callback can write data to mem directly */
    }
    harddisk_sab_i32a[3] = readOrWrite;
    harddisk_sab_i32a[2] = sector;
    harddisk_sab_i32a[1] = num;
    harddisk_output_sab_mutex.unlock();
    /* Finally unlock the buffer */
  },
  lib_harddisk_input: function() {
    /* First lock the buffer */
    harddisk_input_sab_mutex.lock();
    const harddisk_sab_i32a = new Int32Array(harddisk_input_sab);
    const harddisk_sab_u8a = new Uint8Array(harddisk_input_sab);
    const n = harddisk_sab_i32a[1];
    const readOrWrite = harddisk_sab_i32a[2];
    // console.log('l ' + readOrWrite + ' n ' + n);
    if (n > 0) {
      
      if (!readOrWrite) {
        /* read */
        const outs = harddisk_sab_i32a[3];
        const ustr = harddisk_sab_u8a.slice(16, 16 + n * HARDDISK_PAGE);
        HEAP8.set(ustr, outs); /* Use the dest ptr */
      }

      harddisk_sab_i32a[1] = 0;
    }
    /* Finally unlock the buffer */
    harddisk_input_sab_mutex.unlock();
    return n;
  },
  lib_ethernet_output: function(outs, len) {
    /* First lock the buffer */
    ethernet_output_sab_mutex.lock();
    const ethernet_sab_i32a = new Int32Array(ethernet_output_sab);
    const ethernet_sab_u8a = new Uint8Array(ethernet_output_sab);
    const origin_len = ethernet_sab_i32a[1];
    const ustr = HEAP8.slice(outs, outs + len);
    ethernet_sab_u8a.set(ustr, 8 + origin_len);
    ethernet_sab_i32a[1] = origin_len + len;
    ethernet_output_sab_mutex.unlock();
    /* Finally unlock the buffer */
  },
  lib_ethernet_input: function(ins, len) {
    /* First lock the buffer */
    ethernet_input_sab_mutex.lock();
    const ethernet_sab_i32a = new Int32Array(ethernet_input_sab);
    const ethernet_sab_u8a = new Uint8Array(ethernet_input_sab);
    const ulen = ethernet_sab_i32a[1];
    if (ulen > 0) {
      if (ulen > len) {
        ulen = len;
      }
      const ustr = ethernet_sab_u8a.slice(8, 8 + ulen);
      HEAP8.set(ustr, ins);
      ethernet_sab_i32a[1] = 0;
    }
    
    /* Finally unlock the buffer */
    ethernet_input_sab_mutex.unlock();
    return ulen;
  }

});
