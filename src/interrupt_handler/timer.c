//
// Created by tia on 2020/05/11.
//

#include <pic.h>
#include <graphics/print.h>
#include <std.h>
#include <interrupt_handler.h>

uint64_t TIMER_COUNT;

__attribute__((interrupt))
void int_32_handler(struct InterruptFrame *frame) {
    __asm__ volatile ("": : : "rcx");
//    print("timer...");
    TIMER_COUNT ++;
    PIC_MASTER_EOI();
}
