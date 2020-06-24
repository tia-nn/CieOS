//
// Created by tia on 2020/05/02.
//

#ifndef CIEOS_INCLUDE_DESCRIPTOR_SEGMENT_H
#define CIEOS_INCLUDE_DESCRIPTOR_SEGMENT_H

#include <stdint.h>
#include <descriptor/table.h>

#pragma pack(1)

struct SegmentDescriptor {
    uint64_t bit_00_63;
};

struct DataSegmentDescriptor {
    uint16_t limit_00_15;
    uint16_t base_00_15;
    uint8_t base_16_23;
    unsigned accessed: 1;
    unsigned writeable: 1;
    unsigned expansion_direction: 1;
    unsigned _reserved_0: 1;
    unsigned _reserved_1: 1;
    unsigned dpl: 2;
    unsigned present: 1;
    unsigned limit_16_19: 4;
    unsigned available: 1;
    unsigned _reserved2_0: 1;
    unsigned big: 1;
    unsigned granularity: 1;
    uint8_t base_24_31;
};

struct CodeSegmentDescriptor64 {
    uint32_t _ignore_1;
    uint8_t _ignore_2;
    unsigned accessed: 1;
    unsigned readable: 1;
    unsigned conforming: 1;
    unsigned _reserved_1: 1;
    unsigned _reserved2_1: 1;
    unsigned dpl: 2;
    unsigned present: 1;
    unsigned _ignore_3: 4;
    unsigned available: 1;
    unsigned long_flag: 1;
    unsigned default_: 1;
    unsigned granularity: 1;
    uint8_t _ignore_4;
};

#pragma pack()

void GDT_init();

//#defile M_LOAD_GDT() do{ \
//struct DescriptorTableRegister gdtr = { GDT_LIMIT, (uint64_t)GDT };\
//__asm__ volatile (\
//"lea rax, %0 \n"\
//"lgdt [rax]"\
//: : "m"(gdtr));\
//} while(0);

#define GDT_LEN 5
#define GDT_DESCRIPTOR_SIZE (sizeof(struct SegmentDescriptor))
#define GDT_LIMIT (GDT_LEN * GDT_DESCRIPTOR_SIZE - 1)

extern struct SegmentDescriptor GDT[GDT_LEN];


#define M_LOAD_GDT() do {\
struct DescriptorTableRegister gdtr = {GDT_LIMIT, (uint64_t)GDT};\
\
__asm__ volatile (\
"lea rax, %0 \n"\
"lgdt [rax]"\
: : "m"(gdtr));\
} while (0);


//__attribute__((always_inline)) void load_global_descriptor_table();


#endif //CIEOS_INCLUDE_DESCRIPTOR_SEGMENT_H
