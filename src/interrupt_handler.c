//
// Created by tia on 2020/09/17.
//

#include "interrupt_handler.h"


#include <stdint.h>
#include <x64_IA32e64.h>
#include "tools.h"
#include "print.h"
#include "peripheral_control.h"

#define INTERRUPT_HANDLER(vec, name, var) __attribute__((interrupt)) \
void int_ ##vec## _ ##name## _handler(union InterruptFrame * var)


_Noreturn INTERRUPT_HANDLER(13, GP, frame) {
    uint64_t _ds;
    char errorcode[17], rip[17], cs[17], rflags[17], rsp[17], ss[17], ds[17];
    __asm__ volatile ("mov rax, ds": "=a"(_ds));

    char offset_buf[17];
    itoa((uint64_t) frame->withErrorCode.rip - (uint64_t)KERNEL_LOADED_POINT, offset_buf, 17, 16, SET_NULL_TERMINATE|FILL_ZERO);

    itoa(frame->withErrorCode.error_code, errorcode, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->withErrorCode.rip, rip, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->withErrorCode.cs, cs, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->withErrorCode.rflags, rflags, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->withErrorCode.rsp, rsp, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->withErrorCode.ss, ss, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(_ds, ds, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);

    print("interrupt --- %", "13 - #GP" "\n");
    print("error_code: %" "\n", errorcode);
    print("rip:        % ( offset: % )" "\n", rip, offset_buf);
    print("cs :        %" "\n", cs);
    print("rflags:     %" "\n", rflags);
    print("rsp:        %" "\n", rsp);
    print("ss:         %" "\n", ss);
    print("ds:         %" "\n", ds);

    while (true) __asm__ volatile ("hlt");
}

INTERRUPT_HANDLER(32, TIMER, frame) {
    TIMER_COUNT ++;
    PIC_MASTER_EOI();
}
