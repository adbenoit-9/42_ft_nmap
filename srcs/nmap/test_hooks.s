	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_print_st                       ## -- Begin function print_st
	.p2align	4, 0x90
_print_st:                              ## @print_st
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movzbl	1(%rsi), %r8d
	leaq	L_.str(%rip), %rsi
	leaq	L___func__.print_st(%rip), %rdx
	movl	$8, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_print_nd                       ## -- Begin function print_nd
	.p2align	4, 0x90
_print_nd:                              ## @print_nd
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rdx, %rbx
	movq	___stderrp@GOTPCREL(%rip), %r15
	movq	(%r15), %rdi
	movl	(%rdx), %r8d
	leaq	L_.str.1(%rip), %rsi
	leaq	L___func__.print_nd(%rip), %r14
	movq	%r14, %rdx
	movl	$18, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	movq	(%r15), %rdi
	movzwl	4(%rbx), %r8d
	leaq	L_.str.2(%rip), %rsi
	movq	%r14, %rdx
	movl	$20, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_print_rd                       ## -- Begin function print_rd
	.p2align	4, 0x90
_print_rd:                              ## @print_rd
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movzbl	4(%rcx), %r8d
	leaq	L_.str.3(%rip), %rsi
	leaq	L___func__.print_rd(%rip), %rdx
	movl	$31, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%s:%d link->sock.ss_family = %08x\n"

L___func__.print_st:                    ## @__func__.print_st
	.asciz	"print_st"

L_.str.1:                               ## @.str.1
	.asciz	"%s:%d link->socket = %08x\n"

L___func__.print_nd:                    ## @__func__.print_nd
	.asciz	"print_nd"

L_.str.2:                               ## @.str.2
	.asciz	"%s:%d link->port = %04x\n"

L_.str.3:                               ## @.str.3
	.asciz	"%s:%d link->tcpflag = %02x\n"

L___func__.print_rd:                    ## @__func__.print_rd
	.asciz	"print_rd"

.subsections_via_symbols
