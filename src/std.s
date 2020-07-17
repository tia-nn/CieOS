.intel_syntax noprefix

.global test_and_set
test_and_set:
    push rbp
    mov rbp, rsp

    .10L:                               # loop {
        lock bts qword ptr [rdi], rsi   #   CF = (*arg1)[arg2]; (*arg1)[arg2] = 1;
        jnc .10E                        #   if (CF == 0) break
        .12L:                           #   else do {
            bt qword ptr [rdi], rsi     #     CF = (*arg1)[arg2];
            jc .12L                     #   } while (CF != 0);
        jmp .10L                        #   continue;
    .10E:                               # }

    leave
    ret
