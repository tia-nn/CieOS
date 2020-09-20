//
// Created by tia on 2020/09/19.
//

#ifndef CIEOS_SRC_PERIPHERAL_CONTROL_H
#define CIEOS_SRC_PERIPHERAL_CONTROL_H

#include <stdint.h>

#define _OUT_BYTE(port, value) __asm__ volatile ("out " #port ", al" :: "a"(value))
#define OUT_BYTE(port, value) _OUT_BYTE(port, value)
#define _OUT_WORD(port, value) __asm__ volatile ("out " #port ", ax" :: "a"(value))
#define OUT_WORD(port, value) _OUT_WORD(port, value)
#define _OUT_DWORD(port, value) __asm__ volatile ("out " #port ", eax" :: "a"(value))
#define OUT_DWORD(port, value) _OUT_DWORD(port, value)

#define PIC_MASTER_EOI() __asm__ volatile ("mov al, 0x20 \n" "out 0x20, al")
#define PIC_SLAVE_EOI() __asm__ volatile ("mov al, 0x20 \n" "out 0xa0, al")

#define PIC1_ENABLE_TIMER (~(uint8_t)0x01u)
#define PIC1_ENABLE_KBC (~(uint8_t)02u)
#define PIC1_ENABLE_SLAVE (~(uint8_t)04u)
#define PIC1_ENABLE_SERIAL2 (~(uint8_t)08u)
#define PIC1_ENABLE_SERIAL1 (~(uint8_t)10u)
#define PCI1_ENABLE_PARALLEL2 (~(uint8_t)20u)
#define PIC1_ENABLE_FDD (~(uint8_t)40u)
#define PIC1_ENABLE_PARALLEL1 (~(uint8_t)80u)

#define PIC2_ENABLE_RTC (~(uint8_t)01u)
#define PIC2_ENABLE_IRQ2 (~(uint8_t)02u)
#define PIC2_ENABLE_MOUSE (~(uint8_t)10u)
#define PIC2_ENABLE_CO_PROCESSOR (~(uint8_t)20u)
#define PIC2_ENABLE_HDD (~(uint8_t)40u)

void initial_pic(uint8_t pic1_mask, uint8_t pic2_mask);
void initial_timer(uint16_t count_per_sec);

#endif //CIEOS_SRC_PERIPHERAL_CONTROL_H
