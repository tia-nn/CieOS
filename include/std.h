//
// Created by tia on 2020/03/16.
//

#ifndef CIEOS_STD_H
#define CIEOS_STD_H

#include <stdint.h>

typedef _Bool bool;
#define true ((_Bool)1)
#define false ((_Bool)0)

typedef struct DIVMOD {
    int64_t div;
    int64_t mod;
} DIVMOD;

enum ITOA_FRAGS {
    DEFAULT             = 0,
    FILL_SPACE          = 0x1,
    FILL_ZERO           = 0x2,
    IS_SIGNED           = 0x4,
    SET_SIGN            = 0x8,
    UPPERCASE           = 0x10,
    SET_NULL_TERMINATE  = 0x20,
    ZERO_IS_EMPTY       = 0x40
};

struct DoubleWordAccess {
    uint32_t low;
    uint32_t high;
};

struct BitAccess64 {
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

struct BitAccess32 {
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
};

#define M_DOUBLEWORD_ACCESS(target) (*((struct DoubleWordAccess*)&target))
#define M_BIT_ACCESS_64(target) (*((struct BitAccess64*)&target))
#define M_BIT_ACCESS_32(target) (*((struct BitAccess32*)&target))

extern uint64_t TIMER_COUNT;
extern void * KERNEL_LOADED_POINT;
extern void * ENTRY_POINT;


void halt();
void hstop();

DIVMOD divmod(int64_t x, int64_t y);
void itoa(uint64_t value, char *buffer, uint64_t buffer_size, uint64_t radix, uint32_t flags);
bool strncmp(const char *a, const char *b, uint64_t n);
bool strcmp(const char *a, const char *b);
void strncpy(const char *src, char *dist, uint64_t n);
void strcpy(const char *src, char *dist);
void bool2str(char *dist, bool x);

#endif //CIEOS_STD_H
