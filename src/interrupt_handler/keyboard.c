//
// Created by tia on 2020/05/12.
//

#include <stdint.h>
#include <std.h>
#include <graphics/print.h>
#include <interrupt_handler.h>
#include <pic.h>

struct RingBuffer KEYBOARD_BUFFER;

__attribute__((interrupt))
void int_33_handler(union InterruptFrame *frame) {
    uint8_t key_code;
    __asm__ volatile ("in al, 0x60" : "=a"(key_code));
    ringbuf_write(&KEYBOARD_BUFFER, key_code);
    PIC_MASTER_EOI();
}
