section .text
	global ft_strcmp

ft_strcmp:
	xor rcx, rcx

loop:
	mov al, byte [rdi + rcx]
	mov dl, byte [rsi + rcx]
	cmp al, dl
	jne diff
	cmp al, 0
	je end
	inc rcx
	jmp loop

diff:
	movzx eax, al
	movzx edx, dl
	sub eax, edx
	ret

end:
	xor eax, eax
	ret
