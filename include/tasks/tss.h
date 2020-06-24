//
// Created by tia on 2020/06/19.
//

#ifndef CIEOS_INCLUDE_TASKS_TSS_H
#define CIEOS_INCLUDE_TASKS_TSS_H

#include <stdint.h>

struct TaskStateSegment {
    uint32_t _reserved1;
    uint32_t rsp0_low;
    uint32_t rsp0_high;
    uint32_t rsp1_low;
    uint32_t rsp1_high;
    uint32_t rsp2_low;
    uint32_t rsp2_high;
    uint64_t _reserved2;
    uint32_t ist1_low;
    uint32_t ist1_high;
    uint32_t ist2_low;
    uint32_t ist2_high;
    uint32_t ist3_low;
    uint32_t ist3_high;
    uint32_t ist4_low;
    uint32_t ist4_high;
    uint32_t ist5_low;
    uint32_t ist5_high;
    uint32_t ist6_low;
    uint32_t ist6_high;
    uint32_t ist7_low;
    uint32_t ist7_high;
    uint64_t _reserved3;
    uint16_t _reserved4;
    uint16_t io_map;
};

#endif //CIEOS_INCLUDE_TASKS_TSS_H
