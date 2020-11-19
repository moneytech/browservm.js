#ifndef MAIN_H
#define MAIN_H
#include <target-i386/cpu.h>


struct IODevice {
	uint32_t startPort;
	uint32_t endPort;
	void *opaque;
	uint8_t used;
  void (*_write)(void *opaque, uint32_t offset, uint64_t data, unsigned size);
  uint64_t (*_read)(void *opaque, uint32_t offset, unsigned size);
};

struct MMIODevice {
  target_phys_addr_t startAddr;
  target_phys_addr_t endAddr;
  void *opaque;
  uint8_t used;
  void (*_write)(void *opaque, uint32_t offset,
                              uint32_t val, int size);
  uint32_t (*_read)(void *opaque, uint32_t offset1, int size);
};

typedef struct IODevice IODevice;

typedef struct MMIODevice MMIODevice;

void cpu_register_io_device(IODevice *d);
void cpu_register_mmio_device(MMIODevice *d);



#endif