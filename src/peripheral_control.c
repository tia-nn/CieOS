//
// Created by tia on 2020/09/19.
//

#include "peripheral_control.h"
#include <stdint.h>

#pragma pack(1)

// ------ PIC ------

// r: IRR/ISR w: ICW1/OCW2,3
#define PIC_MASTER_PORT_1 0x20
#define PIC_SLAVE_PORT_1 0xa0
// r: IMR w: ICW2,3,4/OCW1
#define PIC_MASTER_PORT_2 0x21
#define PIC_SLAVE_PORT_2 0xa1

#define ICW1_ICW4 0x01u
#define ICW1_SINGLE 0x02u
#define ICW1_INTERVAL4 0x04u
#define ICW1_LEVEL 0x08u
#define ICW1_INIT 0x10u

#define ICW4_8086 0x01u
#define ICW4_AUTO 0x02u
#define ICW4_BUF_SLAVE 0x08u
#define ICW4_BUF_MASTER 0x0Cu
#define ICW4_SFNM 0x10u

// ------ timer ------

#define TIMER_CLOCK 1193182

typedef struct {
    unsigned BCD: 1;
    unsigned mode: 3;
    unsigned access: 2;
    unsigned target: 2;
} TimerIC;

#pragma pack()

void initial_pic(uint8_t pic1_mask, uint8_t pic2_mask) {
    OUT_BYTE(PIC_MASTER_PORT_1, ICW1_INIT | ICW1_ICW4);
    OUT_BYTE(PIC_MASTER_PORT_2, 0x20);  // vector
    OUT_BYTE(PIC_MASTER_PORT_2, 4);  // slave port;
    OUT_BYTE(PIC_MASTER_PORT_2, ICW4_8086);
    OUT_BYTE(PIC_MASTER_PORT_2, pic1_mask);  // mask

    OUT_BYTE(PIC_SLAVE_PORT_1, ICW1_INIT | ICW1_ICW4);
    OUT_BYTE(PIC_SLAVE_PORT_2, 0x28);
    OUT_BYTE(PIC_SLAVE_PORT_2, 2);  // slave id
    OUT_BYTE(PIC_SLAVE_PORT_2, ICW4_8086);
    OUT_BYTE(PIC_SLAVE_PORT_2, pic2_mask);  // mask
}

void initial_timer(uint16_t count_per_sec) {  // count_per_sec must be 19 or higher
    TimerIC config = {0, 2, 0b11, 0};
    uint16_t count = TIMER_CLOCK / count_per_sec;
    OUT_BYTE(0x43, config);
    OUT_BYTE(0x40, count);
    OUT_BYTE(0x40, count >> 8u);
}
