extern ft_strlen
extern ft_strcpy
extern malloc

section .text
	global ft_strdup

ft_strdup:
	; appel strlen
	call ft_strlen
	inc rax				; +1 pour \0
	push rdi

	; appel malloc
	mov rdi, 0
	call malloc
	test rax, rax
	jz error			; ZF == 1 donc malloc failed

	; appel strcpy
	pop rsi				; rsi = src
	mov rdi, rax		; rdi = dest
	call ft_strcpy
	ret

error:
	pop rdi
	ret