section .text
	global _ft_isalnum

_ft_isalnum:
	xor rax, rax
	cmp rdi, '0'
	jl _end
	cmp rdi, ':'
	jl _good
	cmp rdi, 'A'
	jl _end
	cmp rdi, '['
	jl _good
	cmp rdi, 'a'
	jl _end
	cmp rdi, '{'
	jl _good

_end:
	ret

_good:
	inc rax
	ret
