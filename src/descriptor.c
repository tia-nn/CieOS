//
// Created by tia on 2020/09/16.
//

#include "descriptor.h"
#include <stdint.h>
#include <stdbool.h>
#include <x64_IA32e64.h>
#include "tools.h"

// ------ GDT ------

uint64_t GDT[GDT_LENGTH];

void set_code_segment(CodeSegmentDescriptor *dist, uint8_t dpl, bool readable, bool confirming,
                      bool long_, bool default_, bool granularity);

void set_data_segment(DataSegmentDescriptor *dist, uint32_t base, uint32_t limit, uint8_t dpl,
                      bool writeable, bool expansion_direction, bool big, bool granularity);

void GDT_initial() {
    GDT[0] = 0x0000000000000000;  // null descriptor
    set_code_segment((CodeSegmentDescriptor *) GDT + GDT_KERNEL_CS, 0, true, true, true, false, true);
    set_data_segment((DataSegmentDescriptor *) GDT + GDT_KERNEL_DS, 0x00, 0xfffff, 0, true, false, true, true);

    GDTR gdtr;
    gdtr.base = (uint64_t)GDT;
    gdtr.limit = 8 * GDT_LENGTH;
    __asm__ volatile ("lgdt [%0]"::"r"(&gdtr));
}

void set_code_segment(CodeSegmentDescriptor *dist, uint8_t dpl, bool readable, bool confirming,
                      bool long_, bool default_, bool granularity) {
    dist->_1_fill_s = 1;
    dist->_1_fill_dt = 1;
    dist->available = 0;
    dist->present = 1;
    dist->accessed = 0;

    dist->dpl = (dpl > 3) ? 3 : dpl;
    dist->readable = to_bool(readable);
    dist->conforming = to_bool(confirming);
    dist->long_ = to_bool(long_);
    dist->default_ = to_bool(default_);
    dist->granularity = to_bool(granularity);
}

void set_data_segment(DataSegmentDescriptor *dist, uint32_t base, uint32_t limit, uint8_t dpl,
                      bool writeable, bool expansion_direction, bool big, bool granularity) {
    dist->_0_fill_dt = 0;
    dist->_0_reserved_ = 0;
    dist->_1_fill_s = 1;
    dist->available = 0;
    dist->present = 1;
    dist->accessed = 0;

    dist->dpl = (dpl > 3) ? 3 : dpl;
    dist->writeable = to_bool(writeable);
    dist->expansion_direction = to_bool(expansion_direction);
    dist->big = to_bool(big);
    dist->granularity = to_bool(granularity);

    dist->base_15_00 = base;
    dist->base_23_16 = base >> 16u;
    dist->base_31_24 = base >> 24u;

    dist->limit_15_00 = limit;
    dist->limit_19_16 = limit >> 16u;
}

// ------ IDT ------
