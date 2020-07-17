//
// Created by tia on 2020/06/10.
//

#include <stdint.h>
#include <graphics/print.h>

uint64_t systemcall_puts(
        uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
    static uint64_t row = 1;
    puts_right((char *)arg1);
    return 0;
}

uint64_t syscall_print (
        uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6){
    print((char *)arg1, (char *)arg2, (char *)arg3, (char *)arg4, (char *)arg5, (char *)arg6);
    return 0;
}

uint64_t syscall_print_right (
        uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6){
    print_right((char *)arg1, (char *)arg2, (char *)arg3, (char *)arg4, (char *)arg5, (char *)arg6);
    return 0;
}

__attribute__((no_caller_saved_registers))
uint64_t int_128_handler_main(
        uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
    uint64_t rax;
    __asm__ volatile ("": "=a"(rax));

    switch (rax) {
        case 1:
            systemcall_puts(arg1, arg2, arg3, arg4, arg5, arg6);
            break;
        case 2:
            syscall_print(arg1, arg2, arg3, arg4, arg5, arg6);
            break;
        case 3:
            syscall_print_right(arg1, arg2, arg3, arg4, arg5, arg6);
            break;
        default:
            return 0xffffffffffffffff;
    }

}
