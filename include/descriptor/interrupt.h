//
// Created by tia on 2020/05/11.
//

#ifndef CIEOS_INCLUDE_DESCRIPTOR_INTERRUPT_H
#define CIEOS_INCLUDE_DESCRIPTOR_INTERRUPT_H

#include <stdint.h>
#include <descriptor/table.h>

#pragma pack(1)

struct InterruptDescriptor {
    uint16_t offset_00_15;
    uint16_t segment_selector;
    unsigned ist      : 3;
    unsigned _zero1   : 5;
    unsigned type     : 4;
    unsigned _zero2   : 1;
    unsigned dpl      : 2;
    unsigned p        : 1;
    uint16_t offset_16_31;
    uint32_t offset_32_64;
    uint32_t _reserved;
};

#pragma pack()

#define IDT_LEN 256
#define IDT_DESCRIPTOR_SIZE (sizeof(struct InterruptDescriptor))
#define IDT_LIMIT (IDT_DESCRIPTOR_SIZE * IDT_LEN - 1)

extern struct InterruptDescriptor IDT[IDT_LEN];

void IDT_init();

#define M_LOAD_IDT() do {\
struct DescriptorTableRegister idtr = {IDT_LIMIT, (uint64_t)IDT};\
\
__asm__ volatile (\
"lea rax, %0 \n"\
"lidt [rax]"\
: : "m"(idtr));\
} while (0)

#endif //CIEOS_INCLUDE_DESCRIPTOR_INTERRUPT_H
