//
// Created by tia on 2020/05/11.
//

#include <descriptor/interrupt.h>
#include <descriptor/table.h>
#include <stdint.h>
#include <std.h>
#include <interrupt_handler.h>
#include <int_default_handler_array.h>

struct InterruptDescriptor IDT[256];


void IDT_set(uint8_t vector, void *offset, uint16_t ss, uint8_t ist, uint8_t type, uint8_t dpl) {
    struct InterruptDescriptor *id = &IDT[vector];
    id->_zero1 = 0;
    id->_zero2 = 0;
    id->_reserved = 0;

    id->p = 1;

    if (dpl) id->dpl = 3; else id->dpl = 0;

    id->segment_selector = ss;
    id->ist = ist;
    id->type = type;

    uint64_t offset_int = (uint64_t) offset;
    id->offset_00_15 = offset_int;
    id->offset_16_31 = offset_int >> 16;
    id->offset_32_64 = offset_int >> 32;
}

void IDT_init() {
    for (uint16_t vector = 0; vector < 256; vector ++) {
        IDT_set(vector, INT_DEFAULT_HANDLER_ARRAY[vector], 8, 0, 0xe, 0);
    }

    IDT_set(32, (void *)int_32_handler, 8, 0, 0x0e, 0);
    IDT_set(13, (void *)int_13_handler, 8, 0, 0x0e, 0);
    IDT_set(33, (void *)int_33_handler, 8, 0, 0x0e, 0);

    // more specific set...
}
