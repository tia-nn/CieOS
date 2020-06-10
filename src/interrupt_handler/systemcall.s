.intel_syntax noprefix

.extern int_128_handler_main
.global int_128_handler
int_128_handler:
    call int_128_handler_main
    iretq

.global int_0x80
int_0x80:
    int 0x80
    ret

.global int_0x80_1
int_0x80_1:
    mov rax, 1
    int 0x80
    ret
