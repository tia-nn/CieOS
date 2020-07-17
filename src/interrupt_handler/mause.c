//
// Created by tia on 2020/07/13.
//

#include <std.h>
#include <interrupt_handler.h>
#include <pic.h>

struct RingBuffer MOUSE_BUFFER;

__attribute__((interrupt))
void int_44_handler(union InterruptFrame *frame) {
    uint8_t key_code;
    __asm__ volatile ("in al, 0x60" : "=a"(key_code));
    ringbuf_write(&MOUSE_BUFFER, key_code);
    PIC_SLAVE_EOI();
    PIC_MASTER_EOI();
}
