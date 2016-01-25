section .text
	global _ft_memset

_ft_memset:
	mov r10, rdi
	mov rcx, rdx
	mov rax, rsi
	rep stosb
	mov rax, r10
	ret
