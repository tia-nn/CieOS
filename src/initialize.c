//
// Created by tia on 2020/09/16.
//

#include <x64_IA32e64.h>
#include "initialize.h"
#include "descriptor.h"
#include "print.h"

__attribute__((always_inline)) inline
void set_segment_register(SegmentRegister cs, SegmentRegister ds, SegmentRegister ss) {
    void *a = &&ret;
    __asm__ volatile (
    "movzx eax, %0 \n"
    "push rax \n"
    "lea rax, +8[rsp] \n"
    "push rax \n"
    "pushfq \n"
    "movzx eax, %1 \n"
    "push rax \n"
    "push %2 \n"
    "mov ax, %3 \n"
    "mov ds, ax \n"
    "iretq"
    : : "m"(ss), "m"(cs), "m"(a), "m"(ds)
    );
    ret:
    __asm__ volatile ("nop");
}

void initialize(GraphicsConfig *gc) {
    GDT_initial();
    SegmentRegister kernel_cs = {0, 0, GDT_KERNEL_CS};
    SegmentRegister kernel_ds = {0, 0, GDT_KERNEL_DS};
    set_segment_register(kernel_cs, kernel_ds, kernel_ds);

    initialize_print(gc);
}
