/*
 * VIRTIO driver
 * 
 * Copyright (c) 2016 Fabrice Bellard
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <assert.h>
#include <stdarg.h>
#include <cpu/memdbg.h>
#include "main.h"
#include "peripheral.h"
#include "virtio.h"

static inline int min_int(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}


static inline uint16_t get_le16(const uint8_t *ptr)
{
    return ptr[0] | (ptr[1] << 8);
}

static inline uint32_t get_le32(const uint8_t *ptr)
{
    return ptr[0] | (ptr[1] << 8) | (ptr[2] << 16) | (ptr[3] << 24);
}


static inline void put_le16(uint8_t *ptr, uint16_t v)
{
    ptr[0] = v;
    ptr[1] = v >> 8;
}

static inline void put_le32(uint8_t *ptr, uint32_t v)
{
    ptr[0] = v;
    ptr[1] = v >> 8;
    ptr[2] = v >> 16;
    ptr[3] = v >> 24;
}

//#define DEBUG_VIRTIO

/* MMIO addresses - from the Linux kernel */
#define VIRTIO_MMIO_MAGIC_VALUE		0x000
#define VIRTIO_MMIO_VERSION		0x004
#define VIRTIO_MMIO_DEVICE_ID		0x008
#define VIRTIO_MMIO_VENDOR_ID		0x00c
#define VIRTIO_MMIO_DEVICE_FEATURES	0x010
#define VIRTIO_MMIO_DEVICE_FEATURES_SEL	0x014
#define VIRTIO_MMIO_DRIVER_FEATURES	0x020
#define VIRTIO_MMIO_DRIVER_FEATURES_SEL	0x024
#define VIRTIO_MMIO_GUEST_PAGE_SIZE	0x028 /* version 1 only */
#define VIRTIO_MMIO_QUEUE_SEL		0x030
#define VIRTIO_MMIO_QUEUE_NUM_MAX	0x034
#define VIRTIO_MMIO_QUEUE_NUM		0x038
#define VIRTIO_MMIO_QUEUE_ALIGN		0x03c /* version 1 only */
#define VIRTIO_MMIO_QUEUE_PFN		0x040 /* version 1 only */
#define VIRTIO_MMIO_QUEUE_READY		0x044
#define VIRTIO_MMIO_QUEUE_NOTIFY	0x050
#define VIRTIO_MMIO_INTERRUPT_STATUS	0x060
#define VIRTIO_MMIO_INTERRUPT_ACK	0x064
#define VIRTIO_MMIO_STATUS		0x070
#define VIRTIO_MMIO_QUEUE_DESC_LOW	0x080
#define VIRTIO_MMIO_QUEUE_DESC_HIGH	0x084
#define VIRTIO_MMIO_QUEUE_AVAIL_LOW	0x090
#define VIRTIO_MMIO_QUEUE_AVAIL_HIGH	0x094
#define VIRTIO_MMIO_QUEUE_USED_LOW	0x0a0
#define VIRTIO_MMIO_QUEUE_USED_HIGH	0x0a4
#define VIRTIO_MMIO_CONFIG_GENERATION	0x0fc
#define VIRTIO_MMIO_CONFIG		0x100



#define MAX_QUEUE 8
#define MAX_CONFIG_SPACE_SIZE 256
#define MAX_QUEUE_NUM 64

typedef struct {
    uint32_t ready; /* 0 or 1 */
    uint32_t num;
    uint16_t last_avail_idx;
    virtio_phys_addr_t desc_addr;
    virtio_phys_addr_t avail_addr;
    virtio_phys_addr_t used_addr;
    BOOL manual_recv; /* if TRUE, the device_recv() callback is not called */
} QueueState;

#define VRING_DESC_F_NEXT	1
#define VRING_DESC_F_WRITE	2
#define VRING_DESC_F_INDIRECT	4

typedef struct {
    uint64_t addr;
    uint32_t len;
    uint16_t flags; /* VRING_DESC_F_x */
    uint16_t next;
} VIRTIODesc;

/* return < 0 to stop the notification (it must be manually restarted
   later), 0 if OK */
typedef int VIRTIODeviceRecvFunc(VIRTIODevice *s1, int queue_idx,
                                 int desc_idx, int read_size,
                                 int write_size);


struct VIRTIODevice {
    /* MMIO only */
    IRQSignal *irq;
    
    uint32_t int_status;
    uint32_t status;
    uint32_t device_features_sel;
    uint32_t queue_sel; /* currently selected queue */
    QueueState queue[MAX_QUEUE];

    /* device specific */
    uint32_t device_id;
    uint32_t vendor_id;
    uint32_t device_features;
    VIRTIODeviceRecvFunc *device_recv;
    void (*config_write)(VIRTIODevice *s); /* called after the config
                                              is written */
    uint32_t config_space_size; /* in bytes, must be multiple of 4 */
    uint8_t config_space[MAX_CONFIG_SPACE_SIZE];
};

static uint32_t virtio_mmio_read(void *opaque, uint32_t offset1, int size);
static void virtio_mmio_write(void *opaque, uint32_t offset,
                              uint32_t val, int size);


static void virtio_reset(VIRTIODevice *s)
{
    int i;

    s->status = 0;
    s->queue_sel = 0;
    s->device_features_sel = 0;
    s->int_status = 0;
    for(i = 0; i < MAX_QUEUE; i++) {
        QueueState *qs = &s->queue[i];
        qs->ready = 0;
        qs->num = MAX_QUEUE_NUM;
        qs->desc_addr = 0;
        qs->avail_addr = 0;
        qs->used_addr = 0;
        qs->last_avail_idx = 0;
    }
}




static void virtio_init(VIRTIODevice *s, virtio_phys_addr_t base, IRQSignal *irq,
                        uint32_t device_id, int config_space_size,
                        VIRTIODeviceRecvFunc *device_recv)
{
    memset(s, 0, sizeof(VIRTIODevice));
    /* MMIO case */
    // s->mem_map = bus->mem_map;
    s->irq = irq;
    s->device_id = device_id;
    s->vendor_id = 0xffff;
    s->config_space_size = config_space_size;
    s->device_recv = device_recv;
    virtio_reset(s);

    MMIODevice d;
    d.startAddr = base;
    d.endAddr = base + VIRTIO_PAGE_SIZE;
    d.opaque = s;
    d._read = virtio_mmio_read;
    d._write = virtio_mmio_write;
    cpu_register_mmio_device(&d);
}

static uint16_t virtio_read16(VIRTIODevice *s, virtio_phys_addr_t addr)
{
    uint8_t *ptr;
    if (addr & 1)
        return 0; /* unaligned access are not supported */
    uint16_t val;
    cpu_physical_memory_rw(addr, (uint8_t*)&val, sizeof(uint16_t), 0);
    
    return val;
}

static void virtio_write16(VIRTIODevice *s, virtio_phys_addr_t addr,
                           uint16_t val)
{
    uint8_t *ptr;
    if (addr & 1)
        return; /* unaligned access are not supported */
   cpu_physical_memory_rw(addr, (uint8_t*)&val, sizeof(uint16_t), 1);
}

static void virtio_write32(VIRTIODevice *s, virtio_phys_addr_t addr,
                           uint32_t val)
{
    uint8_t *ptr;
    if (addr & 3)
        return; /* unaligned access are not supported */
    cpu_physical_memory_rw(addr, (uint8_t*)&val, sizeof(uint32_t), 1);
}

static int virtio_memcpy_from_ram(VIRTIODevice *s, uint8_t *buf,
                                  virtio_phys_addr_t addr, int count)
{
    uint8_t *ptr;
    int l;
    // printf("Copy from ram %p\n", addr);
    while (count > 0) {
        l = min_int(count, VIRTIO_PAGE_SIZE - (addr & (VIRTIO_PAGE_SIZE - 1)));
        cpu_physical_memory_rw(addr, buf, l, 0);
        // ptr = s->get_ram_ptr(s, addr, FALSE);
        // if (!ptr)
        //     return -1;
        // memcpy(buf, ptr, l);
        addr += l;
        buf += l;
        count -= l;
    }
    return 0;
}

static int virtio_memcpy_to_ram(VIRTIODevice *s, virtio_phys_addr_t addr, 
                                const uint8_t *buf, int count)
{
    uint8_t *ptr;
    int l;
    // printf("Copy to ram %p\n", addr);
    while (count > 0) {
        l = min_int(count, VIRTIO_PAGE_SIZE - (addr & (VIRTIO_PAGE_SIZE - 1)));
        cpu_physical_memory_rw(addr, (uint8_t*)buf, l, 1);
        // ptr = s->get_ram_ptr(s, addr, TRUE);
        // if (!ptr)
        //     return -1;
        // memcpy(ptr, buf, l);
        addr += l;
        buf += l;
        count -= l;
    }
    return 0;
}

static int get_desc(VIRTIODevice *s, VIRTIODesc *desc,  
                    int queue_idx, int desc_idx)
{
    QueueState *qs = &s->queue[queue_idx];
    return virtio_memcpy_from_ram(s, (void *)desc, qs->desc_addr +
                                  desc_idx * sizeof(VIRTIODesc),
                                  sizeof(VIRTIODesc));
}

static int memcpy_to_from_queue(VIRTIODevice *s, uint8_t *buf,
                                int queue_idx, int desc_idx,
                                int offset, int count, BOOL to_queue)
{
    VIRTIODesc desc;
    int l, f_write_flag;

    if (count == 0)
        return 0;

    get_desc(s, &desc, queue_idx, desc_idx);

    if (to_queue) {
        f_write_flag = VRING_DESC_F_WRITE;
        /* find the first write descriptor */
        for(;;) {
            if ((desc.flags & VRING_DESC_F_WRITE) == f_write_flag)
                break;
            if (!(desc.flags & VRING_DESC_F_NEXT))
                return -1;
            desc_idx = desc.next;
            get_desc(s, &desc, queue_idx, desc_idx);
        }
    } else {
        f_write_flag = 0;
    }

    /* find the descriptor at offset */
    for(;;) {
        if ((desc.flags & VRING_DESC_F_WRITE) != f_write_flag)
            return -1;
        if (offset < desc.len)
            break;
        if (!(desc.flags & VRING_DESC_F_NEXT))
            return -1;
        desc_idx = desc.next;
        offset -= desc.len;
        get_desc(s, &desc, queue_idx, desc_idx);
    }

    for(;;) {
        l = min_int(count, desc.len - offset);
        if (to_queue)
            virtio_memcpy_to_ram(s, desc.addr + offset, buf, l);
        else {
            virtio_memcpy_from_ram(s, buf, desc.addr + offset, l);
        }
        count -= l;
        if (count == 0)
            break;
        offset += l;
        buf += l;
        if (offset == desc.len) {
            if (!(desc.flags & VRING_DESC_F_NEXT))
                return -1;
            desc_idx = desc.next;
            get_desc(s, &desc, queue_idx, desc_idx);
            if ((desc.flags & VRING_DESC_F_WRITE) != f_write_flag)
                return -1;
            offset = 0;
        }
    }
    return 0;
}

static int memcpy_from_queue(VIRTIODevice *s, void *buf,
                             int queue_idx, int desc_idx,
                             int offset, int count)
{
    return memcpy_to_from_queue(s, buf, queue_idx, desc_idx, offset, count,
                                FALSE);
}

static int memcpy_to_queue(VIRTIODevice *s,
                           int queue_idx, int desc_idx,
                           int offset, const void *buf, int count)
{
    return memcpy_to_from_queue(s, (void *)buf, queue_idx, desc_idx, offset,
                                count, TRUE);
}

/* signal that the descriptor has been consumed */
static void virtio_consume_desc(VIRTIODevice *s,
                                int queue_idx, int desc_idx, int desc_len)
{
    QueueState *qs = &s->queue[queue_idx];
    virtio_phys_addr_t addr;
    uint32_t index;

    addr = qs->used_addr + 2;
    index = virtio_read16(s, addr);
    virtio_write16(s, addr, index + 1);

    addr = qs->used_addr + 4 + (index & (qs->num - 1)) * 8;
    virtio_write32(s, addr, desc_idx);
    virtio_write32(s, addr + 4, desc_len);

    s->int_status |= 1;
    set_irq(s->irq, 1);
}

static int get_desc_rw_size(VIRTIODevice *s, 
                             int *pread_size, int *pwrite_size,
                             int queue_idx, int desc_idx)
{
    VIRTIODesc desc;
    int read_size, write_size;

    read_size = 0;
    write_size = 0;
    get_desc(s, &desc, queue_idx, desc_idx);

    for(;;) {
        if (desc.flags & VRING_DESC_F_WRITE)
            break;
        read_size += desc.len;
        if (!(desc.flags & VRING_DESC_F_NEXT))
            goto done;
        desc_idx = desc.next;
        get_desc(s, &desc, queue_idx, desc_idx);
    }
    
    for(;;) {
        if (!(desc.flags & VRING_DESC_F_WRITE))
            return -1;
        write_size += desc.len;
        if (!(desc.flags & VRING_DESC_F_NEXT))
            break;
        desc_idx = desc.next;
        get_desc(s, &desc, queue_idx, desc_idx);
    }

 done:
    *pread_size = read_size;
    *pwrite_size = write_size;
    return 0;
}

/* XXX: test if the queue is ready ? */
static void queue_notify(VIRTIODevice *s, int queue_idx)
{
    QueueState *qs = &s->queue[queue_idx];
    uint16_t avail_idx;
    int desc_idx, read_size, write_size;

    if (qs->manual_recv)
        return;

    avail_idx = virtio_read16(s, qs->avail_addr + 2);
    while (qs->last_avail_idx != avail_idx) {
        desc_idx = virtio_read16(s, qs->avail_addr + 4 + 
                                 (qs->last_avail_idx & (qs->num - 1)) * 2);
        if (!get_desc_rw_size(s, &read_size, &write_size, queue_idx, desc_idx)) {
            // printf("queue_notify: idx=%d read_size=%d write_size=%d\n",
            //            queue_idx, read_size, write_size);
            if (s->device_recv(s, queue_idx, desc_idx,
                               read_size, write_size) < 0)
                break;
        }
        qs->last_avail_idx++;
    }
}

static uint32_t virtio_config_read(VIRTIODevice *s, uint32_t offset,
                                   int size)
{
    uint32_t val;
    switch(size) {
    case 1:
        if (offset < s->config_space_size) {
            val = s->config_space[offset];
        } else {
            val = 0;
        }
        break;
    case 2:
        if (offset < (s->config_space_size - 1)) {
            val = get_le16(&s->config_space[offset]);
        } else {
            val = 0;
        }
        break;
    case 4:
        if (offset < (s->config_space_size - 3)) {
            val = get_le32(s->config_space + offset);
        } else {
            val = 0;
        }
        break;
    default:
        abort();
    }
    return val;
}

static void virtio_config_write(VIRTIODevice *s, uint32_t offset,
                                uint32_t val, int size)
{
    switch(size) {
    case 1:
        if (offset < s->config_space_size) {
            s->config_space[offset] = val;
            if (s->config_write)
                s->config_write(s);
        }
        break;
    case 2:
        if (offset < s->config_space_size - 1) {
            put_le16(s->config_space + offset, val);
            if (s->config_write)
                s->config_write(s);
        }
        break;
    case 4:
        if (offset < s->config_space_size - 3) {
            put_le32(s->config_space + offset, val);
            if (s->config_write)
                s->config_write(s);
        }
        break;
    }
}

static uint32_t virtio_mmio_read(void *opaque, uint32_t offset, int size)
{
    VIRTIODevice *s = opaque;
    uint32_t val;

    if (offset >= VIRTIO_MMIO_CONFIG) {
        return virtio_config_read(s, offset - VIRTIO_MMIO_CONFIG, size);
    }

    if (size == 4) {
        switch(offset) {
        case VIRTIO_MMIO_MAGIC_VALUE:
            val = 0x74726976;
            break;
        case VIRTIO_MMIO_VERSION:
            val = 2;
            break;
        case VIRTIO_MMIO_DEVICE_ID:
            val = s->device_id;
            break;
        case VIRTIO_MMIO_VENDOR_ID:
            val = s->vendor_id;
            break;
        case VIRTIO_MMIO_DEVICE_FEATURES:
            switch(s->device_features_sel) {
            case 0:
                val = s->device_features;
                break;
            case 1:
                val = 1; /* version 1 */
                break;
            default:
                val = 0;
                break;
            }
            break;
        case VIRTIO_MMIO_DEVICE_FEATURES_SEL:
            val = s->device_features_sel;
            break;
        case VIRTIO_MMIO_QUEUE_SEL:
            val = s->queue_sel;
            break;
        case VIRTIO_MMIO_QUEUE_NUM_MAX:
            val = MAX_QUEUE_NUM;
            break;
        case VIRTIO_MMIO_QUEUE_NUM:
            val = s->queue[s->queue_sel].num;
            break;
        case VIRTIO_MMIO_QUEUE_DESC_LOW:
            val = s->queue[s->queue_sel].desc_addr;
            break;
        case VIRTIO_MMIO_QUEUE_AVAIL_LOW:
            val = s->queue[s->queue_sel].avail_addr;
            break;
        case VIRTIO_MMIO_QUEUE_USED_LOW:
            val = s->queue[s->queue_sel].used_addr;
            break;
#if defined(TARGET_X86_64)
        case VIRTIO_MMIO_QUEUE_DESC_HIGH:
            val = s->queue[s->queue_sel].desc_addr >> 32;
            break;
        case VIRTIO_MMIO_QUEUE_AVAIL_HIGH:
            val = s->queue[s->queue_sel].avail_addr >> 32;
            break;
        case VIRTIO_MMIO_QUEUE_USED_HIGH:
            val = s->queue[s->queue_sel].used_addr >> 32;
            break;
#endif
        case VIRTIO_MMIO_QUEUE_READY:
            val = s->queue[s->queue_sel].ready;
            break;
        case VIRTIO_MMIO_INTERRUPT_STATUS:
            val = s->int_status;
            break;
        case VIRTIO_MMIO_STATUS:
            val = s->status;
            break;
        case VIRTIO_MMIO_CONFIG_GENERATION:
            val = 0;
            break;
        default:
            val = 0;
            break;
        }
    } else {
        val = 0;
    }

    // printf("virto_mmio_read: offset=0x%x val=0x%x size=%d %p\n", 
    //            offset, val, size, opaque);
    return val;
}

#if defined(TARGET_X86_64)
static void set_low32(virtio_phys_addr_t *paddr, uint32_t val)
{
    *paddr = (*paddr & ~(virtio_phys_addr_t)0xffffffff) | val;
}

static void set_high32(virtio_phys_addr_t *paddr, uint32_t val)
{
    *paddr = (*paddr & 0xffffffff) | ((virtio_phys_addr_t)val << 32);
}
#else
static void set_low32(virtio_phys_addr_t *paddr, uint32_t val)
{
    *paddr = val;
}
#endif

static void virtio_mmio_write(void *opaque, uint32_t offset,
                              uint32_t val, int size)
{
    VIRTIODevice *s = opaque;
    
    // printf("virto_mmio_write: offset=0x%x val=0x%x size=%d %p\n",
    //            offset, val, size, opaque);


    if (offset >= VIRTIO_MMIO_CONFIG) {
        virtio_config_write(s, offset - VIRTIO_MMIO_CONFIG, val, size);
        return;
    }

    if (size == 4) {
        switch(offset) {
        case VIRTIO_MMIO_DEVICE_FEATURES_SEL:
            s->device_features_sel = val;
            break;
        case VIRTIO_MMIO_QUEUE_SEL:
            if (val < MAX_QUEUE)
                s->queue_sel = val;
            break;
        case VIRTIO_MMIO_QUEUE_NUM:
            if ((val & (val - 1)) == 0 && val > 0) {
                s->queue[s->queue_sel].num = val;
            }
            break;
        case VIRTIO_MMIO_QUEUE_DESC_LOW:
            set_low32(&s->queue[s->queue_sel].desc_addr, val);
            break;
        case VIRTIO_MMIO_QUEUE_AVAIL_LOW:
            set_low32(&s->queue[s->queue_sel].avail_addr, val);
            break;
        case VIRTIO_MMIO_QUEUE_USED_LOW:
            set_low32(&s->queue[s->queue_sel].used_addr, val);
            break;
#if defined(TARGET_X86_64)
        case VIRTIO_MMIO_QUEUE_DESC_HIGH:
            set_high32(&s->queue[s->queue_sel].desc_addr, val);
            break;
        case VIRTIO_MMIO_QUEUE_AVAIL_HIGH:
            set_high32(&s->queue[s->queue_sel].avail_addr, val);
            break;
        case VIRTIO_MMIO_QUEUE_USED_HIGH:
            set_high32(&s->queue[s->queue_sel].used_addr, val);
            break;
#endif
        case VIRTIO_MMIO_STATUS:
            // printf("STATUS\n");
            s->status = val;
            if (val == 0) {
                /* reset */
                set_irq(s->irq, 0);
                virtio_reset(s);
            }
            break;
        case VIRTIO_MMIO_QUEUE_READY:
            s->queue[s->queue_sel].ready = val & 1;
            break;
        case VIRTIO_MMIO_QUEUE_NOTIFY:
            if (val < MAX_QUEUE)
                queue_notify(s, val);
            break;
        case VIRTIO_MMIO_INTERRUPT_ACK:
            // printf("ACK\n");
            s->int_status &= ~val;
            if (s->int_status == 0) {
                set_irq(s->irq, 0);
            }
            break;
        }
    }
}


static void virtio_config_change_notify(VIRTIODevice *s)
{
    /* INT_CONFIG interrupt */
    s->int_status |= 2;
    set_irq(s->irq, 1);
}

// /*********************************************************************/
// /* block device */

typedef struct {
    uint32_t type;
    uint8_t *buf;
    int write_size;
    int queue_idx;
    int desc_idx;
} BlockRequest;

typedef struct VIRTIOBlockDevice {
    VIRTIODevice common;
    BlockDevice *bs;

    BOOL req_in_progress;
    BlockRequest req; /* request in progress */
} VIRTIOBlockDevice;

typedef struct {
    uint32_t type;
    uint32_t ioprio;
    uint64_t sector_num;
} BlockRequestHeader;

#define VIRTIO_BLK_T_IN          0
#define VIRTIO_BLK_T_OUT         1
#define VIRTIO_BLK_T_FLUSH       4
#define VIRTIO_BLK_T_FLUSH_OUT   5

#define VIRTIO_BLK_S_OK     0
#define VIRTIO_BLK_S_IOERR  1
#define VIRTIO_BLK_S_UNSUPP 2

#define SECTOR_SIZE 512

static void virtio_block_req_end(VIRTIODevice *s, int ret)
{

    VIRTIOBlockDevice *s1 = (VIRTIOBlockDevice *)s;
    int write_size;
    int queue_idx = s1->req.queue_idx;
    int desc_idx = s1->req.desc_idx;
    uint8_t *buf, buf1[1];

    switch(s1->req.type) {
    case VIRTIO_BLK_T_IN:
        write_size = s1->req.write_size;
        buf = s1->req.buf;
        if (ret < 0) {
            buf[write_size - 1] = VIRTIO_BLK_S_IOERR;
            
        } else {
            buf[write_size - 1] = VIRTIO_BLK_S_OK;
        }
        memcpy_to_queue(s, queue_idx, desc_idx, 0, buf, write_size);
        free(buf);
        virtio_consume_desc(s, queue_idx, desc_idx, write_size);

        break;
    case VIRTIO_BLK_T_OUT:
        if (ret < 0)
            buf1[0] = VIRTIO_BLK_S_IOERR;
        else
            buf1[0] = VIRTIO_BLK_S_OK;
        memcpy_to_queue(s, queue_idx, desc_idx, 0, buf1, sizeof(buf1));
        virtio_consume_desc(s, queue_idx, desc_idx, 1);
        break;
    default:
        abort();
    }
}

static void virtio_block_req_cb(void *opaque, int ret)
{
    VIRTIODevice *s = opaque;
    VIRTIOBlockDevice *s1 = (VIRTIOBlockDevice *)s;

    virtio_block_req_end(s, ret);
    
    s1->req_in_progress = FALSE;

    /* handle next requests */
    queue_notify((VIRTIODevice *)s, s1->req.queue_idx);
}

/* XXX: handle async I/O */
static int virtio_block_recv_request(VIRTIODevice *s, int queue_idx,
                                     int desc_idx, int read_size,
                                     int write_size)
{

    

    VIRTIOBlockDevice *s1 = (VIRTIOBlockDevice *)s;
    BlockDevice *bs = s1->bs;
    BlockRequestHeader h;
    uint8_t *buf;
    int len, ret;

    if (s1->req_in_progress) {
       
        return -1;
    }
    
    if (memcpy_from_queue(s, &h, queue_idx, desc_idx, 0, sizeof(h)) < 0) {
        
        return 0;
    }

    
    s1->req.type = h.type;
    s1->req.queue_idx = queue_idx;
    s1->req.desc_idx = desc_idx;
    switch(h.type) {
    case VIRTIO_BLK_T_IN:
        s1->req.buf = malloc(write_size);
        s1->req.write_size = write_size;
        ret = bs->read_async(bs, h.sector_num, s1->req.buf, 
                             (write_size - 1) / SECTOR_SIZE,
                             virtio_block_req_cb, s);
        if (ret > 0) {
            /* asyncronous read */
           
            s1->req_in_progress = TRUE;
        } else {
            virtio_block_req_end(s, ret);
        }
        break;
    case VIRTIO_BLK_T_OUT:
        assert(write_size >= 1);
        len = read_size - sizeof(h);
        buf = malloc(len);
        memcpy_from_queue(s, buf, queue_idx, desc_idx, sizeof(h), len);
        ret = bs->write_async(bs, h.sector_num, buf, len / SECTOR_SIZE,
                              virtio_block_req_cb, s);
        free(buf);
        if (ret > 0) {
            /* asyncronous write */
           
            s1->req_in_progress = TRUE;
        } else {
            virtio_block_req_end(s, ret);
        }
        break;
    default:
        break;
    }
    return 0;
}

VIRTIODevice *virtio_block_init(virtio_phys_addr_t base, IRQSignal* irq, BlockDevice *bs)
{
    VIRTIOBlockDevice *s;
    uint64_t nb_sectors;

    s = malloc(sizeof(VIRTIOBlockDevice));

    if(!s) {
        abort();
    }

    memset(s, 0, sizeof(VIRTIOBlockDevice));

    virtio_init(&s->common, base, irq,
                2, 8, virtio_block_recv_request);
    s->bs = bs;
    
    nb_sectors = bs->get_sector_count(bs);
    put_le32(s->common.config_space, nb_sectors);
    put_le32(s->common.config_space + 4, nb_sectors >> 32);

    return (VIRTIODevice *)s;
}

// /*********************************************************************/
// /* network device */

typedef struct VIRTIONetDevice {
    VIRTIODevice common;
    EthernetDevice *es;
    int header_size;
} VIRTIONetDevice;

typedef struct {
    uint8_t flags;
    uint8_t gso_type;
    uint16_t hdr_len;
    uint16_t gso_size;
    uint16_t csum_start;
    uint16_t csum_offset;
    uint16_t num_buffers;
} VIRTIONetHeader;

static int virtio_net_recv_request(VIRTIODevice *s, int queue_idx,
                                   int desc_idx, int read_size,
                                   int write_size)
{
    VIRTIONetDevice *s1 = (VIRTIONetDevice *)s;
    EthernetDevice *es = s1->es;
    VIRTIONetHeader h;
    uint8_t *buf;
    int len;

    if (queue_idx == 1) {
        /* send to network */
        if (memcpy_from_queue(s, &h, queue_idx, desc_idx, 0, s1->header_size) < 0){
            return 0;
        }
        len = read_size - s1->header_size;
        buf = malloc(len);
        memcpy_from_queue(s, buf, queue_idx, desc_idx, s1->header_size, len);
        es->write_packet(es, buf, len);
        free(buf);
        virtio_consume_desc(s, queue_idx, desc_idx, 0);
    }
    return 0;
}

static BOOL virtio_net_can_write_packet(EthernetDevice *es)
{
    VIRTIODevice *s = es->device_opaque;
    QueueState *qs = &s->queue[0];
    uint16_t avail_idx;

    if (!qs->ready)
        return FALSE;
    avail_idx = virtio_read16(s, qs->avail_addr + 2);
    return qs->last_avail_idx != avail_idx;
}

static void virtio_net_write_packet(EthernetDevice *es, const uint8_t *buf, int buf_len)
{
    VIRTIODevice *s = es->device_opaque;
    VIRTIONetDevice *s1 = (VIRTIONetDevice *)s;
    int queue_idx = 0;
    QueueState *qs = &s->queue[queue_idx];
    int desc_idx;
    VIRTIONetHeader h;
    int len, read_size, write_size;
    uint16_t avail_idx;

    if (!qs->ready)
        return;
    avail_idx = virtio_read16(s, qs->avail_addr + 2);
    if (qs->last_avail_idx == avail_idx)
        return;
    desc_idx = virtio_read16(s, qs->avail_addr + 4 + 
                             (qs->last_avail_idx & (qs->num - 1)) * 2);
    if (get_desc_rw_size(s, &read_size, &write_size, queue_idx, desc_idx))
        return;
    len = s1->header_size + buf_len; 
    if (len > write_size)
        return;
    memset(&h, 0, s1->header_size);
    memcpy_to_queue(s, queue_idx, desc_idx, 0, &h, s1->header_size);
    memcpy_to_queue(s, queue_idx, desc_idx, s1->header_size, buf, buf_len);
    virtio_consume_desc(s, queue_idx, desc_idx, len);
    qs->last_avail_idx++;
}

static void virtio_net_set_carrier(EthernetDevice *es, BOOL carrier_state)
{
#if 0
    VIRTIODevice *s1 = es->device_opaque;
    VIRTIONetDevice *s = (VIRTIONetDevice *)s1;
    int cur_carrier_state;

    //    printf("virtio_net_set_carrier: %d\n", carrier_state);
    cur_carrier_state = s->common.config_space[6] & 1;
    if (cur_carrier_state != carrier_state) {
        s->common.config_space[6] = (carrier_state << 0);
        virtio_config_change_notify(s1);
    }
#endif
}

VIRTIODevice *virtio_net_init(virtio_phys_addr_t base, IRQSignal *irq, EthernetDevice *es)
{
    VIRTIONetDevice *s;

    s = malloc(sizeof(*s));

    if (!s) {
        abort();
    }

    memset(s, 0, sizeof(*s));
    virtio_init(&s->common, base, irq,
                1, 6 + 2, virtio_net_recv_request);
    /* VIRTIO_NET_F_MAC, VIRTIO_NET_F_STATUS */
    s->common.device_features = (1 << 5) /* | (1 << 16) */;
    s->common.queue[0].manual_recv = TRUE;
    s->es = es;
    memcpy(s->common.config_space, es->mac_addr, 6);
    /* status */
    s->common.config_space[6] = 0;
    s->common.config_space[7] = 0;

    s->header_size = sizeof(VIRTIONetHeader);
    
    es->device_opaque = s;
    es->device_can_write_packet = virtio_net_can_write_packet;
    es->device_write_packet = virtio_net_write_packet;
    es->device_set_carrier = virtio_net_set_carrier;
    return (VIRTIODevice *)s;
}

/*********************************************************************/
/* console device */

typedef struct VIRTIOConsoleDevice {
    VIRTIODevice common;
    CharacterDevice *cs;
} VIRTIOConsoleDevice;

static int virtio_console_recv_request(VIRTIODevice *s, int queue_idx,
                                       int desc_idx, int read_size,
                                       int write_size)
{
    VIRTIOConsoleDevice *s1 = (VIRTIOConsoleDevice *)s;
    CharacterDevice *cs = s1->cs;
    uint8_t *buf;

    if (queue_idx == 1) {
        /* send to console */
        buf = malloc(read_size + 1);
        memcpy_from_queue(s, buf, queue_idx, desc_idx, 0, read_size);
        buf[read_size] = 0;
        cs->write_data(cs->opaque, buf, read_size);
        free(buf);
        virtio_consume_desc(s, queue_idx, desc_idx, 0);
    }
    return 0;
}

BOOL virtio_console_can_write_data(VIRTIODevice *s)
{
    QueueState *qs = &s->queue[0];
    uint16_t avail_idx;

    if (!qs->ready)
        return FALSE;
    avail_idx = virtio_read16(s, qs->avail_addr + 2);
    return qs->last_avail_idx != avail_idx;
}

int virtio_console_get_write_len(VIRTIODevice *s)
{
    int queue_idx = 0;
    QueueState *qs = &s->queue[queue_idx];
    int desc_idx;
    int read_size, write_size;
    uint16_t avail_idx;

    if (!qs->ready)
        return 0;
    avail_idx = virtio_read16(s, qs->avail_addr + 2);
    if (qs->last_avail_idx == avail_idx)
        return 0;
    desc_idx = virtio_read16(s, qs->avail_addr + 4 + 
                             (qs->last_avail_idx & (qs->num - 1)) * 2);
    if (get_desc_rw_size(s, &read_size, &write_size, queue_idx, desc_idx))
        return 0;
    return write_size;
}

int virtio_console_write_data(VIRTIODevice *s, const uint8_t *buf, int buf_len)
{
    int queue_idx = 0;
    QueueState *qs = &s->queue[queue_idx];
    int desc_idx;
    uint16_t avail_idx;

    if (!qs->ready)
        return 0;
    avail_idx = virtio_read16(s, qs->avail_addr + 2);
    if (qs->last_avail_idx == avail_idx)
        return 0;
    desc_idx = virtio_read16(s, qs->avail_addr + 4 + 
                             (qs->last_avail_idx & (qs->num - 1)) * 2);
    memcpy_to_queue(s, queue_idx, desc_idx, 0, buf, buf_len);
    virtio_consume_desc(s, queue_idx, desc_idx, buf_len);
    qs->last_avail_idx++;
    return buf_len;
}

/* send a resize event */
void virtio_console_resize_event(VIRTIODevice *s, int width, int height)
{
    /* indicate the console size */
    put_le16(s->config_space + 0, width);
    put_le16(s->config_space + 2, height);

    virtio_config_change_notify(s);
}

VIRTIODevice *virtio_console_init(virtio_phys_addr_t base, IRQSignal *irq, CharacterDevice *cs)
{
    VIRTIOConsoleDevice *s;

    s = malloc(sizeof(VIRTIOConsoleDevice));
    if (!s) {
        abort();
    }

    memset(s, 0, sizeof(VIRTIOConsoleDevice));


    virtio_init(&s->common, base, irq,
                3, 4, virtio_console_recv_request);
    s->common.device_features = (1 << 0); /* VIRTIO_CONSOLE_F_SIZE */
    s->common.queue[0].manual_recv = TRUE;
    
    s->cs = cs;


    return (VIRTIODevice *)s;
}

// /*********************************************************************/
// /* input device */

// enum {
//     VIRTIO_INPUT_CFG_UNSET      = 0x00,
//     VIRTIO_INPUT_CFG_ID_NAME    = 0x01,
//     VIRTIO_INPUT_CFG_ID_SERIAL  = 0x02,
//     VIRTIO_INPUT_CFG_ID_DEVIDS  = 0x03,
//     VIRTIO_INPUT_CFG_PROP_BITS  = 0x10,
//     VIRTIO_INPUT_CFG_EV_BITS    = 0x11,
//     VIRTIO_INPUT_CFG_ABS_INFO   = 0x12,
// };

// #define VIRTIO_INPUT_EV_SYN 0x00
// #define VIRTIO_INPUT_EV_KEY 0x01
// #define VIRTIO_INPUT_EV_REL 0x02
// #define VIRTIO_INPUT_EV_ABS 0x03
// #define VIRTIO_INPUT_EV_REP 0x14

// #define BTN_LEFT         0x110
// #define BTN_RIGHT        0x111
// #define BTN_MIDDLE       0x112
// #define BTN_GEAR_DOWN    0x150
// #define BTN_GEAR_UP      0x151

// #define REL_X 0x00
// #define REL_Y 0x01
// #define REL_Z 0x02
// #define REL_WHEEL 0x08

// #define ABS_X 0x00
// #define ABS_Y 0x01
// #define ABS_Z 0x02

// typedef struct VIRTIOInputDevice {
//     VIRTIODevice common;
//     VirtioInputTypeEnum type;
//     uint32_t buttons_state;
// } VIRTIOInputDevice;

// static const uint16_t buttons_list[] = {
//     BTN_LEFT, BTN_RIGHT, BTN_MIDDLE
// };

// static int virtio_input_recv_request(VIRTIODevice *s, int queue_idx,
//                                       int desc_idx, int read_size,
//                                       int write_size)
// {
//     if (queue_idx == 1) {
//         /* led & keyboard updates */
//         //        printf("%s: write_size=%d\n", __func__, write_size);
//         virtio_consume_desc(s, queue_idx, desc_idx, 0);
//     }
//     return 0;
// }

// /* return < 0 if could not send key event */
// static int virtio_input_queue_event(VIRTIODevice *s,
//                                     uint16_t type, uint16_t code,
//                                     uint32_t value)
// {
//     int queue_idx = 0;
//     QueueState *qs = &s->queue[queue_idx];
//     int desc_idx, buf_len;
//     uint16_t avail_idx;
//     uint8_t buf[8];

//     if (!qs->ready)
//         return -1;

//     put_le16(buf, type);
//     put_le16(buf + 2, code);
//     put_le32(buf + 4, value);
//     buf_len = 8;
    
//     avail_idx = virtio_read16(s, qs->avail_addr + 2);
//     if (qs->last_avail_idx == avail_idx)
//         return -1;
//     desc_idx = virtio_read16(s, qs->avail_addr + 4 + 
//                              (qs->last_avail_idx & (qs->num - 1)) * 2);
//     //    printf("send: queue_idx=%d desc_idx=%d\n", queue_idx, desc_idx);
//     memcpy_to_queue(s, queue_idx, desc_idx, 0, buf, buf_len);
//     virtio_consume_desc(s, queue_idx, desc_idx, buf_len);
//     qs->last_avail_idx++;
//     return 0;
// }

// int virtio_input_send_key_event(VIRTIODevice *s, BOOL is_down,
//                                 uint16_t key_code)
// {
//     VIRTIOInputDevice *s1 = (VIRTIOInputDevice *)s;
//     int ret;
    
//     if (s1->type != VIRTIO_INPUT_TYPE_KEYBOARD)
//         return -1;
//     ret = virtio_input_queue_event(s, VIRTIO_INPUT_EV_KEY, key_code, is_down);
//     if (ret)
//         return ret;
//     return virtio_input_queue_event(s, VIRTIO_INPUT_EV_SYN, 0, 0);
// }

// /* also used for the tablet */
// int virtio_input_send_mouse_event(VIRTIODevice *s, int dx, int dy, int dz,
//                                   unsigned int buttons)
// {
//     VIRTIOInputDevice *s1 = (VIRTIOInputDevice *)s;
//     int ret, i, b, last_b;

//     if (s1->type != VIRTIO_INPUT_TYPE_MOUSE &&
//         s1->type != VIRTIO_INPUT_TYPE_TABLET)
//         return -1;
//     if (s1->type == VIRTIO_INPUT_TYPE_MOUSE) {
//         ret = virtio_input_queue_event(s, VIRTIO_INPUT_EV_REL, REL_X, dx);
//         if (ret != 0)
//             return ret;
//         ret = virtio_input_queue_event(s, VIRTIO_INPUT_EV_REL, REL_Y, dy);
//         if (ret != 0)
//             return ret;
//     } else {
//         ret = virtio_input_queue_event(s, VIRTIO_INPUT_EV_ABS, ABS_X, dx);
//         if (ret != 0)
//             return ret;
//         ret = virtio_input_queue_event(s, VIRTIO_INPUT_EV_ABS, ABS_Y, dy);
//         if (ret != 0)
//             return ret;
//     }
//     if (dz != 0) {
//         ret = virtio_input_queue_event(s, VIRTIO_INPUT_EV_REL, REL_WHEEL, dz);
//         if (ret != 0)
//             return ret;
//     }

//     if (buttons != s1->buttons_state) {
//         for(i = 0; i < countof(buttons_list); i++) {
//             b = (buttons >> i) & 1;
//             last_b = (s1->buttons_state >> i) & 1;
//             if (b != last_b) {
//                 ret = virtio_input_queue_event(s, VIRTIO_INPUT_EV_KEY,
//                                                buttons_list[i], b);
//                 if (ret != 0)
//                     return ret;
//             }
//         }
//         s1->buttons_state = buttons;
//     }

//     return virtio_input_queue_event(s, VIRTIO_INPUT_EV_SYN, 0, 0);
// }

// static void set_bit(uint8_t *tab, int k)
// {
//     tab[k >> 3] |= 1 << (k & 7);
// }

// static void virtio_input_config_write(VIRTIODevice *s)
// {
//     VIRTIOInputDevice *s1 = (VIRTIOInputDevice *)s;
//     uint8_t *config = s->config_space;
//     int i;
    
//     //    printf("config_write: %02x %02x\n", config[0], config[1]);
//     switch(config[0]) {
//     case VIRTIO_INPUT_CFG_UNSET:
//         break;
//     case VIRTIO_INPUT_CFG_ID_NAME:
//         {
//             const char *name;
//             int len;
//             switch(s1->type) {
//             case VIRTIO_INPUT_TYPE_KEYBOARD:
//                 name = "virtio_keyboard";
//                 break;
//             case VIRTIO_INPUT_TYPE_MOUSE:
//                 name = "virtio_mouse";
//                 break;
//             case VIRTIO_INPUT_TYPE_TABLET:
//                 name = "virtio_tablet";
//                 break;
//             default:
//                 abort();
//             }
//             len = strlen(name);
//             config[2] = len;
//             memcpy(config + 8, name, len);
//         }
//         break;
//     default:
//     case VIRTIO_INPUT_CFG_ID_SERIAL:
//     case VIRTIO_INPUT_CFG_ID_DEVIDS:
//     case VIRTIO_INPUT_CFG_PROP_BITS:
//         config[2] = 0; /* size of reply */
//         break;
//     case VIRTIO_INPUT_CFG_EV_BITS:
//         config[2] = 0;
//         switch(s1->type) {
//         case VIRTIO_INPUT_TYPE_KEYBOARD:
//             switch(config[1]) {
//             case VIRTIO_INPUT_EV_KEY:
//                 config[2] = 128 / 8;
//                 memset(config + 8, 0xff, 128 / 8); /* bitmap */
//                 break;
//             case VIRTIO_INPUT_EV_REP: /* allow key repetition */
//                 config[2] = 1;
//                 break;
//             default:
//                 break;
//             }
//             break;
//         case VIRTIO_INPUT_TYPE_MOUSE:
//             switch(config[1]) {
//             case VIRTIO_INPUT_EV_KEY:
//                 config[2] = 512 / 8;
//                 memset(config + 8, 0, 512 / 8); /* bitmap */
//                 for(i = 0; i < countof(buttons_list); i++)
//                     set_bit(config + 8, buttons_list[i]);
//                 break;
//             case VIRTIO_INPUT_EV_REL:
//                 config[2] = 2;
//                 config[8] = 0;
//                 config[9] = 0;
//                 set_bit(config + 8, REL_X);
//                 set_bit(config + 8, REL_Y);
//                 set_bit(config + 8, REL_WHEEL);
//                 break;
//             default:
//                 break;
//             }
//             break;
//         case VIRTIO_INPUT_TYPE_TABLET:
//             switch(config[1]) {
//             case VIRTIO_INPUT_EV_KEY:
//                 config[2] = 512 / 8;
//                 memset(config + 8, 0, 512 / 8); /* bitmap */
//                 for(i = 0; i < countof(buttons_list); i++)
//                     set_bit(config + 8, buttons_list[i]);
//                 break;
//             case VIRTIO_INPUT_EV_REL:
//                 config[2] = 2;
//                 config[8] = 0;
//                 config[9] = 0;
//                 set_bit(config + 8, REL_WHEEL);
//                 break;
//             case VIRTIO_INPUT_EV_ABS:
//                 config[2] = 1;
//                 config[8] = 0;
//                 set_bit(config + 8, ABS_X);
//                 set_bit(config + 8, ABS_Y);
//                 break;
//             default:
//                 break;
//             }
//             break;
//         default:
//             abort();
//         }
//         break;
//     case VIRTIO_INPUT_CFG_ABS_INFO:
//         if (s1->type == VIRTIO_INPUT_TYPE_TABLET && config[1] <= 1) {
//             /* for ABS_X and ABS_Y */
//             config[2] = 5 * 4;
//             put_le32(config + 8, 0); /* min */
//             put_le32(config + 12, VIRTIO_INPUT_ABS_SCALE - 1) ; /* max */
//             put_le32(config + 16, 0); /* fuzz */
//             put_le32(config + 20, 0); /* flat */
//             put_le32(config + 24, 0); /* res */
//         }
//         break;
//     }
// }

// VIRTIODevice *virtio_input_init(VIRTIOBusDef *bus, VirtioInputTypeEnum type)
// {
//     VIRTIOInputDevice *s;

//     s = mallocz(sizeof(*s));
//     virtio_init(&s->common, bus,
//                 18, 256, virtio_input_recv_request);
//     s->common.queue[0].manual_recv = TRUE;
//     s->common.device_features = 0;
//     s->common.config_write = virtio_input_config_write;
//     s->type = type;
//     return (VIRTIODevice *)s;
// }

