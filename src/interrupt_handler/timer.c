//
// Created by tia on 2020/05/11.
//

#include <pic.h>
#include <graphics/print.h>
#include <std.h>
#include <interrupt_handler.h>
#include <graphics/draw.h>

struct TaskRegisterState {
    uint64_t rax;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rbx;
    uint64_t rsi;
    uint64_t rdi;
    uint64_t rbp;
    uint64_t rsp;
    uint64_t r8;
    uint64_t r9;
    uint64_t r10;
    uint64_t r11;
    uint64_t r12;
    uint64_t r13;
    uint64_t r14;
    uint64_t r15;
    uint64_t rflags;
    uint64_t ss;
    uint64_t cs;
    uint64_t rip;
};

uint64_t TIMER_COUNT;

uint64_t current_task = 0;
struct TaskRegisterState task_register_state[2];

void restore_context(struct TaskRegisterState*);

void int_32_handler_schedule(struct TaskRegisterState *register_state) {
    TIMER_COUNT ++;
    task_register_state[current_task].rax = register_state->rax;
    task_register_state[current_task].rcx = register_state->rcx;
    task_register_state[current_task].rdx = register_state->rdx;
    task_register_state[current_task].rbx = register_state->rbx;
    task_register_state[current_task].rsi = register_state->rsi;
    task_register_state[current_task].rdi = register_state->rdi;
    task_register_state[current_task].rbp = register_state->rbp;
    task_register_state[current_task].rsp = register_state->rsp;
    task_register_state[current_task].r8 = register_state->r8;
    task_register_state[current_task].r9 = register_state->r9;
    task_register_state[current_task].r10 = register_state->r10;
    task_register_state[current_task].r11 = register_state->r11;
    task_register_state[current_task].r12 = register_state->r12;
    task_register_state[current_task].r13 = register_state->r13;
    task_register_state[current_task].r14 = register_state->r14;
    task_register_state[current_task].r15 = register_state->r15;
    task_register_state[current_task].rflags = register_state->rflags;
    task_register_state[current_task].ss = register_state->ss;
    task_register_state[current_task].cs = register_state->cs;
    task_register_state[current_task].rip = register_state->rip;

    current_task = (current_task + 1) % 2;  // max task count is 2
    PIC_MASTER_EOI();
    restore_context(&task_register_state[current_task]);

    return;  // ここまで到達しない
}

void task_2();

__attribute__((no_caller_saved_registers))
void dump(uint64_t val) {
    char buf[17];
    itoa(val, buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print(buf);
}

void init_schedule() {
    task_register_state[1].cs = 0x08;
    task_register_state[1].ss = 0x10;
    task_register_state[1].rflags =0x202;
    task_register_state[1].rsp = 0x1000;
    task_register_state[1].rip = (uint64_t)task_2;
}


void task_2() {
    uint64_t last = 0;
    uint32_t color = 0;
    static const uint32_t color_max = 0x1000000;
    while (true) {
        if (TIMER_COUNT != last) {
            draw_char('O', draw_get_width() - 8, draw_get_height() - 16, color);
            color = (color + 1) % color_max;
            last = TIMER_COUNT;
        }
        halt();
    };
}