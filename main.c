#include <memory.h>
#include <cpu/cpus.h>
#include <cpu/exec.h>
#include <cpu/memory.h>
#include <timer.h>
#include <cpu/cpu-common.h>
#include <cpu/i386/cpu.h>
#include <cpu/ioport.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "peripheral.h"
#include "virtio.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#define HARDDISK_PAGE 512
#define CPU_MODEL "qemu32-s2e"
#define MAIN_MEM_SIZE 512 * 1024 * 1024
#define KERNEL_PARAMS_ADDR 0x00090000
#define LOAD_ADDRESS 0x100000
#define MAX_KERNEL_SIZE 8 * 1024 * 1024
#define KERNEL_CMD                                                             \
  "console=hvc0 earlyprintk=ttyS0 tsc=unstable "                             \
  "virtio_mmio.device=4K@0x20000000:10 virtio_mmio.device=4K@0x20020000:11 "   \
  "virtio_mmio.device=4K@0x20040000:12 virtio_mmio.device=4K@0x20060000:13 root=/dev/vda"
#define MAX_DEVICE_NO 16
static CPUX86State *g_cpu_env;
static PIC2State *g_pic;
static CMOSState *g_cmos;
static SerialState *g_serial;
static PITState *g_pit;
static VIRTIODevice *g_console;
static VIRTIODevice *g_second_harddrive;
static EthernetDevice *g_ether;
IODevice io_devices[MAX_DEVICE_NO];
MMIODevice mmio_devices[MAX_DEVICE_NO];
IRQSignal g_irqSignals[16]; /* Normal PC */
static cpuid_t m_cpuid;
#define FB_WIDTH 1280
#define FB_HEIGHT 960
#define FB_STRIDE FB_WIDTH * 4
#define FB_BASEADDR 0xf0400000
#define FB_ALLOC_ALIGN 65536
#define FB_REGION_SIZE                                                         \
  ((FB_HEIGHT * FB_STRIDE + FB_ALLOC_ALIGN - 1) & ~(FB_ALLOC_ALIGN - 1))

void tcg_register_thread(void); /* Hack? For linking */

void cpu_register_io_device(IODevice *d) {
  int j = 0;
  for (j = 0; j < MAX_DEVICE_NO; j++) {
    if (!io_devices[j].used) {
      break;
    }
  }
  if (j == MAX_DEVICE_NO) {
    printf("Too many IO devices\n");
    abort();
  }
  io_devices[j] = *d;
  io_devices[j].used = 1;
  printf("Register port (%04x-%04x), (%p, %p)\n", d->startPort, d->endPort,
         d->_read, d->_write);
}

void cpu_register_mmio_device(MMIODevice *d) {
  int j = 0;
  for (j = 0; j < MAX_DEVICE_NO; j++) {
    if (!mmio_devices[j].used) {
      break;
    }
  }
  if (j == MAX_DEVICE_NO) {
    printf("Too many MMIO devices\n");
    abort();
  }
  mmio_devices[j] = *d;
  mmio_devices[j].used = 1;
  printf("Register mmio Addr (%p-%p)\n", (void *)(d->startAddr),
         (void *)(d->endAddr));
}

static IODevice *find_io_device(uint32_t port) {
  for (int j = 0; j < MAX_DEVICE_NO; j++) {
    if (!io_devices[j].used) {
      break;
    }
    if (port >= io_devices[j].startPort && port <= io_devices[j].endPort) {
      return &(io_devices[j]);
    }
  }
  return NULL;
}

static MMIODevice *find_mmio_device(target_phys_addr_t addr) {
  for (int j = 0; j < MAX_DEVICE_NO; j++) {
    if (!mmio_devices[j].used) {
      break;
    }
    if (addr >= mmio_devices[j].startAddr && addr <= mmio_devices[j].endAddr) {
      return &(mmio_devices[j]);
    }
  }
  return NULL;
}

void cpu_hw_irq(uint8_t level) {
  if (level) {

    // printf("-->Setting %d\n", irq_no);
    // assert((g_cpu_env->mflags & IF_MASK) != 0);
    // assert(!(g_cpu_env->interrupt_request & CPU_INTERRUPT_HARD));
    // g_cpu_env->interrupt_request |= CPU_INTERRUPT_HARD;
    // g_cpu_env->kvm_irq = irq_no;
    g_cpu_env->kvm_request_interrupt_window = 1;
  } else {
    // printf("Deset \n");
    // g_cpu_env->interrupt_request &= ~(CPU_INTERRUPT_HARD);
    g_cpu_env->kvm_request_interrupt_window = 0;
  }
}

struct screen_info {
} __attribute__((packed));

/* from plex86 (BSD license) */
struct __attribute__((packed)) linux_params {
  /* screen_info structure */
  uint8_t orig_x;             /* 0x00 */
  uint8_t orig_y;             /* 0x01 */
  uint16_t ext_mem_k;         /* 0x02 */
  uint16_t orig_video_page;   /* 0x04 */
  uint8_t orig_video_mode;    /* 0x06 */
  uint8_t orig_video_cols;    /* 0x07 */
  uint8_t flags;              /* 0x08 */
  uint8_t unused2;            /* 0x09 */
  uint16_t orig_video_ega_bx; /* 0x0a */
  uint16_t unused3;           /* 0x0c */
  uint8_t orig_video_lines;   /* 0x0e */
  uint8_t orig_video_isVGA;   /* 0x0f */
  uint16_t orig_video_points; /* 0x10 */

  /* VESA graphic mode -- linear frame buffer */
  uint16_t lfb_width;           /* 0x12 */
  uint16_t lfb_height;          /* 0x14 */
  uint16_t lfb_depth;           /* 0x16 */
  uint32_t lfb_base;            /* 0x18 */
  uint32_t lfb_size;            /* 0x1c */
  uint16_t cl_magic, cl_offset; /* 0x20 */
  uint16_t lfb_linelength;      /* 0x24 */
  uint8_t red_size;             /* 0x26 */
  uint8_t red_pos;              /* 0x27 */
  uint8_t green_size;           /* 0x28 */
  uint8_t green_pos;            /* 0x29 */
  uint8_t blue_size;            /* 0x2a */
  uint8_t blue_pos;             /* 0x2b */
  uint8_t rsvd_size;            /* 0x2c */
  uint8_t rsvd_pos;             /* 0x2d */
  uint16_t vesapm_seg;          /* 0x2e */
  uint16_t vesapm_off;          /* 0x30 */
  uint16_t pages;               /* 0x32 */
  uint16_t vesa_attributes;     /* 0x34 */
  uint32_t capabilities;        /* 0x36 */
  uint32_t ext_lfb_base;        /* 0x3a */
  uint8_t _reserved[2];         /* 0x3e */

  /* 0x040 */ uint8_t apm_bios_info[20]; // struct apm_bios_info
  /* 0x054 */ uint8_t pad2[0x80 - 0x54];

  // Following 2 from 'struct drive_info_struct' in drivers/block/cciss.h.
  // Might be truncated?
  /* 0x080 */ uint8_t hd0_info[16]; // hd0-disk-parameter from intvector 0x41
  /* 0x090 */ uint8_t hd1_info[16]; // hd1-disk-parameter from intvector 0x46

  // System description table truncated to 16 bytes
  // From 'struct sys_desc_table_struct' in linux/arch/i386/kernel/setup.c.
  /* 0x0a0 */ uint16_t sys_description_len;
  /* 0x0a2 */ uint8_t sys_description_table[14];
  // [0] machine id
  // [1] machine submodel id
  // [2] BIOS revision
  // [3] bit1: MCA bus

  /* 0x0b0 */ uint8_t pad3[0x1e0 - 0xb0];
  /* 0x1e0 */ uint32_t alt_mem_k;
  /* 0x1e4 */ uint8_t pad4[4];
  /* 0x1e8 */ uint8_t e820map_entries;
  /* 0x1e9 */ uint8_t eddbuf_entries; // EDD_NR
  /* 0x1ea */ uint8_t pad5[0x1f1 - 0x1ea];
  /* 0x1f1 */ uint8_t setup_sects;        // size of setup.S, number of sectors
  /* 0x1f2 */ uint16_t mount_root_rdonly; // MOUNT_ROOT_RDONLY (if !=0)
  /* 0x1f4 */ uint16_t
      sys_size; // size of compressed kernel-part in the
                // (b)zImage-file (in 16 byte units, rounded up)
  /* 0x1f6 */ uint16_t swap_dev; // (unused AFAIK)
  /* 0x1f8 */ uint16_t ramdisk_flags;
  /* 0x1fa */ uint16_t vga_mode;      // (old one)
  /* 0x1fc */ uint16_t orig_root_dev; // (high=Major, low=minor)
  /* 0x1fe */ uint8_t pad6[1];
  /* 0x1ff */ uint8_t aux_device_info;
  /* 0x200 */ uint16_t jump_setup;        // Jump to start of setup code,
                                          // aka "reserved" field.
  /* 0x202 */ uint8_t setup_signature[4]; // Signature for SETUP-header, ="HdrS"
  /* 0x206 */ uint16_t
      header_format_version;            // Version number of header format;
  /* 0x208 */ uint8_t setup_S_temp0[8]; // Used by setup.S for communication
                                        // with boot loaders, look there.
  /* 0x210 */ uint8_t loader_type;
  // 0 for old one.
  // else 0xTV:
  //   T=0: LILO
  //   T=1: Loadlin
  //   T=2: bootsect-loader
  //   T=3: SYSLINUX
  //   T=4: ETHERBOOT
  //   V=version
  /* 0x211 */ uint8_t loadflags;
  // bit0 = 1: kernel is loaded high (bzImage)
  // bit7 = 1: Heap and pointer (see below) set by boot
  //   loader.
  /* 0x212 */ uint16_t setup_S_temp1;
  /* 0x214 */ uint32_t kernel_start;
  /* 0x218 */ uint32_t initrd_start;
  /* 0x21c */ uint32_t initrd_size;
  /* 0x220 */ uint8_t setup_S_temp2[4];
  /* 0x224 */ uint16_t setup_S_heap_end_pointer;
  /* 0x226 */ uint16_t pad70;
  /* 0x228 */ uint32_t cmd_line_ptr;
  /* 0x22c */ uint8_t pad7[0x2d0 - 0x22c];

  /* 0x2d0 : Int 15, ax=e820 memory map. */
  // (linux/include/asm-i386/e820.h, 'struct e820entry')
#define E820MAX 32
#define E820_RAM 1
#define E820_RESERVED 2
#define E820_ACPI 3 /* usable as RAM once ACPI tables have been read */
#define E820_NVS 4
  struct {
    uint64_t addr;
    uint64_t size;
    uint32_t type;
  } e820map[E820MAX];

  /* 0x550 */ uint8_t pad8[0x600 - 0x550];

  // BIOS Enhanced Disk Drive Services.
  // (From linux/include/asm-i386/edd.h, 'struct edd_info')
  // Each 'struct edd_info is 78 bytes, times a max of 6 structs in array.
  /* 0x600 */ uint8_t eddbuf[0x7d4 - 0x600];

  /* 0x7d4 */ uint8_t pad9[0x800 - 0x7d4];
  /* 0x800 */ uint8_t commandline[0x800];

  uint64_t gdt_table[4];
};

static void copy_kernel(CPUX86State *env, uint8_t *main_mem_ptr, uint8_t *buf,
                        int buf_len, const char *cmd_line) {

  int setup_sects, header_len, copy_len, setup_hdr_start, setup_hdr_end;
  struct linux_params *params;

  if (buf_len < 1024) {
  too_small:
    fprintf(stderr, "Kernel too small\n");
    exit(1);
  }
  if (buf[0x1fe] != 0x55 || buf[0x1ff] != 0xaa) {
    fprintf(stderr, "Invalid kernel magic\n");
    exit(1);
  }
  setup_sects = buf[0x1f1];
  if (setup_sects == 0)
    setup_sects = 4;
  header_len = (setup_sects + 1) * 512;
  if (buf_len < header_len)
    goto too_small;
  if (memcmp(buf + 0x202, "HdrS", 4) != 0) {
    fprintf(stderr, "Kernel too old\n");
    exit(1);
  }

  copy_len = buf_len - header_len;

  memcpy(main_mem_ptr + LOAD_ADDRESS, buf + header_len, copy_len);

  params = (struct linux_params *)(main_mem_ptr + KERNEL_PARAMS_ADDR);

  memset(params, 0, sizeof(struct linux_params));

  /* copy the setup header */
  setup_hdr_start = 0x1f1;
  setup_hdr_end = 0x202 + buf[0x201];
  memcpy((uint8_t *)params + setup_hdr_start, buf + setup_hdr_start,
         setup_hdr_end - setup_hdr_start);

  strcpy((char *)params->commandline, cmd_line);

  params->mount_root_rdonly = 0;
  params->cmd_line_ptr =
      KERNEL_PARAMS_ADDR + offsetof(struct linux_params, commandline);
  params->alt_mem_k = (MAIN_MEM_SIZE / 1024) - 1024;
  params->loader_type = 0x01;

  /* Video */
  params->orig_video_lines = 0;
  params->orig_video_cols = 0;
  params->orig_video_isVGA = 0x23; /* VIDEO_TYPE_VLFB */
  params->lfb_depth = 32;
  params->red_size = 8;
  params->red_pos = 16;
  params->green_size = 8;
  params->green_pos = 8;
  params->blue_size = 8;
  params->blue_pos = 0;
  params->rsvd_size = 8;
  params->rsvd_pos = 24;

  params->lfb_width = FB_WIDTH;
  params->lfb_height = FB_HEIGHT;
  params->lfb_linelength = FB_STRIDE;
  params->lfb_size = FB_REGION_SIZE;
  params->lfb_base = FB_BASEADDR;

  params->gdt_table[2] = 0x00cf9b000000ffffLL; /* CS */
  params->gdt_table[3] = 0x00cf93000000ffffLL; /* DS */

  env->gdt.limit = sizeof(params->gdt_table) - 1;
  env->gdt.base = KERNEL_PARAMS_ADDR + offsetof(struct linux_params, gdt_table);

  uint32_t val = env->cr[0];
  cpu_x86_update_cr0(env, val | 1);

  int code_flags = DESC_G_MASK | DESC_B_MASK | DESC_P_MASK | DESC_S_MASK |
                   (0xb << DESC_TYPE_SHIFT);
  cpu_x86_load_seg_cache(env, R_CS, 2 << 3, 0, 0xffffffff, code_flags);

  int data_flags = DESC_G_MASK | DESC_S_MASK | DESC_B_MASK | DESC_P_MASK |
                   (0x3 << DESC_TYPE_SHIFT);

  cpu_x86_load_seg_cache(env, R_DS, 3 << 3, 0, 0xffffffff, data_flags);

  cpu_x86_load_seg_cache(env, R_ES, 3 << 3, 0, 0xffffffff, data_flags);

  cpu_x86_load_seg_cache(env, R_SS, 3 << 3, 0, 0xffffffff, data_flags);
  cpu_x86_load_seg_cache(env, R_FS, 3 << 3, 0, 0xffffffff, data_flags);
  cpu_x86_load_seg_cache(env, R_GS, 3 << 3, 0, 0xffffffff, data_flags);

  // env->regs[R_EDX] = 0;
  env->regs[R_ESI] = KERNEL_PARAMS_ADDR;
  env->eip = LOAD_ADDRESS;
  // env->eflags = 0x2;
  env->cc_op = CC_OP_EFLAGS;
}

uint64_t __mmio_read(target_phys_addr_t addr, unsigned size) {
  MMIODevice *d = find_mmio_device(addr);

  if (d && d->_read) {
    uint32_t offset = addr - d->startAddr;
    VIRTIODevice *s = (VIRTIODevice *)d->opaque;
    return d->_read(s, offset, size);
    // printf("Reading %04X %d\n", offset, val);
  } else {
    printf("Not implemented mmio_read %p\n", (void *)addr);
    return 0;
  }
}

void __mmio_write(target_phys_addr_t addr, uint64_t data, unsigned size) {
  MMIODevice *d = find_mmio_device(addr);
  if (d && d->_write) {

    uint32_t offset = addr - d->startAddr;
    uint32_t val = (uint32_t)data;
    VIRTIODevice *s = (VIRTIODevice *)d->opaque;
    d->_write(s, offset, val, size);
    // printf("Writing %04X %d\n", offset, val)
  } else {
    printf("Not implemented mmio_write %p\n", (void *)addr);
  }
}

uint64_t __ioport_read(pio_addr_t addr, unsigned size) {
  // if ((addr < 0x3f8 || addr > 0x3ff) && addr != 0x61) {
  //   printf("read addr %d\n", addr);
  // }
  IODevice *d = find_io_device(addr);
  if (d && d->_read) {
    return d->_read(d->opaque, addr - d->startPort, size);
  } else {
    printf("Not implemented ioport_read for %d\n", addr);
    return 0;
  }
}

void __ioport_write(
    pio_addr_t addr, uint64_t data,
    unsigned size) { // if ((addr < 0x3f8 || addr > 0x3ff) && addr != 0x61) {
  //   printf("writing addr %d\n", addr);
  // }
  IODevice *d = find_io_device(addr);
  if (d && d->_write) {
    d->_write(d->opaque, addr - d->startPort, data, size);
  } else {
    printf("Not implemented ioport_write for %d\n", addr);
  }
}

static struct cpu_io_funcs_t g_io = {
    .io_read = __ioport_read,
    .io_write = __ioport_write,
    .mmio_read = __mmio_read,
    .mmio_write = __mmio_write,
};

static void machine_cpu_init() {
  cpu_register_io(&g_io);
  x86_cpudef_setup();

  if (cpu_x86_register(&m_cpuid, CPU_MODEL, 0) < 0) {
    fprintf(stderr, "Could not register CPUID for model %s\n", CPU_MODEL);
    exit(-1);
  }
  tcg_exec_init(0);
  init_clocks();
  tcg_register_thread();
  g_cpu_env = cpu_x86_init(&m_cpuid);
  if (!g_cpu_env) {
    printf("Could not create cpu\n");
    exit(-1);
  }
  g_cpu_env->v_apic_base = 0xfee00000;
  g_cpu_env->size = sizeof(*g_cpu_env);
  do_cpu_init(g_cpu_env);
  cpu_exec_init_all();
}

static void machine_mem_init() {
  struct kvm_userspace_memory_region region;
  void *g_main_ram_ptr = malloc(MAIN_MEM_SIZE);
  region.slot = 0;
  region.flags = 0;
  region.guest_phys_addr = 0x0;
  region.memory_size = MAIN_MEM_SIZE;
  region.userspace_addr = (uint64_t)g_main_ram_ptr;
  mem_desc_register(&region);

  uint8_t *kernel_mem = (uint8_t *)malloc(MAX_KERNEL_SIZE);
  if (!kernel_mem) {
    abort();
  }
  FILE *kernel_file = fopen("vmlinux.bin", "r");
  if (!kernel_file) {
    printf("Failed to load kernel\n");
    abort();
  }
  int kernel_size = fread(kernel_mem, 1, MAX_KERNEL_SIZE, kernel_file);
  if (kernel_size < 1024) {
    printf("Failed to read %d\n", kernel_size);
    abort();
  }
  fclose(kernel_file);
  printf("Kernel Size %d\n", kernel_size);
  copy_kernel(g_cpu_env, g_main_ram_ptr, kernel_mem, kernel_size, KERNEL_CMD);
  free(kernel_mem);

  /* FB Region */
  struct kvm_userspace_memory_region fb_region;
  void *fb_ram_ptr = malloc(FB_REGION_SIZE);
  fb_region.slot = 1;
  fb_region.flags = 0;
  fb_region.guest_phys_addr = FB_BASEADDR;
  fb_region.memory_size = FB_REGION_SIZE;
  fb_region.userspace_addr = (uint64_t)fb_ram_ptr;
  mem_desc_register(&fb_region);
}

#define HARDDISK_CAP (16384 * 4)
void init_harddisk(BlockDevice *bs) {
  FILE *harddisk_file = fopen("rootfs.ext2", "r");
  char *memdisk = malloc(HARDDISK_CAP * HARDDISK_PAGE);
  int r = fread(memdisk, 1, HARDDISK_CAP * HARDDISK_PAGE, harddisk_file);
  printf("Read %d bytes\n", r);
  fclose(harddisk_file);
  bs->opaque = memdisk;
}

int64_t harddisk_get_sector_count(BlockDevice *bs) { return HARDDISK_CAP; }

int harddisk_read_async(BlockDevice *bs, uint64_t sector_num, uint8_t *buf,
                        int n, BlockDeviceCompletionFunc *cb, void *opaque) {

  if (!bs->opaque) {
    init_harddisk(bs);
  }
  char *memdisk = bs->opaque;
  uint32_t startAddr = sector_num * HARDDISK_PAGE;
  uint32_t length = n * HARDDISK_PAGE;
  // printf("RootDisk Read %d \n", n);
  memcpy(buf, memdisk + startAddr, length);
  return 0;
}
int harddisk_write_async(BlockDevice *bs, uint64_t sector_num,
                         const uint8_t *buf, int n,
                         BlockDeviceCompletionFunc *cb, void *opaque) {
  if (!bs->opaque) {
    init_harddisk(bs);
  }
  char *memdisk = bs->opaque;
  uint32_t startAddr = sector_num * HARDDISK_PAGE;
  uint32_t length = n * HARDDISK_PAGE;
  // printf("RootDisk Write %d \n", n);
  memcpy(memdisk + startAddr, buf, length);
  return 0;
}

#ifndef __EMSCRIPTEN__

void write_console_data(void *opaque, const uint8_t *buf, int len) {
  printf("%s", buf);
}

void ethernet_write_packet(EthernetDevice *net, const uint8_t *buf, int len) {
  /* Put into a shared memory queue */
  /* If wanna recv a packet, set yield to browser, and check queue */
  printf(" Writing packet %d\n", len);
}

#else /* Emscripten Emulation */

/* Console */
void lib_console_output(const uint8_t *buf, int len);
uint32_t lib_console_input(uint8_t *buf, uint32_t maxlen);
void write_console_data(void *opaque, const uint8_t *buf, int len) {
  // printf("%s", buf);
  lib_console_output(buf, len);
}

/* Ethernet */
void lib_ethernet_output(const uint8_t *buf, int len);
uint32_t lib_ethernet_input(uint8_t *buf, uint32_t maxlen);
void ethernet_write_packet(EthernetDevice *net, const uint8_t *buf, int len) {
  lib_ethernet_output(buf, len);
}

/* Second harddisk */
BlockDeviceCompletionFunc *reg_harddisk_cb; /* So we can continue from javascript call */
void lib_harddisk_output(const uint8_t *buf, uint32_t sector_num, int n, int readOrWrite);
int lib_harddisk_input();
int64_t second_harddisk_get_sector_count(BlockDevice *bs) { return 16384 * 32; /* 256MB */}

int second_harddisk_read_async(BlockDevice *bs, uint64_t sector_num, uint8_t *buf,
                        int n, BlockDeviceCompletionFunc *cb, void *opaque) {
  reg_harddisk_cb = cb;
  /* 64 bit -> 32 bit */
  lib_harddisk_output(buf, (uint32_t)(sector_num), n, 0);
  return 1;
}
int second_harddisk_write_async(BlockDevice *bs, uint64_t sector_num,
                         const uint8_t *buf, int n,
                         BlockDeviceCompletionFunc *cb, void *opaque) {
  reg_harddisk_cb = cb;
  /* 64 bit -> 32 bit */
  lib_harddisk_output(buf, (uint32_t)(sector_num), n, 1);
  return 1;
}

uint32_t lib_poll_hardware();
void lib_sleep();
void poll_hardware(uint8_t busyPoll) {
  cmos_update_irq(g_cmos);
  pit_update_irq(g_pit);
  uint32_t ret = lib_poll_hardware();
  if (ret == 0) {
    if (!busyPoll) {
      lib_sleep();
    }
    return;
  }
  if (ret & 1) {
    /* Console */
    if (virtio_console_can_write_data(g_console)) {
      uint8_t cbuf[1024];

      int sz = lib_console_input(cbuf, 1024);
      if (sz) {
        int wsz = virtio_console_get_write_len(g_console);
        if (wsz < sz) {
          sz = wsz;
        }
        // printf("Writing %d %d\n", sz, cbuf[0]);
        virtio_console_write_data(g_console, cbuf, sz);
      }
    }
  }

  if (ret & 2) {
    /* Hard disk */
    int sz = lib_harddisk_input();
    if (sz && reg_harddisk_cb) {
      reg_harddisk_cb(g_second_harddrive, 0);
    }
  }

  if (ret & 4) {
    /* ethernet */
    if (g_ether->device_can_write_packet(g_ether)) {
      uint8_t cbuf[2048];

      int sz = lib_ethernet_input(cbuf, 2048);
      if (sz) {
        // printf("Writing %d %d\n", sz, cbuf[0]);
        g_ether->device_write_packet(g_ether, cbuf, sz);
      }
    }
  }
}

#endif
void main_exec_loop() {
  while (1) {
    // libcpu_run_all_timers();
    int r = cpu_x86_exec(g_cpu_env);
    if (g_cpu_env->exit_request) {
      exit(0);
    } else {
      if (r == EXCP_HALTED) { // Halt Logic
#ifdef __EMSCRIPTEN__
        poll_hardware(0);
#else
        usleep(1000);
#endif
      }
      if (g_cpu_env->kvm_request_interrupt_window == 1) { // Interrupt logic
        g_cpu_env->kvm_request_interrupt_window = 0;
        assert((g_cpu_env->mflags & IF_MASK) != 0);
        assert(!(g_cpu_env->interrupt_request & CPU_INTERRUPT_HARD));
        g_cpu_env->interrupt_request |= CPU_INTERRUPT_HARD;
        g_cpu_env->kvm_irq = pic2_get_hard_intno(g_pic);
        // printf("Getting irq %d\n", g_cpu_env->kvm_irq);
      }
    }
  }
}

int main() {
  /* Register CPU */
  machine_cpu_init();
  /* Register Ram */
  machine_mem_init();
  /* Register IRQ Controller */
  g_pic = pic2_init(g_irqSignals, cpu_hw_irq);
  /* Register CMOS, irq 8 */
  g_cmos = cmos_init(&g_irqSignals[8]);
  cmos_update_mem(g_cmos, MAIN_MEM_SIZE);
  /* Register Serial, irq 4 */
  g_serial = serial_init(&g_irqSignals[4]);
  /* Register PIT, irq 0 */
  g_pit = pit_init(&g_irqSignals[0]);
  /* Register Console, irq 10. mmio 0x20000000 */
  CharacterDevice *chardev = malloc(sizeof(CharacterDevice));
  memset(chardev, 0, sizeof(CharacterDevice));
  chardev->write_data = write_console_data;
  g_console = virtio_console_init(0x20000000, &g_irqSignals[10], chardev);
  /* Register Harddrive, irq 11. mmio 0x20002000 */
  BlockDevice *harddev = malloc(sizeof(BlockDevice));
  memset(harddev, 0, sizeof(BlockDevice));
  harddev->get_sector_count = harddisk_get_sector_count;
  harddev->read_async = harddisk_read_async;
  harddev->write_async = harddisk_write_async;
  virtio_block_init(0x20020000, &g_irqSignals[11], harddev);
#ifdef __EMSCRIPTEN__
  /* Second Harddrive, irq 12. mmio 0x20004000 */
  BlockDevice *second_harddev = malloc(sizeof(BlockDevice));
  memset(second_harddev, 0, sizeof(BlockDevice));
  second_harddev->get_sector_count = second_harddisk_get_sector_count;
  second_harddev->read_async = second_harddisk_read_async;
  second_harddev->write_async = second_harddisk_write_async;
  g_second_harddrive = virtio_block_init(0x20040000, &g_irqSignals[12], second_harddev);
#endif
  /* Register EthernetDevice, irq 13. mmio 0x20006000 */
  EthernetDevice *g_ether = malloc(sizeof(EthernetDevice));
  memset(g_ether, 0, sizeof(EthernetDevice));
  g_ether->mac_addr[0] = 0x12;
  g_ether->mac_addr[1] = 0x23;
  g_ether->mac_addr[2] = 0x34;
  g_ether->mac_addr[3] = 0x45;
  g_ether->mac_addr[4] = 0x51;
  g_ether->mac_addr[5] = 0x57;
  g_ether->write_packet = ethernet_write_packet;
  virtio_net_init(0x20060000, &g_irqSignals[13], g_ether);
  // etherdev->device_set_carrier(etherdev, 1);
  /* Lift off */
  g_cpu_env->exit_request = 0;

  main_exec_loop();

  return 0;
}