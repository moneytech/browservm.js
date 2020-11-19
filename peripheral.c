#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include "main.h"
#include "peripheral.h"

/* Pic */
static void pic2_update_irq(void *opaque);
void set_irq(IRQSignal *irq, int level)
{
    // printf("Setting IRQ %d\n", level);
    irq->set_irq(irq->opaque, irq->irq_num, level);
}

void irq_init(IRQSignal *irq, SetIRQFunc *set1_irq, void *opaque, int irq_num)
{
    irq->set_irq = set1_irq;
    irq->opaque = opaque;
    irq->irq_num = irq_num;
}

static void pic_reset(PICState *s)
{
    /* all 8 bit registers */
    s->last_irr = 0; /* edge detection */
    s->irr = 0; /* interrupt request register */
    s->imr = 0; /* interrupt mask register */
    s->isr = 0; /* interrupt service register */
    s->priority_add = 0; /* used to compute irq priority */
    s->irq_base = 0;
    s->read_reg_select = 0;
    s->special_mask = 0;
    s->init_state = 0;
    s->auto_eoi = 0;
    s->rotate_on_autoeoi = 0;
    s->init4 = 0; /* true if 4 byte init */
}

/* set irq level. If an edge is detected, then the IRR is set to 1 */
static void pic_set_irq1(PICState *s, int irq, int level)
{
    int mask;
    mask = 1 << irq;
    if (s->elcr & mask) {
        /* level triggered */
        if (level) {
            s->irr |= mask;
            s->last_irr |= mask;
        } else {
            s->irr &= ~mask;
            s->last_irr &= ~mask;
        }
    } else {
        /* edge triggered */
        if (level) {
            if ((s->last_irr & mask) == 0)
                s->irr |= mask;
            s->last_irr |= mask;
        } else {
            s->last_irr &= ~mask;
        }
    }
}
    
static int pic_get_priority(PICState *s, int mask)
{
    int priority;
    if (mask == 0)
        return -1;
    priority = 7;
    while ((mask & (1 << ((priority + s->priority_add) & 7))) == 0)
        priority--;
    return priority;
}

/* return the pic wanted interrupt. return -1 if none */
static int pic_get_irq(PICState *s)
{
    int mask, cur_priority, priority;

    mask = s->irr & ~s->imr;
    priority = pic_get_priority(s, mask);
    if (priority < 0)
        return -1;
    /* compute current priority */
    cur_priority = pic_get_priority(s, s->isr);
    if (priority > cur_priority) {
        /* higher priority found: an irq should be generated */
        return priority;
    } else {
        return -1;
    }
}
    
/* acknowledge interrupt 'irq' */
static void pic_intack(PICState *s, int irq)
{
    if (s->auto_eoi) {
        if (s->rotate_on_autoeoi)
            s->priority_add = (irq + 1) & 7;
    } else {
        s->isr |= (1 << irq);
    }
    /* We don't clear a level sensitive interrupt here */
    if (!(s->elcr & (1 << irq)))
        s->irr &= ~(1 << irq);
}

static void pic_write(void *opaque, uint32_t offset,
                      uint64_t val, unsigned size_log2)
{
    PICState *s = opaque;
    int priority, addr;
    
    addr = offset & 1;
#ifdef DEBUG_PIC
    console.log("pic_write: addr=" + toHex2(addr) + " val=" + toHex2(val));
#endif
    if (addr == 0) {
        if (val & 0x10) {
            /* init */
            pic_reset(s);
            s->init_state = 1;
            s->init4 = val & 1;
            if (val & 0x02)
                abort(); /* "single mode not supported" */
            if (val & 0x08)
                abort(); /* "level sensitive irq not supported" */
        } else if (val & 0x08) {
            if (val & 0x02)
                s->read_reg_select = val & 1;
            if (val & 0x40)
                s->special_mask = (val >> 5) & 1;
        } else {
            switch(val) {
            case 0x00:
            case 0x80:
                s->rotate_on_autoeoi = val >> 7;
                break;
            case 0x20: /* end of interrupt */
            case 0xa0:
                priority = pic_get_priority(s, s->isr);
                if (priority >= 0) {
                    s->isr &= ~(1 << ((priority + s->priority_add) & 7));
                }
                if (val == 0xa0)
                    s->priority_add = (s->priority_add + 1) & 7;
                break;
            case 0x60:
            case 0x61:
            case 0x62:
            case 0x63:
            case 0x64:
            case 0x65:
            case 0x66:
            case 0x67:
                priority = val & 7;
                s->isr &= ~(1 << priority);
                break;
            case 0xc0:
            case 0xc1:
            case 0xc2:
            case 0xc3:
            case 0xc4:
            case 0xc5:
            case 0xc6:
            case 0xc7:
                s->priority_add = (val + 1) & 7;
                break;
            case 0xe0:
            case 0xe1:
            case 0xe2:
            case 0xe3:
            case 0xe4:
            case 0xe5:
            case 0xe6:
            case 0xe7:
                priority = val & 7;
                s->isr &= ~(1 << priority);
                s->priority_add = (priority + 1) & 7;
                break;
            }
        }
    } else {
        switch(s->init_state) {
        case 0:
            /* normal mode */
            s->imr = val;
            s->update_irq(s->opaque);
            break;
        case 1:
            s->irq_base = val & 0xf8;
            // printf("setting irq_base %d\n", s->irq_base);
            s->init_state = 2;
            break;
        case 2:
            if (s->init4) {
                s->init_state = 3;
            } else {
                s->init_state = 0;
            }
            break;
        case 3:
            s->auto_eoi = (val >> 1) & 1;
            s->init_state = 0;
            break;
        }
    }
}

static uint64_t pic_read(void *opaque, uint32_t offset, unsigned size_log2)
{
    PICState *s = opaque;
    int addr, ret;

    addr = offset & 1;
    if (addr == 0) {
        if (s->read_reg_select)
            ret = s->isr;
        else
            ret = s->irr;
    } else {
        ret = s->imr;
    }

    return ret;
}

static void pic_elcr_write(void *opaque, uint32_t offset,
                           uint64_t val, unsigned size_log2)
{
    // printf("elcr_write\n");
    PICState *s = opaque;
    s->elcr = val & s->elcr_mask;
}

static uint64_t pic_elcr_read(void *opaque, uint32_t offset, unsigned size_log2)
{
    // printf("elcr_read\n");
    PICState *s = opaque;
    return s->elcr;
}

static PICState *pic_init(int port, int elcr_port,
                   int elcr_mask,
                   PICUpdateIRQFunc *update_irq, void *opaque)
{
    PICState *s;

    s = malloc(sizeof(*s));

    if(!s) {
        abort();
    }

    memset(s, 0, sizeof(*s));
    s->elcr_mask = elcr_mask;
    s->update_irq = update_irq;
    s->opaque = opaque;
    

    IODevice control0;
    control0.startPort = port;
    control0.endPort = port + 1;
    control0._read = pic_read;
    control0._write = pic_write;
    control0.opaque = s;
    cpu_register_io_device(&control0);
    // cpu_register_device(port_map, port, 2, s,
    //                     pic_read, pic_write, DEVIO_SIZE8);

    IODevice control1;
    control1.startPort = elcr_port;
    control1.endPort = elcr_port;
    control1._read = pic_elcr_read;
    control1._write = pic_elcr_write;
    control1.opaque = s;
    cpu_register_io_device(&control1);
    // cpu_register_device(port_map, elcr_port, 1, s,
    //                     pic_elcr_read, pic_elcr_write, DEVIO_SIZE8);

    pic_reset(s);
    return s;
}



void pic2_set_elcr(PIC2State *s, const uint8_t *elcr)
{
    int i;
    for(i = 0; i < 2; i++) {
        s->pics[i]->elcr = elcr[i] & s->pics[i]->elcr_mask;
    }
}



static void pic2_set_irq(void *opaque, int irq, int level)
{
    PIC2State *s = opaque;
#if defined(DEBUG_PIC)
    if (irq != 0 && level != s->irq_level[irq]) {
        console.log("pic_set_irq: irq=" + irq + " level=" + level);
        s->irq_level[irq] = level;
    }
#endif
    pic_set_irq1(s->pics[irq >> 3], irq & 7, level);
    pic2_update_irq(s);
}

/* called from the CPU to get the hardware interrupt number */
int pic2_get_hard_intno(PIC2State *s)
{
    int irq, irq2, intno;

    irq = pic_get_irq(s->pics[0]);
    if (irq >= 0) {
        pic_intack(s->pics[0], irq);
        if (irq == 2) {
            irq2 = pic_get_irq(s->pics[1]);
            if (irq2 >= 0) {
                pic_intack(s->pics[1], irq2);
            } else {
                /* spurious IRQ on slave controller */
                irq2 = 7;
            }
            intno = s->pics[1]->irq_base + irq2;
            irq = irq2 + 8;
        } else {
            intno = s->pics[0]->irq_base + irq;
        }
    } else {
        /* spurious IRQ on host controller */
        irq = 7;
        intno = s->pics[0]->irq_base + irq;
    }
    pic2_update_irq(s);


    // if (irq != 0 && irq != 14)
    //     printf("pic_interrupt: irq=%d\n", irq);

    return intno;
}

/* raise irq to CPU if necessary. must be called every time the active
   irq may change */
static void pic2_update_irq(void *opaque)
{
    PIC2State *s = opaque;
    int irq2, irq;

    /* first look at slave pic */
    irq2 = pic_get_irq(s->pics[1]);
    if (irq2 >= 0) {
        /* if irq request by slave pic, signal master PIC */
        pic_set_irq1(s->pics[0], 2, 1);
        pic_set_irq1(s->pics[0], 2, 0);
    }
    /* look at requested irq */
    irq = pic_get_irq(s->pics[0]);
#if 0
    console.log("irr=" + toHex2(s->pics[0].irr) + " imr=" + toHex2(s->pics[0].imr) + " isr=" + toHex2(s->pics[0].isr) + " irq="+ irq);
#endif
    if (irq >= 0) {
        /* raise IRQ request on the CPU */
        // s->cpu_set_irq(s->opaque, 1);
        // int t_irq = pic2_get_hard_intno(s);
        s->cpu_set_irq(1);
    } else {
        /* lower irq */
        s->cpu_set_irq(0);
    }
}

PIC2State *pic2_init(IRQSignal *irqs,
                     void (*cpu_set_irq)(uint8_t level))
{
    const uint32_t addr0 = 0x20;
    const uint32_t addr1 = 0xa0;
    const uint32_t elcr_addr0 = 0x4d0;
    const uint32_t elcr_addr1 = 0x4d1;

    PIC2State *s;
    int i;
    
    s = malloc(sizeof(*s));

    if(!s) {
        abort();
    }

    memset(s, 0, sizeof(*s));

    for(i = 0; i < 16; i++) {
        irq_init(&irqs[i], pic2_set_irq, s, i);
    }
    s->cpu_set_irq = cpu_set_irq;
    s->pics[0] = pic_init(addr0, elcr_addr0, 0xf8, pic2_update_irq, s);
    s->pics[1] = pic_init(addr1, elcr_addr1, 0xde, pic2_update_irq, s);
    s->irq_requested = 0;
    return s;
}

/* Pit */
static int64_t pit_get_time(PITChannel *pc) {
  PITState *s = pc->pit_state;
  return s->get_ticks();
}

static void pit_load_count(PITChannel *s, int val) {
  if (val == 0)
    val = 0x10000;
  s->count_load_time = pit_get_time(s);
  s->last_irq_time = 0;
  s->count = val;
}


static int64_t pit_get_ticks_cb() {
  struct timespec ts;

  clock_gettime(CLOCK_MONOTONIC, &ts);
  return (uint64_t)ts.tv_sec * PIT_FREQ +
         ((uint64_t)ts.tv_nsec * PIT_FREQ / 1000000000);
}

static uint32_t pit_get_count(PITChannel *pc) {
  uint32_t counter;
  uint64_t d;

  d = pit_get_time(pc) - pc->count_load_time;
  switch (pc->mode) {
  case 0:
  case 1:
  case 4:
  case 5:
    counter = (pc->count - d) & 0xffff;
    break;
  default:
    counter = pc->count - (d % pc->count);
    break;
  }
  return counter;
}

/* get pit output bit */
static int pit_get_out(PITChannel *pc) {
  int out;
  int64_t d;

  d = pit_get_time(pc) - pc->count_load_time;
  switch (pc->mode) {
  default:
  case 0:
    out = (d >= pc->count) >> 0;
    break;
  case 1:
    out = (d < pc->count) >> 0;
    break;
  case 2:
    /* mode used by Linux */
    if ((d % pc->count) == 0 && d != 0)
      out = 1;
    else
      out = 0;
    break;
  case 3:
    out = ((d % pc->count) < (pc->count >> 1)) >> 0;
    break;
  case 4:
  case 5:
    out = (d == pc->count) >> 0;
    break;
  }
  return out;
}


void pit_write(void *opaque, uint32_t offset, uint64_t val,
                      unsigned size) {
  PITState *pit = opaque;
  int channel, access, addr;
  PITChannel *s;

  addr = offset & 3;

  // printf("pit_write: off=%d val=0x%02lx\n", addr, val);

  if (addr == 3) {
    channel = val >> 6;
    if (channel == 3)
      return;
    s = &pit->pit_channels[channel];
    access = (val >> 4) & 3;
    switch (access) {
    case 0:
      s->latched_count = pit_get_count(s);
      s->rw_state = RW_STATE_LATCHED_WORD0;
      break;
    default:
      s->mode = (val >> 1) & 7;
      s->bcd = val & 1;
      s->rw_state = access - 1 + RW_STATE_LSB;
      break;
    }
  } else {
    s = &pit->pit_channels[addr];
    switch (s->rw_state) {
    case RW_STATE_LSB:
      pit_load_count(s, val);
      break;
    case RW_STATE_MSB:
      pit_load_count(s, val << 8);
      break;
    case RW_STATE_WORD0:
    case RW_STATE_WORD1:
      if (s->rw_state & 1) {
        pit_load_count(s, (s->latched_count & 0xff) | (val << 8));
      } else {
        s->latched_count = val;
      }
      s->rw_state ^= 1;
      break;
    }
  }
}

uint64_t pit_read(void *opaque, uint32_t offset, unsigned size) {
  PITState *pit = opaque;
  PITChannel *s;
  int ret, count, addr;

  // printf("pit_read: off=%ld val=0x%02x\n", offset, 0);
  addr = offset & 3;
  if (addr == 3)
    return 0xff;

  s = &pit->pit_channels[addr];
  switch (s->rw_state) {
  case RW_STATE_LSB:
  case RW_STATE_MSB:
  case RW_STATE_WORD0:
  case RW_STATE_WORD1:
    count = pit_get_count(s);
    if (s->rw_state & 1)
      ret = (count >> 8) & 0xff;
    else
      ret = count & 0xff;
    if (s->rw_state & 2)
      s->rw_state ^= 1;
    break;
  default:
  case RW_STATE_LATCHED_WORD0:
  case RW_STATE_LATCHED_WORD1:
    if (s->rw_state & 1)
      ret = s->latched_count >> 8;
    else
      ret = s->latched_count & 0xff;
    s->rw_state ^= 1;
    break;
  }

  return ret;
}

/* set the IRQ if necessary and return the delay in ms until the next
   IRQ. Note: The code does not handle all the PIT configurations. */
int pit_update_irq(PITState *pit) {
  PITChannel *s;
  int64_t d, delay;

  s = &pit->pit_channels[0];

  delay = PIT_FREQ; /* could be infinity delay */

  d = pit_get_time(s) - s->count_load_time;
  switch (s->mode) {
  default:
  case 0:
  case 1:
  case 4:
  case 5:
    if (s->last_irq_time == 0) {
      delay = s->count - d;
      if (delay <= 0) {
        set_irq(pit->irq, 1);
        set_irq(pit->irq, 0);
        s->last_irq_time = d;
      }
    }
    break;
  case 2: /* mode used by Linux */
  case 3:
    delay = s->last_irq_time + s->count - d;
    if (delay <= 0) {
      set_irq(pit->irq, 1);
      set_irq(pit->irq, 0);
      s->last_irq_time += s->count;
    }
    break;
  }

  if (delay <= 0)
    return 0;
  else
    return delay / (PIT_FREQ / 1000);
}

void speaker_write(void *opaque, uint32_t offset, uint64_t val,
                          unsigned size) {
  PITState *pit = opaque;
  pit->speaker_data_on = (val >> 1) & 1;
  pit->pit_channels[2].gate = val & 1;
  // printf("Speaking writing %lld\n", val);
}

uint64_t speaker_read(void *opaque, uint32_t offset, unsigned size) {
  PITState *pit = opaque;
  PITChannel *s;
  int out, val;

  s = &pit->pit_channels[2];
  out = pit_get_out(s);
  val = (pit->speaker_data_on << 1) | s->gate | (out << 5);
  // printf("Speaking reading %lld\n", val);
  return val;
}

PITState *pit_init(IRQSignal* irq) {
  PITState *s;
  PITChannel *pc;
  int i;

  s = malloc(sizeof(*s));
  if (!s) {
    abort();
  }

  memset(s, 0, sizeof(*s));

  s->irq = irq;
  s->get_ticks = pit_get_ticks_cb;

  for (i = 0; i < 3; i++) {
    pc = &s->pit_channels[i];
    pc->pit_state = s;
    pc->mode = 3;
    pc->gate = (i != 2) >> 0;
    pit_load_count(pc, 0);
  }
  s->speaker_data_on = 0;

  IODevice control0;
  control0.startPort = 0x40;
  control0.endPort = 0x43;
  control0._read = pit_read;
  control0._write = pit_write;
  control0.opaque = s;
  cpu_register_io_device(&control0);
  // MemoryRegion *pit_io = g_new(MemoryRegion, 1);
  // memory_region_init_io(pit_io, NULL, &pit_io_ops, s, "pitio", 4);
  // memory_region_add_subregion(system_io, 0x40, pit_io);

  IODevice control1;
  control1.startPort = 0x61;
  control1.endPort = 0x64;
  control1._read = speaker_read;
  control1._write = speaker_write;
  control1.opaque = s;
  cpu_register_io_device(&control1);
  // MemoryRegion *speaker_io = g_new(MemoryRegion, 1);
  // memory_region_init_io(speaker_io, NULL, &speaker_io_ops, s, "speakerio", 4);
  // memory_region_add_subregion(system_io, 0x61, speaker_io);

  return s;
}

/* Cmos */

static inline void put_le16(uint8_t *ptr, uint16_t v) {
  ptr[0] = v;
  ptr[1] = v >> 8;
}


static int to_bcd(CMOSState *s, unsigned int a)
{
    if (s->cmos_data[RTC_REG_B] & 0x04) {
        return a;
    } else {
        return ((a / 10) << 4) | (a % 10);
    }
}

static void cmos_update_time(CMOSState *s, char set_century)
{
    struct timeval tv;
    struct tm tm;
    time_t ti;
    int val;
    
    gettimeofday(&tv, NULL);
    ti = tv.tv_sec;
    
    gmtime_r(&ti, &tm);
    
    
    s->cmos_data[RTC_SECONDS] = to_bcd(s, tm.tm_sec);
    s->cmos_data[RTC_MINUTES] = to_bcd(s, tm.tm_min);
    if (s->cmos_data[RTC_REG_B] & 0x02) {
        s->cmos_data[RTC_HOURS] = to_bcd(s, tm.tm_hour);
    } else {
        s->cmos_data[RTC_HOURS] = to_bcd(s, tm.tm_hour % 12);
        if (tm.tm_hour >= 12)
            s->cmos_data[RTC_HOURS] |= 0x80;
    }
    s->cmos_data[RTC_DAY_OF_WEEK] = to_bcd(s, tm.tm_wday);
    s->cmos_data[RTC_DAY_OF_MONTH] = to_bcd(s, tm.tm_mday);
    s->cmos_data[RTC_MONTH] = to_bcd(s, tm.tm_mon + 1);
    s->cmos_data[RTC_YEAR] = to_bcd(s, tm.tm_year % 100);

    if (set_century) {
        /* not set by the hardware, but easier to do it here */
        val = to_bcd(s, (tm.tm_year / 100) + 19);
        s->cmos_data[0x32] = val;
        s->cmos_data[0x37] = val;
    }
    
    /* update in progress flag: 8/32768 seconds after change */
    if (tv.tv_usec < 244) {
        s->cmos_data[RTC_REG_A] |= REG_A_UIP;
    } else {
        s->cmos_data[RTC_REG_A] &= ~REG_A_UIP;
    }
}




void cmos_update_mem(CMOSState *cmos_state, uint64_t main_mem_size) {
    int cmos_mem_size;
    /* memory size */
    cmos_mem_size = MIN((main_mem_size - (1 << 20)) >> 10, 65535);
    put_le16(cmos_state->cmos_data + 0x30, cmos_mem_size);
    if (main_mem_size >= (16 << 20)) {
      cmos_mem_size = MIN((main_mem_size - (16 << 20)) >> 16, 65535);
      put_le16(cmos_state->cmos_data + 0x34, cmos_mem_size);
    }
    cmos_state->cmos_data[0x14] = 0x6; /* mouse + FPU present */
}

#define CMOS_FREQ 32768

static uint32_t cmos_get_timer(CMOSState *s)
{
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint32_t)ts.tv_sec * CMOS_FREQ +
        ((uint64_t)ts.tv_nsec * CMOS_FREQ / 1000000000);
}

static void cmos_update_timer(CMOSState *s)
{
    int period_code;

    period_code = s->cmos_data[RTC_REG_A] & 0x0f;
    if ((s->cmos_data[RTC_REG_B] & REG_B_PIE) &&
        period_code != 0) {
        if (period_code <= 2)
            period_code += 7;
        s->irq_period = 1 << (period_code - 1);
        s->irq_timeout = (cmos_get_timer(s) + s->irq_period) &
            ~(s->irq_period - 1);
    }
}

/* XXX: could return a delay, but we don't need high precision
   (Windows 2000 uses it for delay calibration) */
void cmos_update_irq(CMOSState *s)
{
    uint32_t d;
    if (s->cmos_data[RTC_REG_B] & REG_B_PIE) {
        d = cmos_get_timer(s) - s->irq_timeout;
        if ((int32_t)d >= 0) {
            /* this is not what the real RTC does. Here we sent the IRQ
               immediately */
            s->cmos_data[RTC_REG_C] |= 0xc0;
            set_irq(s->irq, 1);
            /* update for the next irq */
            s->irq_timeout += s->irq_period;
        }
    }
}


static void cmos_write(void *opaque, uint32_t offset, uint64_t data,
                           unsigned size)
{
    CMOSState *s = opaque;

    // printf("cmos_write: offset=0x%02lx reg=0x%02x val=0x%02lx\n", offset, s->cmos_index, data);

    if (offset == 0) {
        s->cmos_index = data & 0x7f;
    } else {

        switch(s->cmos_index) {
        case RTC_REG_A:
            s->cmos_data[RTC_REG_A] = (data & ~REG_A_UIP) |
                (s->cmos_data[RTC_REG_A] & REG_A_UIP);
            cmos_update_timer(s);
            break;
        case RTC_REG_B:
            s->cmos_data[s->cmos_index] = data;
            cmos_update_timer(s);
            break;
        default:
            s->cmos_data[s->cmos_index] = data;
            break;
        }
    }
}

static uint64_t cmos_read(void *opaque, uint32_t offset, unsigned size)
{
    CMOSState *s = opaque;
    // printf("cmos_read: offset=0x%02lx reg=0x%02x val=0x%02x\n", offset, s->cmos_index);
    int ret;

    if (offset == 0) {
        return 0xff;
    } else {
        switch(s->cmos_index) {
        case RTC_SECONDS:
        case RTC_MINUTES:
        case RTC_HOURS:
        case RTC_DAY_OF_WEEK:
        case RTC_DAY_OF_MONTH:
        case RTC_MONTH:
        case RTC_YEAR:
        case RTC_REG_A:
            cmos_update_time(s, 0);
            ret = s->cmos_data[s->cmos_index];
            break;
        case RTC_REG_C:
            ret = s->cmos_data[s->cmos_index];
            s->cmos_data[RTC_REG_C] = 0x00;
            set_irq(s->irq, 0);
            break;
        default:
            ret = s->cmos_data[s->cmos_index];
        }
#ifdef DEBUG_CMOS
        printf("cmos_read: reg=0x%02x val=0x%02x\n", s->cmos_index, ret);
#endif
        return ret;
    }
}

static void cmos_status_write(void *opaque, uint32_t offset, uint64_t data, unsigned size) {
    
}

static uint64_t cmos_status_read(void *opaque, uint32_t offset, unsigned size) {
    return 0xff;
}

CMOSState *cmos_init(IRQSignal* irq)
{
    CMOSState *s;
    
    s = malloc(sizeof(*s));

    if(!s) {
        abort();
    }

    memset(s, 0, sizeof(*s));
    
    s->cmos_index = 0;

    s->cmos_data[RTC_REG_A] = 0x26;
    s->cmos_data[RTC_REG_B] = 0x02;
    s->cmos_data[RTC_REG_C] = 0x00;
    s->cmos_data[RTC_REG_D] = 0x80;

    cmos_update_time(s, 1);
    
    s->irq = irq;

    IODevice control0;
    control0.startPort = 0x70;
    control0.endPort = 0x70 + 1;
    control0._read = cmos_read;
    control0._write = cmos_write;
    control0.opaque = s;
    cpu_register_io_device(&control0);


    IODevice control1;
    control1.startPort = 0x80;
    control1.endPort = 0x80;
    control1._read = cmos_status_read;
    control1._write = cmos_status_write;
    control1.opaque = NULL;
    cpu_register_io_device(&control1);
    
    return s;
}

/* Serial */
static void serial_update_irq(SerialState *s) {
  if ((s->lsr & TUART_LSR_DR) && (s->ier & TUART_IER_RDI)) {
    s->iir = TUART_IIR_RDI;
  } else if ((s->lsr & TUART_LSR_THRE) && (s->ier & TUART_IER_THRI)) {
    s->iir = TUART_IIR_THRI;
  } else {
    s->iir = TUART_IIR_NO_INT;
  }
  if (s->iir != TUART_IIR_NO_INT) {
    set_irq(s->irq, 1);
  } else {
    set_irq(s->irq, 0);
  }
}

#if 0
/* send remainining chars in fifo */
Serial.prototype.write_tx_fifo = function()
{
    if (s->tx_fifo != "") {
        s->write_func(s->tx_fifo);
        s->tx_fifo = "";
        
        s->lsr |= TUART_LSR_THRE;
        s->lsr |= TUART_LSR_TEMT;
        s->update_irq();
    }
}
#endif

static void serial_write(void *opaque, uint32_t offset, uint64_t val,
                         unsigned size) {
  // printf("Serial write %ld %ld\n", offset, val);
  SerialState *s = opaque;
  int addr;

  addr = offset & 7;
  switch (addr) {
  default:
  case 0:
    if (s->lcr & TUART_LCR_DLAB) {
      s->divider = (s->divider & 0xff00) | val;
    } else {
#if 0
            if (s->fcr & TUART_FCR_FE) {
                s->tx_fifo += String.fromCharCode(val);
                s->lsr &= ~TUART_LSR_THRE;
                serial_update_irq(s);
                if (s->tx_fifo.length >= TUART_FIFO_LENGTH) {
                    /* write to the terminal */
                    s->write_tx_fifo();
                }
            } else
#endif
      {
        uint8_t ch;
        s->lsr &= ~TUART_LSR_THRE;
        serial_update_irq(s);

        /* write to the terminal */
        ch = val;
        printf("%c", ch);
        
        s->lsr |= TUART_LSR_THRE;
        s->lsr |= TUART_LSR_TEMT;
        serial_update_irq(s);
      }
    }
    break;
  case 1:
    if (s->lcr & TUART_LCR_DLAB) {
      s->divider = (s->divider & 0x00ff) | (val << 8);
    } else {
      s->ier = val;
      serial_update_irq(s);
    }
    break;
  case 2:
#if 0
        if ((s->fcr ^ val) & TUART_FCR_FE) {
            /* clear fifos */
            val |= TUART_FCR_XFR | TUART_FCR_RFR;
        }
        if (val & TUART_FCR_XFR)
            s->tx_fifo = "";
        if (val & TUART_FCR_RFR)
            s->rx_fifo = "";
        s->fcr = val & TUART_FCR_FE;
#endif
    break;
  case 3:
    s->lcr = val;
    break;
  case 4:
    s->mcr = val;
    break;
  case 5:
    break;
  case 6:
    s->msr = val;
    break;
  case 7:
    s->scr = val;
    break;
  }
}

static uint64_t serial_read(void *opaque, uint32_t offset, unsigned size) {
  SerialState *s = opaque;
  int ret, addr;
  // printf("Serial read %ld %d\n", offset, size);
  addr = offset & 7;
  switch (addr) {
  default:
  case 0:
    if (s->lcr & TUART_LCR_DLAB) {
      ret = s->divider & 0xff;
    } else {
      ret = s->rbr;
      s->lsr &= ~(TUART_LSR_DR | TUART_LSR_BI);
      serial_update_irq(s);
#if 0
            /* try to receive next chars */
            s->send_char_from_fifo();
#endif
    }
    break;
  case 1:
    if (s->lcr & TUART_LCR_DLAB) {
      ret = (s->divider >> 8) & 0xff;
    } else {
      ret = s->ier;
    }
    break;
  case 2:
    ret = s->iir;
    if (s->fcr & TUART_FCR_FE)
      ret |= TUART_IIR_FE;
    break;
  case 3:
    ret = s->lcr;
    break;
  case 4:
    ret = s->mcr;
    break;
  case 5:
    ret = s->lsr;
    break;
  case 6:
    ret = s->msr;
    break;
  case 7:
    ret = s->scr;
    break;
  }
  return ret;
}

SerialState *serial_init(IRQSignal *irq) {
  SerialState *s;
  s = malloc(sizeof(*s));

  if(!s) {
    abort();
  }

  memset(s, 0, sizeof(*s));

  /* all 8 bit registers */
  s->divider = 0;
  s->rbr = 0; /* receive register */
  s->ier = 0;
  s->iir = TUART_IIR_NO_INT; /* read only */
  s->lcr = 0;
  s->mcr = 0;
  s->lsr = TUART_LSR_TEMT | TUART_LSR_THRE; /* read only */
  s->msr = 0;
  s->scr = 0;
  s->fcr = 0;

  s->irq = irq;

  IODevice control0;
  control0.startPort = 0x3f8;
  control0.endPort = 0x3ff;
  control0._read = serial_read;
  control0._write = serial_write;
  control0.opaque = s;
  cpu_register_io_device(&control0);

  return s;
}