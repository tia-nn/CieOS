//
// Created by tia on 2020/07/18.
//

#include <stdint.h>
#include <std.h>
#include <graphics/print.h>
#include <interrupt_handler.h>

__attribute__((interrupt))
void int_0_handler(union InterruptFrame *frame) {
    uint64_t _ds;
    char rip[17], cs[17], rflags[17], rsp[17], ss[17], ds[17];
    __asm__ volatile ("mov rax, ds": "=a"(_ds));

    char offset_buf[17];
    itoa((uint64_t) frame->noErrorCode.rip - (uint64_t)KERNEL_LOADED_POINT, offset_buf, 17, 16, SET_NULL_TERMINATE|FILL_ZERO);

    itoa(frame->noErrorCode.rip, rip, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->noErrorCode.cs, cs, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->noErrorCode.rflags, rflags, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->noErrorCode.rsp, rsp, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->noErrorCode.ss, ss, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(_ds, ds, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);

    print("interrupt --- %", "0 - #DE");
    print("rip:        % ( offset: % )", rip, offset_buf);
    print("cs :        %", cs);
    print("rflags:     %", rflags);
    print("rsp:        %", rsp);
    print("ss:         %", ss);
    print("ds:         %", ds);

    hstop();
}


