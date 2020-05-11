
#include <std.h>
#include <stdint.h>
#include <graphics/print.h>

void int_162_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "162 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}
