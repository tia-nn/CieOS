
#include <std.h>
#include <stdint.h>
#include <graphics/print.h>

void int_0_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "0 - Divide Error Exception (#DE)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_1_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "1 - Debug Exception (#DB)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_2_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "2 - NMI Interrupt");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_3_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "3 - Breakpoint Exception (#BP)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_4_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "4 - Overflow Exception (#OF)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_5_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "5 - BOUND Range Exceeded Exception (#BR)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_6_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "6 - Invalid Opcode Exception (#UD)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_7_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "7 - Device Not Available Exception (#NM)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_8_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "8 - Double Fault Exception (#DF)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_9_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "9 - Coprocessor Segment Overrun");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_10_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "10 - Invalid TSS Exception (#TS)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_11_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "11 - Segment Not Present (#NP)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_12_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "12 - Stack Fault Exception (#SS)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_13_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "13 - General Protection Exception (#GP)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_14_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "14 - Page-Fault Exception (#PF)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_15_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "15 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_16_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "16 - x87 FPU Floating-Point Error (#MF)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_17_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "17 - Alignment Check Exception (#AC)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_18_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "18 - Machine-Check Exception (#MC)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_19_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "19 - SIMD Floating-Point Exception (#XM)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_20_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "20 - Virtualization Exception (#VE)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_21_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "21 - Control Protection Exception (#CP)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_22_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "22 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_23_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "23 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_24_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "24 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_25_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "25 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_26_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "26 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_27_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "27 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_28_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "28 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_29_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "29 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_30_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "30 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_31_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "31 - default handler (intel reserved vector)");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_32_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "32 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_33_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "33 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_34_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "34 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_35_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "35 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_36_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "36 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_37_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "37 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_38_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "38 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_39_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "39 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_40_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "40 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_41_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "41 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_42_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "42 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_43_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "43 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_44_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "44 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_45_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "45 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_46_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "46 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_47_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "47 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_48_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "48 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_49_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "49 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_50_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "50 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_51_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "51 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_52_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "52 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_53_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "53 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_54_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "54 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_55_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "55 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_56_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "56 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_57_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "57 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_58_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "58 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_59_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "59 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_60_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "60 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_61_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "61 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_62_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "62 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_63_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "63 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_64_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "64 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_65_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "65 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_66_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "66 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_67_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "67 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_68_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "68 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_69_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "69 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_70_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "70 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_71_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "71 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_72_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "72 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_73_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "73 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_74_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "74 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_75_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "75 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_76_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "76 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_77_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "77 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_78_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "78 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_79_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "79 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_80_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "80 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_81_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "81 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_82_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "82 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_83_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "83 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_84_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "84 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_85_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "85 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_86_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "86 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_87_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "87 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_88_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "88 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_89_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "89 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_90_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "90 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_91_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "91 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_92_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "92 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_93_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "93 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_94_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "94 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_95_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "95 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_96_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "96 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_97_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "97 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_98_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "98 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_99_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "99 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_100_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "100 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_101_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "101 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_102_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "102 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_103_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "103 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_104_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "104 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_105_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "105 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_106_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "106 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_107_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "107 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_108_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "108 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_109_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "109 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_110_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "110 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_111_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "111 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_112_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "112 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_113_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "113 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_114_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "114 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_115_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "115 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_116_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "116 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_117_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "117 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_118_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "118 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_119_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "119 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_120_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "120 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_121_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "121 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_122_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "122 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_123_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "123 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_124_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "124 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_125_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "125 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_126_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "126 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_127_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "127 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_128_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "128 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_129_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "129 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_130_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "130 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_131_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "131 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_132_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "132 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_133_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "133 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_134_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "134 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_135_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "135 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_136_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "136 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_137_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "137 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_138_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "138 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_139_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "139 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_140_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "140 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_141_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "141 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_142_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "142 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_143_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "143 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_144_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "144 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_145_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "145 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_146_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "146 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_147_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "147 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_148_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "148 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_149_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "149 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_150_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "150 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_151_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "151 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_152_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "152 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_153_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "153 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_154_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "154 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_155_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "155 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_156_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "156 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_157_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "157 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_158_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "158 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_159_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "159 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_160_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "160 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_161_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "161 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

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

void int_163_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "163 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_164_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "164 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_165_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "165 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_166_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "166 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_167_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "167 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_168_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "168 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_169_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "169 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_170_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "170 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_171_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "171 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_172_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "172 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_173_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "173 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_174_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "174 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_175_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "175 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_176_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "176 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_177_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "177 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_178_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "178 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_179_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "179 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_180_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "180 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_181_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "181 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_182_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "182 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_183_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "183 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_184_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "184 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_185_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "185 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_186_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "186 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_187_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "187 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_188_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "188 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_189_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "189 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_190_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "190 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_191_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "191 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_192_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "192 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_193_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "193 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_194_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "194 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_195_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "195 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_196_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "196 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_197_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "197 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_198_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "198 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_199_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "199 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_200_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "200 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_201_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "201 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_202_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "202 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_203_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "203 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_204_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "204 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_205_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "205 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_206_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "206 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_207_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "207 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_208_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "208 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_209_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "209 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_210_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "210 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_211_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "211 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_212_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "212 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_213_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "213 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_214_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "214 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_215_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "215 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_216_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "216 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_217_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "217 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_218_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "218 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_219_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "219 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_220_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "220 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_221_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "221 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_222_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "222 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_223_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "223 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_224_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "224 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_225_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "225 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_226_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "226 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_227_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "227 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_228_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "228 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_229_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "229 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_230_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "230 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_231_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "231 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_232_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "232 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_233_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "233 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_234_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "234 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_235_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "235 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_236_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "236 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_237_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "237 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_238_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "238 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_239_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "239 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_240_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "240 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_241_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "241 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_242_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "242 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_243_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "243 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_244_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "244 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_245_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "245 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_246_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "246 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_247_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "247 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_248_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "248 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_249_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "249 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_250_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "250 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_251_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "251 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_252_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "252 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_253_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "253 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_254_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "254 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}

void int_255_default_handler () {
    uint64_t error_code, RIP, CS, RFLAGS, RSP, SS;
    char error_code_buf[17];

    __asm__ volatile (
    "mov rax, [rbp + 8]"
    : "=a"(error_code)
    );

    itoa(error_code, error_code_buf, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
    print("interrupt --- %", "255 - default handler");
    print("errorCode --- %", error_code_buf);

    hstop();
}
