section .text
global _ft_strdup
extern _ft_strlen, _malloc

_ft_strdup:
	xor     rax, rax
	call    _ft_strlen
	inc     rax 
	mov     r13, rdi
	mov     r12, rax
	mov     rdi, rax
	call    _malloc
	test    rax, rax
	je      _end
	mov     rcx, r12
	mov     r14, rax
	mov     rdi, rax
	mov     rsi, r13
	cld
	rep movsb
	mov     byte[rdi], 0
	mov     rax, r14
	jmp     _end

_end:
ret
