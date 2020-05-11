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
