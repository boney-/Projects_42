%define FTALL(nb)	0x2000000 | nb
%define STDOUT		1

section .data
retline	db 0xa,0   ;new line
null db "(null)"

section .text
extern _ft_strlen
global _ft_puts

_ft_puts:
enter 16, 0
pushf

mov r14, rdi

or rdi, rdi
jz _null

exe:
mov r15, rdi						; on met l'argument de puts qui est dans rdi dans rsi pour qu'il soit l'argument du write
call _ft_strlen						; on compte la longueur de rdi

mov rdx, rax						; on recupere la longueur de la chaine (dans rax) comme troisieme argument de write (dans rdx)
mov rdi, STDOUT
lea rsi, [rel r15]
mov rax, 0x2000004
syscall
mov r15, rax

cmp rax, 0
jl false

or r14, r14
jz true

mov rdx, 1
mov rdi, STDOUT
mov rsi, retline
mov rax, 0x2000004
syscall

true:
mov rax, 10
jmp end

false:
mov rax, -1
jmp end

end:
popf
leave
ret

_null:
mov rdi, null
jmp exe
