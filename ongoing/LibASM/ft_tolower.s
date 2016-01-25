section .text
	global _ft_tolower

_ft_tolower:
	mov rax, rdi
	cmp rdi, 'A'
	jl _end
	cmp rdi, 'Z'
	jg _end
	add rax, 32

_end:
	ret
