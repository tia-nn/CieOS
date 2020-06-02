//
// Created by tia on 2020/05/12.
//

#include <stdint.h>
#include <std.h>
#include <graphics/print.h>
#include <interrupt_handler.h>

__attribute__((interrupt))
void int_13_handler(struct InterruptFrame *frame) {
    char errorcode[17], rip[17], cs[17], rflags[17], rsp[17], ss[17];

    char offset_buf[17];
    itoa((uint64_t) frame->rip - (uint64_t)KERNEL_LOADED_POINT, offset_buf, 17, 16, SET_NULL_TERMINATE|FILL_ZERO);

    itoa(frame->error_code, errorcode, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->rip, rip, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->cs, cs, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->rflags, rflags, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->rsp, rsp, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    itoa(frame->ss, ss, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);

    print("interrupt --- %", "13 - #GP");
    print("error_code: %", errorcode);
    print("rip:        % ( offset: % )", rip, offset_buf);
    print("cs :        %", cs);
    print("rflags:     %", rflags);
    print("rsp:        %", rsp);
    print("ss:         %", ss);

    hstop();
}
