.intel_syntax noprefix

#struct TaskRegisterState {
.set of_cr3, 0x00
.set of_ds,  0x08

.set of_rax, 0x10
.set of_rcx, 0x18
.set of_rdx, 0x20
.set of_rbx, 0x28
.set of_rsi, 0x30
.set of_rdi, 0x38
.set of_rbp, 0x40
.set of_rsp, 0x48
.set of_r8,  0x50
.set of_r9,  0x58
.set of_r10, 0x60
.set of_r11, 0x68
.set of_r12, 0x70
.set of_r13, 0x78
.set of_r14, 0x80
.set of_r15, 0x88

.set of_rflags, 0x90
.set of_ss,     0x98
.set of_cs,     0xa0
.set of_rip,    0xa8
#};

.extern dump

.global restore_context
restore_context:
    push qword ptr [rdi + of_ss] # ss
    push qword ptr [rdi + of_rsp] # rsp
    push qword ptr [rdi + of_rflags] # rflags
    push qword ptr [rdi + of_cs] # cs
    push qword ptr [rdi + of_rip] # rip

    # raxは後
    mov rcx, [rdi + of_rcx]
    mov rdx, [rdi + of_rdx]
    mov rbx, [rdi + of_rbx]
    mov rsi, [rdi + of_rsi]
    # rdiは後
    mov rbp, [rdi + of_rbp]
    mov r8,  [rdi + of_r8]
    mov r9,  [rdi + of_r9]
    mov r10, [rdi + of_r10]
    mov r11, [rdi + of_r11]
    mov r12, [rdi + of_r12]
    mov r13, [rdi + of_r13]
    mov r14, [rdi + of_r14]
    mov r15, [rdi + of_r15]

    mov rax, [rdi + of_cr3]  # cr3
    mov cr3, rax
    mov rax, [rdi + of_ds]
    mov ds, ax
    mov rax, [rdi + of_rax]
    mov rdi, [rdi + of_rdi]

    mov al, 0x20
    out 0x20, al  # master pic EOI

    iretq


.extern int_32_handler_schedule
.global int_32_handler
int_32_handler:
    push rbp
    mov rbp, rsp

    push qword ptr [rbp + 0x8] # rip
    push qword ptr [rbp + 0x10] # cs
    push qword ptr [rbp + 0x28] # ss
    push qword ptr [rbp + 0x18] # rflags

    push r15
    push r14
    push r13
    push r12
    push r11
    push r10
    push r9
    push r8
    push qword ptr [rbp + 0x20] # rsp
    push qword ptr [rbp] # rbp
    push rdi
    push rsi
    push rbx
    push rdx
    push rcx
    push rax

    mov ax, ds
    movzx eax, ax
    push rax
    mov rax, cr3
    push rax

    mov rdi, rsp

    jmp int_32_handler_schedule

