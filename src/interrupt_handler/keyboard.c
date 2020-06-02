//
// Created by tia on 2020/05/12.
//

#include <stdint.h>
#include <std.h>
#include <graphics/print.h>
#include <interrupt_handler.h>
#include <pic.h>

__attribute__((interrupt))
void int_33_handler(struct InterruptFrame *frame) {
    uint8_t key_code;
    __asm__ volatile ("in al, 0x60" : "=a"(key_code));
    char buf[3];
    itoa(key_code, buf, 3, 16, SET_NULL_TERMINATE|FILL_SPACE);

    print("key input: 0x%", buf);

    PIC_MASTER_EOI();
}
