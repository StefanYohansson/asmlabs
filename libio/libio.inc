global exit
global string_length
global print_string
global string_copy

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

print_string:
        push r14
        xor rax, rax
        call string_length
        mov r14, rax
        push r13
        mov r13, rdi
        mov rax, 1
        mov rdi, 1
        mov rsi, r13
        mov rdx, r14
        syscall
        pop r13
        pop r14
        ret

string_copy:
        push rsi
.loop:
        mov dl, byte[rdi]
        mov byte[rsi], dl
        inc rdi
        inc rsi
        test dl, dl
        jnz .loop

        pop rax
        ret
