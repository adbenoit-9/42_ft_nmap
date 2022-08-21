	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
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
	movl	$23790232, %edi                 ## imm = 0x16B0298
	callq	_malloc
	movq	%rax, %r12
	movq	___stderrp@GOTPCREL(%rip), %r13
	movq	(%r13), %rdi
	leaq	L_.str(%rip), %rsi
	leaq	L_.str.1(%rip), %rdx
	leaq	L_.str.2(%rip), %rcx
	leaq	L_.str.3(%rip), %r8
	leaq	L_.str.4(%rip), %r9
	xorl	%eax, %eax
	pushq	$8
	pushq	$8
	pushq	$8
	pushq	$8
	pushq	$8
	pushq	$-2147483648                    ## imm = 0x80000000
	pushq	$10
	pushq	$6
	pushq	$1024                           ## imm = 0x400
	pushq	$16
	pushq	$23790232                       ## imm = 0x16B0298
	pushq	$256                            ## imm = 0x100
	pushq	$250
	pushq	$250
	callq	_fprintf
	addq	$112, %rsp
	movl	$-1, %r14d
	testq	%r12, %r12
	je	LBB0_13
## %bb.1:
	movq	(%r13), %rdi
	leaq	L_.str.5(%rip), %rsi
	leaq	L___func__.main(%rip), %r15
	movl	$10358960, %r8d                 ## imm = 0x9E10B0
	movq	%r15, %rdx
	movl	$52, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	movq	(%r13), %rdi
	leaq	L_.str.6(%rip), %rsi
	movq	%r15, %rdx
	movl	$53, %ecx
	movq	%r12, %r8
	xorl	%eax, %eax
	callq	_fprintf
	movq	(%r13), %rdi
	leaq	10358960(%r12), %rbx
	leaq	L_.str.7(%rip), %rsi
	movq	%r15, %rdx
	movl	$54, %ecx
	movq	%rbx, %r8
	xorl	%eax, %eax
	callq	_fprintf
	movq	(%r13), %rdi
	movq	%r12, %r8
	addq	$23790232, %r8                  ## imm = 0x16B0298
	leaq	L_.str.8(%rip), %rsi
	movq	%r15, %rdx
	movl	$55, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	movq	%rbx, 2216(%r12)
	movabsq	$21474836485, %rax              ## imm = 0x500000005
	movq	%rax, 2200(%r12)
	movl	$5, 2208(%r12)
	movq	_set_sockaddr@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_set_st
	testl	%eax, %eax
	jne	LBB0_13
## %bb.2:
	movq	_set_port@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_set_nd
	testl	%eax, %eax
	jne	LBB0_13
## %bb.3:
	movq	_set_socket@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_set_nd
	testl	%eax, %eax
	jne	LBB0_13
## %bb.4:
	movq	_set_tcpflag@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_set_rd
	testl	%eax, %eax
	jne	LBB0_13
## %bb.5:
	movq	_print_st@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_set_st
	testl	%eax, %eax
	jne	LBB0_13
## %bb.6:
	movq	_print_nd@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_set_nd
	testl	%eax, %eax
	jne	LBB0_13
## %bb.7:
	movq	_print_rd@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_set_rd
	testl	%eax, %eax
	jne	LBB0_13
## %bb.8:
	movq	_build_ipv4_tcp@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_mapy_f
	testl	%eax, %eax
	jne	LBB0_13
## %bb.9:
	movq	(%r13), %rdi
	leaq	L_.str.9(%rip), %rsi
	leaq	L___func__.main(%rip), %rdx
	movl	$84, %ecx
	xorl	%r8d, %r8d
	xorl	%eax, %eax
	callq	_fprintf
	movq	_send_ipv4_tcp@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_mapy_f
	testl	%eax, %eax
	jne	LBB0_13
## %bb.10:
	movq	(%r13), %rdi
	leaq	L_.str.9(%rip), %rsi
	leaq	L___func__.main(%rip), %rdx
	movl	$87, %ecx
	xorl	%r8d, %r8d
	xorl	%eax, %eax
	callq	_fprintf
	movq	_clean_net@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_set_nd
	testl	%eax, %eax
	jne	LBB0_13
## %bb.11:
	movq	(%r13), %rdi
	leaq	L_.str.9(%rip), %rsi
	leaq	L___func__.main(%rip), %rdx
	movl	$90, %ecx
	xorl	%r8d, %r8d
	xorl	%eax, %eax
	callq	_fprintf
	movq	_print_all@GOTPCREL(%rip), %rsi
	movq	%r12, %rdi
	callq	_mapy_f
	testl	%eax, %eax
	jne	LBB0_13
## %bb.12:
	movq	(%r13), %rdi
	leaq	L_.str.9(%rip), %rsi
	leaq	L___func__.main(%rip), %rbx
	movq	%rbx, %rdx
	movl	$100, %ecx
	xorl	%r8d, %r8d
	xorl	%eax, %eax
	callq	_fprintf
	movq	(%r13), %rdi
	leaq	L_.str.10(%rip), %rsi
	movq	%rbx, %rdx
	movl	$105, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	xorl	%r14d, %r14d
LBB0_13:
	movl	%r14d, %eax
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
	.asciz	"Hello\na=%s b=%s c=%s  d=%s e=%d f=%d g=%d h=%d  i=%d j=%d k=%d l=%d m=%d n=%d o=%d p=%d q=%d r=%d \n"

L_.str.1:                               ## @.str.1
	.asciz	"test_root"

L_.str.2:                               ## @.str.2
	.asciz	"test_st"

L_.str.3:                               ## @.str.3
	.asciz	"test_nd"

L_.str.4:                               ## @.str.4
	.asciz	"test_rd"

L_.str.5:                               ## @.str.5
	.asciz	"%s:%d configsize=%lx\n"

L___func__.main:                        ## @__func__.main
	.asciz	"main"

L_.str.6:                               ## @.str.6
	.asciz	"%s:%d bufferptr=%p\n"

L_.str.7:                               ## @.str.7
	.asciz	"%s:%d mapptr=%p\n"

L_.str.8:                               ## @.str.8
	.asciz	"%s:%d limit_buffer=%p\n"

L_.str.9:                               ## @.str.9
	.asciz	"%s:%d r = %d"

L_.str.10:                              ## @.str.10
	.asciz	"%s:%d\n"

.subsections_via_symbols
