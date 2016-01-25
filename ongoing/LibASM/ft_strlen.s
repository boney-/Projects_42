section .text
	global _ft_strlen

_ft_strlen:
	xor rcx, rcx	;rcx = 0
	not rcx 		;renverse les bits de rcx (devient le + gros int possible).	
	mov r10, rdi
	xor al, al		;al = 0 (le caractere recherche)
	cld				;On indique le sens du scan
	repne scasb		;scan byte par byte (repete tant que != al)
	not rcx			;renverse a nouveau les bits de rcx pour retrouver la valeur.
	dec rcx			;On dec rcx une fois pour ne pas compter le \0
	mov rax, rcx	;On place rcx dans le registre de retour
	mov rdi, r10
	ret
