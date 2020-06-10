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
//__attribute__((no_caller_saved_registers)) uint64_t int_128_handler();
void int_128_handler();

void schedule_init();

void int_0x80(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);
void int_0x80_1(char *arg1);
#endif //CIEOS_INTERRUPT_HANDLER_H
