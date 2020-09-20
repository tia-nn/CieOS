//
// Created by tia on 2020/09/17.
//

#ifndef CIEOS_SRC_INTERRUPT_HANDLER_H
#define CIEOS_SRC_INTERRUPT_HANDLER_H

#include <x64_IA32e64.h>

#define INTERRUPT_HANDLER(vec, name, var) __attribute__((interrupt)) \
void int_ ##vec## _ ##name## _handler(union InterruptFrame * var)

_Noreturn INTERRUPT_HANDLER(13, GP, frame);
INTERRUPT_HANDLER(32, TIMER, frame);

#endif //CIEOS_SRC_INTERRUPT_HANDLER_H
