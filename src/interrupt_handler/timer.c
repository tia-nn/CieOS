//
// Created by tia on 2020/05/11.
//

#include <pic.h>
#include <graphics/print.h>
#include <std.h>
#include <interrupt_handler.h>
#include <graphics/draw.h>
#include <control_registers.h>
#include <tasks/tasks.h>

struct TaskRegisterState {
    uint64_t cr3;

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

uint64_t TIMER_COUNT;  // extern definition is in std.h

uint64_t current_task = 0;
#define MAX_TASK_COUNT 3
struct TaskRegisterState task_register_state[MAX_TASK_COUNT];

void restore_context(struct TaskRegisterState*);  // asm function

void int_32_handler_schedule(struct TaskRegisterState *register_state) {  // called by asm int handler
    TIMER_COUNT ++;
    task_register_state[current_task] = *register_state;

    current_task = (current_task + 1) % MAX_TASK_COUNT;
    PIC_MASTER_EOI();
    restore_context(&task_register_state[current_task]);

    return;  // ここまで到達しない
}

void schedule_init() {
    (*((struct CR3*)&task_register_state[1].cr3)).PML4_addr = 0x3000u >> 12u;
    (*((struct CR3*)&task_register_state[1].cr3)).PCID = 0;
    task_register_state[1].cs = 0x18;
    task_register_state[1].ss = 0x20;
    task_register_state[1].rflags =0x202;
    task_register_state[1].rsp = 0x1000;  // 決め打ちなのでなんとかする
    task_register_state[1].rip = (uint64_t)task_2;

    (*((struct CR3*)&task_register_state[2].cr3)).PML4_addr = 0x3000u >> 12u;
    (*((struct CR3*)&task_register_state[2].cr3)).PCID = 0;
    task_register_state[2].cs = 0x28;
    task_register_state[2].ss = 0x30;
    task_register_state[2].rflags =0x202;
    task_register_state[2].rsp = 0x2000;  // 決め打ちなのでなんとかする
    task_register_state[2].rip = (uint64_t)task_3;
}


__attribute__((no_caller_saved_registers))
void dump(uint64_t val) {
    char buf[17];
    itoa(val, buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print(buf);
}