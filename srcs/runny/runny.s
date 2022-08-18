	.file	"runny.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%s:%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB73:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movq	%rsi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movl	%edi, %r12d
	movl	$50331648, %edi
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	subq	$2080, %rsp
	.cfi_def_cfa_offset 2112
	movq	%fs:40, %rax
	movq	%rax, 2072(%rsp)
	xorl	%eax, %eax
	call	malloc@PLT
	movq	%rax, %rbp
	testq	%rax, %rax
	je	.L4
	movl	%r12d, %esi
	movq	%rsp, %rdi
	movq	%r13, %rdx
	xorl	%r12d, %r12d
	call	parser@PLT
	movq	stderr(%rip), %rdi
	xorl	%eax, %eax
	movl	$36, %r8d
	leaq	__func__.5923(%rip), %rcx
	leaq	.LC0(%rip), %rdx
	movl	$1, %esi
	call	__fprintf_chk@PLT
.L2:
	movq	%rbp, %rdi
	call	free@PLT
	movq	2072(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L7
	addq	$2080, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	movl	%r12d, %eax
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	orl	$-1, %r12d
	jmp	.L2
.L7:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE73:
	.size	main, .-main
	.section	.rodata
	.type	__func__.5923, @object
	.size	__func__.5923, 5
__func__.5923:
	.string	"main"
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
