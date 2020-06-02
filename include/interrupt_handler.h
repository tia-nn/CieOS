//
// Created by tia on 2020/05/11.
//

#ifndef CIEOS_INTERRUPT_HANDLER_H
#define CIEOS_INTERRUPT_HANDLER_H

struct InterruptFrame {
    uint64_t error_code;
    uint64_t rip;
    uint64_t cs;
    uint64_t rflags;
    uint64_t rsp;
    uint64_t ss;
};

void int_32_handler(struct InterruptFrame *frame);  // timer.s
void int_13_handler(struct InterruptFrame *frame);
void int_33_handler(struct InterruptFrame *frame);

void schedule_init();

#endif //CIEOS_INTERRUPT_HANDLER_H
