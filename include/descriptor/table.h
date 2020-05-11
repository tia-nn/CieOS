//
// Created by tia on 2020/05/11.
//

#ifndef CIEOS_INCLUDE_DESCRIPTOR_TABLE_H
#define CIEOS_INCLUDE_DESCRIPTOR_TABLE_H

#include <stdint.h>

#pragma pack(1)

struct DescriptorTableRegister {
    uint16_t limit;
    uint64_t base;
};

#pragma pack()

#endif //CIEOS_INCLUDE_DESCRIPTOR_TABLE_H
