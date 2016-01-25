section .text
	global _ft_isprint

_ft_isprint:
	xor rax, rax
	cmp rdi, 32
	jl _end
	cmp rdi, 126
	jg _end
	inc rax

_end:
	ret
