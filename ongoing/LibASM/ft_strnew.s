section .text
	extern _malloc
	extern _ft_bzero
	global _ft_strnew

_ft_strnew:
	inc rdi
	mov r10, rdi
	call _malloc
	test rax, rax
	je _end
	mov rdi, rax
	mov rsi, r10
	call _ft_bzero	

_end
	ret
