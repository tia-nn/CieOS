.intel_syntax noprefix

.global syscall_print
syscall_print:
    mov rax, 0x0
    mov r10, rcx
    syscall
    ret
