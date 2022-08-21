	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_exey_wrapper                   ## -- Begin function exey_wrapper
	.p2align	4, 0x90
_exey_wrapper:                          ## @exey_wrapper
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
	movl	%r8d, %r13d
	movq	%rcx, %rbx
	movl	40(%rcx), %r8d
	testl	%r8d, %r8d
	js	LBB0_1
## %bb.2:
	movl	44(%rbx), %r8d
	testl	%r8d, %r8d
	js	LBB0_3
## %bb.6:
	movl	48(%rbx), %r8d
	testl	%r8d, %r8d
	js	LBB0_7
## %bb.8:
	movl	52(%rbx), %r8d
	testl	%r8d, %r8d
	js	LBB0_9
## %bb.10:
	movl	56(%rbx), %r8d
	testl	%r8d, %r8d
	js	LBB0_11
## %bb.12:
	movl	60(%rbx), %r8d
	testl	%r8d, %r8d
	js	LBB0_13
## %bb.14:
	movl	64(%rbx), %r8d
	testl	%r8d, %r8d
	js	LBB0_15
## %bb.16:
	movl	68(%rbx), %r8d
	testl	%r8d, %r8d
	js	LBB0_17
## %bb.18:
	movl	72(%rbx), %r8d
	testl	%r8d, %r8d
	js	LBB0_19
## %bb.20:
	movl	76(%rbx), %r8d
	movl	$1, %eax
	testl	%r8d, %r8d
	jns	LBB0_5
## %bb.21:
	movl	$9, %r12d
	jmp	LBB0_4
LBB0_1:
	xorl	%r12d, %r12d
	jmp	LBB0_4
LBB0_3:
	movl	$1, %r12d
	jmp	LBB0_4
LBB0_7:
	movl	$2, %r12d
	jmp	LBB0_4
LBB0_9:
	movl	$3, %r12d
	jmp	LBB0_4
LBB0_11:
	movl	$4, %r12d
	jmp	LBB0_4
LBB0_13:
	movl	$5, %r12d
	jmp	LBB0_4
LBB0_15:
	movl	$6, %r12d
	jmp	LBB0_4
LBB0_17:
	movl	$7, %r12d
	jmp	LBB0_4
LBB0_19:
	movl	$8, %r12d
LBB0_4:
	movl	(%rbx,%r12,4), %r9d
	movl	$-1, %eax
	cmpl	$7, %r9d
	jle	LBB0_22
LBB0_5:                                 ## %.thread
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
LBB0_22:
	andl	$2147483647, %r8d               ## imm = 0x7FFFFFFF
	movl	%r8d, 40(%rbx,%r12,4)
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	%rdi, -48(%rbp)                 ## 8-byte Spill
	movq	(%rax), %rdi
	movq	%rsi, %r14
	leaq	L_.str(%rip), %rsi
	movq	%rdx, %r15
	leaq	L___func__.exey_wrapper(%rip), %rdx
	movl	$48, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	movslq	40(%rbx,%r12,4), %rax
	leaq	__exec(%rip), %rcx
	movq	(%rcx,%rax,8), %rax
	movslq	(%rbx,%r12,4), %rcx
	movslq	%r13d, %rdi
	movq	-48(%rbp), %rdx                 ## 8-byte Reload
	addq	2216(%rdx), %rdi
	movq	(%rax,%rcx,8), %rax
	addq	$647168, %r14                   ## imm = 0x9E000
	addq	$624, %r15                      ## imm = 0x270
	addq	$92, %rbx
	movq	%r14, %rsi
	movq	%r15, %rdx
	movq	%rbx, %rcx
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	jmpq	*%rax                           ## TAILCALL
	.cfi_endproc
                                        ## -- End function
	.globl	_mapy                           ## -- Begin function mapy
	.p2align	4, 0x90
_mapy:                                  ## @mapy
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
	subq	$88, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rdi, -48(%rbp)                 ## 8-byte Spill
	testq	%rdi, %rdi
	je	LBB1_1
## %bb.2:                               ## %.preheader69
	movq	-48(%rbp), %rax                 ## 8-byte Reload
	movl	2200(%rax), %r8d
	testl	%r8d, %r8d
	jle	LBB1_3
## %bb.4:                               ## %.preheader68.preheader
	movq	-48(%rbp), %rax                 ## 8-byte Reload
	movl	2204(%rax), %ebx
	leaq	2224(%rax), %r15
	xorl	%edx, %edx
	movq	%rdx, -56(%rbp)                 ## 8-byte Spill
	xorl	%eax, %eax
	jmp	LBB1_5
	.p2align	4, 0x90
LBB1_14:                                ## %._crit_edge75.loopexit
                                        ##   in Loop: Header=BB1_5 Depth=1
	movq	-48(%rbp), %rcx                 ## 8-byte Reload
	movl	2200(%rcx), %r8d
	movq	-80(%rbp), %r15                 ## 8-byte Reload
LBB1_15:                                ## %._crit_edge75
                                        ##   in Loop: Header=BB1_5 Depth=1
	movq	-56(%rbp), %rcx                 ## 8-byte Reload
	addq	$1, %rcx
	movslq	%r8d, %rdx
	addq	$647296, %r15                   ## imm = 0x9E080
	movq	%rcx, %rdi
	movq	%rcx, -56(%rbp)                 ## 8-byte Spill
	cmpq	%rdx, %rcx
	jge	LBB1_16
LBB1_5:                                 ## %.preheader68
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_7 Depth 2
                                        ##       Child Loop BB1_9 Depth 3
	testl	%ebx, %ebx
	jle	LBB1_15
## %bb.6:                               ## %.preheader.preheader
                                        ##   in Loop: Header=BB1_5 Depth=1
	movq	-56(%rbp), %rdx                 ## 8-byte Reload
	imulq	$647296, %rdx, %rcx             ## imm = 0x9E080
	movq	%rcx, -88(%rbp)                 ## 8-byte Spill
	movq	-48(%rbp), %rdi                 ## 8-byte Reload
	addq	%rdi, %rcx
	addq	$2224, %rcx                     ## imm = 0x8B0
	movq	%rcx, -104(%rbp)                ## 8-byte Spill
	movl	2208(%rdi), %ecx
	movq	%r15, -80(%rbp)                 ## 8-byte Spill
	movq	%rdx, -72(%rbp)                 ## 8-byte Spill
	xorl	%edx, %edx
	movq	%rdx, -64(%rbp)                 ## 8-byte Spill
	jmp	LBB1_7
	.p2align	4, 0x90
LBB1_12:                                ## %._crit_edge.loopexit
                                        ##   in Loop: Header=BB1_7 Depth=2
	movl	%ebx, %eax
	movq	-48(%rbp), %rdx                 ## 8-byte Reload
	movl	2204(%rdx), %ebx
	movq	-96(%rbp), %r15                 ## 8-byte Reload
LBB1_13:                                ## %._crit_edge
                                        ##   in Loop: Header=BB1_7 Depth=2
	movq	-64(%rbp), %rdi                 ## 8-byte Reload
	addq	$1, %rdi
	movslq	%ebx, %rdx
	addq	$1, -72(%rbp)                   ## 8-byte Folded Spill
	addq	$632, %r15                      ## imm = 0x278
	movq	%rdi, %rsi
	movq	%rdi, -64(%rbp)                 ## 8-byte Spill
	cmpq	%rdx, %rdi
	jge	LBB1_14
LBB1_7:                                 ## %.preheader
                                        ##   Parent Loop BB1_5 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB1_9 Depth 3
	testl	%ecx, %ecx
	jle	LBB1_13
## %bb.8:                               ## %.lr.ph.preheader
                                        ##   in Loop: Header=BB1_7 Depth=2
	movq	-88(%rbp), %rax                 ## 8-byte Reload
	movq	-48(%rbp), %rcx                 ## 8-byte Reload
	addq	%rcx, %rax
	imulq	$632, -64(%rbp), %rcx           ## 8-byte Folded Reload
                                        ## imm = 0x278
	addq	%rcx, %rax
	addq	$2224, %rax                     ## imm = 0x8B0
	movq	%rax, -112(%rbp)                ## 8-byte Spill
	movq	%r15, -96(%rbp)                 ## 8-byte Spill
	xorl	%r13d, %r13d
	jmp	LBB1_9
	.p2align	4, 0x90
LBB1_11:                                ##   in Loop: Header=BB1_9 Depth=3
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movl	%r13d, (%rsp)
	leaq	L_.str.2(%rip), %rsi
	leaq	L___func__.mapy(%rip), %rdx
	movl	$86, %ecx
	movq	-56(%rbp), %r14                 ## 8-byte Reload
	movl	%r14d, %r8d
	movq	-64(%rbp), %r12                 ## 8-byte Reload
	movl	%r12d, %r9d
	xorl	%eax, %eax
	callq	_fprintf
	movq	-48(%rbp), %rdx                 ## 8-byte Reload
	movl	2200(%rdx), %eax
	imull	%r14d, %eax
	movl	2204(%rdx), %ecx
	imull	%r12d, %ecx
	imull	%ecx, %eax
	movl	2208(%rdx), %edx
	imull	%r13d, %edx
	addl	%ecx, %eax
	imull	%edx, %eax
	addl	%r13d, %eax
	movslq	%eax, %rbx
	imulq	$274877907, %rbx, %rax          ## imm = 0x10624DD3
	movq	%rax, %rcx
	shrq	$63, %rcx
	shrq	$36, %rax
	addl	%ecx, %eax
	imull	$250, %eax, %eax
	subl	%eax, %ebx
	shll	$8, %ebx
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movl	%r13d, (%rsp)
	leaq	L_.str.2(%rip), %rsi
	leaq	L___func__.mapy(%rip), %rdx
	movl	$91, %ecx
	movl	%r14d, %r8d
	movl	%r12d, %r9d
	xorl	%eax, %eax
	callq	_fprintf
	movq	-48(%rbp), %rdi                 ## 8-byte Reload
	movq	-104(%rbp), %rsi                ## 8-byte Reload
	movq	-112(%rbp), %rdx                ## 8-byte Reload
	movq	%r15, %rcx
	movl	%ebx, %r8d
	callq	_exey_wrapper
	movl	%eax, %ebx
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movl	%r13d, (%rsp)
	leaq	L_.str.2(%rip), %rsi
	leaq	L___func__.mapy(%rip), %rdx
	movl	$96, %ecx
	movl	%r14d, %r8d
	movl	%r12d, %r9d
	xorl	%eax, %eax
	callq	_fprintf
	addq	$1, %r13
	movq	-48(%rbp), %rax                 ## 8-byte Reload
	movslq	2208(%rax), %rcx
	addq	$104, %r15
	cmpq	%rcx, %r13
	jge	LBB1_12
LBB1_9:                                 ## %.lr.ph
                                        ##   Parent Loop BB1_5 Depth=1
                                        ##     Parent Loop BB1_7 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	cmpb	$0, 80(%r15)
	jne	LBB1_11
## %bb.10:                              ##   in Loop: Header=BB1_9 Depth=3
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	leaq	L_.str.1(%rip), %rsi
	leaq	L___func__.mapy(%rip), %rdx
	movl	$82, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	movb	$1, 80(%r15)
	movq	-72(%rbp), %rax                 ## 8-byte Reload
	addl	%r13d, %eax
	movl	%eax, 88(%r15)
	jmp	LBB1_11
LBB1_1:
	movl	$-1, %eax
	jmp	LBB1_16
LBB1_3:
	xorl	%eax, %eax
LBB1_16:                                ## %.loopexit
	addq	$88, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_mapy_f                         ## -- Begin function mapy_f
	.p2align	4, 0x90
_mapy_f:                                ## @mapy_f
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
	subq	$56, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rsi, %r14
	movq	%rdi, %r15
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	leaq	L_.str.3(%rip), %rsi
	leaq	L___func__.mapy_f(%rip), %rdx
	leaq	L_.str.4(%rip), %r8
	xorl	%ebx, %ebx
	movl	$118, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	testq	%r15, %r15
	je	LBB2_1
## %bb.2:                               ## %.preheader49
	movl	2200(%r15), %ecx
	testl	%ecx, %ecx
	jle	LBB2_13
## %bb.3:                               ## %.preheader48.preheader
	movl	2204(%r15), %eax
	leaq	2316(%r15), %rdx
	movq	%rdx, -48(%rbp)                 ## 8-byte Spill
	xorl	%edi, %edi
	xorl	%ebx, %ebx
	movq	%r14, -72(%rbp)                 ## 8-byte Spill
	jmp	LBB2_4
	.p2align	4, 0x90
LBB2_11:                                ## %._crit_edge54.loopexit
                                        ##   in Loop: Header=BB2_4 Depth=1
	movl	2200(%r15), %ecx
LBB2_12:                                ## %._crit_edge54
                                        ##   in Loop: Header=BB2_4 Depth=1
	addq	$1, %rdi
	movslq	%ecx, %rdx
	addq	$647296, -48(%rbp)              ## 8-byte Folded Spill
                                        ## imm = 0x9E080
	cmpq	%rdx, %rdi
	jge	LBB2_13
LBB2_4:                                 ## %.preheader48
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB2_6 Depth 2
                                        ##       Child Loop BB2_8 Depth 3
	testl	%eax, %eax
	jle	LBB2_12
## %bb.5:                               ## %.preheader.preheader
                                        ##   in Loop: Header=BB2_4 Depth=1
	imulq	$647296, %rdi, %rcx             ## imm = 0x9E080
	movq	%rcx, -56(%rbp)                 ## 8-byte Spill
	leaq	(%r15,%rcx), %r13
	addq	$649392, %r13                   ## imm = 0x9E8B0
	movl	2208(%r15), %ecx
	movq	-48(%rbp), %r8                  ## 8-byte Reload
	xorl	%r9d, %r9d
	movq	%rdi, -80(%rbp)                 ## 8-byte Spill
	jmp	LBB2_6
	.p2align	4, 0x90
LBB2_10:                                ## %._crit_edge
                                        ##   in Loop: Header=BB2_6 Depth=2
	addq	$1, %r9
	movslq	%eax, %rdx
	addq	$632, %r8                       ## imm = 0x278
	cmpq	%rdx, %r9
	jge	LBB2_11
LBB2_6:                                 ## %.preheader
                                        ##   Parent Loop BB2_4 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB2_8 Depth 3
	testl	%ecx, %ecx
	jle	LBB2_10
## %bb.7:                               ## %.lr.ph.preheader
                                        ##   in Loop: Header=BB2_6 Depth=2
	movq	-56(%rbp), %rdx                 ## 8-byte Reload
	addq	%r15, %rdx
	imulq	$632, %r9, %rbx                 ## imm = 0x278
	addq	%rbx, %rdx
	addq	$2848, %rdx                     ## imm = 0xB20
	movq	%rdx, -88(%rbp)                 ## 8-byte Spill
	movq	%r8, -64(%rbp)                  ## 8-byte Spill
	movq	%r8, %r14
	xorl	%r12d, %r12d
	.p2align	4, 0x90
LBB2_8:                                 ## %.lr.ph
                                        ##   Parent Loop BB2_4 Depth=1
                                        ##     Parent Loop BB2_6 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movl	2200(%r15), %edx
	imull	%edi, %edx
	imull	%r9d, %eax
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
	orl	$4, %eax
	movslq	%eax, %rdi
	addq	2216(%r15), %rdi
	movq	%r13, %rsi
	movq	-88(%rbp), %rdx                 ## 8-byte Reload
	movq	%r14, %rcx
	movq	%r15, %rbx
	movq	%r9, %r15
	callq	*-72(%rbp)                      ## 8-byte Folded Reload
	movq	%r15, %r9
	movq	%rbx, %r15
	movq	-80(%rbp), %rdi                 ## 8-byte Reload
	movl	%eax, %ebx
	addq	$1, %r12
	movslq	2208(%r15), %rcx
	movl	2204(%r15), %eax
	addq	$104, %r14
	cmpq	%rcx, %r12
	jl	LBB2_8
## %bb.9:                               ##   in Loop: Header=BB2_6 Depth=2
	movq	-64(%rbp), %r8                  ## 8-byte Reload
	jmp	LBB2_10
LBB2_1:
	movl	$-1, %ebx
LBB2_13:                                ## %.loopexit
	movl	%ebx, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	__buildy_exec                   ## @_buildy_exec
	.p2align	4
__buildy_exec:
	.quad	_build_ipv4_tcp
	.quad	0
	.quad	0
	.quad	0
	.quad	0
	.quad	0
	.quad	0
	.quad	0

	.globl	__exec                          ## @_exec
	.p2align	4
__exec:
	.quad	__buildy_exec
	.quad	0
	.quad	0
	.quad	0
	.quad	0
	.quad	0
	.quad	0
	.quad	0

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%s:%d task=%d hook=%d \n"

L___func__.exey_wrapper:                ## @__func__.exey_wrapper
	.asciz	"exey_wrapper"

L_.str.1:                               ## @.str.1
	.asciz	"%s:%d\n"

L___func__.mapy:                        ## @__func__.mapy
	.asciz	"mapy"

L_.str.2:                               ## @.str.2
	.asciz	"%s:%d i=%d j=%d k=%d\n"

L_.str.3:                               ## @.str.3
	.asciz	"%s:%d:%s\n"

L___func__.mapy_f:                      ## @__func__.mapy_f
	.asciz	"mapy_f"

L_.str.4:                               ## @.str.4
	.asciz	"mapy/mapy.c"

.subsections_via_symbols
