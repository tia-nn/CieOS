//
// Created by tia on 2020/05/12.
//

#include <stdint.h>
#include <std.h>
#include <graphics/print.h>
#include <interrupt_handler.h>

__attribute__((interrupt))
void int_13_handler(union InterruptFrame *frame) {
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

    hstop();
}
