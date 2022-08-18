	.file	"setupy_ipv4_udp.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"%s:%d socket call failed, are you root ?\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"setsockopt"
	.text
	.p2align 4
	.globl	setup_ipv4_udp
	.type	setup_ipv4_udp, @function
setup_ipv4_udp:
.LFB76:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdx, %r8
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	testq	%rsi, %rsi
	movl	$1, 4(%rsp)
	sete	%dl
	testq	%r8, %r8
	sete	%al
	orb	%al, %dl
	jne	.L6
	testq	%rdi, %rdi
	je	.L6
	movl	$2, %edi
	movl	$6, %edx
	movl	$3, %esi
	movq	%rcx, %rbx
	call	socket@PLT
	movl	%eax, 36(%rbx)
	movl	%eax, %edi
	testl	%eax, %eax
	js	.L3
	xorl	%esi, %esi
	leaq	4(%rsp), %rcx
	movl	$4, %r8d
	movl	$3, %edx
	call	setsockopt@PLT
	testl	%eax, %eax
	js	.L4
	xorl	%eax, %eax
.L1:
	movq	8(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L9
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	.cfi_restore_state
	movl	$-1, %eax
	jmp	.L1
	.p2align 4,,10
	.p2align 3
.L3:
	movq	stderr(%rip), %rdi
	movl	$32, %r8d
	xorl	%eax, %eax
	leaq	__func__.5350(%rip), %rcx
	leaq	.LC0(%rip), %rdx
	movl	$1, %esi
	call	__fprintf_chk@PLT
	movl	$-1, %eax
	jmp	.L1
.L4:
	leaq	.LC1(%rip), %rdi
	call	perror@PLT
	movl	$-1, %eax
	jmp	.L1
.L9:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE76:
	.size	setup_ipv4_udp, .-setup_ipv4_udp
	.section	.rodata
	.align 8
	.type	__func__.5350, @object
	.size	__func__.5350, 15
__func__.5350:
	.string	"setup_ipv4_udp"
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
