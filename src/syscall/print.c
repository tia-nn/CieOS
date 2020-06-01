//
// Created by tia on 2020/05/15.
//

#include <syscall/print.h>
#include <stdint.h>
#include <graphics/print.h>

uint64_t _syscall_print(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
    puts((char *)arg1);
    return 1;
}
