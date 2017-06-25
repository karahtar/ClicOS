GLOBAL systemCallReceiver

EXTERN systemCallHandler

section .text

; parameters from C are in order through registers rdi, rsi, rdx, rcx
; parameters in Linux's system calls are in rax, rbx, rcx, rdx when int 80h is executed

systemCallReceiver

	push rbp
	mov rbp, rsp

	mov rdi, rax
	mov rsi, rbx
	mov rdx, rcx
	call systemCallHandler

	mov rsp, rbp
	pop rbp
	iretq

section .bss