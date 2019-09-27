global exit
global string_length

exit:
        mov rax, 60
        xor rdi, rdi
        syscall

string_length:
        push r13
        xor rax, rax
.loop:
        cmp byte [rdi+r13], 0
        je .end
        inc r13
        jmp .loop
.end:
        mov rax, r13
        pop r13
        ret
