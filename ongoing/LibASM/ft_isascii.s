section .text
	global _ft_isascii

_ft_isascii:
	xor rax, rax
	cmp rdi, 0
	jl _end
	cmp rdi, 128
	jl _good

_end:
	ret

_good:
	inc rax
	ret
