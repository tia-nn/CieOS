//
// Created by tia on 2020/09/16.
//

#ifndef CIEOS_SRC_TOOLS_H
#define CIEOS_SRC_TOOLS_H

#include <stdint.h>
#include <stdbool.h>

#define to_bool(value) ((value)?true:false)

struct DoubleWordAccess {
    uint32_t low;
    uint32_t high;
};

struct WordAccess {
    uint16_t word_0;
    uint16_t word_1;
    uint16_t word_2;
    uint16_t word_3;
};

struct ByteAccess {
    uint8_t byte_0;
    uint8_t byte_1;
    uint8_t byte_2;
    uint8_t byte_3;
    uint8_t byte_4;
    uint8_t byte_5;
    uint8_t byte_6;
    uint8_t byte_7;
};

struct BitAccess {
    unsigned bit_0: 1;
    unsigned bit_1: 1;
    unsigned bit_2: 1;
    unsigned bit_3: 1;
    unsigned bit_4: 1;
    unsigned bit_5: 1;
    unsigned bit_6: 1;
    unsigned bit_7: 1;
    unsigned bit_8: 1;
    unsigned bit_9: 1;
    unsigned bit_10: 1;
    unsigned bit_11: 1;
    unsigned bit_12: 1;
    unsigned bit_13: 1;
    unsigned bit_14: 1;
    unsigned bit_15: 1;
    unsigned bit_16: 1;
    unsigned bit_17: 1;
    unsigned bit_18: 1;
    unsigned bit_19: 1;
    unsigned bit_20: 1;
    unsigned bit_21: 1;
    unsigned bit_22: 1;
    unsigned bit_23: 1;
    unsigned bit_24: 1;
    unsigned bit_25: 1;
    unsigned bit_26: 1;
    unsigned bit_27: 1;
    unsigned bit_28: 1;
    unsigned bit_29: 1;
    unsigned bit_30: 1;
    unsigned bit_31: 1;
    unsigned bit_32: 1;
    unsigned bit_33: 1;
    unsigned bit_34: 1;
    unsigned bit_35: 1;
    unsigned bit_36: 1;
    unsigned bit_37: 1;
    unsigned bit_38: 1;
    unsigned bit_39: 1;
    unsigned bit_40: 1;
    unsigned bit_41: 1;
    unsigned bit_42: 1;
    unsigned bit_43: 1;
    unsigned bit_44: 1;
    unsigned bit_45: 1;
    unsigned bit_46: 1;
    unsigned bit_47: 1;
    unsigned bit_48: 1;
    unsigned bit_49: 1;
    unsigned bit_50: 1;
    unsigned bit_51: 1;
    unsigned bit_52: 1;
    unsigned bit_53: 1;
    unsigned bit_54: 1;
    unsigned bit_55: 1;
    unsigned bit_56: 1;
    unsigned bit_57: 1;
    unsigned bit_58: 1;
    unsigned bit_59: 1;
    unsigned bit_60: 1;
    unsigned bit_61: 1;
    unsigned bit_62: 1;
    unsigned bit_63: 1;
};

#define DOUBLEWORD_ACCESS(target) (*((struct DoubleWordAccess*)&target))
#define WORD_ACCESS(target) (*((struct WordAccess*)&target))
#define BYTE_ACCESS(target) (*((struct ByteAccess*)&target))
#define BIT_ACCESS(target) (*((struct BitAccess*)&target))

#define BIT_ARR_ACCESS(target, index) _BIT_ARR_ACCESS_(target, index)
#define _BIT_ARR_ACCESS_(target, index) (*((struct BitAccess*)&target)).bit_##index

enum ITOA_FRAGS {
    DEFAULT             = 0u,
    FILL_SPACE          = 0x1u,
    FILL_ZERO           = 0x2u,
    IS_SIGNED           = 0x4u,
    SET_SIGN            = 0x8u,
    UPPERCASE           = 0x10u,
    SET_NULL_TERMINATE  = 0x20u,
    ZERO_IS_EMPTY       = 0x40u
};

void itoa(uint64_t value, char *buffer, uint64_t buffer_size, uint64_t radix, uint32_t flags);
void test_and_set(uint64_t *bitArr, uint64_t pos);  // asm

#endif //CIEOS_SRC_TOOLS_H
