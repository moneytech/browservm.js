#ifndef PERI_H
#define PERI_H

/* Pic */
typedef void SetIRQFunc(void *opaque, int irq_num, int level);

typedef struct {
    SetIRQFunc *set_irq;
    void *opaque;
    int irq_num;
} IRQSignal;

void irq_init(IRQSignal *irq, SetIRQFunc *set_irq, void *opaque, int irq_num);

void set_irq(IRQSignal *irq, int level);



typedef void PICUpdateIRQFunc(void *opaque);

typedef struct {
    uint8_t last_irr; /* edge detection */
    uint8_t irr; /* interrupt request register */
    uint8_t imr; /* interrupt mask register */
    uint8_t isr; /* interrupt service register */
    uint8_t priority_add; /* used to compute irq priority */
    uint8_t irq_base;
    uint8_t read_reg_select;
    uint8_t special_mask;
    uint8_t init_state;
    uint8_t auto_eoi;
    uint8_t rotate_on_autoeoi;
    uint8_t init4; /* true if 4 byte init */
    uint8_t elcr; /* PIIX edge/trigger selection*/
    uint8_t elcr_mask;
    PICUpdateIRQFunc *update_irq;
    void *opaque;
} PICState;

typedef struct {
    PICState *pics[2];
    int irq_requested;
    void (*cpu_set_irq)(uint8_t level);
#if defined(DEBUG_PIC)
    uint8_t irq_level[16];
#endif
    IRQSignal *irqs;
} PIC2State;

PIC2State *pic2_init(IRQSignal *irqs,
                     void (*cpu_set_irq)(uint8_t level)
                    );

int pic2_get_hard_intno(PIC2State *s);

/* Pic */


/* Pit */
#define PIT_FREQ 1193182

#define RW_STATE_LSB 0
#define RW_STATE_MSB 1
#define RW_STATE_WORD0 2
#define RW_STATE_WORD1 3
#define RW_STATE_LATCHED_WORD0 4
#define RW_STATE_LATCHED_WORD1 5

//#define DEBUG_PIT

typedef int64_t PITGetTicksFunc();

typedef struct PITState PITState;

typedef struct {
  PITState *pit_state;
  uint32_t count;
  uint32_t latched_count;
  uint8_t rw_state;
  uint8_t mode;
  uint8_t bcd;
  uint8_t gate;
  int64_t count_load_time;
  int64_t last_irq_time;
} PITChannel;

struct PITState {
  PITChannel pit_channels[3];
  uint8_t speaker_data_on;
  PITGetTicksFunc *get_ticks;
  IRQSignal* irq;
};

PITState *pit_init(IRQSignal* irq);
/* Pit */

/* Cmos */
#define RTC_SECONDS             0
#define RTC_SECONDS_ALARM       1
#define RTC_MINUTES             2
#define RTC_MINUTES_ALARM       3
#define RTC_HOURS               4
#define RTC_HOURS_ALARM         5
#define RTC_ALARM_DONT_CARE    0xC0

#define RTC_DAY_OF_WEEK         6
#define RTC_DAY_OF_MONTH        7
#define RTC_MONTH               8
#define RTC_YEAR                9

#define RTC_REG_A               10
#define RTC_REG_B               11
#define RTC_REG_C               12
#define RTC_REG_D               13

#define REG_A_UIP 0x80

#define REG_B_SET 0x80
#define REG_B_PIE 0x40
#define REG_B_AIE 0x20
#define REG_B_UIE 0x10

typedef struct {
    uint8_t cmos_index;
    uint8_t cmos_data[128];
    IRQSignal* irq;
    /* used for the periodic irq */
    uint32_t irq_timeout;
    uint32_t irq_period;
} CMOSState;

CMOSState *cmos_init(IRQSignal* irq);
void cmos_update_mem(CMOSState*s, uint64_t mem);

/* Cmos */

/* Serial */
#define TUART_LCR_DLAB 0x80 /* Divisor latch access bit */

#define TUART_IER_MSI 0x08  /* Enable Modem status interrupt */
#define TUART_IER_RLSI 0x04 /* Enable receiver line status interrupt */
#define TUART_IER_THRI 0x02 /* Enable Transmitter holding register int. */
#define TUART_IER_RDI 0x01  /* Enable receiver data interrupt */

#define TUART_IIR_NO_INT 0x01 /* No interrupts pending */
#define TUART_IIR_ID 0x06     /* Mask for the interrupt ID */

#define TUART_IIR_MSI 0x00  /* Modem status interrupt */
#define TUART_IIR_THRI 0x02 /* Transmitter holding register empty */
#define TUART_IIR_RDI 0x04  /* Receiver data interrupt */
#define TUART_IIR_RLSI 0x06 /* Receiver line status interrupt */
#define TUART_IIR_FE 0xC0   /* Fifo enabled */

#define TUART_LSR_TEMT 0x40 /* Transmitter empty */
#define TUART_LSR_THRE 0x20 /* Transmit-hold-register empty */
#define TUART_LSR_BI 0x10   /* Break interrupt indicator */
#define TUART_LSR_FE 0x08   /* Frame error indicator */
#define TUART_LSR_PE 0x04   /* Parity error indicator */
#define TUART_LSR_OE 0x02   /* Overrun error indicator */
#define TUART_LSR_DR 0x01   /* Receiver data ready */

#define TUART_FCR_XFR 0x04 /* XMIT Fifo Reset */
#define TUART_FCR_RFR 0x02 /* RCVR Fifo Reset */
#define TUART_FCR_FE 0x01  /* FIFO Enable */

#define TUART_FIFO_LENGTH 16 /* 16550A Fifo Length */

typedef struct {
  uint8_t divider;
  uint8_t rbr; /* receive register */
  uint8_t ier;
  uint8_t iir; /* read only */
  uint8_t lcr;
  uint8_t mcr;
  uint8_t lsr; /* read only */
  uint8_t msr;
  uint8_t scr;
  uint8_t fcr;
  IRQSignal* irq;
} SerialState;

SerialState *serial_init(IRQSignal* irq);
/* Serial */

void cmos_update_irq(CMOSState *s);
int pit_update_irq(PITState *pit);

#endif