global exit

exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    