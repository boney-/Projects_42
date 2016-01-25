section .text
	global _ft_strcat

_ft_strcat:
	mov rax, rdi				;Save le pointeur debut de chaine
	
_loop:							;Avance jusqu'au \0 de s1
	cmp byte [rdi], 0x0
	je _concat
	inc rdi
	jmp _loop

_concat:
	cmp byte [rsi], 0x0
	je _end
	movsb
	jmp _concat

_end:
	ret
	
