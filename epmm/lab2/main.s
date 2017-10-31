	.file	"main.cpp"
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1567:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1567:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.rodata._Z4funcIaEvm.str1.1,"aMS",@progbits,1
.LC0:
	.string	" : "
.LC4:
	.string	"%.15lf\n"
	.section	.text._Z4funcIaEvm,"axG",@progbits,_Z4funcIaEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIaEvm
	.type	_Z4funcIaEvm, @function
_Z4funcIaEvm:
.LFB7061:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7061
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$104, %rsp
	.cfi_def_cfa_offset 160
	movq	%rdi, 40(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 88(%rsp)
	xorl	%eax, %eax
.LEHB0:
	call	_Znwm@PLT
	xorl	%edx, %edx
	movq	%rax, %rbx
	movl	$104857600, %eax
	divq	%r15
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, 24(%rsp)
	jne	.L172
	movl	$24, %edi
	xorl	%r12d, %r12d
	call	_Znwm@PLT
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
.L73:
	movq	0(%rbp), %rsi
	movq	(%rbx), %rcx
	movl	$100, %r9d
	movq	8(%rbx), %rdi
	movq	%r12, 8(%rbp)
	movq	$-1, %r8
	.p2align 4,,10
	.p2align 3
.L7:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%rcx, %rdi
	movq	%rdx, %r10
	je	.L5
	movq	%rsi, %rax
	.p2align 4,,10
	.p2align 3
.L6:
	movzbl	(%rax), %esi
	addq	$1, %rcx
	addq	$1, %rax
	movb	%sil, -1(%rcx)
	cmpq	8(%rbx), %rcx
	jne	.L6
	movq	%rcx, %rdi
	movq	0(%rbp), %rsi
	movq	(%rbx), %rcx
.L5:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%r10, %rax
	cmpq	%rax, %r8
	cmova	%rax, %r8
	subq	$1, %r9
	jne	.L7
	pxor	%xmm4, %xmm4
	testq	%r8, %r8
	movl	100(%rsi), %r14d
	movl	100(%rcx), %r13d
	cvtsi2sdq	24(%rsp), %xmm4
	movsd	%xmm4, 32(%rsp)
	js	.L8
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r8, %xmm0
.L9:
	divsd	32(%rsp), %xmm0
	movq	40(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movsd	%xmm0, 8(%rsp)
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %r12
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r15
	testq	%r15, %r15
	je	.L13
	cmpb	$0, 56(%r15)
	je	.L11
	movsbl	67(%r15), %esi
.L12:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movsd	8(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%r14d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L13
	cmpb	$0, 56(%r12)
	je	.L14
	movsbl	67(%r12), %esi
.L15:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L16
	call	_ZdlPv@PLT
.L16:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L17
	call	_ZdlPv@PLT
.L17:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
	cmpq	$0, 24(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L173
	movl	$24, %edi
	xorl	%ebp, %ebp
	call	_Znwm@PLT
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
.L74:
	movq	%rbp, 8(%r12)
	movq	(%rbx), %r14
	movq	$-1, %r15
	movq	(%r12), %rsi
	movq	$100, 8(%rsp)
	movq	%r12, %r13
	jmp	.L28
	.p2align 4,,10
	.p2align 3
.L177:
	testq	%r12, %r12
	movq	%r14, %rax
	jne	.L174
.L24:
	movq	%rax, 8(%rbx)
.L20:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rbp, %rax
	cmpq	%rax, %r15
	cmova	%rax, %r15
	subq	$1, 8(%rsp)
	je	.L175
.L28:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%r13, %rbx
	movq	%rdx, %rbp
	je	.L20
	movq	8(%r13), %r8
	movq	16(%rbx), %rax
	movq	%r8, %r12
	subq	%r14, %rax
	subq	%rsi, %r12
	cmpq	%rax, %r12
	ja	.L176
	movq	8(%rbx), %rdi
	movq	%rdi, %rdx
	subq	%r14, %rdx
	cmpq	%rdx, %r12
	jbe	.L177
	xorl	%eax, %eax
	testq	%rdx, %rdx
	jne	.L178
.L26:
	addq	%rsi, %rax
	subq	%rax, %r8
	jne	.L27
	leaq	(%r14,%r12), %rax
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L176:
	movq	%r12, %rdi
	movq	%rsi, 16(%rsp)
	call	_Znwm@PLT
	testq	%r12, %r12
	movq	%rax, %r14
	movq	16(%rsp), %rsi
	je	.L22
	movq	%r12, %rdx
	movq	%rax, %rdi
	call	memmove@PLT
.L22:
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L23
	call	_ZdlPv@PLT
.L23:
	leaq	(%r14,%r12), %rax
	movq	%r14, (%rbx)
	movq	0(%r13), %rsi
	movq	%rax, 16(%rbx)
	jmp	.L24
.L174:
	movq	%r14, %rdi
	movq	%r12, %rdx
	call	memmove@PLT
	movq	(%rbx), %r14
	movq	0(%r13), %rsi
	leaq	(%r14,%r12), %rax
	jmp	.L24
.L27:
	movq	%rax, %rsi
	movq	%r8, %rdx
	call	memmove@PLT
	movq	(%rbx), %r14
	movq	0(%r13), %rsi
	leaq	(%r14,%r12), %rax
	jmp	.L24
.L178:
	movq	%r14, %rdi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r14
	movq	0(%r13), %rsi
	movq	8(%r13), %r8
	movq	%rdi, %rax
	subq	%r14, %rax
	jmp	.L26
.L175:
	testq	%r15, %r15
	movq	%r13, %r12
	movl	100(%rsi), %ebp
	movl	100(%r14), %r13d
	js	.L29
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r15, %xmm0
.L30:
	divsd	32(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L13
	cmpb	$0, 56(%rbp)
	je	.L31
	movsbl	67(%rbp), %esi
.L32:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L33
	call	_ZdlPv@PLT
.L33:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L34
	call	_ZdlPv@PLT
.L34:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
	cmpq	$0, 24(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L179
	movl	$24, %edi
	xorl	%ebp, %ebp
	call	_Znwm@PLT
	movq	%rax, 8(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
.L76:
	movdqa	.LC1(%rip), %xmm7
	leaq	64(%rsp), %r15
	movabsq	$9223372036854775807, %r12
	movq	%rbp, 8(%rax)
	leaq	48(%rsp), %rax
	movl	$100, %ebp
	movaps	%xmm7, 48(%rsp)
	movq	%rax, 16(%rsp)
	.p2align 4,,10
	.p2align 3
.L43:
	movl	$4, %edi
	movq	%r15, %rsi
	call	clock_gettime@PLT
	movq	(%rbx), %rax
	cmpq	8(%rbx), %rax
	movq	8(%rsp), %rdi
	movq	64(%rsp), %r14
	movq	72(%rsp), %r13
	movq	(%rdi), %rdx
	je	.L41
	.p2align 4,,10
	.p2align 3
.L133:
	movzbl	(%rdx), %ecx
	addq	$1, %rax
	addq	$1, %rdx
	movb	%cl, -1(%rax)
	cmpq	%rax, 8(%rbx)
	jne	.L133
.L41:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	72(%rsp), %rcx
	movq	64(%rsp), %rsi
	subq	%r13, %rcx
	subq	%r14, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, 64(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r12, %rsi
	movq	%rcx, 72(%rsp)
	jle	.L38
	movq	16(%rsp), %rax
.L39:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbp
	movq	%rax, 48(%rsp)
	movq	%rdx, 56(%rsp)
	je	.L42
	movq	48(%rsp), %r12
	jmp	.L43
	.p2align 4,,10
	.p2align 3
.L38:
	cmpq	56(%rsp), %rcx
	movq	16(%rsp), %rax
	cmovle	%r15, %rax
	jmp	.L39
.L42:
	movq	8(%rsp), %rax
	movq	40(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	100(%rax), %r12d
	movq	(%rbx), %rax
	movl	100(%rax), %ebp
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %r13
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	%ebp, %esi
	movq	%r13, %rdi
	call	_ZNSolsEi@PLT
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L13
	cmpb	$0, 56(%rbp)
	je	.L44
	movsbl	67(%rbp), %esi
.L45:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	56(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	48(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L46
	call	_ZdlPv@PLT
.L46:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	8(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L47
	call	_ZdlPv@PLT
.L47:
	movq	8(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
	cmpq	$0, 24(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L180
	movl	$24, %edi
	xorl	%r12d, %r12d
	call	_Znwm@PLT
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
.L77:
	movdqa	.LC1(%rip), %xmm4
	leaq	48(%rsp), %rax
	movq	%rbx, %r13
	movq	%r12, 8(%rbp)
	movq	$100, 8(%rsp)
	movabsq	$9223372036854775807, %r12
	movaps	%xmm4, 48(%rsp)
	movq	%rax, 16(%rsp)
	jmp	.L60
	.p2align 4,,10
	.p2align 3
.L183:
	testq	%r8, %r8
	jne	.L181
.L54:
	movq	%rdi, 8(%r13)
.L50:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	72(%rsp), %rsi
	movq	64(%rsp), %rdi
	subq	%rbx, %rsi
	subq	%r14, %rdi
	movq	16(%rsp), %rbx
	movq	%rsi, %rax
	addq	$1000000000, %rsi
	shrq	$63, %rax
	subq	%rax, %rdi
	movabsq	$1237940039285380275, %rax
	imulq	%rsi
	movq	%rsi, %rax
	movq	%rdi, 64(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	movq	%rbx, %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rsi
	cmpq	%rdi, %r12
	movq	%rsi, 72(%rsp)
	jl	.L58
	cmpq	56(%rsp), %rsi
	cmovle	%r15, %rax
.L58:
	subq	$1, 8(%rsp)
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rdx, 56(%rsp)
	movq	%rax, 48(%rsp)
	je	.L59
	movq	48(%rsp), %r12
.L60:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	cmpq	%rbp, %r13
	movq	64(%rsp), %r14
	movq	72(%rsp), %rbx
	je	.L50
	movq	8(%rbp), %r9
	movq	0(%rbp), %rsi
	movq	0(%r13), %rdi
	movq	16(%r13), %rax
	movq	%r9, %r8
	subq	%rsi, %r8
	subq	%rdi, %rax
	cmpq	%rax, %r8
	ja	.L182
	movq	8(%r13), %rax
	movq	%rax, %rdx
	subq	%rdi, %rdx
	cmpq	%rdx, %r8
	jbe	.L183
	xorl	%r10d, %r10d
	testq	%rdx, %rdx
	jne	.L184
.L56:
	addq	%r10, %rsi
	subq	%rsi, %r9
	jne	.L57
	addq	%r8, %rdi
	jmp	.L54
	.p2align 4,,10
	.p2align 3
.L182:
	movq	%r8, %rdi
	movq	%rsi, 32(%rsp)
	movq	%r8, 24(%rsp)
	call	_Znwm@PLT
	movq	24(%rsp), %r8
	movq	%rax, %r9
	movq	32(%rsp), %rsi
	testq	%r8, %r8
	je	.L52
	movq	%r8, %rdx
	movq	%rax, %rdi
	call	memmove@PLT
	movq	24(%rsp), %r8
	movq	%rax, %r9
.L52:
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L53
	movq	%r9, 32(%rsp)
	movq	%r8, 24(%rsp)
	call	_ZdlPv@PLT
	movq	32(%rsp), %r9
	movq	24(%rsp), %r8
.L53:
	leaq	(%r9,%r8), %rdi
	movq	%r9, 0(%r13)
	movq	%rdi, 16(%r13)
	jmp	.L54
.L181:
	movq	%r8, %rdx
	movq	%r8, 24(%rsp)
	call	memmove@PLT
	movq	24(%rsp), %r8
	movq	%r8, %rdi
	addq	0(%r13), %rdi
	jmp	.L54
.L57:
	movq	%rax, %rdi
	movq	%r9, %rdx
	movq	%r8, 24(%rsp)
	call	memmove@PLT
	movq	24(%rsp), %r8
	movq	%r8, %rdi
	addq	0(%r13), %rdi
	jmp	.L54
.L184:
	movq	%r8, 24(%rsp)
	call	memmove@PLT
	movq	8(%r13), %rax
	movq	0(%r13), %rdi
	movq	0(%rbp), %rsi
	movq	8(%rbp), %r9
	movq	24(%rsp), %r8
	movq	%rax, %r10
	subq	%rdi, %r10
	jmp	.L56
.L59:
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	56(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	movq	%r13, %rbx
	cvtsi2sdq	48(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk@PLT
	movq	0(%rbp), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movl	100(%rax), %r12d
	movq	0(%r13), %rax
	movl	100(%rax), %esi
	call	_ZNSolsEi@PLT
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L13
	cmpb	$0, 56(%r12)
	je	.L61
	movsbl	67(%r12), %esi
.L62:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L63
	call	_ZdlPv@PLT
.L63:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L64
	call	_ZdlPv@PLT
.L64:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	88(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L185
	addq	$104, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L61:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L62
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L62
.L44:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L45
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L45
.L31:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L32
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L32
.L14:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L15
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L15
.L11:
	movq	%r15, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r15), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L12
	movq	%r15, %rdi
	call	*%rax
.LEHE0:
	movsbl	%al, %esi
	jmp	.L12
.L180:
	movq	24(%rsp), %r14
	movq	%r14, %rdi
.LEHB1:
	call	_Znwm@PLT
.LEHE1:
	leaq	(%rax,%r14), %rbp
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%rbx)
	movq	%rbp, 16(%rbx)
	call	memset@PLT
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB2:
	call	_Znwm@PLT
.LEHE2:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbp
.LEHB3:
	call	_Znwm@PLT
.LEHE3:
	movq	24(%rsp), %rdi
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, 8(%rbp)
	leaq	(%rax,%rdi), %r12
	movq	%rdi, %rdx
	movq	%rax, %rdi
	movq	%r12, 16(%rbp)
	call	memset@PLT
	jmp	.L77
.L179:
	movq	24(%rsp), %r15
	movq	%r15, %rdi
.LEHB4:
	call	_Znwm@PLT
.LEHE4:
	leaq	(%rax,%r15), %rbp
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%rbx)
	movq	%rbp, 16(%rbx)
	call	memset@PLT
	movl	$24, %edi
	movq	%rbp, 8(%rbx)
.LEHB5:
	call	_Znwm@PLT
.LEHE5:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, 8(%rsp)
.LEHB6:
	call	_Znwm@PLT
.LEHE6:
	movq	24(%rsp), %rsi
	movq	8(%rsp), %rdi
	leaq	(%rax,%rsi), %rbp
	movq	%rax, (%rdi)
	movq	%rax, 8(%rdi)
	movq	%rsi, %rdx
	xorl	%esi, %esi
	movq	%rbp, 16(%rdi)
	movq	%rax, %rdi
	call	memset@PLT
	movq	8(%rsp), %rax
	jmp	.L76
.L173:
	movq	24(%rsp), %r15
	movq	%r15, %rdi
.LEHB7:
	call	_Znwm@PLT
.LEHE7:
	leaq	(%rax,%r15), %rbp
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%rbx)
	movq	%rbp, 16(%rbx)
	call	memset@PLT
	movl	$24, %edi
	movq	%rbp, 8(%rbx)
.LEHB8:
	call	_Znwm@PLT
.LEHE8:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB9:
	call	_Znwm@PLT
.LEHE9:
	movq	24(%rsp), %rdi
	movq	%rax, (%r12)
	xorl	%esi, %esi
	movq	%rax, 8(%r12)
	leaq	(%rax,%rdi), %rbp
	movq	%rdi, %rdx
	movq	%rax, %rdi
	movq	%rbp, 16(%r12)
	call	memset@PLT
	jmp	.L74
.L172:
	movq	%rax, %rdi
	movq	%rax, %r15
.LEHB10:
	call	_Znwm@PLT
.LEHE10:
	leaq	(%rax,%r15), %rbp
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%rbx)
	movq	%rbp, 16(%rbx)
	call	memset@PLT
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB11:
	call	_Znwm@PLT
.LEHE11:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbp
.LEHB12:
	call	_Znwm@PLT
.LEHE12:
	movq	24(%rsp), %rdi
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, 8(%rbp)
	leaq	(%rax,%rdi), %r12
	movq	%rdi, %rdx
	movq	%rax, %rdi
	movq	%r12, 16(%rbp)
	call	memset@PLT
	jmp	.L73
.L8:
	movq	%r8, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r8d
	orq	%r8, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L9
.L29:
	movq	%r15, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r15d
	orq	%r15, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L30
.L97:
.L164:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
.LEHB13:
	call	_Unwind_Resume@PLT
.L185:
	call	__stack_chk_fail@PLT
.L13:
	call	_ZSt16__throw_bad_castv@PLT
.L92:
.L165:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L91:
	jmp	.L164
.L94:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L93:
	jmp	.L164
.L96:
	movq	8(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.LEHE13:
.L95:
	jmp	.L164
.L98:
	jmp	.L165
	.cfi_endproc
.LFE7061:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._Z4funcIaEvm,"aG",@progbits,_Z4funcIaEvm,comdat
.LLSDA7061:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7061-.LLSDACSB7061
.LLSDACSB7061:
	.uleb128 .LEHB0-.LFB7061
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB7061
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L97-.LFB7061
	.uleb128 0
	.uleb128 .LEHB2-.LFB7061
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB7061
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L98-.LFB7061
	.uleb128 0
	.uleb128 .LEHB4-.LFB7061
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L95-.LFB7061
	.uleb128 0
	.uleb128 .LEHB5-.LFB7061
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB6-.LFB7061
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L96-.LFB7061
	.uleb128 0
	.uleb128 .LEHB7-.LFB7061
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L93-.LFB7061
	.uleb128 0
	.uleb128 .LEHB8-.LFB7061
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB9-.LFB7061
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L94-.LFB7061
	.uleb128 0
	.uleb128 .LEHB10-.LFB7061
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L91-.LFB7061
	.uleb128 0
	.uleb128 .LEHB11-.LFB7061
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB12-.LFB7061
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L92-.LFB7061
	.uleb128 0
	.uleb128 .LEHB13-.LFB7061
	.uleb128 .LEHE13-.LEHB13
	.uleb128 0
	.uleb128 0
.LLSDACSE7061:
	.section	.text._Z4funcIaEvm,"axG",@progbits,_Z4funcIaEvm,comdat
	.size	_Z4funcIaEvm, .-_Z4funcIaEvm
	.section	.text._ZNSt6vectorIsSaIsEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIsSaIsEEaSERKS1_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIsSaIsEEaSERKS1_
	.type	_ZNSt6vectorIsSaIsEEaSERKS1_, @function
_ZNSt6vectorIsSaIsEEaSERKS1_:
.LFB7166:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	cmpq	%rdi, %rsi
	je	.L187
	movq	8(%rsi), %rax
	movq	(%rsi), %r15
	movq	%rsi, %r12
	movq	(%rdi), %r13
	movq	16(%rdi), %rcx
	movq	%rax, %rbp
	subq	%r15, %rbp
	subq	%r13, %rcx
	movq	%rbp, %r14
	sarq	%rcx
	sarq	%r14
	cmpq	%r14, %rcx
	jb	.L210
	movq	8(%rdi), %rdi
	movq	%rdi, %rsi
	subq	%r13, %rsi
	movq	%rsi, %rdx
	sarq	%rdx
	cmpq	%rdx, %r14
	jbe	.L211
	testq	%rdx, %rdx
	jne	.L212
.L197:
	addq	%r15, %rsi
	subq	%rsi, %rax
	movq	%rax, %rdx
	shrq	%rdx
	jne	.L198
.L209:
	addq	%r13, %rbp
.L194:
	movq	%rbp, 8(%rbx)
.L187:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L211:
	.cfi_restore_state
	testq	%r14, %r14
	je	.L209
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%r13, %rdi
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L194
	.p2align 4,,10
	.p2align 3
.L210:
	xorl	%r12d, %r12d
	testq	%r14, %r14
	je	.L192
	js	.L213
	movq	%rbp, %rdi
	call	_Znwm@PLT
	testq	%r14, %r14
	movq	%rax, %r12
	movq	(%rbx), %r13
	jne	.L214
.L192:
	testq	%r13, %r13
	je	.L193
.L215:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
.L193:
	addq	%r12, %rbp
	movq	%r12, (%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L194
	.p2align 4,,10
	.p2align 3
.L214:
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%rax, %rdi
	call	memmove@PLT
	testq	%r13, %r13
	jne	.L215
	jmp	.L193
	.p2align 4,,10
	.p2align 3
.L198:
	movq	%rax, %rdx
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L194
	.p2align 4,,10
	.p2align 3
.L212:
	movq	%r13, %rdi
	movq	%rsi, %rdx
	movq	%r15, %rsi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r13
	movq	(%r12), %r15
	movq	8(%r12), %rax
	movq	%rdi, %rsi
	subq	%r13, %rsi
	jmp	.L197
.L213:
	call	_ZSt17__throw_bad_allocv@PLT
	.cfi_endproc
.LFE7166:
	.size	_ZNSt6vectorIsSaIsEEaSERKS1_, .-_ZNSt6vectorIsSaIsEEaSERKS1_
	.section	.text._Z4funcIsEvm,"axG",@progbits,_Z4funcIsEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIsEvm
	.type	_Z4funcIsEvm, @function
_Z4funcIsEvm:
.LFB7062:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7062
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$136, %rsp
	.cfi_def_cfa_offset 192
	movq	%rdi, 72(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 120(%rsp)
	xorl	%eax, %eax
.LEHB14:
	call	_Znwm@PLT
.LEHE14:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movq	%rax, 56(%rsp)
	movl	$104857600, %eax
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	divq	%r15
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, 40(%rsp)
	je	.L217
	addq	%rax, %rax
	movq	%rax, %rdi
	movq	%rax, %r14
	movq	%rax, 32(%rsp)
.LEHB15:
	call	_Znwm@PLT
.LEHE15:
	movq	%rbx, %r15
	movq	%rax, (%rbx)
	movq	%r14, %rbx
	addq	%rax, %rbx
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r15)
	call	memset@PLT
	movl	$24, %edi
	movq	%rbx, 8(%r15)
.LEHB16:
	call	_Znwm@PLT
.LEHE16:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbp
	movq	%rax, 48(%rsp)
.LEHB17:
	call	_Znwm@PLT
.LEHE17:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	movq	%r14, %rdx
	movq	%rbx, 0(%rbp)
	movq	%rbx, 8(%rbp)
	leaq	(%rbx,%r14), %rbp
	xorl	%esi, %esi
	movq	%rbp, 16(%rdi)
	movq	%rbx, %rdi
	call	memset@PLT
	movq	48(%rsp), %rax
.L304:
	movq	%rbp, 8(%rax)
	movq	56(%rsp), %rax
	movq	%rbx, %r8
	movl	$100, %r10d
	movq	$-1, %r9
	movq	(%rax), %rsi
	movq	8(%rax), %rdi
	leaq	2(%rsi), %rax
	movq	%rdi, %rcx
	subq	%rax, %rcx
	movq	%rax, 64(%rsp)
	movq	%rcx, %rax
	leaq	16(%rsi), %rcx
	shrq	%rax
	cmpq	%rcx, %rbx
	leaq	16(%rbx), %rcx
	leaq	1(%rax), %rdx
	setnb	%r11b
	cmpq	%rcx, %rsi
	setnb	%cl
	orl	%ecx, %r11d
	cmpq	$14, %rdx
	seta	%cl
	shrq	%r8
	negq	%r8
	andl	%ecx, %r11d
	andl	$7, %r8d
	cmpq	%rdx, %r8
	cmova	%rdx, %r8
	subq	%r8, %rdx
	leaq	(%r8,%r8), %r12
	subq	%r8, %rax
	movq	%rdx, 24(%rsp)
	subq	$8, %rdx
	movq	%rax, (%rsp)
	shrq	$3, %rdx
	leaq	(%rbx,%r12), %r13
	addq	%rsi, %r12
	leaq	1(%rdx), %rcx
	leaq	0(,%rcx,8), %rdx
	movq	%rcx, 8(%rsp)
	salq	$4, %rcx
	movq	%rcx, %rbp
	movq	%rdx, 16(%rsp)
	.p2align 4,,10
	.p2align 3
.L220:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%edx, %r14d
	movl	%eax, %eax
	salq	$32, %r14
	orq	%rax, %r14
	cmpq	%rsi, %rdi
	je	.L229
	testb	%r11b, %r11b
	je	.L221
	testq	%r8, %r8
	je	.L309
	movzwl	(%rbx), %eax
	cmpq	$1, %r8
	leaq	2(%rbx), %rcx
	movw	%ax, (%rsi)
	je	.L310
	movzwl	2(%rbx), %eax
	cmpq	$2, %r8
	leaq	4(%rbx), %rcx
	movw	%ax, 2(%rsi)
	leaq	4(%rsi), %rax
	je	.L222
	movzwl	4(%rbx), %eax
	cmpq	$3, %r8
	leaq	6(%rbx), %rcx
	movw	%ax, 4(%rsi)
	leaq	6(%rsi), %rax
	je	.L222
	movzwl	6(%rbx), %eax
	cmpq	$4, %r8
	leaq	8(%rbx), %rcx
	movw	%ax, 6(%rsi)
	leaq	8(%rsi), %rax
	je	.L222
	movzwl	8(%rbx), %eax
	cmpq	$5, %r8
	leaq	10(%rbx), %rcx
	movw	%ax, 8(%rsi)
	leaq	10(%rsi), %rax
	je	.L222
	movzwl	10(%rbx), %eax
	cmpq	$7, %r8
	leaq	12(%rbx), %rcx
	movw	%ax, 10(%rsi)
	leaq	12(%rsi), %rax
	jne	.L222
	movzwl	12(%rbx), %eax
	leaq	14(%rbx), %rcx
	movw	%ax, 12(%rsi)
	leaq	14(%rsi), %rax
.L222:
	cmpq	$6, (%rsp)
	jbe	.L224
	xorl	%edx, %edx
	xorl	%r15d, %r15d
.L225:
	movdqa	0(%r13,%rdx), %xmm0
	addq	$1, %r15
	movups	%xmm0, (%r12,%rdx)
	addq	$16, %rdx
	cmpq	%r15, 8(%rsp)
	ja	.L225
	addq	%rbp, %rax
	addq	%rbp, %rcx
	movq	24(%rsp), %r15
	cmpq	%r15, 16(%rsp)
	je	.L229
.L224:
	movzwl	(%rcx), %edx
	movw	%dx, (%rax)
	leaq	2(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L229
	movzwl	2(%rcx), %edx
	movw	%dx, 2(%rax)
	leaq	4(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L229
	movzwl	4(%rcx), %edx
	movw	%dx, 4(%rax)
	leaq	6(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L229
	movzwl	6(%rcx), %edx
	movw	%dx, 6(%rax)
	leaq	8(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L229
	movzwl	8(%rcx), %edx
	movw	%dx, 8(%rax)
	leaq	10(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L229
	movzwl	10(%rcx), %edx
	movw	%dx, 10(%rax)
	leaq	12(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L229
	movzwl	12(%rcx), %edx
	movw	%dx, 12(%rax)
.L229:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%eax, %ecx
	movq	%rdx, %rax
	salq	$32, %rax
	orq	%rcx, %rax
	subq	%r14, %rax
	cmpq	%rax, %r9
	cmova	%rax, %r9
	subq	$1, %r10
	jne	.L220
	pxor	%xmm4, %xmm4
	testq	%r9, %r9
	movl	200(%rbx), %ebx
	movl	200(%rsi), %ebp
	cvtsi2sdq	40(%rsp), %xmm4
	movsd	%xmm4, 24(%rsp)
	js	.L232
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r9, %xmm0
.L233:
	divsd	24(%rsp), %xmm0
	movq	72(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movsd	%xmm0, (%rsp)
.LEHB18:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %r12
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r13
	testq	%r13, %r13
	je	.L237
	cmpb	$0, 56(%r13)
	je	.L235
	movsbl	67(%r13), %esi
.L236:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movsd	(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L237
	cmpb	$0, 56(%rbx)
	je	.L238
	movsbl	67(%rbx), %esi
.L239:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	56(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L240
	call	_ZdlPv@PLT
.L240:
	movq	56(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	48(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L241
	call	_ZdlPv@PLT
.L241:
	movq	48(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE18:
	cmpq	$0, 40(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L433
	movq	32(%rsp), %r15
	movq	%r15, %rdi
.LEHB19:
	call	_Znwm@PLT
.LEHE19:
	movq	%rax, %r12
	movq	%rax, 0(%rbp)
	movq	%r15, %rax
	addq	%r12, %rax
	movq	%r12, %rdi
	xorl	%esi, %esi
	movq	%rax, 16(%rbp)
	movq	40(%rsp), %rax
	leaq	(%rax,%rax), %rbx
	movq	%rbx, %rdx
	addq	%rbx, %r12
	call	memset@PLT
	movl	$24, %edi
	movq	%r12, 8(%rbp)
.LEHB20:
	call	_Znwm@PLT
.LEHE20:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r13
.LEHB21:
	call	_Znwm@PLT
.LEHE21:
	movq	%rax, %r12
	movq	%rax, 0(%r13)
	movq	%rax, 8(%r13)
	movq	32(%rsp), %rax
	movq	%rbx, %rdx
	xorl	%esi, %esi
	movq	%r12, %rdi
	addq	%r12, %rbx
	addq	%r12, %rax
	movq	%rax, 16(%r13)
	call	memset@PLT
.L305:
	movq	%rbx, 8(%r13)
	movq	0(%rbp), %r14
	movl	$100, %r12d
	movq	0(%r13), %rsi
	movq	$-1, %r15
	jmp	.L256
	.p2align 4,,10
	.p2align 3
.L437:
	testq	%r8, %r8
	jne	.L434
.L421:
	leaq	(%r14,%rbx), %rcx
.L251:
	movq	%rcx, 8(%rbp)
.L244:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	(%rsp), %rax
	cmpq	%rax, %r15
	cmova	%rax, %r15
	subq	$1, %r12
	je	.L435
.L256:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%rbp, %r13
	movq	%rdx, (%rsp)
	je	.L244
	movq	8(%r13), %r9
	movq	16(%rbp), %rax
	movq	%r9, %rbx
	subq	%r14, %rax
	subq	%rsi, %rbx
	sarq	%rax
	movq	%rbx, %r8
	sarq	%r8
	cmpq	%rax, %r8
	ja	.L436
	movq	8(%rbp), %rdi
	movq	%rdi, %rdx
	subq	%r14, %rdx
	movq	%rdx, %rax
	sarq	%rax
	cmpq	%rax, %r8
	jbe	.L437
	testq	%rax, %rax
	jne	.L438
.L254:
	leaq	(%rsi,%rdx), %rax
	subq	%rax, %r9
	movq	%r9, %rcx
	shrq	%rcx
	je	.L421
	movq	%rax, %rsi
	movq	%r9, %rdx
	call	memmove@PLT
	movq	0(%rbp), %r14
	movq	0(%r13), %rsi
	leaq	(%r14,%rbx), %rcx
	jmp	.L251
	.p2align 4,,10
	.p2align 3
.L436:
	movq	%r14, %r9
	xorl	%r14d, %r14d
	testq	%r8, %r8
	je	.L249
	js	.L439
	movq	%rbx, %rdi
	movq	%rsi, 16(%rsp)
	movq	%r8, 8(%rsp)
.LEHB22:
	call	_Znwm@PLT
	movq	8(%rsp), %r8
	movq	%rax, %r14
	movq	0(%rbp), %r9
	movq	16(%rsp), %rsi
	testq	%r8, %r8
	je	.L249
	movq	%rbx, %rdx
	movq	%rax, %rdi
	movq	%r9, 8(%rsp)
	call	memmove@PLT
	movq	8(%rsp), %r9
.L249:
	testq	%r9, %r9
	je	.L250
	movq	%r9, %rdi
	call	_ZdlPv@PLT
.L250:
	leaq	(%r14,%rbx), %rcx
	movq	%r14, 0(%rbp)
	movq	0(%r13), %rsi
	movq	%rcx, 16(%rbp)
	jmp	.L251
	.p2align 4,,10
	.p2align 3
.L309:
	movq	%rbx, %rcx
	movq	%rsi, %rax
	jmp	.L222
	.p2align 4,,10
	.p2align 3
.L221:
	movq	%rsi, %rax
	movq	%rbx, %rdx
	.p2align 4,,10
	.p2align 3
.L230:
	movzwl	(%rdx), %ecx
	addq	$2, %rax
	addq	$2, %rdx
	movw	%cx, -2(%rax)
	cmpq	%rax, %rdi
	jne	.L230
	jmp	.L229
	.p2align 4,,10
	.p2align 3
.L438:
	movq	%r14, %rdi
	call	memmove@PLT
	movq	8(%rbp), %rdi
	movq	0(%rbp), %r14
	movq	0(%r13), %rsi
	movq	8(%r13), %r9
	movq	%rdi, %rdx
	subq	%r14, %rdx
	jmp	.L254
	.p2align 4,,10
	.p2align 3
.L434:
	movq	%r14, %rdi
	movq	%rbx, %rdx
	call	memmove@PLT
	movq	0(%rbp), %r14
	movq	0(%r13), %rsi
	leaq	(%r14,%rbx), %rcx
	jmp	.L251
	.p2align 4,,10
	.p2align 3
.L310:
	movq	64(%rsp), %rax
	jmp	.L222
.L435:
	testq	%r15, %r15
	movl	200(%rsi), %ebx
	movl	200(%r14), %r12d
	js	.L257
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r15, %xmm0
.L258:
	divsd	24(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L237
	cmpb	$0, 56(%rbx)
	je	.L259
	movsbl	67(%rbx), %esi
.L260:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L261
	call	_ZdlPv@PLT
.L261:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L262
	call	_ZdlPv@PLT
.L262:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE22:
	cmpq	$0, 40(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L440
	movq	32(%rsp), %r15
	movq	%r15, %rdi
.LEHB23:
	call	_Znwm@PLT
.LEHE23:
	movq	%rax, %r12
	movq	%rax, (%rbx)
	movq	%r15, %rax
	addq	%r12, %rax
	movq	%r12, %rdi
	xorl	%esi, %esi
	movq	%rax, 16(%rbx)
	movq	40(%rsp), %rax
	leaq	(%rax,%rax), %rbp
	movq	%rbp, %rdx
	addq	%rbp, %r12
	call	memset@PLT
	movl	$24, %edi
	movq	%r12, 8(%rbx)
.LEHB24:
	call	_Znwm@PLT
.LEHE24:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, (%rsp)
.LEHB25:
	call	_Znwm@PLT
.LEHE25:
	movq	%rax, %r12
	movq	32(%rsp), %rax
	movq	(%rsp), %rdi
	movq	%rbp, %rdx
	xorl	%esi, %esi
	addq	%r12, %rbp
	addq	%r12, %rax
	movq	%r12, (%rdi)
	movq	%r12, 8(%rdi)
	movq	%rax, 16(%rdi)
	movq	%r12, %rdi
	call	memset@PLT
	movq	(%rsp), %rax
.L306:
	movdqa	.LC1(%rip), %xmm7
	leaq	96(%rsp), %r14
	movl	$100, %r15d
	movq	%rbp, 8(%rax)
	leaq	80(%rsp), %rax
	movabsq	$9223372036854775807, %rbp
	movaps	%xmm7, 80(%rsp)
	movq	%rax, 8(%rsp)
	.p2align 4,,10
	.p2align 3
.L279:
	movq	%r14, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	(%rbx), %r10
	movq	8(%rbx), %rsi
	movq	(%rsp), %rax
	movq	96(%rsp), %r13
	movq	104(%rsp), %r12
	cmpq	%rsi, %r10
	movq	(%rax), %rdx
	je	.L275
	leaq	2(%r10), %rcx
	movq	%rsi, %rdi
	leaq	16(%rdx), %rax
	subq	%rcx, %rdi
	shrq	%rdi
	addq	$1, %rdi
	cmpq	%rax, %r10
	leaq	16(%r10), %rax
	setnb	%r8b
	cmpq	%rax, %rdx
	setnb	%al
	orb	%al, %r8b
	je	.L268
	cmpq	$14, %rdi
	jbe	.L268
	movq	%rdx, %rax
	shrq	%rax
	negq	%rax
	andl	$7, %eax
	je	.L314
	movzwl	(%rdx), %r8d
	cmpq	$1, %rax
	movw	%r8w, (%r10)
	leaq	2(%rdx), %r8
	je	.L269
	movzwl	2(%rdx), %ecx
	cmpq	$2, %rax
	leaq	4(%rdx), %r8
	movw	%cx, 2(%r10)
	leaq	4(%r10), %rcx
	je	.L269
	movzwl	4(%rdx), %ecx
	cmpq	$3, %rax
	leaq	6(%rdx), %r8
	movw	%cx, 4(%r10)
	leaq	6(%r10), %rcx
	je	.L269
	movzwl	6(%rdx), %ecx
	cmpq	$4, %rax
	leaq	8(%rdx), %r8
	movw	%cx, 6(%r10)
	leaq	8(%r10), %rcx
	je	.L269
	movzwl	8(%rdx), %ecx
	cmpq	$5, %rax
	leaq	10(%rdx), %r8
	movw	%cx, 8(%r10)
	leaq	10(%r10), %rcx
	je	.L269
	movzwl	10(%rdx), %ecx
	cmpq	$7, %rax
	leaq	12(%rdx), %r8
	movw	%cx, 10(%r10)
	leaq	12(%r10), %rcx
	jne	.L269
	movzwl	12(%rdx), %ecx
	leaq	14(%rdx), %r8
	movw	%cx, 12(%r10)
	leaq	14(%r10), %rcx
.L269:
	subq	%rax, %rdi
	addq	%rax, %rax
	leaq	-8(%rdi), %r9
	addq	%rax, %rdx
	addq	%r10, %rax
	xorl	%r10d, %r10d
	shrq	$3, %r9
	addq	$1, %r9
	leaq	0(,%r9,8), %r11
	movq	%r11, 16(%rsp)
	xorl	%r11d, %r11d
.L271:
	movdqa	(%rdx,%r10), %xmm0
	addq	$1, %r11
	movups	%xmm0, (%rax,%r10)
	addq	$16, %r10
	cmpq	%r11, %r9
	ja	.L271
	movq	16(%rsp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rax, %rcx
	addq	%rax, %r8
	cmpq	%rdi, %rdx
	je	.L275
	movzwl	(%r8), %eax
	movw	%ax, (%rcx)
	leaq	2(%rcx), %rax
	cmpq	%rax, %rsi
	je	.L275
	movzwl	2(%r8), %eax
	movw	%ax, 2(%rcx)
	leaq	4(%rcx), %rax
	cmpq	%rax, %rsi
	je	.L275
	movzwl	4(%r8), %eax
	movw	%ax, 4(%rcx)
	leaq	6(%rcx), %rax
	cmpq	%rax, %rsi
	je	.L275
	movzwl	6(%r8), %eax
	movw	%ax, 6(%rcx)
	leaq	8(%rcx), %rax
	cmpq	%rax, %rsi
	je	.L275
	movzwl	8(%r8), %eax
	movw	%ax, 8(%rcx)
	leaq	10(%rcx), %rax
	cmpq	%rax, %rsi
	je	.L275
	movzwl	10(%r8), %eax
	movw	%ax, 10(%rcx)
	leaq	12(%rcx), %rax
	cmpq	%rax, %rsi
	je	.L275
	movzwl	12(%r8), %eax
	movw	%ax, 12(%rcx)
.L275:
	movq	%r14, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	104(%rsp), %rcx
	movq	96(%rsp), %rsi
	subq	%r12, %rcx
	subq	%r13, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, 96(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%rbp, %rsi
	movq	%rcx, 104(%rsp)
	jle	.L266
	movq	8(%rsp), %rax
.L267:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %r15
	movq	%rax, 80(%rsp)
	movq	%rdx, 88(%rsp)
	je	.L278
	movq	80(%rsp), %rbp
	jmp	.L279
	.p2align 4,,10
	.p2align 3
.L266:
	cmpq	88(%rsp), %rcx
	movq	8(%rsp), %rax
	cmovle	%r14, %rax
	jmp	.L267
	.p2align 4,,10
	.p2align 3
.L314:
	movq	%rdx, %r8
	movq	%r10, %rcx
	jmp	.L269
	.p2align 4,,10
	.p2align 3
.L268:
	movq	%r10, %rax
	.p2align 4,,10
	.p2align 3
.L276:
	movzwl	(%rdx), %ecx
	addq	$2, %rax
	addq	$2, %rdx
	movw	%cx, -2(%rax)
	cmpq	%rax, %rsi
	jne	.L276
	jmp	.L275
.L278:
	movq	(%rsp), %rax
	movq	72(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	200(%rax), %ebp
	movq	(%rbx), %rax
	movl	200(%rax), %r12d
.LEHB26:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %r13
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	%r12d, %esi
	movq	%r13, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L237
	cmpb	$0, 56(%rbp)
	je	.L280
	movsbl	67(%rbp), %esi
.L281:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	80(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L282
	call	_ZdlPv@PLT
.L282:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L283
	call	_ZdlPv@PLT
.L283:
	movq	(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE26:
	cmpq	$0, 40(%rsp)
	movq	%rax, 8(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L441
	movq	32(%rsp), %r12
	movq	%r12, %rdi
.LEHB27:
	call	_Znwm@PLT
.LEHE27:
	movq	40(%rsp), %rbp
	movq	8(%rsp), %r15
	movq	%rax, %rbx
	movq	%r12, %rax
	movq	%rbx, %rdi
	xorl	%esi, %esi
	addq	%rbx, %rax
	addq	%rbp, %rbp
	movq	%rbx, (%r15)
	movq	%rax, 16(%r15)
	movq	%rbp, %rdx
	addq	%rbp, %rbx
	call	memset@PLT
	movl	$24, %edi
	movq	%rbx, 8(%r15)
.LEHB28:
	call	_Znwm@PLT
.LEHE28:
	movq	%r12, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, (%rsp)
.LEHB29:
	call	_Znwm@PLT
.LEHE29:
	movq	%rax, %rbx
	movq	32(%rsp), %rax
	movq	(%rsp), %rdi
	movq	%rbp, %rdx
	xorl	%esi, %esi
	addq	%rbx, %rax
	movq	%rbx, (%rdi)
	movq	%rbx, 8(%rdi)
	movq	%rax, 16(%rdi)
	movq	%rbx, %rdi
	addq	%rbp, %rbx
	call	memset@PLT
	movq	(%rsp), %rax
.L307:
	movdqa	.LC1(%rip), %xmm4
	movabsq	$9223372036854775807, %rbp
	leaq	80(%rsp), %r15
	movq	%rbx, 8(%rax)
	movl	$100, %ebx
	movaps	%xmm4, 80(%rsp)
	jmp	.L288
	.p2align 4,,10
	.p2align 3
.L442:
	movq	80(%rsp), %rbp
.L288:
	movq	%r14, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	(%rsp), %rsi
	movq	8(%rsp), %rdi
	movq	96(%rsp), %r12
	movq	104(%rsp), %r13
.LEHB30:
	call	_ZNSt6vectorIsSaIsEEaSERKS1_
	movq	%r14, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	104(%rsp), %rcx
	movq	96(%rsp), %rsi
	subq	%r13, %rcx
	subq	%r12, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, 96(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	movq	%r15, %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%rsi, %rbp
	movq	%rcx, 104(%rsp)
	jl	.L286
	cmpq	88(%rsp), %rcx
	movq	%r14, %rax
	cmovg	%r15, %rax
.L286:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbx
	movq	%rax, 80(%rsp)
	movq	%rdx, 88(%rsp)
	jne	.L442
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	80(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk@PLT
	movq	(%rsp), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	200(%rax), %ebx
	movq	8(%rsp), %rax
	movq	(%rax), %rax
	movl	200(%rax), %esi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L237
	cmpb	$0, 56(%rbx)
	je	.L289
	movsbl	67(%rbx), %esi
.L290:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	8(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L291
	call	_ZdlPv@PLT
.L291:
	movq	8(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L292
	call	_ZdlPv@PLT
.L292:
	movq	(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	120(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L443
	addq	$136, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L280:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L281
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L281
.L259:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L260
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L260
.L235:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%r13), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L236
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L236
.L238:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L239
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L239
.L289:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L290
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L290
.L257:
	movq	%r15, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r15d
	orq	%r15, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L258
.L232:
	movq	%r9, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r9d
	orq	%r9, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L233
.L217:
	movq	$0, 16(%rbx)
	movl	$24, %edi
	xorl	%ebx, %ebx
	call	_Znwm@PLT
	xorl	%ebp, %ebp
	movq	%rax, 48(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, 32(%rsp)
	jmp	.L304
.L433:
	movq	32(%rsp), %rbx
	movl	$24, %edi
	movq	%rbx, 16(%rbp)
	call	_Znwm@PLT
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rbx, 16(%r13)
	xorl	%ebx, %ebx
	jmp	.L305
.L440:
	movq	32(%rsp), %r15
	movl	$24, %edi
	xorl	%ebp, %ebp
	movq	%r15, 16(%rbx)
	call	_Znwm@PLT
	movq	%rax, (%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%r15, 16(%rax)
	jmp	.L306
.L441:
	movq	32(%rsp), %rbx
	movq	%rax, %rdi
	movq	%rbx, 16(%rdi)
	movl	$24, %edi
	call	_Znwm@PLT
	movq	%rbx, 16(%rax)
	movq	%rax, (%rsp)
	xorl	%ebx, %ebx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	jmp	.L307
.L325:
.L422:
	movq	(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L439:
	call	_ZSt17__throw_bad_allocv@PLT
.L443:
	call	__stack_chk_fail@PLT
.L324:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
	call	_Unwind_Resume@PLT
.L237:
	call	_ZSt16__throw_bad_castv@PLT
.L322:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L323:
	movq	%rax, %rbx
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L320:
	movq	56(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L321:
	movq	48(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L326:
	movq	8(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.LEHE30:
.L327:
	jmp	.L422
	.cfi_endproc
.LFE7062:
	.section	.gcc_except_table._Z4funcIsEvm,"aG",@progbits,_Z4funcIsEvm,comdat
.LLSDA7062:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7062-.LLSDACSB7062
.LLSDACSB7062:
	.uleb128 .LEHB14-.LFB7062
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB15-.LFB7062
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L320-.LFB7062
	.uleb128 0
	.uleb128 .LEHB16-.LFB7062
	.uleb128 .LEHE16-.LEHB16
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB17-.LFB7062
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L321-.LFB7062
	.uleb128 0
	.uleb128 .LEHB18-.LFB7062
	.uleb128 .LEHE18-.LEHB18
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB19-.LFB7062
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L322-.LFB7062
	.uleb128 0
	.uleb128 .LEHB20-.LFB7062
	.uleb128 .LEHE20-.LEHB20
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB21-.LFB7062
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L323-.LFB7062
	.uleb128 0
	.uleb128 .LEHB22-.LFB7062
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB23-.LFB7062
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L324-.LFB7062
	.uleb128 0
	.uleb128 .LEHB24-.LFB7062
	.uleb128 .LEHE24-.LEHB24
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB25-.LFB7062
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L325-.LFB7062
	.uleb128 0
	.uleb128 .LEHB26-.LFB7062
	.uleb128 .LEHE26-.LEHB26
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB27-.LFB7062
	.uleb128 .LEHE27-.LEHB27
	.uleb128 .L326-.LFB7062
	.uleb128 0
	.uleb128 .LEHB28-.LFB7062
	.uleb128 .LEHE28-.LEHB28
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB29-.LFB7062
	.uleb128 .LEHE29-.LEHB29
	.uleb128 .L327-.LFB7062
	.uleb128 0
	.uleb128 .LEHB30-.LFB7062
	.uleb128 .LEHE30-.LEHB30
	.uleb128 0
	.uleb128 0
.LLSDACSE7062:
	.section	.text._Z4funcIsEvm,"axG",@progbits,_Z4funcIsEvm,comdat
	.size	_Z4funcIsEvm, .-_Z4funcIsEvm
	.section	.text._ZNSt6vectorIiSaIiEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIiSaIiEEaSERKS1_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIiSaIiEEaSERKS1_
	.type	_ZNSt6vectorIiSaIiEEaSERKS1_, @function
_ZNSt6vectorIiSaIiEEaSERKS1_:
.LFB7187:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	cmpq	%rdi, %rsi
	je	.L445
	movq	8(%rsi), %rax
	movq	(%rsi), %r15
	movq	%rsi, %r12
	movq	(%rdi), %r13
	movq	16(%rdi), %rcx
	movq	%rax, %rbp
	subq	%r15, %rbp
	subq	%r13, %rcx
	movq	%rbp, %r14
	sarq	$2, %rcx
	sarq	$2, %r14
	cmpq	%r14, %rcx
	jb	.L468
	movq	8(%rdi), %rdi
	movq	%rdi, %rsi
	subq	%r13, %rsi
	movq	%rsi, %rdx
	sarq	$2, %rdx
	cmpq	%rdx, %r14
	jbe	.L469
	testq	%rdx, %rdx
	jne	.L470
.L455:
	addq	%r15, %rsi
	subq	%rsi, %rax
	movq	%rax, %rdx
	sarq	$2, %rdx
	testq	%rdx, %rdx
	jne	.L456
.L467:
	addq	%r13, %rbp
.L452:
	movq	%rbp, 8(%rbx)
.L445:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L469:
	.cfi_restore_state
	testq	%r14, %r14
	je	.L467
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%r13, %rdi
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L452
	.p2align 4,,10
	.p2align 3
.L468:
	xorl	%r12d, %r12d
	testq	%r14, %r14
	je	.L450
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %r14
	ja	.L471
	movq	%rbp, %rdi
	call	_Znwm@PLT
	testq	%r14, %r14
	movq	%rax, %r12
	movq	(%rbx), %r13
	jne	.L472
.L450:
	testq	%r13, %r13
	je	.L451
.L473:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
.L451:
	addq	%r12, %rbp
	movq	%r12, (%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L452
	.p2align 4,,10
	.p2align 3
.L472:
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%rax, %rdi
	call	memmove@PLT
	testq	%r13, %r13
	jne	.L473
	jmp	.L451
	.p2align 4,,10
	.p2align 3
.L456:
	movq	%rax, %rdx
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L452
	.p2align 4,,10
	.p2align 3
.L470:
	movq	%r13, %rdi
	movq	%rsi, %rdx
	movq	%r15, %rsi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r13
	movq	(%r12), %r15
	movq	8(%r12), %rax
	movq	%rdi, %rsi
	subq	%r13, %rsi
	jmp	.L455
.L471:
	call	_ZSt17__throw_bad_allocv@PLT
	.cfi_endproc
.LFE7187:
	.size	_ZNSt6vectorIiSaIiEEaSERKS1_, .-_ZNSt6vectorIiSaIiEEaSERKS1_
	.section	.text._Z4funcIiEvm,"axG",@progbits,_Z4funcIiEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIiEvm
	.type	_Z4funcIiEvm, @function
_Z4funcIiEvm:
.LFB7063:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7063
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$136, %rsp
	.cfi_def_cfa_offset 192
	movq	%rdi, 72(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 120(%rsp)
	xorl	%eax, %eax
.LEHB31:
	call	_Znwm@PLT
.LEHE31:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movq	%rax, 56(%rsp)
	movl	$104857600, %eax
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	divq	%r15
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, 64(%rsp)
	je	.L475
	salq	$2, %rax
	movq	%rax, %rdi
	movq	%rax, %r14
	movq	%rax, 40(%rsp)
.LEHB32:
	call	_Znwm@PLT
.LEHE32:
	movq	%rbx, %r15
	movq	%rax, (%rbx)
	movq	%r14, %rbx
	addq	%rax, %rbx
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r15)
	call	memset@PLT
	movl	$24, %edi
	movq	%rbx, 8(%r15)
.LEHB33:
	call	_Znwm@PLT
.LEHE33:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbp
	movq	%rax, 48(%rsp)
.LEHB34:
	call	_Znwm@PLT
.LEHE34:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	movq	%r14, %rdx
	movq	%rbx, 0(%rbp)
	movq	%rbx, 8(%rbp)
	leaq	(%rbx,%r14), %rbp
	xorl	%esi, %esi
	movq	%rbp, 16(%rdi)
	movq	%rbx, %rdi
	call	memset@PLT
	movq	48(%rsp), %rax
.L556:
	movq	%rbp, 8(%rax)
	movq	56(%rsp), %rax
	movq	%rbx, %r10
	movl	$100, %r9d
	movq	$-1, %r8
	movq	(%rax), %rdi
	movq	8(%rax), %rsi
	leaq	4(%rdi), %rax
	movq	%rsi, %rcx
	subq	%rax, %rcx
	movq	%rax, 8(%rsp)
	movq	%rcx, %rax
	leaq	16(%rbx), %rcx
	shrq	$2, %rax
	cmpq	%rcx, %rdi
	leaq	16(%rdi), %rcx
	leaq	1(%rax), %rdx
	setnb	%r11b
	cmpq	%rcx, %rbx
	setnb	%cl
	orl	%ecx, %r11d
	cmpq	$12, %rdx
	seta	%cl
	shrq	$2, %r10
	negq	%r10
	andl	%ecx, %r11d
	andl	$3, %r10d
	cmpq	%rdx, %r10
	cmova	%rdx, %r10
	subq	%r10, %rdx
	subq	%r10, %rax
	leaq	0(,%r10,4), %r12
	leaq	-4(%rdx), %rbp
	movq	%rax, (%rsp)
	movq	%rdx, 24(%rsp)
	leaq	(%rbx,%r12), %r13
	addq	%rdi, %r12
	shrq	$2, %rbp
	addq	$1, %rbp
	leaq	0(,%rbp,4), %rcx
	movq	%rbp, %rax
	salq	$4, %rax
	movq	%rcx, 32(%rsp)
	movq	%rax, 16(%rsp)
	jmp	.L478
	.p2align 4,,10
	.p2align 3
.L651:
	movl	(%rbx), %eax
	cmpq	$1, %r10
	leaq	4(%rbx), %rdx
	movl	%eax, (%rdi)
	movq	8(%rsp), %rax
	je	.L480
	movl	4(%rbx), %eax
	cmpq	$3, %r10
	leaq	8(%rbx), %rdx
	movl	%eax, 4(%rdi)
	leaq	8(%rdi), %rax
	jne	.L480
	movl	8(%rbx), %eax
	leaq	12(%rbx), %rdx
	movl	%eax, 8(%rdi)
	leaq	12(%rdi), %rax
.L480:
	cmpq	$2, (%rsp)
	jbe	.L482
	xorl	%r14d, %r14d
	xorl	%r15d, %r15d
.L483:
	movdqa	0(%r13,%r14), %xmm0
	addq	$1, %r15
	movups	%xmm0, (%r12,%r14)
	addq	$16, %r14
	cmpq	%rbp, %r15
	jb	.L483
	movq	16(%rsp), %r15
	movq	32(%rsp), %r14
	addq	%r15, %rax
	addq	%r15, %rdx
	cmpq	%r14, 24(%rsp)
	je	.L487
.L482:
	movl	(%rdx), %r14d
	movl	%r14d, (%rax)
	leaq	4(%rax), %r14
	cmpq	%r14, %rsi
	je	.L487
	movl	4(%rdx), %r14d
	movl	%r14d, 4(%rax)
	leaq	8(%rax), %r14
	cmpq	%r14, %rsi
	je	.L487
	movl	8(%rdx), %edx
	movl	%edx, 8(%rax)
.L487:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%eax, %r14d
	movq	%rdx, %rax
	salq	$32, %rax
	orq	%r14, %rax
	subq	%rcx, %rax
	cmpq	%rax, %r8
	cmova	%rax, %r8
	subq	$1, %r9
	je	.L650
.L478:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%edx, %ecx
	movl	%eax, %eax
	salq	$32, %rcx
	orq	%rax, %rcx
	cmpq	%rsi, %rdi
	je	.L487
	testb	%r11b, %r11b
	je	.L479
	testq	%r10, %r10
	jne	.L651
	movq	%rbx, %rdx
	movq	%rdi, %rax
	jmp	.L480
	.p2align 4,,10
	.p2align 3
.L479:
	movq	%rdi, %rax
	movq	%rbx, %rdx
	.p2align 4,,10
	.p2align 3
.L488:
	movl	(%rdx), %r14d
	addq	$4, %rax
	addq	$4, %rdx
	movl	%r14d, -4(%rax)
	cmpq	%rax, %rsi
	jne	.L488
	jmp	.L487
.L650:
	pxor	%xmm4, %xmm4
	testq	%r8, %r8
	movl	400(%rbx), %ebx
	movl	400(%rdi), %ebp
	cvtsi2sdq	64(%rsp), %xmm4
	movsd	%xmm4, 24(%rsp)
	js	.L490
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r8, %xmm0
.L491:
	divsd	24(%rsp), %xmm0
	movq	72(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movsd	%xmm0, (%rsp)
.LEHB35:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %r12
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r13
	testq	%r13, %r13
	je	.L495
	cmpb	$0, 56(%r13)
	je	.L493
	movsbl	67(%r13), %esi
.L494:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movsd	(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L495
	cmpb	$0, 56(%rbx)
	je	.L496
	movsbl	67(%rbx), %esi
.L497:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	56(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L498
	call	_ZdlPv@PLT
.L498:
	movq	56(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	48(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L499
	call	_ZdlPv@PLT
.L499:
	movq	48(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE35:
	movq	64(%rsp), %rbx
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%rbx, %rbx
	je	.L500
	movq	40(%rsp), %r15
	movq	%r15, %rdi
.LEHB36:
	call	_Znwm@PLT
.LEHE36:
	movq	%rax, %r12
	movq	%rax, 0(%rbp)
	leaq	0(,%rbx,4), %rbx
	movq	%r15, %rax
	movq	%r12, %rdi
	xorl	%esi, %esi
	addq	%r12, %rax
	movq	%rbx, %rdx
	addq	%rbx, %r12
	movq	%rax, 16(%rbp)
	call	memset@PLT
	movl	$24, %edi
	movq	%r12, 8(%rbp)
.LEHB37:
	call	_Znwm@PLT
.LEHE37:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r13
.LEHB38:
	call	_Znwm@PLT
.LEHE38:
	movq	%rax, %r12
	movq	%rax, 0(%r13)
	movq	%rax, 8(%r13)
	movq	%r15, %rax
	movq	%rbx, %rdx
	xorl	%esi, %esi
	addq	%r12, %rax
	movq	%r12, %rdi
	addq	%r12, %rbx
	movq	%rax, 16(%r13)
	call	memset@PLT
.L557:
	movq	%rbx, 8(%r13)
	movq	0(%rbp), %r15
	movl	$100, %r12d
	movq	0(%r13), %rsi
	movq	$-1, %r14
	jmp	.L513
	.p2align 4,,10
	.p2align 3
.L655:
	testq	%r8, %r8
	jne	.L652
.L644:
	leaq	(%r15,%rbx), %rcx
.L508:
	movq	%rcx, 8(%rbp)
.L501:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	(%rsp), %rax
	cmpq	%rax, %r14
	cmova	%rax, %r14
	subq	$1, %r12
	je	.L653
.L513:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%rbp, %r13
	movq	%rdx, (%rsp)
	je	.L501
	movq	8(%r13), %r9
	movq	16(%rbp), %rax
	movq	%r9, %rbx
	subq	%r15, %rax
	subq	%rsi, %rbx
	sarq	$2, %rax
	movq	%rbx, %r8
	sarq	$2, %r8
	cmpq	%rax, %r8
	ja	.L654
	movq	8(%rbp), %rdi
	movq	%rdi, %rdx
	subq	%r15, %rdx
	movq	%rdx, %rax
	sarq	$2, %rax
	cmpq	%rax, %r8
	jbe	.L655
	testq	%rax, %rax
	jne	.L656
.L511:
	leaq	(%rsi,%rdx), %rax
	subq	%rax, %r9
	movq	%r9, %rdx
	sarq	$2, %rdx
	testq	%rdx, %rdx
	je	.L644
	movq	%rax, %rsi
	movq	%r9, %rdx
	call	memmove@PLT
	movq	0(%rbp), %r15
	movq	0(%r13), %rsi
	leaq	(%r15,%rbx), %rcx
	jmp	.L508
	.p2align 4,,10
	.p2align 3
.L654:
	movq	%r15, %r9
	xorl	%r15d, %r15d
	testq	%r8, %r8
	je	.L506
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %r8
	ja	.L657
	movq	%rbx, %rdi
	movq	%rsi, 16(%rsp)
	movq	%r8, 8(%rsp)
.LEHB39:
	call	_Znwm@PLT
	movq	8(%rsp), %r8
	movq	%rax, %r15
	movq	0(%rbp), %r9
	movq	16(%rsp), %rsi
	testq	%r8, %r8
	je	.L506
	movq	%rbx, %rdx
	movq	%rax, %rdi
	movq	%r9, 8(%rsp)
	call	memmove@PLT
	movq	8(%rsp), %r9
.L506:
	testq	%r9, %r9
	je	.L507
	movq	%r9, %rdi
	call	_ZdlPv@PLT
.L507:
	leaq	(%r15,%rbx), %rcx
	movq	%r15, 0(%rbp)
	movq	0(%r13), %rsi
	movq	%rcx, 16(%rbp)
	jmp	.L508
	.p2align 4,,10
	.p2align 3
.L656:
	movq	%r15, %rdi
	call	memmove@PLT
	movq	8(%rbp), %rdi
	movq	0(%rbp), %r15
	movq	0(%r13), %rsi
	movq	8(%r13), %r9
	movq	%rdi, %rdx
	subq	%r15, %rdx
	jmp	.L511
	.p2align 4,,10
	.p2align 3
.L652:
	movq	%r15, %rdi
	movq	%rbx, %rdx
	call	memmove@PLT
	movq	0(%rbp), %r15
	movq	0(%r13), %rsi
	leaq	(%r15,%rbx), %rcx
	jmp	.L508
.L653:
	testq	%r14, %r14
	movl	400(%rsi), %ebx
	movl	400(%r15), %r12d
	js	.L514
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r14, %xmm0
.L515:
	divsd	24(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L495
	cmpb	$0, 56(%rbx)
	je	.L516
	movsbl	67(%rbx), %esi
.L517:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L518
	call	_ZdlPv@PLT
.L518:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L519
	call	_ZdlPv@PLT
.L519:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE39:
	movq	64(%rsp), %r15
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%r15, %r15
	je	.L520
	movq	40(%rsp), %r14
	movq	%r14, %rdi
.LEHB40:
	call	_Znwm@PLT
.LEHE40:
	movq	%rax, %r12
	leaq	0(,%r15,4), %rbp
	movq	%rax, (%rbx)
	movq	%r14, %rax
	movq	%r12, %rdi
	xorl	%esi, %esi
	addq	%r12, %rax
	movq	%rbp, %rdx
	addq	%rbp, %r12
	movq	%rax, 16(%rbx)
	call	memset@PLT
	movl	$24, %edi
	movq	%r12, 8(%rbx)
.LEHB41:
	call	_Znwm@PLT
.LEHE41:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, (%rsp)
.LEHB42:
	call	_Znwm@PLT
.LEHE42:
	movq	%rax, %r12
	movq	%r14, %rax
	movq	%rbp, %rdx
	addq	%r12, %rax
	movq	%r12, (%r15)
	movq	%r12, 8(%r15)
	movq	%rax, 16(%r15)
	xorl	%esi, %esi
	movq	%r12, %rdi
	call	memset@PLT
	movq	(%rsp), %rax
	addq	%r12, %rbp
.L558:
	movq	%rbp, 8(%rax)
	leaq	80(%rsp), %rax
	movl	$100, %r15d
	movdqa	.LC1(%rip), %xmm7
	movabsq	$9223372036854775807, %rbp
	leaq	96(%rsp), %r14
	movq	%rax, 8(%rsp)
	movaps	%xmm7, 80(%rsp)
	jmp	.L535
	.p2align 4,,10
	.p2align 3
.L658:
	movq	8(%rsp), %rax
.L523:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %r15
	movq	%rax, 80(%rsp)
	movq	%rdx, 88(%rsp)
	je	.L534
	movq	80(%rsp), %rbp
.L535:
	movl	$4, %edi
	movq	%r14, %rsi
	call	clock_gettime@PLT
	movq	(%rsp), %rdi
	movq	(%rbx), %rax
	movq	96(%rsp), %r13
	movq	104(%rsp), %r12
	movq	(%rdi), %rdx
	movq	8(%rbx), %rdi
	cmpq	%rdi, %rax
	je	.L531
	leaq	4(%rax), %rsi
	movq	%rdi, %rcx
	leaq	16(%rdx), %r8
	subq	%rsi, %rcx
	shrq	$2, %rcx
	addq	$1, %rcx
	cmpq	%r8, %rax
	leaq	16(%rax), %r8
	setnb	%r9b
	cmpq	%r8, %rdx
	setnb	%r8b
	orb	%r8b, %r9b
	je	.L532
	cmpq	$12, %rcx
	jbe	.L532
	movq	%rdx, %r10
	shrq	$2, %r10
	negq	%r10
	andl	$3, %r10d
	je	.L566
	movl	(%rdx), %r8d
	cmpq	$1, %r10
	leaq	4(%rdx), %r9
	movl	%r8d, (%rax)
	je	.L525
	movl	4(%rdx), %esi
	cmpq	$3, %r10
	leaq	8(%rdx), %r9
	movl	%esi, 4(%rax)
	leaq	8(%rax), %rsi
	jne	.L525
	movl	8(%rdx), %esi
	leaq	12(%rdx), %r9
	movl	%esi, 8(%rax)
	leaq	12(%rax), %rsi
.L525:
	subq	%r10, %rcx
	salq	$2, %r10
	leaq	-4(%rcx), %r8
	addq	%r10, %rdx
	addq	%r10, %rax
	xorl	%r10d, %r10d
	shrq	$2, %r8
	addq	$1, %r8
	leaq	0(,%r8,4), %r11
	movq	%r11, 16(%rsp)
	xorl	%r11d, %r11d
.L527:
	movdqa	(%rdx,%r10), %xmm0
	addq	$1, %r11
	movups	%xmm0, (%rax,%r10)
	addq	$16, %r10
	cmpq	%r11, %r8
	ja	.L527
	movq	16(%rsp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rax, %rsi
	addq	%rax, %r9
	cmpq	%rdx, %rcx
	je	.L531
	movl	(%r9), %eax
	movl	%eax, (%rsi)
	leaq	4(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L531
	movl	4(%r9), %eax
	movl	%eax, 4(%rsi)
	leaq	8(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L531
	movl	8(%r9), %eax
	movl	%eax, 8(%rsi)
.L531:
	movq	%r14, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	104(%rsp), %rcx
	movq	96(%rsp), %rsi
	subq	%r12, %rcx
	subq	%r13, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, 96(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%rbp, %rsi
	movq	%rcx, 104(%rsp)
	jg	.L658
	cmpq	88(%rsp), %rcx
	movq	8(%rsp), %rax
	cmovle	%r14, %rax
	jmp	.L523
	.p2align 4,,10
	.p2align 3
.L532:
	movl	(%rdx), %ecx
	addq	$4, %rax
	addq	$4, %rdx
	movl	%ecx, -4(%rax)
	cmpq	%rax, %rdi
	jne	.L532
	jmp	.L531
	.p2align 4,,10
	.p2align 3
.L566:
	movq	%rdx, %r9
	movq	%rax, %rsi
	jmp	.L525
.L534:
	movq	(%rsp), %rax
	movq	72(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	400(%rax), %ebp
	movq	(%rbx), %rax
	movl	400(%rax), %r12d
.LEHB43:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %r13
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	%r12d, %esi
	movq	%r13, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L495
	cmpb	$0, 56(%rbp)
	je	.L536
	movsbl	67(%rbp), %esi
.L537:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	80(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L538
	call	_ZdlPv@PLT
.L538:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L539
	call	_ZdlPv@PLT
.L539:
	movq	(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE43:
	movq	64(%rsp), %rbp
	movq	%rax, %r15
	movq	%rax, 8(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%rbp, %rbp
	je	.L540
	movq	40(%rsp), %r12
	movq	%r12, %rdi
.LEHB44:
	call	_Znwm@PLT
.LEHE44:
	movq	%rax, %rbx
	movq	%r12, %rax
	xorl	%esi, %esi
	addq	%rbx, %rax
	movq	%rbx, (%r15)
	movq	%rbx, %rdi
	movq	%rax, 16(%r15)
	movq	%rbp, %rax
	salq	$2, %rax
	movq	%rax, %rbp
	movq	%rax, %rdx
	addq	%rbp, %rbx
	call	memset@PLT
	movq	%rbx, 8(%r15)
	movl	$24, %edi
.LEHB45:
	call	_Znwm@PLT
.LEHE45:
	movq	%r12, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, (%rsp)
.LEHB46:
	call	_Znwm@PLT
.LEHE46:
	movq	%rax, %rbx
	movq	%r12, %rax
	movq	%rbp, %rdx
	addq	%rbx, %rax
	movq	%rbx, (%r15)
	movq	%rbx, 8(%r15)
	movq	%rbx, %rdi
	movq	%rax, 16(%r15)
	xorl	%esi, %esi
	call	memset@PLT
	movq	(%rsp), %rax
	addq	%rbp, %rbx
.L559:
	movdqa	.LC1(%rip), %xmm4
	movabsq	$9223372036854775807, %rbp
	leaq	80(%rsp), %r15
	movq	%rbx, 8(%rax)
	movl	$100, %ebx
	movaps	%xmm4, 80(%rsp)
	jmp	.L543
	.p2align 4,,10
	.p2align 3
.L659:
	movq	80(%rsp), %rbp
.L543:
	movq	%r14, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	(%rsp), %rsi
	movq	8(%rsp), %rdi
	movq	96(%rsp), %r12
	movq	104(%rsp), %r13
.LEHB47:
	call	_ZNSt6vectorIiSaIiEEaSERKS1_
	movq	%r14, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	104(%rsp), %rcx
	movq	96(%rsp), %rsi
	subq	%r13, %rcx
	subq	%r12, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, 96(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	movq	%r15, %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%rbp, %rsi
	movq	%rcx, 104(%rsp)
	jg	.L541
	cmpq	88(%rsp), %rcx
	movq	%r14, %rax
	cmovg	%r15, %rax
.L541:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbx
	movq	%rax, 80(%rsp)
	movq	%rdx, 88(%rsp)
	jne	.L659
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	80(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk@PLT
	movq	(%rsp), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	400(%rax), %ebx
	movq	8(%rsp), %rax
	movq	(%rax), %rax
	movl	400(%rax), %esi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L495
	cmpb	$0, 56(%rbx)
	je	.L544
	movsbl	67(%rbx), %esi
.L545:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	8(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L546
	call	_ZdlPv@PLT
.L546:
	movq	8(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L547
	call	_ZdlPv@PLT
.L547:
	movq	(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	120(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L660
	addq	$136, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L536:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L537
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L537
.L516:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L517
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L517
.L496:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L497
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L497
.L493:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%r13), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L494
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L494
.L544:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L545
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L545
.L514:
	movq	%r14, %rax
	movq	%r14, %rcx
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %ecx
	orq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L515
.L490:
	movq	%r8, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r8d
	orq	%r8, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L491
.L475:
	movq	$0, 16(%rbx)
	movl	$24, %edi
	xorl	%ebx, %ebx
	call	_Znwm@PLT
	xorl	%ebp, %ebp
	movq	%rax, 48(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, 40(%rsp)
	jmp	.L556
.L500:
	movq	40(%rsp), %rbx
	movl	$24, %edi
	movq	%rbx, 16(%rbp)
	call	_Znwm@PLT
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rbx, 16(%r13)
	xorl	%ebx, %ebx
	jmp	.L557
.L520:
	movq	40(%rsp), %r15
	movl	$24, %edi
	xorl	%ebp, %ebp
	movq	%r15, 16(%rbx)
	call	_Znwm@PLT
	movq	%rax, (%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%r15, 16(%rax)
	jmp	.L558
.L540:
	movq	40(%rsp), %rbx
	movq	%r15, %rdi
	movq	%rbx, 16(%rdi)
	movl	$24, %edi
	call	_Znwm@PLT
	movq	%rbx, 16(%rax)
	movq	%rax, (%rsp)
	xorl	%ebx, %ebx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	jmp	.L559
.L577:
.L645:
	movq	(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L657:
	call	_ZSt17__throw_bad_allocv@PLT
.L660:
	call	__stack_chk_fail@PLT
.L576:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
	call	_Unwind_Resume@PLT
.L495:
	call	_ZSt16__throw_bad_castv@PLT
.L574:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L575:
	movq	%rax, %rbx
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L572:
	movq	56(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L573:
	movq	48(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L578:
	movq	8(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.LEHE47:
.L579:
	jmp	.L645
	.cfi_endproc
.LFE7063:
	.section	.gcc_except_table._Z4funcIiEvm,"aG",@progbits,_Z4funcIiEvm,comdat
.LLSDA7063:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7063-.LLSDACSB7063
.LLSDACSB7063:
	.uleb128 .LEHB31-.LFB7063
	.uleb128 .LEHE31-.LEHB31
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB32-.LFB7063
	.uleb128 .LEHE32-.LEHB32
	.uleb128 .L572-.LFB7063
	.uleb128 0
	.uleb128 .LEHB33-.LFB7063
	.uleb128 .LEHE33-.LEHB33
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB34-.LFB7063
	.uleb128 .LEHE34-.LEHB34
	.uleb128 .L573-.LFB7063
	.uleb128 0
	.uleb128 .LEHB35-.LFB7063
	.uleb128 .LEHE35-.LEHB35
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB36-.LFB7063
	.uleb128 .LEHE36-.LEHB36
	.uleb128 .L574-.LFB7063
	.uleb128 0
	.uleb128 .LEHB37-.LFB7063
	.uleb128 .LEHE37-.LEHB37
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB38-.LFB7063
	.uleb128 .LEHE38-.LEHB38
	.uleb128 .L575-.LFB7063
	.uleb128 0
	.uleb128 .LEHB39-.LFB7063
	.uleb128 .LEHE39-.LEHB39
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB40-.LFB7063
	.uleb128 .LEHE40-.LEHB40
	.uleb128 .L576-.LFB7063
	.uleb128 0
	.uleb128 .LEHB41-.LFB7063
	.uleb128 .LEHE41-.LEHB41
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB42-.LFB7063
	.uleb128 .LEHE42-.LEHB42
	.uleb128 .L577-.LFB7063
	.uleb128 0
	.uleb128 .LEHB43-.LFB7063
	.uleb128 .LEHE43-.LEHB43
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB44-.LFB7063
	.uleb128 .LEHE44-.LEHB44
	.uleb128 .L578-.LFB7063
	.uleb128 0
	.uleb128 .LEHB45-.LFB7063
	.uleb128 .LEHE45-.LEHB45
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB46-.LFB7063
	.uleb128 .LEHE46-.LEHB46
	.uleb128 .L579-.LFB7063
	.uleb128 0
	.uleb128 .LEHB47-.LFB7063
	.uleb128 .LEHE47-.LEHB47
	.uleb128 0
	.uleb128 0
.LLSDACSE7063:
	.section	.text._Z4funcIiEvm,"axG",@progbits,_Z4funcIiEvm,comdat
	.size	_Z4funcIiEvm, .-_Z4funcIiEvm
	.section	.text._ZNSt6vectorIlSaIlEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIlSaIlEEaSERKS1_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIlSaIlEEaSERKS1_
	.type	_ZNSt6vectorIlSaIlEEaSERKS1_, @function
_ZNSt6vectorIlSaIlEEaSERKS1_:
.LFB7208:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	cmpq	%rdi, %rsi
	je	.L662
	movq	8(%rsi), %rax
	movq	(%rsi), %r15
	movq	%rsi, %r12
	movq	(%rdi), %r13
	movq	16(%rdi), %rcx
	movq	%rax, %rbp
	subq	%r15, %rbp
	subq	%r13, %rcx
	movq	%rbp, %r14
	sarq	$3, %rcx
	sarq	$3, %r14
	cmpq	%r14, %rcx
	jb	.L685
	movq	8(%rdi), %rdi
	movq	%rdi, %rsi
	subq	%r13, %rsi
	movq	%rsi, %rdx
	sarq	$3, %rdx
	cmpq	%rdx, %r14
	jbe	.L686
	testq	%rdx, %rdx
	jne	.L687
.L672:
	addq	%r15, %rsi
	subq	%rsi, %rax
	movq	%rax, %rdx
	sarq	$3, %rdx
	testq	%rdx, %rdx
	jne	.L673
.L684:
	addq	%r13, %rbp
.L669:
	movq	%rbp, 8(%rbx)
.L662:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L686:
	.cfi_restore_state
	testq	%r14, %r14
	je	.L684
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%r13, %rdi
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L669
	.p2align 4,,10
	.p2align 3
.L685:
	xorl	%r12d, %r12d
	testq	%r14, %r14
	je	.L667
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %r14
	ja	.L688
	movq	%rbp, %rdi
	call	_Znwm@PLT
	testq	%r14, %r14
	movq	%rax, %r12
	movq	(%rbx), %r13
	jne	.L689
.L667:
	testq	%r13, %r13
	je	.L668
.L690:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
.L668:
	addq	%r12, %rbp
	movq	%r12, (%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L669
	.p2align 4,,10
	.p2align 3
.L689:
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%rax, %rdi
	call	memmove@PLT
	testq	%r13, %r13
	jne	.L690
	jmp	.L668
	.p2align 4,,10
	.p2align 3
.L673:
	movq	%rax, %rdx
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L669
	.p2align 4,,10
	.p2align 3
.L687:
	movq	%r13, %rdi
	movq	%rsi, %rdx
	movq	%r15, %rsi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r13
	movq	(%r12), %r15
	movq	8(%r12), %rax
	movq	%rdi, %rsi
	subq	%r13, %rsi
	jmp	.L672
.L688:
	call	_ZSt17__throw_bad_allocv@PLT
	.cfi_endproc
.LFE7208:
	.size	_ZNSt6vectorIlSaIlEEaSERKS1_, .-_ZNSt6vectorIlSaIlEEaSERKS1_
	.section	.text._Z4funcIlEvm,"axG",@progbits,_Z4funcIlEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIlEvm
	.type	_Z4funcIlEvm, @function
_Z4funcIlEvm:
.LFB7064:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7064
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$136, %rsp
	.cfi_def_cfa_offset 192
	movq	%rdi, 72(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 120(%rsp)
	xorl	%eax, %eax
.LEHB48:
	call	_Znwm@PLT
.LEHE48:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movq	%rax, 56(%rsp)
	movl	$104857600, %eax
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	divq	%r15
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, 64(%rsp)
	je	.L692
	salq	$3, %rax
	movq	%rax, %rdi
	movq	%rax, %r14
	movq	%rax, 40(%rsp)
.LEHB49:
	call	_Znwm@PLT
.LEHE49:
	movq	%rbx, %r15
	movq	%rax, (%rbx)
	movq	%r14, %rbx
	addq	%rax, %rbx
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rbx, 16(%r15)
	movq	%rax, %rdi
	call	memset@PLT
	movq	%rbx, 8(%r15)
	movl	$24, %edi
.LEHB50:
	call	_Znwm@PLT
.LEHE50:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, 48(%rsp)
.LEHB51:
	call	_Znwm@PLT
.LEHE51:
	movq	%rax, %rbp
	movq	%r14, %rbx
	movq	%r14, %rdx
	addq	%rbp, %rbx
	movq	%rbp, (%r15)
	movq	%rbp, 8(%r15)
	movq	%rbx, 16(%r15)
	xorl	%esi, %esi
	movq	%rbp, %rdi
	call	memset@PLT
	movq	48(%rsp), %rax
.L765:
	movq	%rbx, 8(%rax)
	movq	56(%rsp), %rax
	leaq	16(%rbp), %rdx
	movq	%rbp, %r13
	movl	$100, %r8d
	movq	$-1, %rsi
	movq	(%rax), %r9
	movq	8(%rax), %rdi
	leaq	8(%r9), %rax
	movq	%rdi, %rbx
	subq	%rax, %rbx
	movq	%rax, (%rsp)
	movq	%rbx, %rax
	shrq	$3, %rax
	addq	$1, %rax
	cmpq	%rdx, %r9
	leaq	16(%r9), %rdx
	setnb	%r12b
	cmpq	%rdx, %rbp
	setnb	%dl
	orl	%edx, %r12d
	cmpq	$24, %rax
	seta	%dl
	shrq	$3, %r13
	andl	$1, %r13d
	andl	%edx, %r12d
	subq	%r13, %rax
	leaq	0(,%r13,8), %r11
	leaq	-2(%rax), %r10
	movq	%rax, 16(%rsp)
	leaq	0(%rbp,%r11), %rbx
	addq	%r9, %r11
	shrq	%r10
	addq	$1, %r10
	leaq	(%r10,%r10), %rax
	movq	%rax, 24(%rsp)
	movq	%r10, %rax
	salq	$4, %rax
	movq	%rax, 32(%rsp)
	leaq	8(%rbp), %rax
	movq	%rax, 8(%rsp)
	.p2align 4,,10
	.p2align 3
.L695:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%edx, %r14d
	movl	%eax, %eax
	salq	$32, %r14
	orq	%rax, %r14
	cmpq	%r9, %rdi
	je	.L700
	testb	%r12b, %r12b
	je	.L696
	testq	%r13, %r13
	je	.L770
	movq	0(%rbp), %rax
	movq	8(%rsp), %r15
	movq	(%rsp), %rdx
	movq	%rax, (%r9)
.L697:
	xorl	%eax, %eax
	xorl	%ecx, %ecx
.L698:
	movdqa	(%rbx,%rax), %xmm0
	addq	$1, %rcx
	movups	%xmm0, (%r11,%rax)
	addq	$16, %rax
	cmpq	%rcx, %r10
	ja	.L698
	movq	32(%rsp), %rax
	movq	24(%rsp), %rcx
	addq	%rax, %rdx
	addq	%rax, %r15
	cmpq	%rcx, 16(%rsp)
	je	.L700
	movq	(%r15), %rax
	movq	%rax, (%rdx)
.L700:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%eax, %ecx
	movq	%rdx, %rax
	salq	$32, %rax
	orq	%rcx, %rax
	subq	%r14, %rax
	cmpq	%rax, %rsi
	cmova	%rax, %rsi
	subq	$1, %r8
	jne	.L695
	pxor	%xmm4, %xmm4
	testq	%rsi, %rsi
	movl	800(%rbp), %ebx
	movl	800(%r9), %ebp
	cvtsi2sdq	64(%rsp), %xmm4
	movsd	%xmm4, (%rsp)
	js	.L703
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rsi, %xmm0
.L704:
	divsd	(%rsp), %xmm0
	movq	72(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movsd	%xmm0, 8(%rsp)
.LEHB52:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %r12
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r13
	testq	%r13, %r13
	je	.L708
	cmpb	$0, 56(%r13)
	je	.L706
	movsbl	67(%r13), %esi
.L707:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movsd	8(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L708
	cmpb	$0, 56(%rbx)
	je	.L709
	movsbl	67(%rbx), %esi
.L710:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	56(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L711
	call	_ZdlPv@PLT
.L711:
	movq	56(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	48(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L712
	call	_ZdlPv@PLT
.L712:
	movq	48(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE52:
	movq	64(%rsp), %rbx
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%rbx, %rbx
	je	.L713
	movq	40(%rsp), %r15
	movq	%r15, %rdi
.LEHB53:
	call	_Znwm@PLT
.LEHE53:
	movq	%rax, %rbp
	movq	%rax, 0(%r13)
	leaq	0(,%rbx,8), %rbx
	movq	%r15, %rax
	movq	%rbp, %rdi
	xorl	%esi, %esi
	addq	%rbp, %rax
	movq	%rbx, %rdx
	addq	%rbx, %rbp
	movq	%rax, 16(%r13)
	call	memset@PLT
	movl	$24, %edi
	movq	%rbp, 8(%r13)
.LEHB54:
	call	_Znwm@PLT
.LEHE54:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB55:
	call	_Znwm@PLT
.LEHE55:
	movq	%rax, %rbp
	movq	%rax, (%r12)
	movq	%rax, 8(%r12)
	movq	%r15, %rax
	movq	%rbx, %rdx
	xorl	%esi, %esi
	addq	%rbp, %rax
	movq	%rbp, %rdi
	addq	%rbp, %rbx
	movq	%rax, 16(%r12)
	call	memset@PLT
.L766:
	movq	%rbx, 8(%r12)
	movl	$100, %ebp
	movq	$-1, %r14
	.p2align 4,,10
	.p2align 3
.L714:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%r12, %rsi
	movq	%rdx, %rbx
	movq	%r13, %rdi
	orq	%rax, %rbx
.LEHB56:
	call	_ZNSt6vectorIlSaIlEEaSERKS1_
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rbx, %rax
	cmpq	%rax, %r14
	cmova	%rax, %r14
	subq	$1, %rbp
	jne	.L714
	movq	(%r12), %rax
	testq	%r14, %r14
	movl	800(%rax), %ebx
	movq	0(%r13), %rax
	movl	800(%rax), %ebp
	js	.L715
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r14, %xmm0
.L716:
	divsd	(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L708
	cmpb	$0, 56(%rbx)
	je	.L717
	movsbl	67(%rbx), %esi
.L718:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L719
	call	_ZdlPv@PLT
.L719:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L720
	call	_ZdlPv@PLT
.L720:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE56:
	movq	64(%rsp), %rbx
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%rbx, %rbx
	je	.L721
	movq	40(%rsp), %r14
	movq	%r14, %rdi
.LEHB57:
	call	_Znwm@PLT
.LEHE57:
	movq	%rax, %r12
	movq	%rax, 0(%rbp)
	leaq	0(,%rbx,8), %rbx
	movq	%r14, %rax
	movq	%r12, %rdi
	xorl	%esi, %esi
	addq	%r12, %rax
	movq	%rbx, %rdx
	addq	%rbx, %r12
	movq	%rax, 16(%rbp)
	call	memset@PLT
	movl	$24, %edi
	movq	%r12, 8(%rbp)
.LEHB58:
	call	_Znwm@PLT
.LEHE58:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, (%rsp)
.LEHB59:
	call	_Znwm@PLT
.LEHE59:
	movq	%rax, %r12
	movq	%r14, %rax
	movq	%rbx, %rdx
	addq	%r12, %rax
	movq	%r12, (%r15)
	movq	%r12, 8(%r15)
	movq	%rax, 16(%r15)
	xorl	%esi, %esi
	movq	%r12, %rdi
	call	memset@PLT
	movq	(%rsp), %rax
	addq	%r12, %rbx
.L767:
	movdqa	.LC1(%rip), %xmm7
	leaq	96(%rsp), %r15
	movabsq	$9223372036854775807, %r12
	movq	%rbx, 8(%rax)
	leaq	80(%rsp), %rax
	movl	$100, %ebx
	movaps	%xmm7, 80(%rsp)
	movq	%rax, 8(%rsp)
	.p2align 4,,10
	.p2align 3
.L733:
	movl	$4, %edi
	movq	%r15, %rsi
	call	clock_gettime@PLT
	movq	(%rsp), %rdi
	movq	0(%rbp), %rax
	movq	96(%rsp), %r14
	movq	104(%rsp), %r13
	movq	(%rdi), %rdx
	movq	8(%rbp), %rdi
	cmpq	%rdi, %rax
	je	.L729
	leaq	8(%rax), %r8
	movq	%rdi, %rsi
	leaq	16(%rdx), %rcx
	subq	%r8, %rsi
	shrq	$3, %rsi
	addq	$1, %rsi
	cmpq	%rcx, %rax
	leaq	16(%rax), %rcx
	setnb	%r9b
	cmpq	%rcx, %rdx
	setnb	%cl
	orb	%cl, %r9b
	je	.L730
	cmpq	$24, %rsi
	jbe	.L730
	movq	%rdx, %rcx
	shrq	$3, %rcx
	andl	$1, %ecx
	je	.L774
	movq	(%rdx), %rdi
	leaq	8(%rdx), %r9
	movq	%rdi, (%rax)
.L726:
	subq	%rcx, %rsi
	salq	$3, %rcx
	xorl	%r11d, %r11d
	leaq	-2(%rsi), %rdi
	addq	%rcx, %rdx
	addq	%rcx, %rax
	xorl	%ecx, %ecx
	shrq	%rdi
	addq	$1, %rdi
	leaq	(%rdi,%rdi), %r10
.L727:
	movdqa	(%rdx,%rcx), %xmm0
	addq	$1, %r11
	movups	%xmm0, (%rax,%rcx)
	addq	$16, %rcx
	cmpq	%r11, %rdi
	ja	.L727
	leaq	0(,%r10,8), %rax
	addq	%rax, %r8
	addq	%rax, %r9
	cmpq	%r10, %rsi
	je	.L729
	movq	(%r9), %rax
	movq	%rax, (%r8)
.L729:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	104(%rsp), %rcx
	movq	96(%rsp), %rsi
	subq	%r13, %rcx
	subq	%r14, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, 96(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r12, %rsi
	movq	%rcx, 104(%rsp)
	jle	.L723
	movq	8(%rsp), %rax
.L724:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbx
	movq	%rax, 80(%rsp)
	movq	%rdx, 88(%rsp)
	je	.L732
	movq	80(%rsp), %r12
	jmp	.L733
	.p2align 4,,10
	.p2align 3
.L730:
	movq	(%rdx), %rcx
	addq	$8, %rax
	addq	$8, %rdx
	movq	%rcx, -8(%rax)
	cmpq	%rax, %rdi
	jne	.L730
	jmp	.L729
	.p2align 4,,10
	.p2align 3
.L723:
	cmpq	88(%rsp), %rcx
	movq	8(%rsp), %rax
	cmovle	%r15, %rax
	jmp	.L724
	.p2align 4,,10
	.p2align 3
.L774:
	movq	%rdx, %r9
	movq	%rax, %r8
	jmp	.L726
	.p2align 4,,10
	.p2align 3
.L770:
	movq	%rbp, %r15
	movq	%r9, %rdx
	jmp	.L697
	.p2align 4,,10
	.p2align 3
.L696:
	movq	%r9, %rax
	movq	%rbp, %rdx
	.p2align 4,,10
	.p2align 3
.L701:
	movq	(%rdx), %rcx
	addq	$8, %rax
	addq	$8, %rdx
	movq	%rcx, -8(%rax)
	cmpq	%rax, %rdi
	jne	.L701
	jmp	.L700
.L732:
	movq	(%rsp), %rax
	movq	72(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	800(%rax), %ebx
	movq	0(%rbp), %rax
	movl	800(%rax), %r12d
.LEHB60:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %r13
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	%r12d, %esi
	movq	%r13, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L708
	cmpb	$0, 56(%rbx)
	je	.L734
	movsbl	67(%rbx), %esi
.L735:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	80(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L736
	call	_ZdlPv@PLT
.L736:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L737
	call	_ZdlPv@PLT
.L737:
	movq	(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE60:
	movq	64(%rsp), %r13
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	40(%rsp), %r14
	testq	%r13, %r13
	je	.L738
	movq	%r14, %rdi
.LEHB61:
	call	_Znwm@PLT
.LEHE61:
	movq	%rax, %rbp
	movq	%rax, (%rbx)
	movq	%r14, %rax
	addq	%rbp, %rax
	movq	%rbp, %rdi
	xorl	%esi, %esi
	movq	%rax, 16(%rbx)
	movq	%r13, %rax
	salq	$3, %rax
	movq	%rax, %r13
	movq	%rax, %rdx
	addq	%r13, %rbp
	call	memset@PLT
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB62:
	call	_Znwm@PLT
.LEHE62:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbp
.LEHB63:
	call	_Znwm@PLT
.LEHE63:
	movq	%rax, %r12
	movq	%rax, 0(%rbp)
	movq	%rax, 8(%rbp)
	movq	%r14, %rax
	movq	%r12, %rdi
	movq	%r13, %rdx
	addq	%r12, %rax
	xorl	%esi, %esi
	addq	%r13, %r12
	movq	%rax, 16(%rbp)
	call	memset@PLT
.L768:
	movdqa	.LC1(%rip), %xmm4
	leaq	80(%rsp), %rax
	movq	%r12, 8(%rbp)
	movq	$100, (%rsp)
	movq	%rbx, %r13
	movaps	%xmm4, 80(%rsp)
	movq	%rax, 8(%rsp)
	jmp	.L752
	.p2align 4,,10
	.p2align 3
.L854:
	testq	%r11, %r11
	jne	.L851
.L847:
	addq	%r12, %r8
.L746:
	movq	%r8, 8(%r13)
.L739:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	104(%rsp), %rsi
	movq	96(%rsp), %rdi
	subq	%rbx, %rsi
	subq	%r14, %rdi
	movq	8(%rsp), %rbx
	movq	%rsi, %rax
	addq	$1000000000, %rsi
	shrq	$63, %rax
	subq	%rax, %rdi
	movabsq	$1237940039285380275, %rax
	imulq	%rsi
	movq	%rsi, %rax
	movq	%rdi, 96(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	movq	%rbx, %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rsi
	cmpq	80(%rsp), %rdi
	movq	%rsi, 104(%rsp)
	jg	.L751
	cmpq	88(%rsp), %rsi
	cmovle	%r15, %rax
.L751:
	subq	$1, (%rsp)
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rdx, 88(%rsp)
	movq	%rax, 80(%rsp)
	je	.L852
.L752:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	cmpq	%rbp, %r13
	movq	96(%rsp), %r14
	movq	104(%rsp), %rbx
	je	.L739
	movq	8(%rbp), %r10
	movq	0(%rbp), %rsi
	movq	0(%r13), %r8
	movq	16(%r13), %rax
	movq	%r10, %r12
	subq	%rsi, %r12
	subq	%r8, %rax
	movq	%r12, %r11
	sarq	$3, %rax
	sarq	$3, %r11
	cmpq	%rax, %r11
	ja	.L853
	movq	8(%r13), %rdi
	movq	%rdi, %rdx
	subq	%r8, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	cmpq	%rax, %r11
	jbe	.L854
	testq	%rax, %rax
	jne	.L855
.L749:
	addq	%rdx, %rsi
	subq	%rsi, %r10
	movq	%r10, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	je	.L847
	movq	%r10, %rdx
	call	memmove@PLT
	movq	%r12, %r8
	addq	0(%r13), %r8
	jmp	.L746
	.p2align 4,,10
	.p2align 3
.L853:
	xorl	%r10d, %r10d
	testq	%r11, %r11
	je	.L744
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %r11
	ja	.L856
	movq	%r12, %rdi
	movq	%r11, 24(%rsp)
	movq	%rsi, 16(%rsp)
.LEHB64:
	call	_Znwm@PLT
	movq	24(%rsp), %r11
	movq	%rax, %r10
	movq	0(%r13), %r8
	movq	16(%rsp), %rsi
	testq	%r11, %r11
	je	.L744
	movq	%r12, %rdx
	movq	%rax, %rdi
	movq	%r8, 16(%rsp)
	call	memmove@PLT
	movq	16(%rsp), %r8
	movq	%rax, %r10
.L744:
	testq	%r8, %r8
	je	.L745
	movq	%r8, %rdi
	movq	%r10, 16(%rsp)
	call	_ZdlPv@PLT
	movq	16(%rsp), %r10
.L745:
	leaq	(%r10,%r12), %r8
	movq	%r10, 0(%r13)
	movq	%r8, 16(%r13)
	jmp	.L746
	.p2align 4,,10
	.p2align 3
.L855:
	movq	%r8, %rdi
	call	memmove@PLT
	movq	8(%r13), %rdi
	movq	0(%r13), %r8
	movq	0(%rbp), %rsi
	movq	8(%rbp), %r10
	movq	%rdi, %rdx
	subq	%r8, %rdx
	jmp	.L749
	.p2align 4,,10
	.p2align 3
.L851:
	movq	%r8, %rdi
	movq	%r12, %rdx
	call	memmove@PLT
	movq	%r12, %r8
	addq	0(%r13), %r8
	jmp	.L746
.L852:
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	movq	%r13, %rbx
	cvtsi2sdq	80(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk@PLT
	movq	0(%rbp), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movl	800(%rax), %r12d
	movq	0(%r13), %rax
	movl	800(%rax), %esi
	call	_ZNSolsEi@PLT
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L708
	cmpb	$0, 56(%r12)
	je	.L753
	movsbl	67(%r12), %esi
.L754:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L755
	call	_ZdlPv@PLT
.L755:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L756
	call	_ZdlPv@PLT
.L756:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	120(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L857
	addq	$136, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L734:
	.cfi_restore_state
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L735
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L735
.L717:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L718
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L718
.L709:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L710
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L710
.L706:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%r13), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L707
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L707
.L753:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L754
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L754
.L715:
	movq	%r14, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r14d
	orq	%r14, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L716
.L703:
	movq	%rsi, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %esi
	orq	%rsi, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L704
.L692:
	movq	$0, 16(%rbx)
	movl	$24, %edi
	xorl	%ebp, %ebp
	call	_Znwm@PLT
	xorl	%ebx, %ebx
	movq	%rax, 48(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, 40(%rsp)
	jmp	.L765
.L713:
	movq	40(%rsp), %rbx
	movl	$24, %edi
	movq	%rbx, 16(%r13)
	call	_Znwm@PLT
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rbx, 16(%r12)
	xorl	%ebx, %ebx
	jmp	.L766
.L721:
	movq	40(%rsp), %rbx
	movl	$24, %edi
	movq	%rbx, 16(%rbp)
	call	_Znwm@PLT
	movq	%rbx, 16(%rax)
	movq	%rax, (%rsp)
	xorl	%ebx, %ebx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	jmp	.L767
.L738:
	movq	%r14, 16(%rbx)
	movl	$24, %edi
	xorl	%r12d, %r12d
	call	_Znwm@PLT
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%r14, 16(%rbp)
	jmp	.L768
.L786:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
	call	_Unwind_Resume@PLT
.L784:
.L848:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L785:
	movq	(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L857:
	call	__stack_chk_fail@PLT
.L708:
	call	_ZSt16__throw_bad_castv@PLT
.L782:
	movq	%rax, %rbx
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L783:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L780:
	movq	56(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L781:
	movq	48(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L787:
	jmp	.L848
.L856:
	call	_ZSt17__throw_bad_allocv@PLT
.LEHE64:
	.cfi_endproc
.LFE7064:
	.section	.gcc_except_table._Z4funcIlEvm,"aG",@progbits,_Z4funcIlEvm,comdat
.LLSDA7064:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7064-.LLSDACSB7064
.LLSDACSB7064:
	.uleb128 .LEHB48-.LFB7064
	.uleb128 .LEHE48-.LEHB48
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB49-.LFB7064
	.uleb128 .LEHE49-.LEHB49
	.uleb128 .L780-.LFB7064
	.uleb128 0
	.uleb128 .LEHB50-.LFB7064
	.uleb128 .LEHE50-.LEHB50
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB51-.LFB7064
	.uleb128 .LEHE51-.LEHB51
	.uleb128 .L781-.LFB7064
	.uleb128 0
	.uleb128 .LEHB52-.LFB7064
	.uleb128 .LEHE52-.LEHB52
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB53-.LFB7064
	.uleb128 .LEHE53-.LEHB53
	.uleb128 .L782-.LFB7064
	.uleb128 0
	.uleb128 .LEHB54-.LFB7064
	.uleb128 .LEHE54-.LEHB54
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB55-.LFB7064
	.uleb128 .LEHE55-.LEHB55
	.uleb128 .L783-.LFB7064
	.uleb128 0
	.uleb128 .LEHB56-.LFB7064
	.uleb128 .LEHE56-.LEHB56
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB57-.LFB7064
	.uleb128 .LEHE57-.LEHB57
	.uleb128 .L784-.LFB7064
	.uleb128 0
	.uleb128 .LEHB58-.LFB7064
	.uleb128 .LEHE58-.LEHB58
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB59-.LFB7064
	.uleb128 .LEHE59-.LEHB59
	.uleb128 .L785-.LFB7064
	.uleb128 0
	.uleb128 .LEHB60-.LFB7064
	.uleb128 .LEHE60-.LEHB60
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB61-.LFB7064
	.uleb128 .LEHE61-.LEHB61
	.uleb128 .L786-.LFB7064
	.uleb128 0
	.uleb128 .LEHB62-.LFB7064
	.uleb128 .LEHE62-.LEHB62
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB63-.LFB7064
	.uleb128 .LEHE63-.LEHB63
	.uleb128 .L787-.LFB7064
	.uleb128 0
	.uleb128 .LEHB64-.LFB7064
	.uleb128 .LEHE64-.LEHB64
	.uleb128 0
	.uleb128 0
.LLSDACSE7064:
	.section	.text._Z4funcIlEvm,"axG",@progbits,_Z4funcIlEvm,comdat
	.size	_Z4funcIlEvm, .-_Z4funcIlEvm
	.section	.text._ZNSt6vectorInSaInEEaSERKS1_,"axG",@progbits,_ZNSt6vectorInSaInEEaSERKS1_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorInSaInEEaSERKS1_
	.type	_ZNSt6vectorInSaInEEaSERKS1_, @function
_ZNSt6vectorInSaInEEaSERKS1_:
.LFB7229:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	cmpq	%rdi, %rsi
	je	.L859
	movq	8(%rsi), %rax
	movq	(%rsi), %r15
	movq	%rsi, %r12
	movq	(%rdi), %r13
	movq	16(%rdi), %rcx
	movq	%rax, %rbp
	subq	%r15, %rbp
	subq	%r13, %rcx
	movq	%rbp, %r14
	sarq	$4, %rcx
	sarq	$4, %r14
	cmpq	%r14, %rcx
	jb	.L882
	movq	8(%rdi), %rdi
	movq	%rdi, %rsi
	subq	%r13, %rsi
	movq	%rsi, %rdx
	sarq	$4, %rdx
	cmpq	%rdx, %r14
	jbe	.L883
	testq	%rdx, %rdx
	jne	.L884
.L869:
	addq	%r15, %rsi
	subq	%rsi, %rax
	movq	%rax, %rdx
	sarq	$4, %rdx
	testq	%rdx, %rdx
	jne	.L870
.L881:
	addq	%r13, %rbp
.L866:
	movq	%rbp, 8(%rbx)
.L859:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L883:
	.cfi_restore_state
	testq	%r14, %r14
	je	.L881
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%r13, %rdi
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L866
	.p2align 4,,10
	.p2align 3
.L882:
	xorl	%r12d, %r12d
	testq	%r14, %r14
	je	.L864
	movabsq	$1152921504606846975, %rax
	cmpq	%rax, %r14
	ja	.L885
	movq	%rbp, %rdi
	call	_Znwm@PLT
	testq	%r14, %r14
	movq	%rax, %r12
	movq	(%rbx), %r13
	jne	.L886
.L864:
	testq	%r13, %r13
	je	.L865
.L887:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
.L865:
	addq	%r12, %rbp
	movq	%r12, (%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L866
	.p2align 4,,10
	.p2align 3
.L886:
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%rax, %rdi
	call	memmove@PLT
	testq	%r13, %r13
	jne	.L887
	jmp	.L865
	.p2align 4,,10
	.p2align 3
.L870:
	movq	%rax, %rdx
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L866
	.p2align 4,,10
	.p2align 3
.L884:
	movq	%r13, %rdi
	movq	%rsi, %rdx
	movq	%r15, %rsi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r13
	movq	(%r12), %r15
	movq	8(%r12), %rax
	movq	%rdi, %rsi
	subq	%r13, %rsi
	jmp	.L869
.L885:
	call	_ZSt17__throw_bad_allocv@PLT
	.cfi_endproc
.LFE7229:
	.size	_ZNSt6vectorInSaInEEaSERKS1_, .-_ZNSt6vectorInSaInEEaSERKS1_
	.section	.text._Z4funcInEvm,"axG",@progbits,_Z4funcInEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcInEvm
	.type	_Z4funcInEvm, @function
_Z4funcInEvm:
.LFB7065:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7065
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$104, %rsp
	.cfi_def_cfa_offset 160
	movq	%rdi, 40(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 88(%rsp)
	xorl	%eax, %eax
.LEHB65:
	call	_Znwm@PLT
.LEHE65:
	xorl	%edx, %edx
	movq	%rax, %rbp
	movl	$104857600, %eax
	divq	%rbx
	movq	$0, 0(%rbp)
	movq	$0, 8(%rbp)
	movq	$0, 16(%rbp)
	testq	%rax, %rax
	movq	%rax, 32(%rsp)
	je	.L889
	salq	$4, %rax
	movq	%rax, %rdi
	movq	%rax, %r15
	movq	%rax, 24(%rsp)
.LEHB66:
	call	_Znwm@PLT
.LEHE66:
	leaq	(%rax,%r15), %rbx
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, 0(%rbp)
	movq	%rbx, 16(%rbp)
	call	memset@PLT
	movq	%rbx, 8(%rbp)
	movl	$24, %edi
.LEHB67:
	call	_Znwm@PLT
.LEHE67:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbx
.LEHB68:
	call	_Znwm@PLT
.LEHE68:
	leaq	(%rax,%r15), %r13
	movq	%rax, (%rbx)
	movq	%rax, 8(%rbx)
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r13, 16(%rbx)
	movq	%rax, %r12
	call	memset@PLT
.L941:
	movq	8(%rbp), %rdi
	movq	0(%rbp), %r10
	movl	$100, %r11d
	movq	%r13, 8(%rbx)
	movq	$-1, %r9
	movq	%rdi, %r8
	.p2align 4,,10
	.p2align 3
.L892:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%r12, %rcx
	orq	%rax, %rdx
	cmpq	%r10, %r8
	movq	%r10, %rax
	movq	%rdx, %r13
	je	.L894
	.p2align 4,,10
	.p2align 3
.L987:
	movq	(%rcx), %rsi
	movq	8(%rcx), %rdi
	addq	$16, %rax
	addq	$16, %rcx
	movq	%rsi, -16(%rax)
	movq	%rdi, -8(%rax)
	cmpq	%rax, %r8
	jne	.L987
.L894:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%r13, %rax
	cmpq	%rax, %r9
	cmova	%rax, %r9
	subq	$1, %r11
	jne	.L892
	pxor	%xmm4, %xmm4
	testq	%r9, %r9
	movl	1600(%r12), %r14d
	movl	1600(%r10), %r13d
	cvtsi2sdq	32(%rsp), %xmm4
	movsd	%xmm4, 8(%rsp)
	js	.L895
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r9, %xmm0
.L896:
	divsd	8(%rsp), %xmm0
	movq	40(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movsd	%xmm0, 16(%rsp)
.LEHB69:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %r12
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r15
	testq	%r15, %r15
	je	.L900
	cmpb	$0, 56(%r15)
	je	.L898
	movsbl	67(%r15), %esi
.L899:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movsd	16(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%r14d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L900
	cmpb	$0, 56(%r12)
	je	.L901
	movsbl	67(%r12), %esi
.L902:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L903
	call	_ZdlPv@PLT
.L903:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L904
	call	_ZdlPv@PLT
.L904:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE69:
	movq	32(%rsp), %rbx
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%rbx, %rbx
	je	.L905
	movq	24(%rsp), %r15
	movq	%r15, %rdi
.LEHB70:
	call	_Znwm@PLT
.LEHE70:
	movq	%rax, %rbp
	movq	%rax, 0(%r13)
	movq	%r15, %rax
	addq	%rbp, %rax
	movq	%rbp, %rdi
	xorl	%esi, %esi
	movq	%rax, 16(%r13)
	movq	%rbx, %rax
	salq	$4, %rax
	movq	%rax, %rbx
	movq	%rax, %rdx
	addq	%rbx, %rbp
	call	memset@PLT
	movl	$24, %edi
	movq	%rbp, 8(%r13)
.LEHB71:
	call	_Znwm@PLT
.LEHE71:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB72:
	call	_Znwm@PLT
.LEHE72:
	movq	%rax, %rbp
	movq	%rax, (%r12)
	movq	%rax, 8(%r12)
	movq	%r15, %rax
	movq	%rbx, %rdx
	xorl	%esi, %esi
	addq	%rbp, %rax
	movq	%rbp, %rdi
	addq	%rbp, %rbx
	movq	%rax, 16(%r12)
	call	memset@PLT
.L942:
	movq	%rbx, 8(%r12)
	movl	$100, %ebp
	movq	$-1, %r14
	.p2align 4,,10
	.p2align 3
.L906:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%r12, %rsi
	movq	%rdx, %rbx
	movq	%r13, %rdi
	orq	%rax, %rbx
.LEHB73:
	call	_ZNSt6vectorInSaInEEaSERKS1_
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rbx, %rax
	cmpq	%rax, %r14
	cmova	%rax, %r14
	subq	$1, %rbp
	jne	.L906
	movq	(%r12), %rax
	testq	%r14, %r14
	movl	1600(%rax), %ebx
	movq	0(%r13), %rax
	movl	1600(%rax), %ebp
	js	.L907
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r14, %xmm0
.L908:
	divsd	8(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L900
	cmpb	$0, 56(%rbx)
	je	.L909
	movsbl	67(%rbx), %esi
.L910:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L911
	call	_ZdlPv@PLT
.L911:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L912
	call	_ZdlPv@PLT
.L912:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE73:
	movq	32(%rsp), %rbx
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%rbx, %rbx
	je	.L913
	movq	24(%rsp), %r14
	movq	%r14, %rdi
.LEHB74:
	call	_Znwm@PLT
.LEHE74:
	movq	%rax, %rbp
	movq	%rax, (%r12)
	movq	%r14, %rax
	addq	%rbp, %rax
	movq	%rbp, %rdi
	xorl	%esi, %esi
	movq	%rax, 16(%r12)
	movq	%rbx, %rax
	salq	$4, %rax
	movq	%rax, %rbx
	movq	%rax, %rdx
	addq	%rbx, %rbp
	call	memset@PLT
	movl	$24, %edi
	movq	%rbp, 8(%r12)
.LEHB75:
	call	_Znwm@PLT
.LEHE75:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, 8(%rsp)
.LEHB76:
	call	_Znwm@PLT
.LEHE76:
	movq	%rax, %rbp
	movq	%r14, %rax
	movq	%rbx, %rdx
	addq	%rbp, %rax
	movq	%rbp, (%r15)
	movq	%rbp, 8(%r15)
	movq	%rax, 16(%r15)
	xorl	%esi, %esi
	movq	%rbp, %rdi
	call	memset@PLT
	movq	8(%rsp), %rax
	addq	%rbp, %rbx
.L943:
	movdqa	.LC1(%rip), %xmm7
	movl	$100, %ebp
	movabsq	$9223372036854775807, %r13
	movq	%rbx, 8(%rax)
	leaq	48(%rsp), %rax
	leaq	64(%rsp), %rbx
	movaps	%xmm7, 48(%rsp)
	movq	%rax, 16(%rsp)
	.p2align 4,,10
	.p2align 3
.L920:
	movq	%rbx, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	8(%rsp), %rax
	movq	8(%r12), %rcx
	movq	64(%rsp), %r15
	movq	72(%rsp), %r14
	movq	(%rax), %rdx
	movq	(%r12), %rax
	cmpq	%rcx, %rax
	je	.L918
	.p2align 4,,10
	.p2align 3
.L986:
	movq	(%rdx), %rsi
	movq	8(%rdx), %rdi
	addq	$16, %rax
	addq	$16, %rdx
	movq	%rsi, -16(%rax)
	movq	%rdi, -8(%rax)
	cmpq	%rax, %rcx
	jne	.L986
.L918:
	movq	%rbx, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	72(%rsp), %rcx
	movq	64(%rsp), %rsi
	subq	%r14, %rcx
	subq	%r15, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, 64(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r13, %rsi
	movq	%rcx, 72(%rsp)
	jle	.L915
	movq	16(%rsp), %rax
.L916:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbp
	movq	%rax, 48(%rsp)
	movq	%rdx, 56(%rsp)
	je	.L919
	movq	48(%rsp), %r13
	jmp	.L920
	.p2align 4,,10
	.p2align 3
.L915:
	cmpq	56(%rsp), %rcx
	movq	16(%rsp), %rax
	cmovle	%rbx, %rax
	jmp	.L916
.L919:
	movq	8(%rsp), %rax
	movq	40(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	1600(%rax), %r13d
	movq	(%r12), %rax
	movl	1600(%rax), %ebp
.LEHB77:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %r14
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	%ebp, %esi
	movq	%r14, %rdi
	call	_ZNSolsEi@PLT
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L900
	cmpb	$0, 56(%rbp)
	je	.L921
	movsbl	67(%rbp), %esi
.L922:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	56(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	48(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L923
	call	_ZdlPv@PLT
.L923:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	8(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L924
	call	_ZdlPv@PLT
.L924:
	movq	8(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE77:
	movq	32(%rsp), %r12
	movq	%rax, %r15
	movq	%rax, 16(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%r12, %r12
	je	.L925
	movq	24(%rsp), %r14
	movq	%r14, %rdi
.LEHB78:
	call	_Znwm@PLT
.LEHE78:
	movq	%rax, %rbp
	movq	%r14, %rax
	xorl	%esi, %esi
	addq	%rbp, %rax
	movq	%rbp, (%r15)
	movq	%rbp, %rdi
	movq	%rax, 16(%r15)
	movq	%r12, %rax
	salq	$4, %rax
	movq	%rax, %r12
	movq	%rax, %rdx
	addq	%r12, %rbp
	call	memset@PLT
	movq	%rbp, 8(%r15)
	movl	$24, %edi
.LEHB79:
	call	_Znwm@PLT
.LEHE79:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, 8(%rsp)
.LEHB80:
	call	_Znwm@PLT
.LEHE80:
	movq	%rax, %rbp
	movq	%r14, %rax
	movq	%r12, %rdx
	addq	%rbp, %rax
	movq	%rbp, (%r15)
	movq	%rbp, 8(%r15)
	movq	%rbp, %rdi
	movq	%rax, 16(%r15)
	xorl	%esi, %esi
	call	memset@PLT
	movq	8(%rsp), %rax
	addq	%r12, %rbp
.L944:
	movdqa	.LC1(%rip), %xmm4
	movabsq	$9223372036854775807, %r12
	leaq	48(%rsp), %r15
	movq	%rbp, 8(%rax)
	movl	$100, %ebp
	movaps	%xmm4, 48(%rsp)
	jmp	.L928
	.p2align 4,,10
	.p2align 3
.L1010:
	movq	48(%rsp), %r12
.L928:
	movq	%rbx, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	8(%rsp), %rsi
	movq	16(%rsp), %rdi
	movq	64(%rsp), %r13
	movq	72(%rsp), %r14
.LEHB81:
	call	_ZNSt6vectorInSaInEEaSERKS1_
	movq	%rbx, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	72(%rsp), %rcx
	movq	64(%rsp), %rsi
	subq	%r14, %rcx
	subq	%r13, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, 64(%rsp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	movq	%r15, %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r12, %rsi
	movq	%rcx, 72(%rsp)
	jg	.L926
	cmpq	56(%rsp), %rcx
	movq	%rbx, %rax
	cmovg	%r15, %rax
.L926:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbp
	movq	%rax, 48(%rsp)
	movq	%rdx, 56(%rsp)
	jne	.L1010
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	56(%rsp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	48(%rsp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk@PLT
	movq	8(%rsp), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	1600(%rax), %ebx
	movq	16(%rsp), %rax
	movq	(%rax), %rax
	movl	1600(%rax), %esi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L900
	cmpb	$0, 56(%rbx)
	je	.L929
	movsbl	67(%rbx), %esi
.L930:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	16(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L931
	call	_ZdlPv@PLT
.L931:
	movq	16(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	8(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L932
	call	_ZdlPv@PLT
.L932:
	movq	8(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	88(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L1011
	addq	$104, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L929:
	.cfi_restore_state
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L930
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L930
.L921:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L922
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L922
.L909:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L910
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L910
.L901:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L902
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L902
.L898:
	movq	%r15, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r15), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L899
	movq	%r15, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L899
.L907:
	movq	%r14, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r14d
	orq	%r14, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L908
.L895:
	movq	%r9, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r9d
	orq	%r9, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L896
.L925:
	movq	%r15, %rdi
	movq	24(%rsp), %r15
	xorl	%ebp, %ebp
	movq	%r15, 16(%rdi)
	movl	$24, %edi
	call	_Znwm@PLT
	movq	%rax, 8(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%r15, 16(%rax)
	jmp	.L944
.L913:
	movq	24(%rsp), %rbx
	movl	$24, %edi
	movq	%rbx, 16(%r12)
	call	_Znwm@PLT
	movq	%rbx, 16(%rax)
	movq	%rax, 8(%rsp)
	xorl	%ebx, %ebx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	jmp	.L943
.L889:
	movq	$0, 16(%rbp)
	movl	$24, %edi
	xorl	%r12d, %r12d
	call	_Znwm@PLT
	xorl	%r13d, %r13d
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, 24(%rsp)
	jmp	.L941
.L905:
	movq	24(%rsp), %rbx
	movl	$24, %edi
	movq	%rbx, 16(%r13)
	call	_Znwm@PLT
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rbx, 16(%r12)
	xorl	%ebx, %ebx
	jmp	.L942
.L960:
	movq	16(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L961:
.L1007:
	movq	8(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L1011:
	call	__stack_chk_fail@PLT
.L958:
.L1006:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L959:
	jmp	.L1007
.L956:
	movq	%rax, %rbx
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L957:
	jmp	.L1006
.L900:
	call	_ZSt16__throw_bad_castv@PLT
.L954:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L955:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
	call	_Unwind_Resume@PLT
.LEHE81:
	.cfi_endproc
.LFE7065:
	.section	.gcc_except_table._Z4funcInEvm,"aG",@progbits,_Z4funcInEvm,comdat
.LLSDA7065:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7065-.LLSDACSB7065
.LLSDACSB7065:
	.uleb128 .LEHB65-.LFB7065
	.uleb128 .LEHE65-.LEHB65
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB66-.LFB7065
	.uleb128 .LEHE66-.LEHB66
	.uleb128 .L954-.LFB7065
	.uleb128 0
	.uleb128 .LEHB67-.LFB7065
	.uleb128 .LEHE67-.LEHB67
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB68-.LFB7065
	.uleb128 .LEHE68-.LEHB68
	.uleb128 .L955-.LFB7065
	.uleb128 0
	.uleb128 .LEHB69-.LFB7065
	.uleb128 .LEHE69-.LEHB69
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB70-.LFB7065
	.uleb128 .LEHE70-.LEHB70
	.uleb128 .L956-.LFB7065
	.uleb128 0
	.uleb128 .LEHB71-.LFB7065
	.uleb128 .LEHE71-.LEHB71
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB72-.LFB7065
	.uleb128 .LEHE72-.LEHB72
	.uleb128 .L957-.LFB7065
	.uleb128 0
	.uleb128 .LEHB73-.LFB7065
	.uleb128 .LEHE73-.LEHB73
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB74-.LFB7065
	.uleb128 .LEHE74-.LEHB74
	.uleb128 .L958-.LFB7065
	.uleb128 0
	.uleb128 .LEHB75-.LFB7065
	.uleb128 .LEHE75-.LEHB75
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB76-.LFB7065
	.uleb128 .LEHE76-.LEHB76
	.uleb128 .L959-.LFB7065
	.uleb128 0
	.uleb128 .LEHB77-.LFB7065
	.uleb128 .LEHE77-.LEHB77
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB78-.LFB7065
	.uleb128 .LEHE78-.LEHB78
	.uleb128 .L960-.LFB7065
	.uleb128 0
	.uleb128 .LEHB79-.LFB7065
	.uleb128 .LEHE79-.LEHB79
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB80-.LFB7065
	.uleb128 .LEHE80-.LEHB80
	.uleb128 .L961-.LFB7065
	.uleb128 0
	.uleb128 .LEHB81-.LFB7065
	.uleb128 .LEHE81-.LEHB81
	.uleb128 0
	.uleb128 0
.LLSDACSE7065:
	.section	.text._Z4funcInEvm,"axG",@progbits,_Z4funcInEvm,comdat
	.size	_Z4funcInEvm, .-_Z4funcInEvm
	.section	.text._ZNSt6vectorIDv4_xSaIS0_EEaSERKS2_,"axG",@progbits,_ZNSt6vectorIDv4_xSaIS0_EEaSERKS2_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIDv4_xSaIS0_EEaSERKS2_
	.type	_ZNSt6vectorIDv4_xSaIS0_EEaSERKS2_, @function
_ZNSt6vectorIDv4_xSaIS0_EEaSERKS2_:
.LFB7250:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	cmpq	%rdi, %rsi
	je	.L1013
	movq	8(%rsi), %rax
	movq	(%rsi), %r15
	movq	%rsi, %r12
	movq	(%rdi), %r13
	movq	16(%rdi), %rcx
	movq	%rax, %rbp
	subq	%r15, %rbp
	subq	%r13, %rcx
	movq	%rbp, %r14
	sarq	$5, %rcx
	sarq	$5, %r14
	cmpq	%r14, %rcx
	jb	.L1036
	movq	8(%rdi), %rdi
	movq	%rdi, %rsi
	subq	%r13, %rsi
	movq	%rsi, %rdx
	sarq	$5, %rdx
	cmpq	%rdx, %r14
	jbe	.L1037
	testq	%rdx, %rdx
	jne	.L1038
.L1023:
	addq	%r15, %rsi
	subq	%rsi, %rax
	movq	%rax, %rdx
	sarq	$5, %rdx
	testq	%rdx, %rdx
	jne	.L1024
.L1035:
	addq	%r13, %rbp
.L1020:
	movq	%rbp, 8(%rbx)
.L1013:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L1037:
	.cfi_restore_state
	testq	%r14, %r14
	je	.L1035
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%r13, %rdi
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L1020
	.p2align 4,,10
	.p2align 3
.L1036:
	xorl	%r12d, %r12d
	testq	%r14, %r14
	je	.L1018
	movabsq	$576460752303423487, %rax
	cmpq	%rax, %r14
	ja	.L1039
	movq	%rbp, %rdi
	call	_Znwm@PLT
	testq	%r14, %r14
	movq	%rax, %r12
	movq	(%rbx), %r13
	jne	.L1040
.L1018:
	testq	%r13, %r13
	je	.L1019
.L1041:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
.L1019:
	addq	%r12, %rbp
	movq	%r12, (%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L1020
	.p2align 4,,10
	.p2align 3
.L1040:
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%rax, %rdi
	call	memmove@PLT
	testq	%r13, %r13
	jne	.L1041
	jmp	.L1019
	.p2align 4,,10
	.p2align 3
.L1024:
	movq	%rax, %rdx
	call	memmove@PLT
	addq	(%rbx), %rbp
	jmp	.L1020
	.p2align 4,,10
	.p2align 3
.L1038:
	movq	%r13, %rdi
	movq	%rsi, %rdx
	movq	%r15, %rsi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r13
	movq	(%r12), %r15
	movq	8(%r12), %rax
	movq	%rdi, %rsi
	subq	%r13, %rsi
	jmp	.L1023
.L1039:
	call	_ZSt17__throw_bad_allocv@PLT
	.cfi_endproc
.LFE7250:
	.size	_ZNSt6vectorIDv4_xSaIS0_EEaSERKS2_, .-_ZNSt6vectorIDv4_xSaIS0_EEaSERKS2_
	.section	.text._Z4funcIDv4_xEvm,"axG",@progbits,_Z4funcIDv4_xEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIDv4_xEvm
	.type	_Z4funcIDv4_xEvm, @function
_Z4funcIDv4_xEvm:
.LFB7066:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7066
	leaq	8(%rsp), %r10
	.cfi_def_cfa 10, 0
	andq	$-32, %rsp
	pushq	-8(%r10)
	pushq	%rbp
	.cfi_escape 0x10,0x6,0x2,0x76,0
	movq	%rsp, %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%r10
	.cfi_escape 0xf,0x3,0x76,0x58,0x6
	.cfi_escape 0x10,0xf,0x2,0x76,0x78
	.cfi_escape 0x10,0xe,0x2,0x76,0x70
	.cfi_escape 0x10,0xd,0x2,0x76,0x68
	.cfi_escape 0x10,0xc,0x2,0x76,0x60
	pushq	%rbx
	.cfi_escape 0x10,0x3,0x2,0x76,0x50
	movq	%rdi, %rbx
	subq	$192, %rsp
	movq	%rdi, -240(%rbp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
.LEHB82:
	call	_Znwm@PLT
.LEHE82:
	xorl	%edx, %edx
	movq	%rax, %r12
	movl	$104857600, %eax
	divq	%rbx
	movq	$0, (%r12)
	movq	$0, 8(%r12)
	movq	$0, 16(%r12)
	testq	%rax, %rax
	movq	%rax, -224(%rbp)
	je	.L1043
	salq	$5, %rax
	movq	%rax, %rdi
	movq	%rax, %r15
	movq	%rax, -216(%rbp)
.LEHB83:
	call	_Znwm@PLT
.LEHE83:
	movq	%r15, %rbx
	movq	%r15, %rdx
	xorl	%esi, %esi
	addq	%rax, %rbx
	movq	%rax, %rdi
	movq	%rax, (%r12)
	movq	%rbx, 16(%r12)
	call	memset@PLT
	movq	%rbx, 8(%r12)
	movl	$24, %edi
.LEHB84:
	call	_Znwm@PLT
.LEHE84:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbx
.LEHB85:
	call	_Znwm@PLT
.LEHE85:
	movq	%rax, %r13
	movq	%rax, (%rbx)
	movq	%rax, 8(%rbx)
	leaq	0(%r13,%r15), %r14
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%r13, %rdi
	movq	%r14, 16(%rbx)
	call	memset@PLT
.L1107:
	movq	(%r12), %r10
	movq	8(%r12), %rsi
	movl	$100, %r9d
	movq	%r14, 8(%rbx)
	movq	$-1, %r8
	.p2align 4,,10
	.p2align 3
.L1046:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%r13, %rcx
	orq	%rax, %rdx
	cmpq	%r10, %rsi
	movq	%r10, %rax
	movq	%rdx, %r11
	je	.L1048
	.p2align 4,,10
	.p2align 3
.L1159:
	movq	(%rcx), %rdi
	addq	$32, %rax
	addq	$32, %rcx
	movq	%rdi, -144(%rbp)
	movq	-24(%rcx), %rdx
	movq	%rdx, -136(%rbp)
	movq	-16(%rcx), %rdx
	movq	%rdx, -128(%rbp)
	movq	-8(%rcx), %rdx
	movq	%rdx, -120(%rbp)
	movq	%rdi, -32(%rax)
	movq	-136(%rbp), %rdx
	movq	%rdx, -24(%rax)
	movq	-128(%rbp), %rdx
	movq	%rdx, -16(%rax)
	movq	-120(%rbp), %rdi
	movq	%rdi, -8(%rax)
	cmpq	%rax, %rsi
	jne	.L1159
.L1048:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%r11, %rax
	cmpq	%rax, %r8
	cmova	%rax, %r8
	subq	$1, %r9
	jne	.L1046
	movl	3200(%r13), %eax
	pxor	%xmm4, %xmm4
	testq	%r8, %r8
	movl	3200(%r10), %r15d
	cvtsi2sdq	-224(%rbp), %xmm4
	movl	%eax, -184(%rbp)
	movsd	%xmm4, -232(%rbp)
	js	.L1049
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r8, %xmm0
.L1050:
	divsd	-232(%rbp), %xmm0
	movq	-240(%rbp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movsd	%xmm0, -192(%rbp)
.LEHB86:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %r13
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	0(%r13), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r14
	testq	%r14, %r14
	je	.L1054
	cmpb	$0, 56(%r14)
	je	.L1052
	movsbl	67(%r14), %esi
.L1053:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movsd	-192(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%r15d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	-184(%rbp), %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r14
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r13
	testq	%r13, %r13
	je	.L1054
	cmpb	$0, 56(%r13)
	je	.L1055
	movsbl	67(%r13), %esi
.L1056:
	movq	%r14, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L1057
	call	_ZdlPv@PLT
.L1057:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L1058
	call	_ZdlPv@PLT
.L1058:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE86:
	movq	-224(%rbp), %rbx
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%rbx, %rbx
	je	.L1059
	movq	-216(%rbp), %r15
	movq	%r15, %rdi
.LEHB87:
	call	_Znwm@PLT
.LEHE87:
	movq	%rax, %r13
	movq	%rax, (%r12)
	movq	%r15, %rax
	addq	%r13, %rax
	movq	%r13, %rdi
	xorl	%esi, %esi
	movq	%rax, 16(%r12)
	movq	%rbx, %rax
	salq	$5, %rax
	movq	%rax, %rbx
	movq	%rax, %rdx
	addq	%rbx, %r13
	call	memset@PLT
	movl	$24, %edi
	movq	%r13, 8(%r12)
.LEHB88:
	call	_Znwm@PLT
.LEHE88:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r14
.LEHB89:
	call	_Znwm@PLT
.LEHE89:
	movq	%rax, %r13
	movq	%rax, (%r14)
	movq	%rax, 8(%r14)
	movq	%r15, %rax
	movq	%rbx, %rdx
	xorl	%esi, %esi
	addq	%r13, %rax
	movq	%r13, %rdi
	addq	%r13, %rbx
	movq	%rax, 16(%r14)
	call	memset@PLT
.L1108:
	movq	(%r12), %rcx
	movq	%rbx, 8(%r14)
	movl	$100, %r13d
	movq	(%r14), %rsi
	movq	%r14, %rbx
	movq	$-1, %r15
	movq	%rcx, %r14
	jmp	.L1072
	.p2align 4,,10
	.p2align 3
.L1191:
	testq	%r9, %r9
	jne	.L1188
.L1182:
	addq	%r14, %r8
.L1067:
	movq	%r8, 8(%r12)
.L1060:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	-184(%rbp), %rax
	cmpq	%rax, %r15
	cmova	%rax, %r15
	subq	$1, %r13
	je	.L1189
.L1072:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%r12, %rbx
	movq	%rdx, -184(%rbp)
	je	.L1060
	movq	8(%rbx), %r10
	movq	16(%r12), %rax
	movq	%r10, %r8
	subq	%r14, %rax
	subq	%rsi, %r8
	sarq	$5, %rax
	movq	%r8, %r9
	sarq	$5, %r9
	cmpq	%rax, %r9
	ja	.L1190
	movq	8(%r12), %rdi
	movq	%rdi, %rdx
	subq	%r14, %rdx
	movq	%rdx, %rax
	sarq	$5, %rax
	cmpq	%rax, %r9
	jbe	.L1191
	testq	%rax, %rax
	jne	.L1192
.L1070:
	leaq	(%rsi,%rdx), %rax
	subq	%rax, %r10
	movq	%r10, %rdx
	sarq	$5, %rdx
	testq	%rdx, %rdx
	je	.L1182
	movq	%r8, -192(%rbp)
	movq	%r10, %rdx
	movq	%rax, %rsi
.L1181:
	call	memmove@PLT
	movq	(%r12), %r14
	movq	-192(%rbp), %r8
	movq	(%rbx), %rsi
	addq	%r14, %r8
	jmp	.L1067
	.p2align 4,,10
	.p2align 3
.L1190:
	movq	%r14, %r10
	xorl	%r14d, %r14d
	testq	%r9, %r9
	je	.L1065
	movabsq	$576460752303423487, %rax
	cmpq	%rax, %r9
	ja	.L1193
	movq	%r8, %rdi
	movq	%rsi, -208(%rbp)
	movq	%r9, -200(%rbp)
	movq	%r8, -192(%rbp)
.LEHB90:
	call	_Znwm@PLT
	movq	-200(%rbp), %r9
	movq	%rax, %r14
	movq	(%r12), %r10
	movq	-192(%rbp), %r8
	movq	-208(%rbp), %rsi
	testq	%r9, %r9
	je	.L1065
	movq	%r8, %rdx
	movq	%rax, %rdi
	movq	%r10, -200(%rbp)
	call	memmove@PLT
	movq	-200(%rbp), %r10
	movq	-192(%rbp), %r8
.L1065:
	testq	%r10, %r10
	je	.L1066
	movq	%r10, %rdi
	movq	%r8, -192(%rbp)
	call	_ZdlPv@PLT
	movq	-192(%rbp), %r8
.L1066:
	addq	%r14, %r8
	movq	%r14, (%r12)
	movq	(%rbx), %rsi
	movq	%r8, 16(%r12)
	jmp	.L1067
.L1192:
	movq	%r14, %rdi
	movq	%r8, -192(%rbp)
	call	memmove@PLT
	movq	8(%r12), %rdi
	movq	(%r12), %r14
	movq	(%rbx), %rsi
	movq	8(%rbx), %r10
	movq	-192(%rbp), %r8
	movq	%rdi, %rdx
	subq	%r14, %rdx
	jmp	.L1070
.L1188:
	movq	%r8, %rdx
	movq	%r8, -192(%rbp)
	movq	%r14, %rdi
	jmp	.L1181
.L1189:
	movq	%r14, %rcx
	testq	%r15, %r15
	movq	%rbx, %r14
	movl	3200(%rcx), %r13d
	movl	3200(%rsi), %ebx
	js	.L1073
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r15, %xmm0
.L1074:
	divsd	-232(%rbp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbx
	testq	%rbx, %rbx
	je	.L1054
	cmpb	$0, 56(%rbx)
	je	.L1075
	movsbl	67(%rbx), %esi
.L1076:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L1077
	call	_ZdlPv@PLT
.L1077:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	je	.L1078
	call	_ZdlPv@PLT
.L1078:
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE90:
	movq	-224(%rbp), %r15
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	testq	%r15, %r15
	je	.L1079
	movq	-216(%rbp), %r14
	movq	%r14, %rdi
.LEHB91:
	call	_Znwm@PLT
.LEHE91:
	movq	%rax, %r13
	movq	%rax, (%rbx)
	movq	%r14, %rax
	addq	%r13, %rax
	movq	%r13, %rdi
	xorl	%esi, %esi
	movq	%rax, 16(%rbx)
	movq	%r15, %rax
	salq	$5, %rax
	movq	%rax, %r12
	movq	%rax, %rdx
	addq	%r12, %r13
	call	memset@PLT
	movl	$24, %edi
	movq	%r13, 8(%rbx)
.LEHB92:
	call	_Znwm@PLT
.LEHE92:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, -184(%rbp)
.LEHB93:
	call	_Znwm@PLT
.LEHE93:
	movq	%rax, %r13
	movq	%r14, %rax
	movq	%r12, %rdx
	addq	%r13, %rax
	movq	%r13, (%r15)
	movq	%r13, 8(%r15)
	movq	%rax, 16(%r15)
	xorl	%esi, %esi
	movq	%r13, %rdi
	call	memset@PLT
	movq	-184(%rbp), %rax
	addq	%r13, %r12
.L1109:
	movdqa	.LC1(%rip), %xmm7
	leaq	-160(%rbp), %r15
	movq	%r12, 8(%rax)
	leaq	-176(%rbp), %rax
	movq	$100, -192(%rbp)
	movaps	%xmm7, -176(%rbp)
	movabsq	$9223372036854775807, %r12
	movq	%rax, -200(%rbp)
	.p2align 4,,10
	.p2align 3
.L1086:
	movl	$4, %edi
	movq	%r15, %rsi
	call	clock_gettime@PLT
	movq	-184(%rbp), %rax
	movq	8(%rbx), %rdi
	movq	-160(%rbp), %r14
	movq	-152(%rbp), %r13
	movq	(%rax), %rdx
	movq	(%rbx), %rax
	cmpq	%rdi, %rax
	je	.L1084
	.p2align 4,,10
	.p2align 3
.L1158:
	movq	(%rdx), %rcx
	addq	$32, %rax
	addq	$32, %rdx
	movq	%rcx, -112(%rbp)
	movq	-24(%rdx), %rsi
	movq	%rsi, -104(%rbp)
	movq	-16(%rdx), %rsi
	movq	%rsi, -96(%rbp)
	movq	-8(%rdx), %rsi
	movq	%rsi, -88(%rbp)
	movq	%rcx, -32(%rax)
	movq	-104(%rbp), %rcx
	movq	%rcx, -24(%rax)
	movq	-96(%rbp), %rcx
	movq	%rcx, -16(%rax)
	movq	-88(%rbp), %rcx
	movq	%rcx, -8(%rax)
	cmpq	%rax, %rdi
	jne	.L1158
.L1084:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	-152(%rbp), %rcx
	movq	-160(%rbp), %rsi
	subq	%r13, %rcx
	subq	%r14, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, -160(%rbp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r12, %rsi
	movq	%rcx, -152(%rbp)
	jle	.L1081
	movq	-200(%rbp), %rax
.L1082:
	subq	$1, -192(%rbp)
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rdx, -168(%rbp)
	movq	%rax, -176(%rbp)
	je	.L1085
	movq	-176(%rbp), %r12
	jmp	.L1086
	.p2align 4,,10
	.p2align 3
.L1081:
	cmpq	-168(%rbp), %rcx
	movq	-200(%rbp), %rax
	cmovle	%r15, %rax
	jmp	.L1082
.L1085:
	movq	-184(%rbp), %rax
	movq	-240(%rbp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	3200(%rax), %r12d
	movq	(%rbx), %rax
	movl	3200(%rax), %r13d
.LEHB94:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %r14
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	%r13d, %esi
	movq	%r14, %rdi
	call	_ZNSolsEi@PLT
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L1054
	cmpb	$0, 56(%r12)
	je	.L1087
	movsbl	67(%r12), %esi
.L1088:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	-168(%rbp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	-176(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L1089
	call	_ZdlPv@PLT
.L1089:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	-184(%rbp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L1090
	call	_ZdlPv@PLT
.L1090:
	movq	-184(%rbp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE94:
	cmpq	$0, -224(%rbp)
	movq	%rax, %r14
	movq	%rax, -192(%rbp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1091
	movq	-216(%rbp), %r13
	movq	%r13, %rdi
.LEHB95:
	call	_Znwm@PLT
.LEHE95:
	movq	%rax, %r12
	movq	%r13, %rax
	xorl	%esi, %esi
	addq	%r12, %rax
	movq	%r12, (%r14)
	movq	%r12, %rdi
	movq	%rax, 16(%r14)
	movq	-224(%rbp), %rax
	salq	$5, %rax
	movq	%rax, %rbx
	movq	%rax, %rdx
	addq	%rbx, %r12
	call	memset@PLT
	movq	%r12, 8(%r14)
	movl	$24, %edi
.LEHB96:
	call	_Znwm@PLT
.LEHE96:
	movq	%r13, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r14
	movq	%rax, -184(%rbp)
.LEHB97:
	call	_Znwm@PLT
.LEHE97:
	movq	%rax, %r12
	movq	%r13, %rax
	movq	%rbx, %rdx
	addq	%r12, %rax
	movq	%r12, (%r14)
	movq	%r12, 8(%r14)
	movq	%rax, 16(%r14)
	xorl	%esi, %esi
	movq	%r12, %rdi
	call	memset@PLT
	movq	-184(%rbp), %rax
	addq	%r12, %rbx
.L1110:
	movq	%rbx, 8(%rax)
	leaq	-176(%rbp), %rax
	movl	$100, %ebx
	movdqa	.LC1(%rip), %xmm4
	movabsq	$9223372036854775807, %r12
	movq	%rax, -200(%rbp)
	movaps	%xmm4, -176(%rbp)
	jmp	.L1094
	.p2align 4,,10
	.p2align 3
.L1194:
	movq	-176(%rbp), %r12
.L1094:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	-184(%rbp), %rsi
	movq	-192(%rbp), %rdi
	movq	-160(%rbp), %r13
	movq	-152(%rbp), %r14
.LEHB98:
	call	_ZNSt6vectorIDv4_xSaIS0_EEaSERKS2_
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	-152(%rbp), %rcx
	movq	-160(%rbp), %rsi
	movq	-200(%rbp), %rdi
	subq	%r14, %rcx
	subq	%r13, %rsi
	movq	%rcx, %rax
	addq	$1000000000, %rcx
	shrq	$63, %rax
	subq	%rax, %rsi
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	movq	%rsi, -160(%rbp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	movq	%rdi, %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r12, %rsi
	movq	%rcx, -152(%rbp)
	jg	.L1092
	cmpq	-168(%rbp), %rcx
	cmovle	%r15, %rax
.L1092:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbx
	movq	%rax, -176(%rbp)
	movq	%rdx, -168(%rbp)
	jne	.L1194
	pxor	%xmm0, %xmm0
	leaq	.LC4(%rip), %rsi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	-168(%rbp), %xmm0
	divsd	.LC2(%rip), %xmm0
	cvtsi2sdq	-176(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk@PLT
	movq	-184(%rbp), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movq	(%rax), %rax
	movl	3200(%rax), %ebx
	movq	-192(%rbp), %rax
	movq	(%rax), %rax
	movl	3200(%rax), %esi
	call	_ZNSolsEi@PLT
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L1054
	cmpb	$0, 56(%rbx)
	je	.L1095
	movsbl	67(%rbx), %esi
.L1096:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	-192(%rbp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L1097
	call	_ZdlPv@PLT
.L1097:
	movq	-192(%rbp), %rdi
	call	_ZdlPv@PLT
	movq	-184(%rbp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L1098
	call	_ZdlPv@PLT
.L1098:
	movq	-184(%rbp), %rdi
	call	_ZdlPv@PLT
	movq	-56(%rbp), %rax
	xorq	%fs:40, %rax
	jne	.L1195
	addq	$192, %rsp
	popq	%rbx
	popq	%r10
	.cfi_remember_state
	.cfi_def_cfa 10, 0
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	leaq	-8(%r10), %rsp
	.cfi_def_cfa 7, 8
	ret
.L1087:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L1088
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1088
.L1075:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L1076
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1076
.L1055:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%r13), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L1056
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1056
.L1052:
	movq	%r14, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r14), %rdx
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movl	$10, %esi
	movq	48(%rdx), %rdx
	cmpq	%rcx, %rdx
	je	.L1053
	movq	%r14, %rdi
	call	*%rdx
	movsbl	%al, %esi
	jmp	.L1053
.L1095:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L1096
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1096
.L1073:
	movq	%r15, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r15d
	orq	%r15, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L1074
.L1049:
	movq	%r8, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r8d
	orq	%r8, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L1050
.L1043:
	movq	$0, 16(%r12)
	movl	$24, %edi
	xorl	%r13d, %r13d
	call	_Znwm@PLT
	xorl	%r14d, %r14d
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, -216(%rbp)
	jmp	.L1107
.L1059:
	movq	-216(%rbp), %rbx
	movl	$24, %edi
	movq	%rbx, 16(%r12)
	call	_Znwm@PLT
	movq	%rax, %r14
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rbx, 16(%r14)
	xorl	%ebx, %ebx
	jmp	.L1108
.L1079:
	movq	-216(%rbp), %r15
	movl	$24, %edi
	xorl	%r12d, %r12d
	movq	%r15, 16(%rbx)
	call	_Znwm@PLT
	movq	%rax, -184(%rbp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%r15, 16(%rax)
	jmp	.L1109
.L1091:
	movq	-216(%rbp), %rbx
	movq	%rax, %rdi
	movq	%rbx, 16(%rdi)
	movl	$24, %edi
	call	_Znwm@PLT
	movq	%rbx, 16(%rax)
	movq	%rax, -184(%rbp)
	xorl	%ebx, %ebx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	jmp	.L1110
.L1125:
.L1185:
	movq	-184(%rbp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L1193:
	call	_ZSt17__throw_bad_allocv@PLT
.L1195:
	call	__stack_chk_fail@PLT
.L1124:
.L1184:
	movq	%rax, %r12
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%r12, %rdi
	call	_Unwind_Resume@PLT
.L1054:
	call	_ZSt16__throw_bad_castv@PLT
.L1122:
.L1183:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L1123:
	movq	%rax, %rbx
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L1120:
	jmp	.L1183
.L1121:
	jmp	.L1184
.L1126:
	movq	-192(%rbp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.LEHE98:
.L1127:
	jmp	.L1185
	.cfi_endproc
.LFE7066:
	.section	.gcc_except_table._Z4funcIDv4_xEvm,"aG",@progbits,_Z4funcIDv4_xEvm,comdat
.LLSDA7066:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7066-.LLSDACSB7066
.LLSDACSB7066:
	.uleb128 .LEHB82-.LFB7066
	.uleb128 .LEHE82-.LEHB82
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB83-.LFB7066
	.uleb128 .LEHE83-.LEHB83
	.uleb128 .L1120-.LFB7066
	.uleb128 0
	.uleb128 .LEHB84-.LFB7066
	.uleb128 .LEHE84-.LEHB84
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB85-.LFB7066
	.uleb128 .LEHE85-.LEHB85
	.uleb128 .L1121-.LFB7066
	.uleb128 0
	.uleb128 .LEHB86-.LFB7066
	.uleb128 .LEHE86-.LEHB86
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB87-.LFB7066
	.uleb128 .LEHE87-.LEHB87
	.uleb128 .L1122-.LFB7066
	.uleb128 0
	.uleb128 .LEHB88-.LFB7066
	.uleb128 .LEHE88-.LEHB88
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB89-.LFB7066
	.uleb128 .LEHE89-.LEHB89
	.uleb128 .L1123-.LFB7066
	.uleb128 0
	.uleb128 .LEHB90-.LFB7066
	.uleb128 .LEHE90-.LEHB90
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB91-.LFB7066
	.uleb128 .LEHE91-.LEHB91
	.uleb128 .L1124-.LFB7066
	.uleb128 0
	.uleb128 .LEHB92-.LFB7066
	.uleb128 .LEHE92-.LEHB92
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB93-.LFB7066
	.uleb128 .LEHE93-.LEHB93
	.uleb128 .L1125-.LFB7066
	.uleb128 0
	.uleb128 .LEHB94-.LFB7066
	.uleb128 .LEHE94-.LEHB94
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB95-.LFB7066
	.uleb128 .LEHE95-.LEHB95
	.uleb128 .L1126-.LFB7066
	.uleb128 0
	.uleb128 .LEHB96-.LFB7066
	.uleb128 .LEHE96-.LEHB96
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB97-.LFB7066
	.uleb128 .LEHE97-.LEHB97
	.uleb128 .L1127-.LFB7066
	.uleb128 0
	.uleb128 .LEHB98-.LFB7066
	.uleb128 .LEHE98-.LEHB98
	.uleb128 0
	.uleb128 0
.LLSDACSE7066:
	.section	.text._Z4funcIDv4_xEvm,"axG",@progbits,_Z4funcIDv4_xEvm,comdat
	.size	_Z4funcIDv4_xEvm, .-_Z4funcIDv4_xEvm
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB6906:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	call	_Z4funcIaEvm
	movl	$2, %edi
	call	_Z4funcIsEvm
	movl	$4, %edi
	call	_Z4funcIiEvm
	movl	$8, %edi
	call	_Z4funcIlEvm
	movl	$16, %edi
	call	_Z4funcInEvm
	movl	$32, %edi
	call	_Z4funcIDv4_xEvm
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE6906:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB7836:
	.cfi_startproc
	leaq	_ZStL8__ioinit(%rip), %rdi
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE7836:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC1:
	.quad	9223372036854775807
	.quad	9223372036854775807
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	0
	.long	1104006501
	.align 8
.LC3:
	.long	0
	.long	1079574528
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
