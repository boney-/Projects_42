%define SYSWR	0x2000004
%define SYSRD	0x2000003
%define BUFSIZE	256

section		.bss
	buffer resb BUFSIZE

section		.text
	global _ft_cat

_ft_cat:
	cmp rdi, 0
	jb _end
	mov r10, rdi

_read:
	mov rdi, r10
	lea rsi, [rel buffer]
	mov rdx, BUFSIZE
	mov rax, SYSRD
	syscall
	cmp rax, 0
	je _end
	mov rdi, 1 ; STDOUT
	mov rdx, rax
	mov rax, SYSWR
	syscall
	jmp _read

	
_end:
	ret
