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

.global int_puts
int_puts:
    mov rax, 1
    int 0x80
    ret

.global int_print
int_print:
    mov rax, 2
    int 0x80
    ret


.global int_getchar
int_getchar:
    mov rax, 3
    int 0x80
    ret
