	.file	"main.cpp"
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.section	.text._ZStanSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStanSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStanSt13_Ios_FmtflagsS_
	.type	_ZStanSt13_Ios_FmtflagsS_, @function
_ZStanSt13_Ios_FmtflagsS_:
.LFB1087:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	andl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1087:
	.size	_ZStanSt13_Ios_FmtflagsS_, .-_ZStanSt13_Ios_FmtflagsS_
	.section	.text._ZStorSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStorSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStorSt13_Ios_FmtflagsS_
	.type	_ZStorSt13_Ios_FmtflagsS_, @function
_ZStorSt13_Ios_FmtflagsS_:
.LFB1088:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	orl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1088:
	.size	_ZStorSt13_Ios_FmtflagsS_, .-_ZStorSt13_Ios_FmtflagsS_
	.section	.text._ZStcoSt13_Ios_Fmtflags,"axG",@progbits,_ZStcoSt13_Ios_Fmtflags,comdat
	.weak	_ZStcoSt13_Ios_Fmtflags
	.type	_ZStcoSt13_Ios_Fmtflags, @function
_ZStcoSt13_Ios_Fmtflags:
.LFB1090:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	notl	%eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1090:
	.size	_ZStcoSt13_Ios_Fmtflags, .-_ZStcoSt13_Ios_Fmtflags
	.section	.text._ZStoRRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStoRRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStoRRSt13_Ios_FmtflagsS_
	.type	_ZStoRRSt13_Ios_FmtflagsS_, @function
_ZStoRRSt13_Ios_FmtflagsS_:
.LFB1091:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStorSt13_Ios_FmtflagsS_
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1091:
	.size	_ZStoRRSt13_Ios_FmtflagsS_, .-_ZStoRRSt13_Ios_FmtflagsS_
	.section	.text._ZStaNRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStaNRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStaNRSt13_Ios_FmtflagsS_
	.type	_ZStaNRSt13_Ios_FmtflagsS_, @function
_ZStaNRSt13_Ios_FmtflagsS_:
.LFB1092:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStanSt13_Ios_FmtflagsS_
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1092:
	.size	_ZStaNRSt13_Ios_FmtflagsS_, .-_ZStaNRSt13_Ios_FmtflagsS_
	.section	.text._ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_,"axG",@progbits,_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_,comdat
	.align 2
	.weak	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	.type	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_, @function
_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_:
.LFB1121:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	24(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, %edi
	call	_ZStcoSt13_Ios_Fmtflags
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	addq	$24, %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStaNRSt13_Ios_FmtflagsS_
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStanSt13_Ios_FmtflagsS_
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	addq	$24, %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStoRRSt13_Ios_FmtflagsS_
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1121:
	.size	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_, .-_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	.section	.text._ZNSt8ios_base9precisionEl,"axG",@progbits,_ZNSt8ios_base9precisionEl,comdat
	.align 2
	.weak	_ZNSt8ios_base9precisionEl
	.type	_ZNSt8ios_base9precisionEl, @function
_ZNSt8ios_base9precisionEl:
.LFB1124:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1124:
	.size	_ZNSt8ios_base9precisionEl, .-_ZNSt8ios_base9precisionEl
	.section	.text._ZSt5fixedRSt8ios_base,"axG",@progbits,_ZSt5fixedRSt8ios_base,comdat
	.weak	_ZSt5fixedRSt8ios_base
	.type	_ZSt5fixedRSt8ios_base, @function
_ZSt5fixedRSt8ios_base:
.LFB1151:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$260, %edx
	movl	$4, %esi
	movq	%rax, %rdi
	call	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1151:
	.size	_ZSt5fixedRSt8ios_base, .-_ZSt5fixedRSt8ios_base
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.align 4
	.type	_ZL4iter, @object
	.size	_ZL4iter, 4
_ZL4iter:
	.long	10000
	.section	.text._Z5rdtscv,"axG",@progbits,_Z5rdtscv,comdat
	.weak	_Z5rdtscv
	.type	_Z5rdtscv, @function
_Z5rdtscv:
.LFB1493:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
#APP
# 8 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%eax, -8(%rbp)
	movl	%edx, -4(%rbp)
	movl	-4(%rbp), %eax
	salq	$32, %rax
	movq	%rax, %rdx
	movl	-8(%rbp), %eax
	orq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1493:
	.size	_Z5rdtscv, .-_Z5rdtscv
	.section	.rodata
.LC0:
	.string	"\b \b"
.LC2:
	.string	","
	.text
	.globl	main
	.type	main, @function
main:
.LFB1496:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$240, %rsp
	movl	%edi, -228(%rbp)
	movq	%rsi, -240(%rbp)
	movl	$5, %esi
	leaq	8+_ZSt4cout(%rip), %rdi
	call	_ZNSt8ios_base9precisionEl
	movl	$1, -224(%rbp)
	movq	-240(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, -148(%rbp)
	cmpl	$5, -148(%rbp)
	ja	.L20
	movl	-148(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L22(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	leaq	.L22(%rip), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L22:
	.long	.L21-.L22
	.long	.L23-.L22
	.long	.L24-.L22
	.long	.L25-.L22
	.long	.L26-.L22
	.long	.L27-.L22
	.text
.L21:
	movl	$1, -220(%rbp)
.L36:
	cmpl	$63, -220(%rbp)
	jg	.L98
	movq	$-1, -144(%rbp)
	movl	$0, -216(%rbp)
.L33:
	cmpl	$999, -216(%rbp)
	jg	.L29
	call	_Z5rdtscv
	movq	%rax, -16(%rbp)
	movl	$0, -212(%rbp)
.L32:
	cmpl	$9999, -212(%rbp)
	jg	.L30
	movl	-212(%rbp), %eax
	cltd
	idivl	-220(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L31
	movl	$0, -224(%rbp)
.L31:
	addl	$1, -212(%rbp)
	jmp	.L32
.L30:
	call	_Z5rdtscv
	movq	%rax, -8(%rbp)
	movl	-224(%rbp), %eax
	cltd
	shrl	$31, %edx
	addl	%edx, %eax
	andl	$1, %eax
	subl	%edx, %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	cmpq	%rax, -144(%rbp)
	cmovbe	-144(%rbp), %rax
	movq	%rax, -144(%rbp)
	addl	$1, -216(%rbp)
	jmp	.L33
.L29:
	leaq	_ZSt5fixedRSt8ios_base(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E@PLT
	movq	%rax, %rcx
	movq	-144(%rbp), %rax
	testq	%rax, %rax
	js	.L34
	cvtsi2sdq	%rax, %xmm0
	jmp	.L35
.L34:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L35:
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%rcx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -220(%rbp)
	jmp	.L36
.L23:
	movl	$1, -208(%rbp)
.L46:
	cmpl	$63, -208(%rbp)
	jg	.L99
	movq	$-1, -136(%rbp)
	movl	$0, -204(%rbp)
.L43:
	cmpl	$999, -204(%rbp)
	jg	.L38
	call	_Z5rdtscv
	movq	%rax, -32(%rbp)
	movl	$0, -200(%rbp)
.L42:
	cmpl	$9999, -200(%rbp)
	jg	.L39
	cmpl	$0, -204(%rbp)
	jns	.L40
	movl	$1, -224(%rbp)
.L40:
	movl	-200(%rbp), %eax
	cltd
	idivl	-208(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L41
	movl	$0, -224(%rbp)
.L41:
	addl	$1, -200(%rbp)
	jmp	.L42
.L39:
	call	_Z5rdtscv
	movq	%rax, -24(%rbp)
	movl	-224(%rbp), %eax
	cltd
	shrl	$31, %edx
	addl	%edx, %eax
	andl	$1, %eax
	subl	%edx, %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	-24(%rbp), %rax
	subq	-32(%rbp), %rax
	cmpq	%rax, -136(%rbp)
	cmovbe	-136(%rbp), %rax
	movq	%rax, -136(%rbp)
	addl	$1, -204(%rbp)
	jmp	.L43
.L38:
	leaq	_ZSt5fixedRSt8ios_base(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E@PLT
	movq	%rax, %rcx
	movq	-136(%rbp), %rax
	testq	%rax, %rax
	js	.L44
	cvtsi2sdq	%rax, %xmm0
	jmp	.L45
.L44:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L45:
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%rcx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -208(%rbp)
	jmp	.L46
.L24:
	movl	$1, -196(%rbp)
.L57:
	cmpl	$63, -196(%rbp)
	jg	.L100
	movq	$-1, -128(%rbp)
	movl	$0, -192(%rbp)
.L54:
	cmpl	$999, -192(%rbp)
	jg	.L48
	call	_Z5rdtscv
	movq	%rax, -48(%rbp)
	movl	$0, -188(%rbp)
.L53:
	cmpl	$9999, -188(%rbp)
	jg	.L49
	cmpl	$0, -192(%rbp)
	jns	.L50
	movl	$1, -224(%rbp)
.L50:
	cmpl	$0, -192(%rbp)
	jns	.L51
	movl	$1, -224(%rbp)
.L51:
	movl	-188(%rbp), %eax
	cltd
	idivl	-196(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L52
	movl	$0, -224(%rbp)
.L52:
	addl	$1, -188(%rbp)
	jmp	.L53
.L49:
	call	_Z5rdtscv
	movq	%rax, -40(%rbp)
	movl	-224(%rbp), %eax
	cltd
	shrl	$31, %edx
	addl	%edx, %eax
	andl	$1, %eax
	subl	%edx, %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	-40(%rbp), %rax
	subq	-48(%rbp), %rax
	cmpq	%rax, -128(%rbp)
	cmovbe	-128(%rbp), %rax
	movq	%rax, -128(%rbp)
	addl	$1, -192(%rbp)
	jmp	.L54
.L48:
	leaq	_ZSt5fixedRSt8ios_base(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E@PLT
	movq	%rax, %rcx
	movq	-128(%rbp), %rax
	testq	%rax, %rax
	js	.L55
	cvtsi2sdq	%rax, %xmm0
	jmp	.L56
.L55:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L56:
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%rcx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -196(%rbp)
	jmp	.L57
.L25:
	movl	$1, -184(%rbp)
.L69:
	cmpl	$63, -184(%rbp)
	jg	.L101
	movq	$-1, -120(%rbp)
	movl	$0, -180(%rbp)
.L66:
	cmpl	$999, -180(%rbp)
	jg	.L59
	call	_Z5rdtscv
	movq	%rax, -64(%rbp)
	movl	$0, -176(%rbp)
.L65:
	cmpl	$9999, -176(%rbp)
	jg	.L60
	cmpl	$0, -180(%rbp)
	jns	.L61
	movl	$1, -224(%rbp)
.L61:
	cmpl	$0, -180(%rbp)
	jns	.L62
	movl	$1, -224(%rbp)
.L62:
	cmpl	$0, -180(%rbp)
	jns	.L63
	movl	$1, -224(%rbp)
.L63:
	movl	-176(%rbp), %eax
	cltd
	idivl	-184(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L64
	movl	$0, -224(%rbp)
.L64:
	addl	$1, -176(%rbp)
	jmp	.L65
.L60:
	call	_Z5rdtscv
	movq	%rax, -56(%rbp)
	movl	-224(%rbp), %eax
	cltd
	shrl	$31, %edx
	addl	%edx, %eax
	andl	$1, %eax
	subl	%edx, %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	-56(%rbp), %rax
	subq	-64(%rbp), %rax
	cmpq	%rax, -120(%rbp)
	cmovbe	-120(%rbp), %rax
	movq	%rax, -120(%rbp)
	addl	$1, -180(%rbp)
	jmp	.L66
.L59:
	leaq	_ZSt5fixedRSt8ios_base(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E@PLT
	movq	%rax, %rcx
	movq	-120(%rbp), %rax
	testq	%rax, %rax
	js	.L67
	cvtsi2sdq	%rax, %xmm0
	jmp	.L68
.L67:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L68:
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%rcx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -184(%rbp)
	jmp	.L69
.L26:
	movl	$1, -172(%rbp)
.L82:
	cmpl	$63, -172(%rbp)
	jg	.L102
	movq	$-1, -112(%rbp)
	movl	$0, -168(%rbp)
.L79:
	cmpl	$999, -168(%rbp)
	jg	.L71
	call	_Z5rdtscv
	movq	%rax, -80(%rbp)
	movl	$0, -164(%rbp)
.L78:
	cmpl	$9999, -164(%rbp)
	jg	.L72
	cmpl	$0, -168(%rbp)
	jns	.L73
	movl	$1, -224(%rbp)
.L73:
	cmpl	$0, -168(%rbp)
	jns	.L74
	movl	$1, -224(%rbp)
.L74:
	cmpl	$0, -168(%rbp)
	jns	.L75
	movl	$1, -224(%rbp)
.L75:
	cmpl	$0, -168(%rbp)
	jns	.L76
	movl	$1, -224(%rbp)
.L76:
	movl	-164(%rbp), %eax
	cltd
	idivl	-172(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L77
	movl	$0, -224(%rbp)
.L77:
	addl	$1, -164(%rbp)
	jmp	.L78
.L72:
	call	_Z5rdtscv
	movq	%rax, -72(%rbp)
	movl	-224(%rbp), %eax
	cltd
	shrl	$31, %edx
	addl	%edx, %eax
	andl	$1, %eax
	subl	%edx, %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	-72(%rbp), %rax
	subq	-80(%rbp), %rax
	cmpq	%rax, -112(%rbp)
	cmovbe	-112(%rbp), %rax
	movq	%rax, -112(%rbp)
	addl	$1, -168(%rbp)
	jmp	.L79
.L71:
	leaq	_ZSt5fixedRSt8ios_base(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E@PLT
	movq	%rax, %rcx
	movq	-112(%rbp), %rax
	testq	%rax, %rax
	js	.L80
	cvtsi2sdq	%rax, %xmm0
	jmp	.L81
.L80:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L81:
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%rcx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -172(%rbp)
	jmp	.L82
.L27:
	movl	$1, -160(%rbp)
.L96:
	cmpl	$63, -160(%rbp)
	jg	.L103
	movq	$-1, -104(%rbp)
	movl	$0, -156(%rbp)
.L93:
	cmpl	$999, -156(%rbp)
	jg	.L84
	call	_Z5rdtscv
	movq	%rax, -96(%rbp)
	movl	$0, -152(%rbp)
.L92:
	cmpl	$9999, -152(%rbp)
	jg	.L85
	cmpl	$0, -156(%rbp)
	jns	.L86
	movl	$1, -224(%rbp)
.L86:
	cmpl	$0, -156(%rbp)
	jns	.L87
	movl	$1, -224(%rbp)
.L87:
	cmpl	$0, -156(%rbp)
	jns	.L88
	movl	$1, -224(%rbp)
.L88:
	cmpl	$0, -156(%rbp)
	jns	.L89
	movl	$1, -224(%rbp)
.L89:
	cmpl	$0, -156(%rbp)
	jns	.L90
	movl	$1, -224(%rbp)
.L90:
	movl	-152(%rbp), %eax
	cltd
	idivl	-160(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L91
	movl	$0, -224(%rbp)
.L91:
	addl	$1, -152(%rbp)
	jmp	.L92
.L85:
	call	_Z5rdtscv
	movq	%rax, -88(%rbp)
	movl	-224(%rbp), %eax
	cltd
	shrl	$31, %edx
	addl	%edx, %eax
	andl	$1, %eax
	subl	%edx, %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	-88(%rbp), %rax
	subq	-96(%rbp), %rax
	cmpq	%rax, -104(%rbp)
	cmovbe	-104(%rbp), %rax
	movq	%rax, -104(%rbp)
	addl	$1, -156(%rbp)
	jmp	.L93
.L84:
	leaq	_ZSt5fixedRSt8ios_base(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E@PLT
	movq	%rax, %rcx
	movq	-104(%rbp), %rax
	testq	%rax, %rax
	js	.L94
	cvtsi2sdq	%rax, %xmm0
	jmp	.L95
.L94:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L95:
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	%rcx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -160(%rbp)
	jmp	.L96
.L98:
	nop
	jmp	.L20
.L99:
	nop
	jmp	.L20
.L100:
	nop
	jmp	.L20
.L101:
	nop
	jmp	.L20
.L102:
	nop
	jmp	.L20
.L103:
	nop
.L20:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1496:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1982:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L106
	cmpl	$65535, -8(%rbp)
	jne	.L106
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L106:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1982:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1983:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1983:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1086556160
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.2.0-8ubuntu3) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
