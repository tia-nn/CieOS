//
// Created by tia on 2020/05/11.
//

#ifndef CIEOS_INTERRUPT_HANDLER_H
#define CIEOS_INTERRUPT_HANDLER_H

struct InterruptFrameWithErrorCode {
    uint64_t error_code;
    uint64_t rip;
    uint64_t cs;
    uint64_t rflags;
    uint64_t rsp;
    uint64_t ss;
};

struct InterruptFrameNoErrorCode {
        uint64_t rip;
        uint64_t cs;
        uint64_t rflags;
        uint64_t rsp;
        uint64_t ss;
};

union InterruptFrame {
    struct InterruptFrameWithErrorCode withErrorCode;
    struct InterruptFrameNoErrorCode noErrorCode;
};

void int_32_handler(union InterruptFrame *frame);  // timer.s
void int_13_handler(union InterruptFrame *frame);
void int_33_handler(union InterruptFrame *frame);
//__attribute__((no_caller_saved_registers)) uint64_t int_128_handler();
void int_128_handler();

void schedule_init();

void int_0x80(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);  // must set rax before call
void int_0x80_1(char *arg1);
#endif //CIEOS_INTERRUPT_HANDLER_H
