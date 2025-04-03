section .text
	global ft_strcpy

ft_strcpy:
	xor rax, rax

loop:
	cmp [rsi + rax], 0
	je end
	mov [rdi + rax], [rsi + rax]
	inc rax
	jmp loop

end:
	mov [rdi + rax], 0
	ret