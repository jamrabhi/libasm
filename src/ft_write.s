extern __errno_location

section .text
	global ft_write

ft_write:
	mov rax, 1
	syscall
	test rax, rax			; tester si rax est négatif (erreur)
	js error				; si neg
	ret

error:
	mov edi, eax			; sauvegarder l'erreur dans edi (errno)
	neg edi
	call __errno_location	; obtenir l'adresse d'errno
	mov [rax], edi
	mov rax, -1
	ret