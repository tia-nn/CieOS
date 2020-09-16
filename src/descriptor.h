//
// Created by tia on 2020/09/16.
//

#ifndef CIEOS_SRC_DESCRIPTOR_H
#define CIEOS_SRC_DESCRIPTOR_H

#include <x64_IA32e64.h>

#define GDT_LENGTH 3

#define GDT_KERNEL_CS 1
#define GDT_KERNEL_DS 2

void GDT_initial();
void IDT_initial();

#endif //CIEOS_SRC_DESCRIPTOR_H
