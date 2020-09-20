//
// Created by tia on 2020/09/16.
//

#include <x64_IA32e64.h>
#include "initialize.h"
#include "descriptor.h"
#include "print.h"
#include "peripheral_control.h"

__attribute__((always_inline)) inline
void set_segment_register(SegmentRegister cs, SegmentRegister ds, SegmentRegister ss);


void initialize(GraphicsConfig *gc, MemoryMap *mm) {
    GDT_initial();
    SegmentRegister kernel_cs = {0, 0, GDT_KERNEL_CS};
    SegmentRegister kernel_ds = {0, 0, GDT_KERNEL_DS};
    set_segment_register(kernel_cs, kernel_ds, kernel_ds);

    IDT_initial();

    initial_timer(100);  // 10ms
    initial_pic(PIC1_ENABLE_TIMER, 0xff);

    initial_print(gc);
}

__attribute__((always_inline)) inline
void set_segment_register(SegmentRegister cs, SegmentRegister ds, SegmentRegister ss) {
    void *a = &&next;
    __asm__ volatile (
    "mov ax, %1 \n"  // ds and other
    "mov ds, ax \n"
    "mov es, ax \n"
    "mov fs, ax \n"
    "mov gs, ax \n"

    "mov ax, %2 \n"
    "mov ss, ax \n"

    "xor rax, rax \n"
    "mov ax, %0 \n"  // cs
    "push rax \n"
    "mov rax, %3 \n"  // rip
    "push rax \n"
    "retfq \n"
    ::"m"(cs), "m"(ds), "m"(ss), "m"(a));
    next:
    return;
}
