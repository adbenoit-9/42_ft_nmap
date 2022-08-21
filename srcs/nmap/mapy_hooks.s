	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_print_all                      ## -- Begin function print_all
	.p2align	4, 0x90
_print_all:                             ## @print_all
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rcx, %r14
	movq	%rdi, %r13
	movq	___stderrp@GOTPCREL(%rip), %r12
	movq	(%r12), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L___func__.print_all(%rip), %rdx
	movl	$23, %ecx
	movq	%r13, %r8
	xorl	%eax, %eax
	callq	_fprintf
	cmpl	$0, (%r14)
	jle	LBB0_5
## %bb.1:                               ## %.lr.ph.preheader
	leaq	L_.str.2(%rip), %r15
	xorl	%ebx, %ebx
	jmp	LBB0_2
	.p2align	4, 0x90
LBB0_4:                                 ##   in Loop: Header=BB0_2 Depth=1
	movq	(%r12), %rdi
	movzbl	(%r13,%rbx), %edx
	addq	$1, %rbx
	movq	%r15, %rsi
	xorl	%eax, %eax
	callq	_fprintf
	movslq	(%r14), %rax
	cmpq	%rax, %rbx
	jge	LBB0_5
LBB0_2:                                 ## %.lr.ph
                                        ## =>This Inner Loop Header: Depth=1
	testb	$31, %bl
	jne	LBB0_4
## %bb.3:                               ##   in Loop: Header=BB0_2 Depth=1
	movq	(%r12), %rsi
	movl	$10, %edi
	callq	_fputc
	jmp	LBB0_4
LBB0_5:                                 ## %._crit_edge
	movq	(%r12), %rcx
	leaq	L_.str.3(%rip), %rdi
	movl	$2, %esi
	movl	$1, %edx
	callq	_fwrite
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%s:%d buf=%p\n\n"

L___func__.print_all:                   ## @__func__.print_all
	.asciz	"print_all"

L_.str.2:                               ## @.str.2
	.asciz	"%02x."

L_.str.3:                               ## @.str.3
	.asciz	"\n\n"

.subsections_via_symbols
