        global _start

        section .data

message:        db 'hello, world!', 10

        section .text
        %include "libio/libio.inc"
_start:
        mov rax, 1
        mov rdi, 1
        mov rsi, message
        mov rdx, 14
        syscall

        call exit