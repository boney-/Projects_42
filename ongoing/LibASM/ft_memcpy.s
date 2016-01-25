section .text
	global _ft_memcpy

_ft_memcpy:
	mov rax, rdi
	mov rcx, rdx
	CLD 
	REP movsb
	ret
