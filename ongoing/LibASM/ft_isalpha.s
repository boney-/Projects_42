section .text
	global _ft_isalpha

_ft_isalpha:
	xor rax, rax
	cmp rdi, 65
	jl _end
	cmp rdi, 91
	jl _good
	cmp rdi, 97
	jl _end
	cmp rdi, 123
	jl _good
	
_end:
	ret

_good:
	inc rax
	ret
