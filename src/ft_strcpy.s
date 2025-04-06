section .text
	global ft_strcpy

ft_strcpy:
	xor rcx, rcx

loop:
	mov al, byte [rsi + rcx]
	mov [rdi + rcx], al
	cmp al, 0
	je end
	inc rcx
	jmp loop

end:
	mov rax, rdi
	ret