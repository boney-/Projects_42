section .text
	global _ft_toupper

_ft_toupper:
	mov rax, rdi
	cmp rdi, 'a'
	jl _end
	cmp rdi, 'z'
	jg _end
	add rax, -32

_end:
	ret
