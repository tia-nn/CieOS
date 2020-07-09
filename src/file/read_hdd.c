//
// Created by tia on 2020/07/04.
//

#include "file/read_hdd.h"
#include <std.h>
#include <pic.h>
#include <graphics/print.h>

#define outw(port, value) __asm__ volatile ( \
    "out dx, ax" \
    : : "a"(value), "d"(port) \
)

#define err(message) do {\
uint8_t error;\
__asm__ volatile ("in al, dx" : "=a"(error) : "d"(0x01f1));\
if (error & 0b00000100u) {\
print_right("error: " message );\
return;\
}} while(0)

void read_hdd(void *buf, uint32_t lba, uint8_t sector_count) {
    const uint32_t bit_24_27 = 0xf000000;
    const uint32_t bit_16_23 = 0x0ff0000;
    const uint32_t bit_8_15  = 0x000ff00;
    const uint32_t bit_0_7   = 0x00000ff;
    uint8_t device = (1 << 6) | (0 << 4) | ((lba & bit_24_27) >> 24u);
    uint8_t lba_low = lba & bit_0_7;
    uint8_t lba_mid = (lba & bit_8_15) >> 8u;
    uint8_t lba_high = (lba & bit_16_23) >> 16u;
    uint8_t command = 0x20;
    uint8_t status;

    do
            __asm__ volatile ("in al, dx" : "=a"(status) : "d"(0x01f7));
    while (status & 0b10000000u || status & 0b00001000u);

    __asm__ volatile ("out dx, al" : : "a"(device), "d"(0x01f6));
    sleepms(1);

    err("device write");

    do
            __asm__ volatile ("in al, dx" : "=a"(status) : "d"(0x01f7));
    while (status & 0b10000000u || status & 0b00001000u);

    __asm__ volatile ("out dx, al" : : "a"(sector_count), "d"(0x01f2));
    __asm__ volatile ("out dx, al" : : "a"(lba_low), "d"(0x01f3));
    __asm__ volatile ("out dx, al" : : "a"(lba_mid), "d"(0x01f4));
    __asm__ volatile ("out dx, al" : : "a"(lba_high), "d"(0x01f5));

    err("param write");

    __asm__ volatile ("out dx, al" : : "a"(command), "d"(0x01f7));
    sleepms(1);

    err("command write");

    do
            __asm__ volatile ("in al, dx" : "=a"(status) : "d"(0x01f7));
    while (status & 0b10000000u);

    do
            __asm__ volatile ("in al, dx" : "=a"(status) : "d"(0x01f7));
    while (!(status & 0b00001000u));

    uint16_t data;
    for (uint64_t i = 0; i < sector_count; i ++) {
        for (uint64_t j = 0; j < 256; j ++) {
            __asm__ volatile ("in ax, dx" : "=a"(data) : "d"(0x01f0));
            ((uint16_t*)buf)[i * 256 + j] = data;
            if (i == 0 && j == 0) err("first read");
        }
    }
}
