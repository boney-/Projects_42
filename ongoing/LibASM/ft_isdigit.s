section .text
	global _ft_isdigit

_ft_isdigit:
	xor rax, rax
	cmp rdi, '0'
	jl _end
	cmp rdi, '9'
	jg _end
	inc rax

_end:
	ret
