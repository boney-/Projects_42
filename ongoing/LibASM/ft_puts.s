section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	cmp rdi, 0
	jz _null_case
	call _ft_strlen
	mov rsi, rdi
	mov rdi, 1
	mov rdx, rax
	mov rax, 0x2000004
	syscall
	lea rsi, [rel nl]
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	mov rax, 10
	ret

_null_case:
	lea rsi, [rel null]
	mov rdx, 7
	mov rdi, 1
	mov rax, 0x2000004
	syscall
	mov rax, 10
	ret

section		.data
nl		db	10,0
null	db	"(null)", 10, 0
