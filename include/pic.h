//
// Created by tia on 2020/05/11.
//

#ifndef CIEOS_INCLUDE_PIC_H
#define CIEOS_INCLUDE_PIC_H

#include <stdint.h>

#define outp(port, value) __asm__ volatile ( \
    "mov al, " #value "\n"\
    "out " #port ", al" \
)

#define outp_v(port, value) __asm__ volatile ( \
    "mov al, %0 \n"\
    "out "#port", al" \
    : : "r"(value) \
)

#define PIC_MASTER_EOI() __asm__ volatile (\
    "mov al, 0x20 \n"\
    "out 0x20, al"\
    : : : "al"\
)

void pic_init();
void pic_set(uint8_t master, uint8_t slave);
void pic_timer_init();

#endif //CIEOS_INCLUDE_PIC_H
