	.file	"cleany.c"
	.text
	.p2align 4
	.globl	clean_net
	.type	clean_net, @function
clean_net:
.LFB72:
	.cfi_startproc
	endbr64
	movq	%rdx, %r8
	testq	%rsi, %rsi
	sete	%dl
	testq	%r8, %r8
	sete	%al
	orb	%al, %dl
	jne	.L3
	testq	%rdi, %rdi
	je	.L3
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	36(%rcx), %edi
	call	close@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L3:
	movl	$-1, %eax
	ret
	.cfi_endproc
.LFE72:
	.size	clean_net, .-clean_net
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
