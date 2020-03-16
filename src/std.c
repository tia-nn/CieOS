//
// Created by tia on 2020/03/16.
//

#include "std.h"

#include <stdint.h>


void halt() {
    __asm__ volatile ("hlt");
}

void hstop() {
    while (true) __asm__ volatile ("hlt");
}
