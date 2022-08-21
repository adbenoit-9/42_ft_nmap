	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_set_sockaddr                   ## -- Begin function set_sockaddr
	.p2align	4, 0x90
_set_sockaddr:                          ## @set_sockaddr
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	subq	$64, %rsp
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	xorps	%xmm0, %xmm0
	movaps	%xmm0, -48(%rbp)
	movaps	%xmm0, -64(%rbp)
	movaps	%xmm0, -80(%rbp)
	movq	$0, -24(%rbp)
	movl	$-1, %ebx
	testq	%rdi, %rdi
	je	LBB0_4
## %bb.1:
	movq	%rsi, %r14
	testq	%rsi, %rsi
	je	LBB0_4
## %bb.2:
	xorps	%xmm0, %xmm0
	movaps	%xmm0, -48(%rbp)
	movaps	%xmm0, -64(%rbp)
	movaps	%xmm0, -80(%rbp)
	leaq	L_.str(%rip), %rdi
	leaq	-80(%rbp), %rdx
	leaq	-24(%rbp), %rcx
	xorl	%esi, %esi
	callq	_getaddrinfo
	testl	%eax, %eax
	jne	LBB0_4
## %bb.3:
	movq	-24(%rbp), %rdi
	movq	32(%rdi), %rax
	movups	112(%rax), %xmm0
	movups	%xmm0, 112(%r14)
	movups	96(%rax), %xmm0
	movups	%xmm0, 96(%r14)
	movups	80(%rax), %xmm0
	movups	%xmm0, 80(%r14)
	movups	64(%rax), %xmm0
	movups	%xmm0, 64(%r14)
	movups	(%rax), %xmm0
	movups	16(%rax), %xmm1
	movups	32(%rax), %xmm2
	movups	48(%rax), %xmm3
	movups	%xmm3, 48(%r14)
	movups	%xmm2, 32(%r14)
	movups	%xmm1, 16(%r14)
	movups	%xmm0, (%r14)
	callq	_freeaddrinfo
	xorl	%ebx, %ebx
LBB0_4:
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	leaq	L_.str.1(%rip), %rsi
	leaq	L___func__.set_sockaddr(%rip), %rdx
	movl	$52, %ecx
	movl	%ebx, %r8d
	xorl	%eax, %eax
	callq	_fprintf
	movl	%ebx, %eax
	addq	$64, %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_set_port                       ## -- Begin function set_port
	.p2align	4, 0x90
_set_port:                              ## @set_port
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movw	$4242, 4(%rdx)                  ## imm = 0x1092
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	leaq	L_.str.2(%rip), %rsi
	leaq	L___func__.set_port(%rip), %rdx
	movl	$62, %ecx
	xorl	%eax, %eax
	callq	_fprintf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_set_socket                     ## -- Begin function set_socket
	.p2align	4, 0x90
_set_socket:                            ## @set_socket
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	movl	$1, -20(%rbp)
	movl	$-1, %ebx
	testq	%rdi, %rdi
	je	LBB2_5
## %bb.1:
	testq	%rsi, %rsi
	je	LBB2_5
## %bb.2:
	movq	%rdx, %r14
	testq	%rdx, %rdx
	je	LBB2_5
## %bb.3:
	movl	$2, %edi
	movl	$3, %esi
	movl	$6, %edx
	callq	_socket
	movl	%eax, (%r14)
	testl	%eax, %eax
	js	LBB2_5
## %bb.4:
	leaq	-20(%rbp), %rcx
	movl	%eax, %edi
	xorl	%esi, %esi
	movl	$2, %edx
	movl	$4, %r8d
	callq	_setsockopt
	movl	%eax, %ebx
	sarl	$31, %ebx
LBB2_5:
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	leaq	L_.str.1(%rip), %rsi
	leaq	L___func__.set_socket(%rip), %rdx
	movl	$91, %ecx
	movl	%ebx, %r8d
	xorl	%eax, %eax
	callq	_fprintf
	movl	%ebx, %eax
	addq	$16, %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_set_tcpflag                    ## -- Begin function set_tcpflag
	.p2align	4, 0x90
_set_tcpflag:                           ## @set_tcpflag
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movb	$2, 4(%rcx)
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"localhost"

L_.str.1:                               ## @.str.1
	.asciz	"%s:%d r=%d\n"

L___func__.set_sockaddr:                ## @__func__.set_sockaddr
	.asciz	"set_sockaddr"

L_.str.2:                               ## @.str.2
	.asciz	"%s:%d\n"

L___func__.set_port:                    ## @__func__.set_port
	.asciz	"set_port"

L___func__.set_socket:                  ## @__func__.set_socket
	.asciz	"set_socket"

.subsections_via_symbols
