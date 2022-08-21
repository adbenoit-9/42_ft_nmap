	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_exey_ctrl                      ## -- Begin function exey_ctrl
	.p2align	4, 0x90
_exey_ctrl:                             ## @exey_ctrl
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
	subq	$40, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rsi, %rbx
	movq	%rdi, %r15
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L___func__.exey_ctrl(%rip), %rdx
	leaq	L_.str.1(%rip), %r8
	xorl	%r13d, %r13d
	movl	$14, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	testq	%r15, %r15
	je	LBB0_1
## %bb.2:                               ## %.preheader44
	movl	2200(%r15), %ecx
	testl	%ecx, %ecx
	jle	LBB0_13
## %bb.3:                               ## %.preheader43.preheader
	movl	2204(%r15), %eax
	leaq	2224(%r15), %rdx
	movq	%rdx, -48(%rbp)                 ## 8-byte Spill
	xorl	%esi, %esi
	xorl	%r13d, %r13d
	movq	%rbx, -72(%rbp)                 ## 8-byte Spill
	movq	%r15, -64(%rbp)                 ## 8-byte Spill
	jmp	LBB0_4
	.p2align	4, 0x90
LBB0_11:                                ## %._crit_edge49.loopexit
                                        ##   in Loop: Header=BB0_4 Depth=1
	movl	2200(%r15), %ecx
LBB0_12:                                ## %._crit_edge49
                                        ##   in Loop: Header=BB0_4 Depth=1
	addq	$1, %rsi
	movslq	%ecx, %rdx
	addq	$647296, -48(%rbp)              ## 8-byte Folded Spill
                                        ## imm = 0x9E080
	cmpq	%rdx, %rsi
	jge	LBB0_13
LBB0_4:                                 ## %.preheader43
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_6 Depth 2
                                        ##       Child Loop BB0_8 Depth 3
	testl	%eax, %eax
	jle	LBB0_12
## %bb.5:                               ## %.preheader.preheader
                                        ##   in Loop: Header=BB0_4 Depth=1
	imulq	$647296, %rsi, %rcx             ## imm = 0x9E080
	leaq	(%r15,%rcx), %r14
	addq	$649392, %r14                   ## imm = 0x9E8B0
	movl	2208(%r15), %ecx
	movq	-48(%rbp), %rbx                 ## 8-byte Reload
	xorl	%edi, %edi
	jmp	LBB0_6
	.p2align	4, 0x90
LBB0_10:                                ## %._crit_edge
                                        ##   in Loop: Header=BB0_6 Depth=2
	addq	$1, %rdi
	movslq	%eax, %rdx
	addq	$632, %rbx                      ## imm = 0x278
	cmpq	%rdx, %rdi
	jge	LBB0_11
LBB0_6:                                 ## %.preheader
                                        ##   Parent Loop BB0_4 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB0_8 Depth 3
	testl	%ecx, %ecx
	jle	LBB0_10
## %bb.7:                               ## %.lr.ph.preheader
                                        ##   in Loop: Header=BB0_6 Depth=2
	movq	%rbx, -56(%rbp)                 ## 8-byte Spill
	xorl	%r12d, %r12d
	.p2align	4, 0x90
LBB0_8:                                 ## %.lr.ph
                                        ##   Parent Loop BB0_4 Depth=1
                                        ##     Parent Loop BB0_6 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movl	2200(%r15), %edx
	imull	%esi, %edx
	imull	%edi, %eax
	imull	%eax, %edx
	imull	%r12d, %ecx
	addl	%eax, %edx
	imull	%ecx, %edx
	addl	%r12d, %edx
	movslq	%edx, %rax
	imulq	$274877907, %rax, %rcx          ## imm = 0x10624DD3
	movq	%rcx, %rdx
	shrq	$63, %rdx
	shrq	$36, %rcx
	addl	%edx, %ecx
	imull	$250, %ecx, %ecx
	subl	%ecx, %eax
	shll	$8, %eax
	movslq	%eax, %rdx
	addq	2216(%r15), %rdx
	movq	%rdi, %r15
	movq	%r14, %rdi
	movq	%rsi, %r13
	movq	%rbx, %rsi
	callq	*-72(%rbp)                      ## 8-byte Folded Reload
	movq	%r15, %rdi
	movq	-64(%rbp), %r15                 ## 8-byte Reload
	movq	%r13, %rsi
	movl	%eax, %r13d
	addq	$1, %r12
	movslq	2208(%r15), %rcx
	movl	2204(%r15), %eax
	addq	$104, %rbx
	cmpq	%rcx, %r12
	jl	LBB0_8
## %bb.9:                               ##   in Loop: Header=BB0_6 Depth=2
	movq	-56(%rbp), %rbx                 ## 8-byte Reload
	jmp	LBB0_10
LBB0_1:
	movl	$-1, %r13d
LBB0_13:                                ## %.loopexit
	movl	%r13d, %eax
	addq	$40, %rsp
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
	.asciz	"%s:%d:%s\n"

L___func__.exey_ctrl:                   ## @__func__.exey_ctrl
	.asciz	"exey_ctrl"

L_.str.1:                               ## @.str.1
	.asciz	"mapy/exey_f.c"

.subsections_via_symbols
