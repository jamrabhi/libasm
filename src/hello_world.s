section .data
	message db "Hello, World!",10
	message_len equ $ - message

section .text
	global hello_world

hello_world:
	mov rax, 1
	mov rdi, 1
	mov rsi, message
	mov rdx, message_len
	syscall