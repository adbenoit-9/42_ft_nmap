	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_set_rd                         ## -- Begin function set_rd
	.p2align	4, 0x90
_set_rd:                                ## @set_rd
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
	movq	%rsi, -88(%rbp)                 ## 8-byte Spill
	cmpl	$0, 2200(%rdi)
	jle	LBB0_1
## %bb.2:                               ## %.preheader35.preheader
	movq	%rdi, %rbx
	leaq	2316(%rdi), %rdx
	xorl	%esi, %esi
LBB0_3:                                 ## %.preheader35
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_5 Depth 2
                                        ##       Child Loop BB0_6 Depth 3
	cmpl	$0, 2204(%rbx)
	jle	LBB0_9
## %bb.4:                               ## %.preheader.preheader
                                        ##   in Loop: Header=BB0_3 Depth=1
	imulq	$647296, %rsi, %rax             ## imm = 0x9E080
	leaq	(%rbx,%rax), %rcx
	addq	$649392, %rcx                   ## imm = 0x9E8B0
	movq	%rcx, -80(%rbp)                 ## 8-byte Spill
	movq	%rdx, %r15
	xorl	%ecx, %ecx
	movq	%rdx, -64(%rbp)                 ## 8-byte Spill
	movq	%rsi, -56(%rbp)                 ## 8-byte Spill
	movq	%rax, -48(%rbp)                 ## 8-byte Spill
LBB0_5:                                 ## %.preheader
                                        ##   Parent Loop BB0_3 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB0_6 Depth 3
	addq	%rbx, %rax
	movq	%rcx, -72(%rbp)                 ## 8-byte Spill
	imulq	$632, %rcx, %rcx                ## imm = 0x278
	leaq	(%rcx,%rax), %r12
	addq	$2848, %r12                     ## imm = 0xB20
	movq	$-1, %r13
	movq	%r15, %rcx
	.p2align	4, 0x90
LBB0_6:                                 ##   Parent Loop BB0_3 Depth=1
                                        ##     Parent Loop BB0_5 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movslq	2208(%rbx), %rax
	addq	$1, %r13
	cmpq	%rax, %r13
	jge	LBB0_8
## %bb.7:                               ##   in Loop: Header=BB0_6 Depth=3
	leaq	104(%rcx), %r14
	movq	%rbx, %rdi
	movq	-80(%rbp), %rsi                 ## 8-byte Reload
	movq	%r12, %rdx
	callq	*-88(%rbp)                      ## 8-byte Folded Reload
	movq	%r14, %rcx
	testl	%eax, %eax
	je	LBB0_6
	jmp	LBB0_10
	.p2align	4, 0x90
LBB0_8:                                 ## %.critedge2
                                        ##   in Loop: Header=BB0_5 Depth=2
	movq	-72(%rbp), %rcx                 ## 8-byte Reload
	addq	$1, %rcx
	movslq	2204(%rbx), %rax
	addq	$632, %r15                      ## imm = 0x278
	cmpq	%rax, %rcx
	movq	-64(%rbp), %rdx                 ## 8-byte Reload
	movq	-56(%rbp), %rsi                 ## 8-byte Reload
	movq	-48(%rbp), %rax                 ## 8-byte Reload
	jl	LBB0_5
	.p2align	4, 0x90
LBB0_9:                                 ## %.critedge1
                                        ##   in Loop: Header=BB0_3 Depth=1
	addq	$1, %rsi
	movslq	2200(%rbx), %rcx
	addq	$647296, %rdx                   ## imm = 0x9E080
	xorl	%eax, %eax
	cmpq	%rcx, %rsi
	jl	LBB0_3
	jmp	LBB0_10
LBB0_1:
	xorl	%eax, %eax
LBB0_10:                                ## %.critedge
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
	.globl	_set_nd                         ## -- Begin function set_nd
	.p2align	4, 0x90
_set_nd:                                ## @set_nd
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
	subq	$24, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	cmpl	$0, 2200(%rdi)
	jle	LBB1_6
## %bb.1:                               ## %.preheader.preheader
	movq	%rsi, %r14
	movq	%rdi, %rbx
	leaq	2848(%rdi), %rdx
	xorl	%ecx, %ecx
LBB1_2:                                 ## %.preheader
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
	movq	%rcx, -48(%rbp)                 ## 8-byte Spill
	imulq	$647296, %rcx, %rax             ## imm = 0x9E080
	leaq	(%rbx,%rax), %r15
	addq	$649392, %r15                   ## imm = 0x9E8B0
	movq	$-1, %r12
	movq	%rdx, -56(%rbp)                 ## 8-byte Spill
	.p2align	4, 0x90
LBB1_3:                                 ##   Parent Loop BB1_2 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movslq	2204(%rbx), %rax
	addq	$1, %r12
	cmpq	%rax, %r12
	jge	LBB1_5
## %bb.4:                               ##   in Loop: Header=BB1_3 Depth=2
	leaq	632(%rdx), %r13
	movq	%rbx, %rdi
	movq	%r15, %rsi
	callq	*%r14
	movq	%r13, %rdx
	testl	%eax, %eax
	je	LBB1_3
	jmp	LBB1_7
	.p2align	4, 0x90
LBB1_5:                                 ## %.critedge1
                                        ##   in Loop: Header=BB1_2 Depth=1
	movq	-48(%rbp), %rcx                 ## 8-byte Reload
	addq	$1, %rcx
	movslq	2200(%rbx), %rax
	movq	-56(%rbp), %rdx                 ## 8-byte Reload
	addq	$647296, %rdx                   ## imm = 0x9E080
	cmpq	%rax, %rcx
	jl	LBB1_2
LBB1_6:
	xorl	%eax, %eax
LBB1_7:                                 ## %.critedge
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_set_st                         ## -- Begin function set_st
	.p2align	4, 0x90
_set_st:                                ## @set_st
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	.cfi_offset %rbx, -48
	.cfi_offset %r12, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rsi, %r14
	movq	%rdi, %r15
	leaq	649392(%rdi), %rsi
	movq	$-1, %rbx
	.p2align	4, 0x90
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movslq	2200(%r15), %rax
	addq	$1, %rbx
	cmpq	%rax, %rbx
	jge	LBB2_2
## %bb.3:                               ##   in Loop: Header=BB2_1 Depth=1
	leaq	647296(%rsi), %r12
	movq	%r15, %rdi
	callq	*%r14
	movq	%r12, %rsi
	testl	%eax, %eax
	je	LBB2_1
	jmp	LBB2_4
LBB2_2:
	xorl	%eax, %eax
LBB2_4:                                 ## %.critedge
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
