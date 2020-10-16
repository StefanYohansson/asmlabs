global exit
global string_length
global print_string
global string_copy
global print_char
global print_newline        

exit:
        mov rax, 60             ; exit operation
        xor rdi, rdi            ; 0ed rdi register
        syscall                 ; call exit 0 operation

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
        push r14                ; save register
        xor rax, rax            ; 0ed rax register
        call string_length      ; call string_length
        mov r14, rax            ; move return of string_length into r14 register
        push r13                ; save register
        mov r13, rdi            ; move print_string argument (string to print) into r13 register
        mov rax, 1              ; write operation
        mov rdi, 1              ; stdout
        mov rsi, r13            ; pass string to output
        mov rdx, r14            ; pass string length
        syscall                 ; call print to stdout operation
        pop r13                 ; restore register
        pop r14                 ; restore register
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

print_char:
#        push rdi
#        mov rax, 1
#        mov rdi, 1
#        mov rsi, rsp
#        mov rdx, 1
#        syscall
#        pop rdi                 
        push rdi                ; save register
        mov rdi, rsp            ; move top of stack value into rdi
        call print_string       ; call print_string
        pop rdi                 ; restore register
        ret

print_newline:
        push rdi                ; save register
        mov rdi, 0xa            ; move 0xA (newline feed) value into rdi
        call print_char         ; call print_char
        pop rdi                 ; restore register
        ret
