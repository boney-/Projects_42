section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

_ft_strdup:
	mov rsi, rdi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	inc rdi
	mov rdx, rax
	call _malloc
	mov rdi, rax
	inc rdx
	call _ft_memcpy
	ret
