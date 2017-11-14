	.file	"main.cpp"
	.section	.text.unlikely._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
.LCOLDB0:
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
.LHOTB0:
	.align 2
	.p2align 4,,15
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1538:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1538:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.text.unlikely._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
.LCOLDE0:
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
.LHOTE0:
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	" : "
.LC4:
	.string	"%.15lf\n"
	.section	.text.unlikely._Z4funcIaEvm,"axG",@progbits,_Z4funcIaEvm,comdat
.LCOLDB5:
	.section	.text._Z4funcIaEvm,"axG",@progbits,_Z4funcIaEvm,comdat
.LHOTB5:
	.p2align 4,,15
	.weak	_Z4funcIaEvm
	.type	_Z4funcIaEvm, @function
_Z4funcIaEvm:
.LFB6945:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA6945
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
	call	_Znwm
	xorl	%edx, %edx
	movq	%rax, %rbx
	movl	$104857600, %eax
	divq	%r15
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, 24(%rsp)
	jne	.L176
	movl	$24, %edi
	xorl	%r12d, %r12d
	call	_Znwm
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
.L75:
	movq	0(%rbp), %rsi
	movq	8(%rbx), %rdi
	movl	$100, %r10d
	movq	(%rbx), %rcx
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
	movq	%rdx, %r9
	je	.L81
	movq	%rsi, %rax
	.p2align 4,,10
	.p2align 3
.L6:
	movzbl	(%rax), %esi
	addq	$1, %rcx
	addq	$1, %rax
	movb	%sil, -1(%rcx)
	movq	8(%rbx), %rdi
	cmpq	%rdi, %rcx
	jne	.L6
	movq	0(%rbp), %rsi
	movq	(%rbx), %r11
.L5:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%r11, %rcx
	orq	%rax, %rdx
	subq	%r9, %rdx
	cmpq	%rdx, %r8
	cmova	%rdx, %r8
	subq	$1, %r10
	jne	.L7
	pxor	%xmm4, %xmm4
	testq	%r8, %r8
	movl	100(%rsi), %r14d
	movl	100(%r11), %r13d
	cvtsi2sdq	24(%rsp), %xmm4
	movsd	%xmm4, 32(%rsp)
	js	.L8
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r8, %xmm0
.L9:
	divsd	32(%rsp), %xmm0
	movq	40(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movsd	%xmm0, 8(%rsp)
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r12
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
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
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movsd	8(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%r14d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
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
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L16
	call	_ZdlPv
.L16:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L17
	call	_ZdlPv
.L17:
	movq	%rbp, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
	cmpq	$0, 24(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L177
	movl	$24, %edi
	xorl	%ebp, %ebp
	call	_Znwm
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
.L76:
	movq	%rbp, 8(%r12)
	movq	(%rbx), %r14
	movl	$100, %ebp
	movq	(%r12), %rsi
	movq	$-1, %r15
	jmp	.L29
	.p2align 4,,10
	.p2align 3
.L181:
	testq	%r13, %r13
	movq	%r14, %rcx
	jne	.L178
.L24:
	movq	%rcx, 8(%rbx)
.L20:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	8(%rsp), %rdx
	cmpq	%rdx, %r15
	cmova	%rdx, %r15
	subq	$1, %rbp
	je	.L179
.L29:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%r12, %rbx
	movq	%rdx, 8(%rsp)
	je	.L20
	movq	8(%r12), %r8
	movq	16(%rbx), %rax
	movq	%r8, %r13
	subq	%r14, %rax
	subq	%rsi, %r13
	cmpq	%rax, %r13
	ja	.L180
	movq	8(%rbx), %rdi
	movq	%rdi, %rdx
	subq	%r14, %rdx
	cmpq	%rdx, %r13
	jbe	.L181
	testq	%rdx, %rdx
	jne	.L182
.L27:
	leaq	(%rsi,%rdx), %rax
	movq	%r8, %rdx
	leaq	(%r14,%r13), %rcx
	subq	%rax, %rdx
	je	.L24
	movq	%rax, %rsi
	call	memmove
	movq	(%rbx), %r14
	movq	(%r12), %rsi
	leaq	(%r14,%r13), %rcx
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L180:
	movq	%r13, %rdi
	movq	%rsi, 16(%rsp)
	call	_Znwm
	testq	%r13, %r13
	movq	%rax, %r14
	movq	16(%rsp), %rsi
	je	.L22
	movq	%r13, %rdx
	movq	%rax, %rdi
	call	memmove
.L22:
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L23
	call	_ZdlPv
.L23:
	leaq	(%r14,%r13), %rcx
	movq	%r14, (%rbx)
	movq	(%r12), %rsi
	movq	%rcx, 16(%rbx)
	jmp	.L24
.L182:
	movq	%r14, %rdi
	call	memmove
	movq	8(%rbx), %rdi
	movq	(%rbx), %r14
	movq	(%r12), %rsi
	movq	8(%r12), %r8
	movq	%rdi, %rdx
	subq	%r14, %rdx
	jmp	.L27
.L178:
	movq	%r14, %rdi
	movq	%r13, %rdx
	call	memmove
	movq	(%rbx), %r14
	movq	(%r12), %rsi
	leaq	(%r14,%r13), %rcx
	jmp	.L24
.L81:
	movq	%rdi, %r11
	jmp	.L5
.L179:
	testq	%r15, %r15
	movl	100(%rsi), %ebp
	movl	100(%r14), %r13d
	js	.L30
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r15, %xmm0
.L31:
	divsd	32(%rsp), %xmm0
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L13
	cmpb	$0, 56(%rbp)
	je	.L32
	movsbl	67(%rbp), %esi
.L33:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L34
	call	_ZdlPv
.L34:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L35
	call	_ZdlPv
.L35:
	movq	%r12, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
	cmpq	$0, 24(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L183
	movl	$24, %edi
	xorl	%ebp, %ebp
	call	_Znwm
	movq	%rax, 8(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
.L78:
	movq	%rbp, 8(%rax)
	movabsq	$9223372036854775807, %rax
	leaq	64(%rsp), %rbp
	movq	%rax, 48(%rsp)
	movq	%rax, 56(%rsp)
	movl	$100, %r12d
	movq	%rax, %r13
	.p2align 4,,10
	.p2align 3
.L44:
	movl	$4, %edi
	movq	%rbp, %rsi
	call	clock_gettime
	movq	(%rbx), %rax
	cmpq	8(%rbx), %rax
	movq	8(%rsp), %rdi
	movq	64(%rsp), %r14
	movq	72(%rsp), %r15
	movq	(%rdi), %rdx
	je	.L42
	.p2align 4,,10
	.p2align 3
.L134:
	movzbl	(%rdx), %ecx
	addq	$1, %rax
	addq	$1, %rdx
	movb	%cl, -1(%rax)
	cmpq	%rax, 8(%rbx)
	jne	.L134
.L42:
	movq	%rbp, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	72(%rsp), %rcx
	movq	64(%rsp), %rsi
	subq	%r15, %rcx
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
	leaq	48(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r13, %rsi
	movq	%rcx, 72(%rsp)
	jg	.L40
	cmpq	56(%rsp), %rcx
	leaq	48(%rsp), %rdi
	movq	%rbp, %rax
	cmovg	%rdi, %rax
.L40:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %r12
	movq	%rax, 48(%rsp)
	movq	%rdx, 56(%rsp)
	je	.L43
	movq	48(%rsp), %r13
	jmp	.L44
.L43:
	movq	8(%rsp), %rax
	movq	40(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movq	(%rax), %rax
	movl	100(%rax), %r13d
	movq	(%rbx), %rax
	movl	100(%rax), %r12d
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r14
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	%r12d, %esi
	movq	%r14, %rdi
	call	_ZNSolsEi
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L13
	cmpb	$0, 56(%r12)
	je	.L45
	movsbl	67(%r12), %esi
.L46:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	movsd	.LC2(%rip), %xmm1
	movl	$.LC4, %esi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	56(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	48(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L47
	call	_ZdlPv
.L47:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	8(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L48
	call	_ZdlPv
.L48:
	movq	8(%rsp), %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
	cmpq	$0, 24(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L184
	movl	$24, %edi
	xorl	%r13d, %r13d
	call	_Znwm
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
.L79:
	movabsq	$9223372036854775807, %rax
	movq	%r13, 8(%r12)
	movq	$100, 8(%rsp)
	movq	%rax, 48(%rsp)
	movq	%rax, 56(%rsp)
	movq	%rax, %r13
	jmp	.L62
	.p2align 4,,10
	.p2align 3
.L187:
	testq	%r8, %r8
	jne	.L185
.L55:
	movq	%rdi, 8(%rbx)
.L51:
	movq	%rbp, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	72(%rsp), %rcx
	movq	64(%rsp), %rsi
	subq	%r15, %rcx
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
	leaq	48(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r13, %rsi
	movq	%rcx, 72(%rsp)
	jg	.L60
	cmpq	56(%rsp), %rcx
	cmovle	%rbp, %rax
.L60:
	subq	$1, 8(%rsp)
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rdx, 56(%rsp)
	movq	%rax, 48(%rsp)
	je	.L61
	movq	48(%rsp), %r13
.L62:
	movq	%rbp, %rsi
	movl	$4, %edi
	call	clock_gettime
	cmpq	%r12, %rbx
	movq	64(%rsp), %r14
	movq	72(%rsp), %r15
	je	.L51
	movq	8(%r12), %rcx
	movq	(%r12), %rsi
	movq	(%rbx), %rdi
	movq	16(%rbx), %rax
	movq	%rcx, %r8
	subq	%rsi, %r8
	subq	%rdi, %rax
	cmpq	%rax, %r8
	ja	.L186
	movq	8(%rbx), %rax
	movq	%rax, %rdx
	subq	%rdi, %rdx
	cmpq	%rdx, %r8
	jbe	.L187
	testq	%rdx, %rdx
	jne	.L188
.L58:
	addq	%rdx, %rsi
	subq	%rsi, %rcx
	movq	%rcx, %rdx
	jne	.L59
	addq	%r8, %rdi
	jmp	.L55
	.p2align 4,,10
	.p2align 3
.L186:
	movq	%r8, %rdi
	movq	%rsi, 24(%rsp)
	movq	%r8, 16(%rsp)
	call	_Znwm
	movq	16(%rsp), %r8
	movq	%rax, %rcx
	movq	24(%rsp), %rsi
	testq	%r8, %r8
	je	.L53
	movq	%r8, %rdx
	movq	%rax, %rdi
	call	memmove
	movq	16(%rsp), %r8
	movq	%rax, %rcx
.L53:
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L54
	movq	%r8, 24(%rsp)
	movq	%rcx, 16(%rsp)
	call	_ZdlPv
	movq	24(%rsp), %r8
	movq	16(%rsp), %rcx
.L54:
	leaq	(%rcx,%r8), %rdi
	movq	%rcx, (%rbx)
	movq	%rdi, 16(%rbx)
	jmp	.L55
.L185:
	movq	%r8, %rdx
	movq	%r8, 16(%rsp)
	call	memmove
	movq	16(%rsp), %r8
	movq	%r8, %rdi
	addq	(%rbx), %rdi
	jmp	.L55
.L59:
	movq	%rax, %rdi
	movq	%r8, 16(%rsp)
	call	memmove
	movq	16(%rsp), %r8
	movq	%r8, %rdi
	addq	(%rbx), %rdi
	jmp	.L55
.L188:
	movq	%r8, 16(%rsp)
	call	memmove
	movq	8(%rbx), %rax
	movq	(%rbx), %rdi
	movq	(%r12), %rsi
	movq	8(%r12), %rcx
	movq	16(%rsp), %r8
	movq	%rax, %rdx
	subq	%rdi, %rdx
	jmp	.L58
.L61:
	pxor	%xmm0, %xmm0
	movl	$.LC4, %esi
	movsd	.LC2(%rip), %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	56(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	48(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk
	movq	(%r12), %rax
	movl	$_ZSt4cout, %edi
	movl	100(%rax), %ebp
	movq	(%rbx), %rax
	movl	100(%rax), %esi
	call	_ZNSolsEi
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L13
	cmpb	$0, 56(%rbp)
	je	.L63
	movsbl	67(%rbp), %esi
.L64:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L65
	call	_ZdlPv
.L65:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L66
	call	_ZdlPv
.L66:
	movq	%r12, %rdi
	call	_ZdlPv
	movq	88(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L189
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
.L63:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%rbp), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L64
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L64
.L45:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L46
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L46
.L32:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%rbp), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L33
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L33
.L11:
	movq	%r15, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r15), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L12
	movq	%r15, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L12
.L14:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L15
	movq	%r12, %rdi
	call	*%rax
.LEHE0:
	movsbl	%al, %esi
	jmp	.L15
.L184:
	movq	24(%rsp), %r15
	movq	%r15, %rdi
.LEHB1:
	call	_Znwm
.LEHE1:
	leaq	(%rax,%r15), %r12
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%rbx)
	movq	%r12, 16(%rbx)
	call	memset
	movq	%r12, 8(%rbx)
	movl	$24, %edi
.LEHB2:
	call	_Znwm
.LEHE2:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB3:
	call	_Znwm
.LEHE3:
	movq	24(%rsp), %rdi
	movq	%rax, (%r12)
	xorl	%esi, %esi
	movq	%rax, 8(%r12)
	leaq	(%rax,%rdi), %r13
	movq	%rdi, %rdx
	movq	%rax, %rdi
	movq	%r13, 16(%r12)
	call	memset
	jmp	.L79
.L183:
	movq	24(%rsp), %r15
	movq	%r15, %rdi
.LEHB4:
	call	_Znwm
.LEHE4:
	leaq	(%rax,%r15), %rbp
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%rbx)
	movq	%rbp, 16(%rbx)
	call	memset
	movl	$24, %edi
	movq	%rbp, 8(%rbx)
.LEHB5:
	call	_Znwm
.LEHE5:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, 8(%rsp)
.LEHB6:
	call	_Znwm
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
	call	memset
	movq	8(%rsp), %rax
	jmp	.L78
.L177:
	movq	24(%rsp), %r15
	movq	%r15, %rdi
.LEHB7:
	call	_Znwm
.LEHE7:
	leaq	(%rax,%r15), %rbp
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%rbx)
	movq	%rbp, 16(%rbx)
	call	memset
	movl	$24, %edi
	movq	%rbp, 8(%rbx)
.LEHB8:
	call	_Znwm
.LEHE8:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB9:
	call	_Znwm
.LEHE9:
	movq	24(%rsp), %rdi
	movq	%rax, (%r12)
	xorl	%esi, %esi
	movq	%rax, 8(%r12)
	leaq	(%rax,%rdi), %rbp
	movq	%rdi, %rdx
	movq	%rax, %rdi
	movq	%rbp, 16(%r12)
	call	memset
	jmp	.L76
.L176:
	movq	%rax, %rdi
	movq	%rax, %r15
.LEHB10:
	call	_Znwm
.LEHE10:
	leaq	(%rax,%r15), %rbp
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%rbx)
	movq	%rbp, 16(%rbx)
	call	memset
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB11:
	call	_Znwm
.LEHE11:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbp
.LEHB12:
	call	_Znwm
.LEHE12:
	movq	24(%rsp), %rdi
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, 8(%rbp)
	leaq	(%rax,%rdi), %r12
	movq	%rdi, %rdx
	movq	%rax, %rdi
	movq	%r12, 16(%rbp)
	call	memset
	jmp	.L75
.L8:
	movq	%r8, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r8d
	orq	%r8, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L9
.L30:
	movq	%r15, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r15d
	orq	%r15, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L31
.L96:
.L168:
	movq	%rax, %rbp
	jmp	.L73
.L189:
	call	__stack_chk_fail
.L73:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	%rbp, %rdi
.LEHB13:
	call	_Unwind_Resume
.L13:
	call	_ZSt16__throw_bad_castv
.L91:
	movq	%rax, %rbx
	jmp	.L68
.L90:
	jmp	.L168
.L93:
.L169:
	movq	%rax, %rbx
	jmp	.L74
.L68:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L74:
	movq	%r12, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L92:
	jmp	.L168
.L95:
	movq	%rax, %rbx
	jmp	.L72
.L94:
	jmp	.L168
.L97:
	jmp	.L169
.L72:
	movq	8(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.LEHE13:
	.cfi_endproc
.LFE6945:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._Z4funcIaEvm,"aG",@progbits,_Z4funcIaEvm,comdat
.LLSDA6945:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE6945-.LLSDACSB6945
.LLSDACSB6945:
	.uleb128 .LEHB0-.LFB6945
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB6945
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L96-.LFB6945
	.uleb128 0
	.uleb128 .LEHB2-.LFB6945
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB6945
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L97-.LFB6945
	.uleb128 0
	.uleb128 .LEHB4-.LFB6945
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L94-.LFB6945
	.uleb128 0
	.uleb128 .LEHB5-.LFB6945
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB6-.LFB6945
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L95-.LFB6945
	.uleb128 0
	.uleb128 .LEHB7-.LFB6945
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L92-.LFB6945
	.uleb128 0
	.uleb128 .LEHB8-.LFB6945
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB9-.LFB6945
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L93-.LFB6945
	.uleb128 0
	.uleb128 .LEHB10-.LFB6945
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L90-.LFB6945
	.uleb128 0
	.uleb128 .LEHB11-.LFB6945
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB12-.LFB6945
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L91-.LFB6945
	.uleb128 0
	.uleb128 .LEHB13-.LFB6945
	.uleb128 .LEHE13-.LEHB13
	.uleb128 0
	.uleb128 0
.LLSDACSE6945:
	.section	.text._Z4funcIaEvm,"axG",@progbits,_Z4funcIaEvm,comdat
	.size	_Z4funcIaEvm, .-_Z4funcIaEvm
	.section	.text.unlikely._Z4funcIaEvm,"axG",@progbits,_Z4funcIaEvm,comdat
.LCOLDE5:
	.section	.text._Z4funcIaEvm,"axG",@progbits,_Z4funcIaEvm,comdat
.LHOTE5:
	.section	.text.unlikely._Z4funcIDv4_xEvm,"axG",@progbits,_Z4funcIDv4_xEvm,comdat
.LCOLDB6:
	.section	.text._Z4funcIDv4_xEvm,"axG",@progbits,_Z4funcIDv4_xEvm,comdat
.LHOTB6:
	.p2align 4,,15
	.weak	_Z4funcIDv4_xEvm
	.type	_Z4funcIDv4_xEvm, @function
_Z4funcIDv4_xEvm:
.LFB6950:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA6950
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
	.cfi_escape 0x10,0xf,0x2,0x76,0x78
	.cfi_escape 0x10,0xe,0x2,0x76,0x70
	.cfi_escape 0x10,0xd,0x2,0x76,0x68
	.cfi_escape 0x10,0xc,0x2,0x76,0x60
	movq	%rdi, %r15
	pushq	%r10
	.cfi_escape 0xf,0x3,0x76,0x58,0x6
	pushq	%rbx
	subq	$192, %rsp
	.cfi_escape 0x10,0x3,0x2,0x76,0x50
	movq	%rdi, -240(%rbp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
.LEHB14:
	call	_Znwm
.LEHE14:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movl	$104857600, %eax
	divq	%r15
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, -224(%rbp)
	je	.L191
	salq	$5, %rax
	movq	%rax, %rdi
	movq	%rax, %r15
	movq	%rax, -216(%rbp)
.LEHB15:
	call	_Znwm
.LEHE15:
	leaq	(%rax,%r15), %r12
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%rbx)
	movq	%r12, 16(%rbx)
	call	memset
	movq	%r12, 8(%rbx)
	movl	$24, %edi
.LEHB16:
	call	_Znwm
.LEHE16:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB17:
	call	_Znwm
.LEHE17:
	movq	%rax, %r14
	movq	%rax, (%r12)
	movq	%rax, 8(%r12)
	leaq	(%rax,%r15), %rax
	movq	%r15, %r13
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%r14, %rdi
	addq	%r14, %r13
	movq	%rax, 16(%r12)
	call	memset
.L267:
	movq	(%r12), %rsi
	movq	8(%rbx), %rdi
	movl	$100, %r10d
	movq	(%rbx), %rcx
	movq	%r13, 8(%r12)
	movq	$-1, %r9
	.p2align 4,,10
	.p2align 3
.L194:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%rdi, %rcx
	movq	%rdx, %r8
	je	.L278
	movq	%rsi, %rax
	.p2align 4,,10
	.p2align 3
.L193:
	movq	(%rax), %rsi
	addq	$32, %rcx
	addq	$32, %rax
	movq	%rsi, -144(%rbp)
	movq	-24(%rax), %rdx
	movq	%rdx, -136(%rbp)
	movq	-16(%rax), %rdx
	movq	%rdx, -128(%rbp)
	movq	-8(%rax), %rdx
	movq	%rdx, -120(%rbp)
	movq	%rsi, -32(%rcx)
	movq	-136(%rbp), %rsi
	movq	%rsi, -24(%rcx)
	movq	-128(%rbp), %rsi
	movq	%rsi, -16(%rcx)
	movq	-120(%rbp), %rsi
	movq	%rsi, -8(%rcx)
	movq	8(%rbx), %rdi
	cmpq	%rdi, %rcx
	jne	.L193
	movq	(%rbx), %r11
	movq	(%r12), %rsi
.L192:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%r11, %rcx
	orq	%rax, %rdx
	subq	%r8, %rdx
	cmpq	%rdx, %r9
	cmova	%rdx, %r9
	subq	$1, %r10
	jne	.L194
	movl	3200(%rsi), %eax
	pxor	%xmm4, %xmm4
	testq	%r9, %r9
	movl	3200(%r11), %r15d
	cvtsi2sdq	-224(%rbp), %xmm4
	movl	%eax, -184(%rbp)
	movsd	%xmm4, -232(%rbp)
	js	.L195
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r9, %xmm0
.L196:
	divsd	-232(%rbp), %xmm0
	movq	-240(%rbp), %rsi
	movl	$_ZSt4cout, %edi
	movsd	%xmm0, -192(%rbp)
.LEHB18:
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r13
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	0(%r13), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r14
	testq	%r14, %r14
	je	.L200
	cmpb	$0, 56(%r14)
	je	.L198
	movsbl	67(%r14), %esi
.L199:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movsd	-192(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%r15d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	-184(%rbp), %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r14
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r13
	testq	%r13, %r13
	je	.L200
	cmpb	$0, 56(%r13)
	je	.L201
	movsbl	67(%r13), %esi
.L202:
	movq	%r14, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L203
	call	_ZdlPv
.L203:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L368
	call	_ZdlPv
.L368:
	movq	%r12, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE18:
	cmpq	$0, -224(%rbp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L205
	movq	-216(%rbp), %rbx
	movq	%rbx, %rdi
.LEHB19:
	call	_Znwm
.LEHE19:
	movq	-224(%rbp), %r15
	movq	%rax, %r13
	movq	%rax, (%r12)
	movq	%rbx, -216(%rbp)
	movq	%rbx, %rax
	movq	%r13, %rdi
	addq	%r13, %rax
	xorl	%esi, %esi
	movq	%r15, %rbx
	movq	%rax, 16(%r12)
	salq	$5, %rbx
	movq	%rbx, %rdx
	addq	%r13, %rbx
	call	memset
	movl	$24, %edi
	movq	%rbx, 8(%r12)
.LEHB20:
	call	_Znwm
.LEHE20:
	movq	-216(%rbp), %r13
	movq	$0, (%rax)
	movq	%rax, %r14
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%r13, %rdi
.LEHB21:
	call	_Znwm
.LEHE21:
	movq	%rax, %rbx
	movq	%rax, (%r14)
	movq	%rax, 8(%r14)
	movq	%r13, %rax
	addq	%rbx, %rax
	testq	%r15, %r15
	movq	%rax, 16(%r14)
	je	.L281
	movq	%r15, %r13
	xorl	%esi, %esi
	movq	%rbx, %rdi
	salq	$5, %r13
	movq	%rbx, %r15
	movq	%r13, %rdx
	call	memset
	leaq	(%rbx,%r13), %rax
.L206:
	movq	(%r12), %rcx
	movq	$-1, %r13
	movq	%rax, 8(%r14)
	movq	%r14, %rbx
	movq	%r15, %rsi
	movq	$100, -192(%rbp)
	movq	%r13, %r15
	movq	%r12, %r13
	movq	%rcx, %r14
	jmp	.L219
	.p2align 4,,10
	.p2align 3
.L375:
	testq	%r9, %r9
	jne	.L372
.L364:
	leaq	(%r14,%r12), %r8
.L214:
	movq	%r8, 8(%r13)
.L207:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	-184(%rbp), %rdx
	cmpq	%rdx, %r15
	cmova	%rdx, %r15
	subq	$1, -192(%rbp)
	je	.L373
.L219:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%rbx, %r13
	movq	%rdx, -184(%rbp)
	je	.L207
	movq	8(%rbx), %r10
	movq	16(%r13), %rax
	movq	%r10, %r12
	subq	%r14, %rax
	subq	%rsi, %r12
	sarq	$5, %rax
	movq	%r12, %r9
	sarq	$5, %r9
	cmpq	%rax, %r9
	ja	.L374
	movq	8(%r13), %rdi
	movq	%rdi, %rax
	subq	%r14, %rax
	movq	%rax, %rdx
	sarq	$5, %rdx
	cmpq	%rdx, %r9
	jbe	.L375
	testq	%rdx, %rdx
	jne	.L376
.L217:
	addq	%rsi, %rax
	subq	%rax, %r10
	movq	%r10, %rdx
	sarq	$5, %rdx
	testq	%rdx, %rdx
	je	.L364
	movq	%rax, %rsi
	movq	%r10, %rdx
	call	memmove
	movq	0(%r13), %r14
	movq	(%rbx), %rsi
	leaq	(%r14,%r12), %r8
	jmp	.L214
	.p2align 4,,10
	.p2align 3
.L374:
	movq	%r14, %r10
	xorl	%r14d, %r14d
	testq	%r9, %r9
	je	.L212
	movabsq	$576460752303423487, %rax
	cmpq	%rax, %r9
	ja	.L245
	movq	%r12, %rdi
	movq	%rsi, -208(%rbp)
	movq	%r9, -200(%rbp)
.LEHB22:
	call	_Znwm
	movq	-200(%rbp), %r9
	movq	%rax, %r14
	movq	0(%r13), %r10
	movq	-208(%rbp), %rsi
	testq	%r9, %r9
	je	.L212
	movq	%r12, %rdx
	movq	%rax, %rdi
	movq	%r10, -200(%rbp)
	call	memmove
	movq	-200(%rbp), %r10
.L212:
	testq	%r10, %r10
	je	.L213
	movq	%r10, %rdi
	call	_ZdlPv
.L213:
	leaq	(%r14,%r12), %r8
	movq	%r14, 0(%r13)
	movq	(%rbx), %rsi
	movq	%r8, 16(%r13)
	jmp	.L214
.L376:
	movq	%r14, %rdi
	movq	%rax, %rdx
	call	memmove
	movq	8(%r13), %rdi
	movq	0(%r13), %r14
	movq	(%rbx), %rsi
	movq	8(%rbx), %r10
	movq	%rdi, %rax
	subq	%r14, %rax
	jmp	.L217
.L372:
	movq	%r14, %rdi
	movq	%r12, %rdx
	call	memmove
	movq	0(%r13), %r14
	movq	(%rbx), %rsi
	leaq	(%r14,%r12), %r8
	jmp	.L214
.L278:
	movq	%rdi, %r11
	jmp	.L192
.L373:
	movq	%r13, %r12
	movq	%r15, %r13
	movq	%r14, %rcx
	testq	%r13, %r13
	movq	%rbx, %r14
	movl	3200(%rcx), %r15d
	movl	3200(%rsi), %ebx
	js	.L220
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r13, %xmm0
.L221:
	divsd	-232(%rbp), %xmm0
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%r15d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbx
	testq	%rbx, %rbx
	je	.L200
	cmpb	$0, 56(%rbx)
	je	.L222
	movsbl	67(%rbx), %esi
.L223:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L224
	call	_ZdlPv
.L224:
	movq	%r12, %rdi
	call	_ZdlPv
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	je	.L369
	call	_ZdlPv
.L369:
	movq	%r14, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE22:
	cmpq	$0, -224(%rbp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L226
	movq	-216(%rbp), %r15
	movq	%r15, %rdi
.LEHB23:
	call	_Znwm
.LEHE23:
	movq	-224(%rbp), %r14
	movq	%rax, %r13
	movq	%rax, (%rbx)
	movq	%r15, %rax
	movq	%r13, %rdi
	xorl	%esi, %esi
	addq	%r13, %rax
	movq	%r15, -216(%rbp)
	movq	%r14, %r12
	movq	%rax, 16(%rbx)
	salq	$5, %r12
	movq	%r12, %rdx
	addq	%r13, %r12
	call	memset
	movl	$24, %edi
	movq	%r12, 8(%rbx)
.LEHB24:
	call	_Znwm
.LEHE24:
	movq	-216(%rbp), %r13
	movq	$0, (%rax)
	movq	%rax, %r15
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, -184(%rbp)
	movq	%r13, %rdi
.LEHB25:
	call	_Znwm
.LEHE25:
	movq	%rax, %r12
	movq	%r13, %rax
	addq	%r12, %rax
	testq	%r14, %r14
	movq	%r12, (%r15)
	movq	%r12, 8(%r15)
	movq	%rax, 16(%r15)
	je	.L227
	movq	%r14, %r13
	movq	%r12, %rdi
	xorl	%esi, %esi
	salq	$5, %r13
	movq	%r13, %rdx
	addq	%r13, %r12
	call	memset
.L227:
	movq	-184(%rbp), %rax
	movq	$100, -192(%rbp)
	movq	%rbx, %r14
	movq	%r12, 8(%rax)
	movabsq	$9223372036854775807, %rax
	leaq	-160(%rbp), %r12
	movq	%rax, -176(%rbp)
	movq	%rax, -168(%rbp)
	movq	%rax, %r13
	.p2align 4,,10
	.p2align 3
.L234:
	movl	$4, %edi
	movq	%r12, %rsi
	call	clock_gettime
	movq	(%r14), %rax
	cmpq	8(%r14), %rax
	movq	-184(%rbp), %rdi
	movq	-160(%rbp), %r15
	movq	-152(%rbp), %rbx
	movq	(%rdi), %rdx
	je	.L232
	.p2align 4,,10
	.p2align 3
.L330:
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
	cmpq	%rax, 8(%r14)
	jne	.L330
.L232:
	movq	%r12, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	-152(%rbp), %rcx
	movq	-160(%rbp), %rsi
	subq	%rbx, %rcx
	subq	%r15, %rsi
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
	leaq	-176(%rbp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r13, %rsi
	movq	%rcx, -152(%rbp)
	jg	.L230
	cmpq	-168(%rbp), %rcx
	leaq	-176(%rbp), %rax
	cmovle	%r12, %rax
.L230:
	subq	$1, -192(%rbp)
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rdx, -168(%rbp)
	movq	%rax, -176(%rbp)
	je	.L233
	movq	-176(%rbp), %r13
	jmp	.L234
.L233:
	movq	-184(%rbp), %rax
	movq	-240(%rbp), %rsi
	movq	%r14, %rbx
	movl	$_ZSt4cout, %edi
	movq	(%rax), %rax
	movl	3200(%rax), %r13d
	movq	(%r14), %rax
	movl	3200(%rax), %r14d
.LEHB26:
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r15
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	%r14d, %esi
	movq	%r15, %rdi
	call	_ZNSolsEi
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r14
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r13
	testq	%r13, %r13
	je	.L200
	cmpb	$0, 56(%r13)
	je	.L235
	movsbl	67(%r13), %esi
.L236:
	movq	%r14, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	movsd	.LC2(%rip), %xmm1
	movl	$.LC4, %esi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	-168(%rbp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	-176(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L237
	call	_ZdlPv
.L237:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	-184(%rbp), %rbx
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L370
	call	_ZdlPv
.L370:
	movq	%rbx, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE26:
	cmpq	$0, -224(%rbp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L239
	movq	-216(%rbp), %r15
	movq	%r15, %rdi
.LEHB27:
	call	_Znwm
.LEHE27:
	movq	-224(%rbp), %r13
	movq	%rax, %r14
	movq	%rax, (%rbx)
	movq	%r15, %rax
	xorl	%esi, %esi
	movq	%r14, %rdi
	addq	%r14, %rax
	salq	$5, %r13
	movq	%rax, 16(%rbx)
	movq	%r13, %rdx
	addq	%r14, %r13
	call	memset
	movq	%r13, 8(%rbx)
	movl	$24, %edi
.LEHB28:
	call	_Znwm
.LEHE28:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r13
.LEHB29:
	call	_Znwm
.LEHE29:
	movq	%rax, %r14
	movq	%rax, 0(%r13)
	movq	%rax, 8(%r13)
	movq	%r15, %rax
	addq	%r14, %rax
	movq	%rax, 16(%r13)
	movq	-224(%rbp), %rax
	testq	%rax, %rax
	je	.L240
	movq	%rax, %r15
	movq	%r14, %rdi
	xorl	%esi, %esi
	salq	$5, %r15
	movq	%r15, %rdx
	addq	%r15, %r14
	call	memset
.L240:
	movabsq	$9223372036854775807, %rax
	movq	%r14, 8(%r13)
	movq	$100, -184(%rbp)
	movq	%rax, -176(%rbp)
	movq	%rax, -168(%rbp)
	movq	%rbx, %r14
	jmp	.L254
	.p2align 4,,10
	.p2align 3
.L380:
	testq	%r11, %r11
	jne	.L377
.L365:
	addq	%r9, %r8
.L248:
	movq	%r8, 8(%r14)
.L241:
	movq	%r12, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	-152(%rbp), %rsi
	movq	-160(%rbp), %rdi
	subq	%rbx, %rsi
	subq	%r15, %rdi
	movq	%rsi, %rax
	addq	$1000000000, %rsi
	shrq	$63, %rax
	subq	%rax, %rdi
	movabsq	$1237940039285380275, %rax
	imulq	%rsi
	movq	%rsi, %rax
	movq	%rdi, -160(%rbp)
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	leaq	-176(%rbp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rsi
	cmpq	-176(%rbp), %rdi
	movq	%rsi, -152(%rbp)
	jg	.L253
	cmpq	-168(%rbp), %rsi
	cmovle	%r12, %rax
.L253:
	subq	$1, -184(%rbp)
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rdx, -168(%rbp)
	movq	%rax, -176(%rbp)
	je	.L378
.L254:
	movq	%r12, %rsi
	movl	$4, %edi
	call	clock_gettime
	cmpq	%r13, %r14
	movq	-160(%rbp), %r15
	movq	-152(%rbp), %rbx
	je	.L241
	movq	8(%r13), %r10
	movq	0(%r13), %rsi
	movq	(%r14), %r9
	movq	16(%r14), %rax
	movq	%r10, %r8
	subq	%rsi, %r8
	subq	%r9, %rax
	movq	%r8, %r11
	sarq	$5, %rax
	sarq	$5, %r11
	cmpq	%rax, %r11
	ja	.L379
	movq	8(%r14), %rdi
	movq	%rdi, %rdx
	subq	%r9, %rdx
	movq	%rdx, %rax
	sarq	$5, %rax
	cmpq	%rax, %r11
	jbe	.L380
	testq	%rax, %rax
	jne	.L381
.L251:
	addq	%rdx, %rsi
	movq	%r10, %rdx
	subq	%rsi, %rdx
	movq	%rdx, %rax
	sarq	$5, %rax
	testq	%rax, %rax
	je	.L365
	movq	%r8, -192(%rbp)
	call	memmove
	movq	-192(%rbp), %r8
	addq	(%r14), %r8
	jmp	.L248
	.p2align 4,,10
	.p2align 3
.L379:
	xorl	%r10d, %r10d
	testq	%r11, %r11
	je	.L246
	movabsq	$576460752303423487, %rax
	movq	%rsi, -208(%rbp)
	movq	%r11, -200(%rbp)
	cmpq	%rax, %r11
	ja	.L245
	movq	%r8, %rdi
	movq	%r8, -192(%rbp)
.LEHB30:
	call	_Znwm
	movq	-200(%rbp), %r11
	movq	%rax, %r10
	movq	(%r14), %r9
	movq	-192(%rbp), %r8
	movq	-208(%rbp), %rsi
	testq	%r11, %r11
	je	.L246
	movq	%r8, %rdx
	movq	%rax, %rdi
	movq	%r9, -200(%rbp)
	call	memmove
	movq	-200(%rbp), %r9
	movq	-192(%rbp), %r8
	movq	%rax, %r10
.L246:
	testq	%r9, %r9
	je	.L247
	movq	%r9, %rdi
	movq	%r10, -200(%rbp)
	movq	%r8, -192(%rbp)
	call	_ZdlPv
	movq	-200(%rbp), %r10
	movq	-192(%rbp), %r8
.L247:
	addq	%r10, %r8
	movq	%r10, (%r14)
	movq	%r8, 16(%r14)
	jmp	.L248
.L381:
	movq	%r9, %rdi
	movq	%r8, -192(%rbp)
	call	memmove
	movq	8(%r14), %rdi
	movq	(%r14), %r9
	movq	0(%r13), %rsi
	movq	8(%r13), %r10
	movq	-192(%rbp), %r8
	movq	%rdi, %rdx
	subq	%r9, %rdx
	jmp	.L251
.L377:
	movq	%r8, %rdx
	movq	%r9, %rdi
	movq	%r8, -192(%rbp)
	call	memmove
	movq	-192(%rbp), %r8
	addq	(%r14), %r8
	jmp	.L248
.L378:
	pxor	%xmm0, %xmm0
	movl	$.LC4, %esi
	movsd	.LC2(%rip), %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	-168(%rbp), %xmm0
	mulsd	%xmm0, %xmm1
	movq	%r14, %rbx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	-176(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk
	movq	0(%r13), %rax
	movl	$_ZSt4cout, %edi
	movl	3200(%rax), %r12d
	movq	(%r14), %rax
	movl	3200(%rax), %esi
	call	_ZNSolsEi
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r14
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r12
	testq	%r12, %r12
	je	.L200
	cmpb	$0, 56(%r12)
	je	.L255
	movsbl	67(%r12), %esi
.L256:
	movq	%r14, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L257
	call	_ZdlPv
.L257:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L258
	call	_ZdlPv
.L258:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	-56(%rbp), %rax
	xorq	%fs:40, %rax
	jne	.L382
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
.L235:
	.cfi_restore_state
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%r13), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L236
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L236
.L222:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L223
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L223
.L198:
	movq	%r14, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r14), %rdx
	movl	$10, %esi
	movq	48(%rdx), %rdx
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rdx
	je	.L199
	movq	%r14, %rdi
	call	*%rdx
	movsbl	%al, %esi
	jmp	.L199
.L201:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%r13), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L202
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L202
.L255:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L256
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L256
.L220:
	movq	%r13, %rax
	movq	%r13, %r8
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r8d
	orq	%r8, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L221
.L195:
	movq	%r9, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r9d
	orq	%r9, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L196
.L226:
	movq	-216(%rbp), %rax
	movl	$24, %edi
	xorl	%r12d, %r12d
	movq	%rax, 16(%rbx)
	call	_Znwm
	movq	-216(%rbp), %rdi
	movq	%rax, -184(%rbp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rdi, 16(%rax)
	jmp	.L227
.L191:
	movq	$0, 16(%rbx)
	movl	$24, %edi
	xorl	%r13d, %r13d
	call	_Znwm
	movq	$0, -216(%rbp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jmp	.L267
.L205:
	movq	-216(%rbp), %rax
	movl	$24, %edi
	xorl	%r15d, %r15d
	movq	%rax, 16(%r12)
	call	_Znwm
	movq	%rax, %r14
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	-216(%rbp), %rax
	movq	%rax, 16(%r14)
	xorl	%eax, %eax
	jmp	.L206
.L239:
	movq	-216(%rbp), %rax
	movl	$24, %edi
	xorl	%r14d, %r14d
	movq	%rax, 16(%rbx)
	call	_Znwm
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	-216(%rbp), %rax
	movq	%rax, 16(%r13)
	jmp	.L240
.L289:
.L366:
	movq	%rax, %rbx
	jmp	.L261
.L281:
	movq	%rbx, %r15
	movq	%rbx, %rax
	jmp	.L206
.L261:
	movq	%r12, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L245:
	call	_ZSt17__throw_bad_allocv
.L295:
	movq	%rax, %rbx
	jmp	.L266
.L382:
	call	__stack_chk_fail
.L200:
	call	_ZSt16__throw_bad_castv
.L290:
	jmp	.L366
.L291:
	movq	%rax, %rbx
	jmp	.L262
.L288:
.L367:
	movq	%rax, %r12
	jmp	.L265
.L262:
	movq	%r14, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L265:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	%r12, %rdi
	call	_Unwind_Resume
.L293:
	movq	%rax, %rbx
	jmp	.L264
.L294:
	jmp	.L367
.L264:
	movq	-184(%rbp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L292:
	jmp	.L367
.L266:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.LEHE30:
	.cfi_endproc
.LFE6950:
	.section	.gcc_except_table._Z4funcIDv4_xEvm,"aG",@progbits,_Z4funcIDv4_xEvm,comdat
.LLSDA6950:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE6950-.LLSDACSB6950
.LLSDACSB6950:
	.uleb128 .LEHB14-.LFB6950
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB15-.LFB6950
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L288-.LFB6950
	.uleb128 0
	.uleb128 .LEHB16-.LFB6950
	.uleb128 .LEHE16-.LEHB16
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB17-.LFB6950
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L289-.LFB6950
	.uleb128 0
	.uleb128 .LEHB18-.LFB6950
	.uleb128 .LEHE18-.LEHB18
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB19-.LFB6950
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L290-.LFB6950
	.uleb128 0
	.uleb128 .LEHB20-.LFB6950
	.uleb128 .LEHE20-.LEHB20
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB21-.LFB6950
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L291-.LFB6950
	.uleb128 0
	.uleb128 .LEHB22-.LFB6950
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB23-.LFB6950
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L292-.LFB6950
	.uleb128 0
	.uleb128 .LEHB24-.LFB6950
	.uleb128 .LEHE24-.LEHB24
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB25-.LFB6950
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L293-.LFB6950
	.uleb128 0
	.uleb128 .LEHB26-.LFB6950
	.uleb128 .LEHE26-.LEHB26
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB27-.LFB6950
	.uleb128 .LEHE27-.LEHB27
	.uleb128 .L294-.LFB6950
	.uleb128 0
	.uleb128 .LEHB28-.LFB6950
	.uleb128 .LEHE28-.LEHB28
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB29-.LFB6950
	.uleb128 .LEHE29-.LEHB29
	.uleb128 .L295-.LFB6950
	.uleb128 0
	.uleb128 .LEHB30-.LFB6950
	.uleb128 .LEHE30-.LEHB30
	.uleb128 0
	.uleb128 0
.LLSDACSE6950:
	.section	.text._Z4funcIDv4_xEvm,"axG",@progbits,_Z4funcIDv4_xEvm,comdat
	.size	_Z4funcIDv4_xEvm, .-_Z4funcIDv4_xEvm
	.section	.text.unlikely._Z4funcIDv4_xEvm,"axG",@progbits,_Z4funcIDv4_xEvm,comdat
.LCOLDE6:
	.section	.text._Z4funcIDv4_xEvm,"axG",@progbits,_Z4funcIDv4_xEvm,comdat
.LHOTE6:
	.weak	_Z4funcIU8__vectorxEvm
	.set	_Z4funcIU8__vectorxEvm,_Z4funcIDv4_xEvm
	.section	.text.unlikely._ZNSt6vectorIsSaIsEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIsSaIsEEaSERKS1_,comdat
	.align 2
.LCOLDB7:
	.section	.text._ZNSt6vectorIsSaIsEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIsSaIsEEaSERKS1_,comdat
.LHOTB7:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIsSaIsEEaSERKS1_
	.type	_ZNSt6vectorIsSaIsEEaSERKS1_, @function
_ZNSt6vectorIsSaIsEEaSERKS1_:
.LFB7050:
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
	je	.L384
	movq	8(%rsi), %rdx
	movq	(%rsi), %r15
	movq	%rsi, %r12
	movq	(%rdi), %r13
	movq	16(%rdi), %rcx
	movq	%rdx, %rbp
	subq	%r15, %rbp
	subq	%r13, %rcx
	movq	%rbp, %r14
	sarq	%rcx
	sarq	%r14
	cmpq	%rcx, %r14
	ja	.L407
	movq	8(%rdi), %rdi
	movq	%rdi, %rax
	subq	%r13, %rax
	movq	%rax, %rcx
	sarq	%rcx
	cmpq	%rcx, %r14
	jbe	.L408
	testq	%rcx, %rcx
	jne	.L409
.L394:
	leaq	(%r15,%rax), %rsi
	subq	%rsi, %rdx
	movq	%rdx, %rax
	shrq	%rax
	jne	.L395
.L406:
	addq	%r13, %rbp
.L391:
	movq	%rbp, 8(%rbx)
.L384:
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
.L408:
	.cfi_restore_state
	testq	%r14, %r14
	je	.L406
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%r13, %rdi
	call	memmove
	addq	(%rbx), %rbp
	jmp	.L391
	.p2align 4,,10
	.p2align 3
.L407:
	xorl	%r12d, %r12d
	testq	%r14, %r14
	je	.L389
	testq	%r14, %r14
	js	.L410
	movq	%rbp, %rdi
	call	_Znwm
	testq	%r14, %r14
	movq	%rax, %r12
	movq	(%rbx), %r13
	jne	.L411
.L389:
	testq	%r13, %r13
	je	.L390
.L412:
	movq	%r13, %rdi
	call	_ZdlPv
.L390:
	addq	%r12, %rbp
	movq	%r12, (%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L391
	.p2align 4,,10
	.p2align 3
.L411:
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%rax, %rdi
	call	memmove
	testq	%r13, %r13
	jne	.L412
	jmp	.L390
	.p2align 4,,10
	.p2align 3
.L395:
	call	memmove
	addq	(%rbx), %rbp
	jmp	.L391
	.p2align 4,,10
	.p2align 3
.L409:
	movq	%r13, %rdi
	movq	%rax, %rdx
	movq	%r15, %rsi
	call	memmove
	movq	8(%rbx), %rdi
	movq	(%rbx), %r13
	movq	(%r12), %r15
	movq	8(%r12), %rdx
	movq	%rdi, %rax
	subq	%r13, %rax
	jmp	.L394
.L410:
	call	_ZSt17__throw_bad_allocv
	.cfi_endproc
.LFE7050:
	.size	_ZNSt6vectorIsSaIsEEaSERKS1_, .-_ZNSt6vectorIsSaIsEEaSERKS1_
	.section	.text.unlikely._ZNSt6vectorIsSaIsEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIsSaIsEEaSERKS1_,comdat
.LCOLDE7:
	.section	.text._ZNSt6vectorIsSaIsEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIsSaIsEEaSERKS1_,comdat
.LHOTE7:
	.section	.text.unlikely._Z4funcIsEvm,"axG",@progbits,_Z4funcIsEvm,comdat
.LCOLDB8:
	.section	.text._Z4funcIsEvm,"axG",@progbits,_Z4funcIsEvm,comdat
.LHOTB8:
	.p2align 4,,15
	.weak	_Z4funcIsEvm
	.type	_Z4funcIsEvm, @function
_Z4funcIsEvm:
.LFB6946:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA6946
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
	call	_Znwm
	xorl	%edx, %edx
	movq	%rax, %rbx
	movq	%rax, 48(%rsp)
	movl	$104857600, %eax
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	divq	%r15
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, 40(%rsp)
	jne	.L647
	movq	$0, 16(%rbx)
	movl	$24, %edi
	xorl	%ebx, %ebx
	call	_Znwm
	xorl	%ebp, %ebp
	movq	%rax, 56(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, 32(%rsp)
.L503:
	movq	%rbp, 8(%rax)
	movq	48(%rsp), %rax
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
	orl	%r11d, %ecx
	cmpq	$14, %rdx
	seta	%r11b
	andl	$15, %r8d
	shrq	%r8
	andl	%ecx, %r11d
	negq	%r8
	andl	$7, %r8d
	cmpq	%rdx, %r8
	cmova	%rdx, %r8
	subq	%r8, %rdx
	leaq	(%r8,%r8), %r12
	subq	%r8, %rax
	movq	%rdx, 16(%rsp)
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
	movq	%rdx, 24(%rsp)
	.p2align 4,,10
	.p2align 3
.L417:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %r14d
	orq	%rdx, %r14
	cmpq	%rdi, %rsi
	je	.L426
	testb	%r11b, %r11b
	je	.L418
	testq	%r8, %r8
	je	.L511
	movzwl	(%rbx), %eax
	cmpq	$1, %r8
	leaq	2(%rbx), %rcx
	movw	%ax, (%rsi)
	je	.L512
	movzwl	2(%rbx), %eax
	cmpq	$2, %r8
	leaq	4(%rbx), %rcx
	movw	%ax, 2(%rsi)
	leaq	4(%rsi), %rax
	je	.L419
	movzwl	4(%rbx), %eax
	cmpq	$3, %r8
	leaq	6(%rbx), %rcx
	movw	%ax, 4(%rsi)
	leaq	6(%rsi), %rax
	je	.L419
	movzwl	6(%rbx), %eax
	cmpq	$4, %r8
	leaq	8(%rbx), %rcx
	movw	%ax, 6(%rsi)
	leaq	8(%rsi), %rax
	je	.L419
	movzwl	8(%rbx), %eax
	cmpq	$5, %r8
	leaq	10(%rbx), %rcx
	movw	%ax, 8(%rsi)
	leaq	10(%rsi), %rax
	je	.L419
	movzwl	10(%rbx), %eax
	cmpq	$7, %r8
	leaq	12(%rbx), %rcx
	movw	%ax, 10(%rsi)
	leaq	12(%rsi), %rax
	jne	.L419
	movzwl	12(%rbx), %eax
	leaq	14(%rbx), %rcx
	movw	%ax, 12(%rsi)
	leaq	14(%rsi), %rax
.L419:
	cmpq	$6, (%rsp)
	jbe	.L421
	xorl	%edx, %edx
	xorl	%r15d, %r15d
.L422:
	movdqa	0(%r13,%rdx), %xmm0
	addq	$1, %r15
	movups	%xmm0, (%r12,%rdx)
	addq	$16, %rdx
	cmpq	8(%rsp), %r15
	jb	.L422
	addq	%rbp, %rcx
	addq	%rbp, %rax
	movq	24(%rsp), %r15
	cmpq	%r15, 16(%rsp)
	je	.L426
.L421:
	movzwl	(%rcx), %edx
	movw	%dx, (%rax)
	leaq	2(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L426
	movzwl	2(%rcx), %edx
	movw	%dx, 2(%rax)
	leaq	4(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L426
	movzwl	4(%rcx), %edx
	movw	%dx, 4(%rax)
	leaq	6(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L426
	movzwl	6(%rcx), %edx
	movw	%dx, 6(%rax)
	leaq	8(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L426
	movzwl	8(%rcx), %edx
	movw	%dx, 8(%rax)
	leaq	10(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L426
	movzwl	10(%rcx), %edx
	movw	%dx, 10(%rax)
	leaq	12(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L426
	movzwl	12(%rcx), %edx
	movw	%dx, 12(%rax)
.L426:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	%r14, %rdx
	cmpq	%rdx, %r9
	cmova	%rdx, %r9
	subq	$1, %r10
	jne	.L417
	pxor	%xmm4, %xmm4
	testq	%r9, %r9
	movl	200(%rbx), %ebx
	movl	200(%rsi), %ebp
	cvtsi2sdq	40(%rsp), %xmm4
	movsd	%xmm4, (%rsp)
	js	.L429
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r9, %xmm0
.L430:
	divsd	(%rsp), %xmm0
	movq	72(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movsd	%xmm0, 8(%rsp)
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r12
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r13
	testq	%r13, %r13
	je	.L434
	cmpb	$0, 56(%r13)
	je	.L432
	movsbl	67(%r13), %esi
.L433:
	movq	%r12, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movsd	8(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L434
	cmpb	$0, 56(%rbx)
	je	.L435
	movsbl	67(%rbx), %esi
.L436:
	movq	%rbp, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	48(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L437
	call	_ZdlPv
.L437:
	movq	48(%rsp), %rdi
	call	_ZdlPv
	movq	56(%rsp), %rbx
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L438
	call	_ZdlPv
.L438:
	movq	%rbx, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
	cmpq	$0, 40(%rsp)
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L648
	movq	32(%rsp), %rax
	movl	$24, %edi
	xorl	%ebx, %ebx
	movq	%rax, 16(%r13)
	call	_Znwm
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	32(%rsp), %rax
	movq	%rax, 16(%r12)
.L441:
	movq	%rbx, 8(%r12)
	movl	$100, %ebp
	movq	$-1, %r14
	.p2align 4,,10
	.p2align 3
.L442:
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
	call	_ZNSt6vectorIsSaIsEEaSERKS1_
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	%rbx, %rdx
	cmpq	%rdx, %r14
	cmova	%rdx, %r14
	subq	$1, %rbp
	jne	.L442
	movq	(%r12), %rax
	testq	%r14, %r14
	movl	200(%rax), %ebx
	movq	0(%r13), %rax
	movl	200(%rax), %ebp
	js	.L443
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r14, %xmm0
.L444:
	divsd	(%rsp), %xmm0
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L434
	cmpb	$0, 56(%rbx)
	je	.L445
	movsbl	67(%rbx), %esi
.L446:
	movq	%rbp, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L447
	call	_ZdlPv
.L447:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L448
	call	_ZdlPv
.L448:
	movq	%r12, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
	cmpq	$0, 40(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L649
	movq	32(%rsp), %rax
	movl	$24, %edi
	xorl	%ebp, %ebp
	movq	%rax, 16(%rbx)
	call	_Znwm
	movq	32(%rsp), %rdi
	movq	%rax, (%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rdi, 16(%rax)
.L451:
	movq	(%rsp), %rax
	leaq	96(%rsp), %r15
	movl	$100, %r14d
	movq	%rbp, 8(%rax)
	movabsq	$9223372036854775807, %rax
	movq	%rax, 80(%rsp)
	movq	%rax, 88(%rsp)
	movq	%rax, %rbp
	.p2align 4,,10
	.p2align 3
.L466:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	(%rbx), %r10
	movq	8(%rbx), %rsi
	movq	(%rsp), %rax
	movq	96(%rsp), %r12
	movq	104(%rsp), %r13
	cmpq	%rsi, %r10
	movq	(%rax), %rax
	je	.L462
	leaq	2(%r10), %r8
	movq	%rsi, %rcx
	leaq	16(%r10), %rdx
	subq	%r8, %rcx
	shrq	%rcx
	addq	$1, %rcx
	cmpq	%rdx, %rax
	leaq	16(%rax), %rdx
	setnb	%dil
	cmpq	%rdx, %r10
	setnb	%dl
	orb	%dl, %dil
	je	.L455
	cmpq	$14, %rcx
	jbe	.L455
	movq	%rax, %rdx
	andl	$15, %edx
	shrq	%rdx
	negq	%rdx
	andl	$7, %edx
	cmpq	%rcx, %rdx
	cmova	%rcx, %rdx
	testq	%rdx, %rdx
	je	.L516
	movzwl	(%rax), %edi
	cmpq	$1, %rdx
	movw	%di, (%r10)
	leaq	2(%rax), %rdi
	je	.L456
	movzwl	2(%rax), %edi
	cmpq	$2, %rdx
	leaq	4(%r10), %r8
	movw	%di, 2(%r10)
	leaq	4(%rax), %rdi
	je	.L456
	movzwl	4(%rax), %edi
	cmpq	$3, %rdx
	leaq	6(%r10), %r8
	movw	%di, 4(%r10)
	leaq	6(%rax), %rdi
	je	.L456
	movzwl	6(%rax), %edi
	cmpq	$4, %rdx
	leaq	8(%r10), %r8
	movw	%di, 6(%r10)
	leaq	8(%rax), %rdi
	je	.L456
	movzwl	8(%rax), %edi
	cmpq	$5, %rdx
	leaq	10(%r10), %r8
	movw	%di, 8(%r10)
	leaq	10(%rax), %rdi
	je	.L456
	movzwl	10(%rax), %edi
	cmpq	$7, %rdx
	leaq	12(%r10), %r8
	movw	%di, 10(%r10)
	leaq	12(%rax), %rdi
	jne	.L456
	movzwl	12(%rax), %edi
	leaq	14(%r10), %r8
	movw	%di, 12(%r10)
	leaq	14(%rax), %rdi
.L456:
	subq	%rdx, %rcx
	addq	%rdx, %rdx
	leaq	-8(%rcx), %r9
	addq	%rdx, %rax
	addq	%r10, %rdx
	xorl	%r10d, %r10d
	shrq	$3, %r9
	addq	$1, %r9
	leaq	0(,%r9,8), %r11
	movq	%r11, 8(%rsp)
	xorl	%r11d, %r11d
.L458:
	movdqa	(%rax,%r10), %xmm0
	addq	$1, %r11
	movups	%xmm0, (%rdx,%r10)
	addq	$16, %r10
	cmpq	%r9, %r11
	jb	.L458
	movq	8(%rsp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rax, %rdi
	addq	%rax, %r8
	cmpq	%rcx, %rdx
	je	.L462
	movzwl	(%rdi), %eax
	movw	%ax, (%r8)
	leaq	2(%r8), %rax
	cmpq	%rax, %rsi
	je	.L462
	movzwl	2(%rdi), %eax
	movw	%ax, 2(%r8)
	leaq	4(%r8), %rax
	cmpq	%rax, %rsi
	je	.L462
	movzwl	4(%rdi), %eax
	movw	%ax, 4(%r8)
	leaq	6(%r8), %rax
	cmpq	%rax, %rsi
	je	.L462
	movzwl	6(%rdi), %eax
	movw	%ax, 6(%r8)
	leaq	8(%r8), %rax
	cmpq	%rax, %rsi
	je	.L462
	movzwl	8(%rdi), %eax
	movw	%ax, 8(%r8)
	leaq	10(%r8), %rax
	cmpq	%rax, %rsi
	je	.L462
	movzwl	10(%rdi), %eax
	movw	%ax, 10(%r8)
	leaq	12(%r8), %rax
	cmpq	%rax, %rsi
	je	.L462
	movzwl	12(%rdi), %eax
	movw	%ax, 12(%r8)
.L462:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
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
	leaq	80(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%rbp, %rsi
	movq	%rcx, 104(%rsp)
	jg	.L454
	cmpq	88(%rsp), %rcx
	leaq	80(%rsp), %rdi
	movq	%r15, %rax
	cmovg	%rdi, %rax
.L454:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %r14
	movq	%rax, 80(%rsp)
	movq	%rdx, 88(%rsp)
	je	.L465
	movq	80(%rsp), %rbp
	jmp	.L466
	.p2align 4,,10
	.p2align 3
.L516:
	movq	%r10, %r8
	movq	%rax, %rdi
	jmp	.L456
	.p2align 4,,10
	.p2align 3
.L511:
	movq	%rsi, %rax
	movq	%rbx, %rcx
	jmp	.L419
	.p2align 4,,10
	.p2align 3
.L418:
	movq	%rsi, %rax
	movq	%rbx, %rdx
	.p2align 4,,10
	.p2align 3
.L427:
	movzwl	(%rdx), %ecx
	addq	$2, %rax
	addq	$2, %rdx
	movw	%cx, -2(%rax)
	cmpq	%rax, %rdi
	jne	.L427
	jmp	.L426
	.p2align 4,,10
	.p2align 3
.L455:
	movq	%r10, %rdx
	.p2align 4,,10
	.p2align 3
.L463:
	movzwl	(%rax), %ecx
	addq	$2, %rdx
	addq	$2, %rax
	movw	%cx, -2(%rdx)
	cmpq	%rdx, %rsi
	jne	.L463
	jmp	.L462
	.p2align 4,,10
	.p2align 3
.L512:
	movq	64(%rsp), %rax
	jmp	.L419
.L465:
	movq	(%rsp), %rax
	movq	72(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movq	(%rax), %rax
	movl	200(%rax), %ebp
	movq	(%rbx), %rax
	movl	200(%rax), %r12d
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r13
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	%r12d, %esi
	movq	%r13, %rdi
	call	_ZNSolsEi
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L434
	cmpb	$0, 56(%rbp)
	je	.L467
	movsbl	67(%rbp), %esi
.L468:
	movq	%r12, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	movsd	.LC2(%rip), %xmm1
	movl	$.LC4, %esi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	80(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L469
	call	_ZdlPv
.L469:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	(%rsp), %rbx
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L470
	call	_ZdlPv
.L470:
	movq	%rbx, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
	cmpq	$0, 40(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L650
	movq	32(%rsp), %rax
	movl	$24, %edi
	xorl	%r12d, %r12d
	movq	%rax, 16(%rbx)
	call	_Znwm
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	32(%rsp), %rax
	movq	%rax, 16(%rbp)
.L473:
	movabsq	$9223372036854775807, %rax
	movq	%r12, 8(%rbp)
	movl	$100, %r12d
	movq	%rax, 80(%rsp)
	movq	%rax, 88(%rsp)
	jmp	.L487
	.p2align 4,,10
	.p2align 3
.L654:
	testq	%r9, %r9
	jne	.L651
.L632:
	addq	%r8, %rcx
.L481:
	movq	%rcx, 8(%rbx)
.L474:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	104(%rsp), %rcx
	movq	96(%rsp), %rsi
	subq	%r14, %rcx
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
	leaq	80(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	80(%rsp), %rsi
	movq	%rcx, 104(%rsp)
	jg	.L486
	cmpq	88(%rsp), %rcx
	cmovle	%r15, %rax
.L486:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %r12
	movq	%rax, 80(%rsp)
	movq	%rdx, 88(%rsp)
	je	.L652
.L487:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
	cmpq	%rbp, %rbx
	movq	96(%rsp), %r13
	movq	104(%rsp), %r14
	je	.L474
	movq	8(%rbp), %r10
	movq	0(%rbp), %rsi
	movq	(%rbx), %r8
	movq	16(%rbx), %rax
	movq	%r10, %rcx
	subq	%rsi, %rcx
	subq	%r8, %rax
	movq	%rcx, %r9
	sarq	%rax
	sarq	%r9
	cmpq	%rax, %r9
	ja	.L653
	movq	8(%rbx), %rdi
	movq	%rdi, %rax
	subq	%r8, %rax
	movq	%rax, %rdx
	sarq	%rdx
	cmpq	%rdx, %r9
	jbe	.L654
	testq	%rdx, %rdx
	jne	.L655
.L484:
	addq	%rax, %rsi
	movq	%r10, %rdx
	subq	%rsi, %rdx
	movq	%rdx, %rax
	shrq	%rax
	je	.L632
	movq	%rcx, (%rsp)
	call	memmove
	movq	(%rsp), %rcx
	addq	(%rbx), %rcx
	jmp	.L481
	.p2align 4,,10
	.p2align 3
.L653:
	xorl	%r10d, %r10d
	testq	%r9, %r9
	je	.L479
	movabsq	$9223372036854775807, %rax
	cmpq	%rax, %r9
	ja	.L656
	movq	%rcx, %rdi
	movq	%r9, 16(%rsp)
	movq	%rsi, 8(%rsp)
	movq	%rcx, (%rsp)
	call	_Znwm
	movq	16(%rsp), %r9
	movq	%rax, %r10
	movq	(%rbx), %r8
	movq	(%rsp), %rcx
	movq	8(%rsp), %rsi
	testq	%r9, %r9
	je	.L479
	movq	%rcx, %rdx
	movq	%rax, %rdi
	movq	%r8, 8(%rsp)
	call	memmove
	movq	8(%rsp), %r8
	movq	(%rsp), %rcx
	movq	%rax, %r10
.L479:
	testq	%r8, %r8
	je	.L480
	movq	%r8, %rdi
	movq	%r10, 8(%rsp)
	movq	%rcx, (%rsp)
	call	_ZdlPv
	movq	8(%rsp), %r10
	movq	(%rsp), %rcx
.L480:
	addq	%r10, %rcx
	movq	%r10, (%rbx)
	movq	%rcx, 16(%rbx)
	jmp	.L481
	.p2align 4,,10
	.p2align 3
.L655:
	movq	%r8, %rdi
	movq	%rax, %rdx
	movq	%rcx, (%rsp)
	call	memmove
	movq	8(%rbx), %rdi
	movq	(%rbx), %r8
	movq	0(%rbp), %rsi
	movq	8(%rbp), %r10
	movq	(%rsp), %rcx
	movq	%rdi, %rax
	subq	%r8, %rax
	jmp	.L484
	.p2align 4,,10
	.p2align 3
.L651:
	movq	%rcx, %rdx
	movq	%r8, %rdi
	movq	%rcx, (%rsp)
	call	memmove
	movq	(%rsp), %rcx
	addq	(%rbx), %rcx
	jmp	.L481
.L652:
	pxor	%xmm0, %xmm0
	movl	$.LC4, %esi
	movsd	.LC2(%rip), %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	80(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk
	movq	0(%rbp), %rax
	movl	$_ZSt4cout, %edi
	movl	200(%rax), %r12d
	movq	(%rbx), %rax
	movl	200(%rax), %esi
	call	_ZNSolsEi
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L434
	cmpb	$0, 56(%r12)
	je	.L488
	movsbl	67(%r12), %esi
.L489:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L490
	call	_ZdlPv
.L490:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L491
	call	_ZdlPv
.L491:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	120(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L657
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
.L488:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L489
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L489
.L467:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%rbp), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L468
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L468
.L432:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%r13), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L433
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L433
.L445:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L446
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L446
.L435:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L436
	movq	%rbx, %rdi
	call	*%rax
.LEHE31:
	movsbl	%al, %esi
	jmp	.L436
.L650:
	movq	32(%rsp), %r14
	movq	%r14, %rdi
.LEHB32:
	call	_Znwm
.LEHE32:
	movq	%rax, %r12
	movq	%rax, (%rbx)
	movq	%r14, %rax
	addq	%r12, %rax
	xorl	%esi, %esi
	movq	%r12, %rdi
	movq	%rax, 16(%rbx)
	movq	40(%rsp), %rax
	leaq	(%rax,%rax), %rbp
	movq	%rbp, %rdx
	addq	%r12, %rbp
	call	memset
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB33:
	call	_Znwm
.LEHE33:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbp
.LEHB34:
	call	_Znwm
.LEHE34:
	movq	%rax, %r12
	movq	%rax, 0(%rbp)
	movq	%rax, 8(%rbp)
	movq	32(%rsp), %rax
	addq	%r12, %rax
	movq	%rax, 16(%rbp)
	movq	40(%rsp), %rax
	testq	%rax, %rax
	je	.L473
	addq	%rax, %rax
	movq	%r12, %rdi
	xorl	%esi, %esi
	movq	%rax, %r13
	movq	%rax, %rdx
	call	memset
	addq	%r13, %r12
	jmp	.L473
.L649:
	movq	32(%rsp), %r15
	movq	%r15, %rdi
.LEHB35:
	call	_Znwm
.LEHE35:
	movq	%rax, %r12
	movq	%rax, (%rbx)
	movq	%r15, %rax
	addq	%r12, %rax
	xorl	%esi, %esi
	movq	%r12, %rdi
	movq	%rax, 16(%rbx)
	movq	40(%rsp), %rax
	leaq	(%rax,%rax), %rbp
	movq	%rbp, %rdx
	addq	%r12, %rbp
	call	memset
	movl	$24, %edi
	movq	%rbp, 8(%rbx)
.LEHB36:
	call	_Znwm
.LEHE36:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, (%rsp)
.LEHB37:
	call	_Znwm
.LEHE37:
	movq	%rax, %rbp
	movq	32(%rsp), %rax
	movq	(%rsp), %rdi
	addq	%rbp, %rax
	movq	%rbp, (%rdi)
	movq	%rbp, 8(%rdi)
	movq	%rax, 16(%rdi)
	movq	40(%rsp), %rax
	testq	%rax, %rax
	je	.L451
	leaq	(%rax,%rax), %r12
	movq	%rbp, %rdi
	xorl	%esi, %esi
	movq	%r12, %rdx
	addq	%r12, %rbp
	call	memset
	jmp	.L451
.L648:
	movq	32(%rsp), %r15
	movq	%r15, %rdi
.LEHB38:
	call	_Znwm
.LEHE38:
	movq	%rax, %rbp
	movq	%rax, 0(%r13)
	movq	%r15, %rax
	addq	%rbp, %rax
	xorl	%esi, %esi
	movq	%rbp, %rdi
	movq	%rax, 16(%r13)
	movq	40(%rsp), %rax
	leaq	(%rax,%rax), %rbx
	movq	%rbx, %rdx
	addq	%rbp, %rbx
	call	memset
	movl	$24, %edi
	movq	%rbx, 8(%r13)
.LEHB39:
	call	_Znwm
.LEHE39:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB40:
	call	_Znwm
.LEHE40:
	movq	%rax, %rbx
	movq	%rax, (%r12)
	movq	%rax, 8(%r12)
	movq	32(%rsp), %rax
	addq	%rbx, %rax
	movq	%rax, 16(%r12)
	movq	40(%rsp), %rax
	testq	%rax, %rax
	je	.L441
	leaq	(%rax,%rax), %rbp
	movq	%rbx, %rdi
	xorl	%esi, %esi
	movq	%rbp, %rdx
	addq	%rbp, %rbx
	call	memset
	jmp	.L441
.L647:
	addq	%rax, %rax
	movq	%rax, %rdi
	movq	%rax, %r14
	movq	%rax, 32(%rsp)
.LEHB41:
	call	_Znwm
.LEHE41:
	movq	48(%rsp), %r15
	movq	%r14, %rbx
	movq	%r14, %rdx
	addq	%rax, %rbx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, (%r15)
	movq	%rbx, 16(%r15)
	call	memset
	movq	%rbx, 8(%r15)
	movl	$24, %edi
.LEHB42:
	call	_Znwm
.LEHE42:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, 56(%rsp)
.LEHB43:
	call	_Znwm
.LEHE43:
	movq	%rax, %rbx
	movq	%r14, %rax
	movq	%r14, %rbp
	addq	%rbx, %rax
	movq	%rbx, (%r15)
	movq	%rbx, 8(%r15)
	movq	%rax, 16(%r15)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	addq	%rbx, %rbp
	call	memset
	movq	56(%rsp), %rax
	jmp	.L503
.L429:
	movq	%r9, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r9d
	orq	%r9, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L430
.L443:
	movq	%r14, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r14d
	orq	%r14, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L444
.L528:
.L633:
	movq	%rax, %rbp
	jmp	.L498
.L656:
.LEHB44:
	call	_ZSt17__throw_bad_allocv
.L657:
	call	__stack_chk_fail
.L498:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	%rbp, %rdi
	call	_Unwind_Resume
.L434:
	call	_ZSt16__throw_bad_castv
.L523:
	movq	%rax, %rbx
	jmp	.L493
.L522:
	movq	%rax, %rbx
	jmp	.L492
.L525:
	movq	%rax, %rbx
	jmp	.L495
.L493:
	movq	56(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L492:
	movq	48(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L495:
	movq	%r12, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L524:
	movq	%rax, %rbx
	jmp	.L494
.L527:
	movq	%rax, %rbx
	jmp	.L497
.L494:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L497:
	movq	(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L526:
	jmp	.L633
.L529:
	movq	%rax, %rbx
.L499:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.LEHE44:
	.cfi_endproc
.LFE6946:
	.section	.gcc_except_table._Z4funcIsEvm,"aG",@progbits,_Z4funcIsEvm,comdat
.LLSDA6946:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE6946-.LLSDACSB6946
.LLSDACSB6946:
	.uleb128 .LEHB31-.LFB6946
	.uleb128 .LEHE31-.LEHB31
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB32-.LFB6946
	.uleb128 .LEHE32-.LEHB32
	.uleb128 .L528-.LFB6946
	.uleb128 0
	.uleb128 .LEHB33-.LFB6946
	.uleb128 .LEHE33-.LEHB33
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB34-.LFB6946
	.uleb128 .LEHE34-.LEHB34
	.uleb128 .L529-.LFB6946
	.uleb128 0
	.uleb128 .LEHB35-.LFB6946
	.uleb128 .LEHE35-.LEHB35
	.uleb128 .L526-.LFB6946
	.uleb128 0
	.uleb128 .LEHB36-.LFB6946
	.uleb128 .LEHE36-.LEHB36
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB37-.LFB6946
	.uleb128 .LEHE37-.LEHB37
	.uleb128 .L527-.LFB6946
	.uleb128 0
	.uleb128 .LEHB38-.LFB6946
	.uleb128 .LEHE38-.LEHB38
	.uleb128 .L524-.LFB6946
	.uleb128 0
	.uleb128 .LEHB39-.LFB6946
	.uleb128 .LEHE39-.LEHB39
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB40-.LFB6946
	.uleb128 .LEHE40-.LEHB40
	.uleb128 .L525-.LFB6946
	.uleb128 0
	.uleb128 .LEHB41-.LFB6946
	.uleb128 .LEHE41-.LEHB41
	.uleb128 .L522-.LFB6946
	.uleb128 0
	.uleb128 .LEHB42-.LFB6946
	.uleb128 .LEHE42-.LEHB42
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB43-.LFB6946
	.uleb128 .LEHE43-.LEHB43
	.uleb128 .L523-.LFB6946
	.uleb128 0
	.uleb128 .LEHB44-.LFB6946
	.uleb128 .LEHE44-.LEHB44
	.uleb128 0
	.uleb128 0
.LLSDACSE6946:
	.section	.text._Z4funcIsEvm,"axG",@progbits,_Z4funcIsEvm,comdat
	.size	_Z4funcIsEvm, .-_Z4funcIsEvm
	.section	.text.unlikely._Z4funcIsEvm,"axG",@progbits,_Z4funcIsEvm,comdat
.LCOLDE8:
	.section	.text._Z4funcIsEvm,"axG",@progbits,_Z4funcIsEvm,comdat
.LHOTE8:
	.section	.text.unlikely._ZNSt6vectorIiSaIiEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIiSaIiEEaSERKS1_,comdat
	.align 2
.LCOLDB9:
	.section	.text._ZNSt6vectorIiSaIiEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIiSaIiEEaSERKS1_,comdat
.LHOTB9:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIiSaIiEEaSERKS1_
	.type	_ZNSt6vectorIiSaIiEEaSERKS1_, @function
_ZNSt6vectorIiSaIiEEaSERKS1_:
.LFB7071:
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
	je	.L659
	movq	8(%rsi), %rdx
	movq	(%rsi), %r15
	movq	%rsi, %r12
	movq	(%rdi), %r13
	movq	16(%rdi), %rcx
	movq	%rdx, %rbp
	subq	%r15, %rbp
	subq	%r13, %rcx
	movq	%rbp, %r14
	sarq	$2, %rcx
	sarq	$2, %r14
	cmpq	%rcx, %r14
	ja	.L682
	movq	8(%rdi), %rdi
	movq	%rdi, %rax
	subq	%r13, %rax
	movq	%rax, %rcx
	sarq	$2, %rcx
	cmpq	%rcx, %r14
	jbe	.L683
	testq	%rcx, %rcx
	jne	.L684
.L669:
	leaq	(%r15,%rax), %rsi
	subq	%rsi, %rdx
	movq	%rdx, %rax
	sarq	$2, %rax
	testq	%rax, %rax
	jne	.L670
.L681:
	addq	%r13, %rbp
.L666:
	movq	%rbp, 8(%rbx)
.L659:
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
.L683:
	.cfi_restore_state
	testq	%r14, %r14
	je	.L681
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%r13, %rdi
	call	memmove
	addq	(%rbx), %rbp
	jmp	.L666
	.p2align 4,,10
	.p2align 3
.L682:
	xorl	%r12d, %r12d
	testq	%r14, %r14
	je	.L664
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %r14
	ja	.L685
	movq	%rbp, %rdi
	call	_Znwm
	testq	%r14, %r14
	movq	%rax, %r12
	movq	(%rbx), %r13
	jne	.L686
.L664:
	testq	%r13, %r13
	je	.L665
.L687:
	movq	%r13, %rdi
	call	_ZdlPv
.L665:
	addq	%r12, %rbp
	movq	%r12, (%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L666
	.p2align 4,,10
	.p2align 3
.L686:
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%rax, %rdi
	call	memmove
	testq	%r13, %r13
	jne	.L687
	jmp	.L665
	.p2align 4,,10
	.p2align 3
.L670:
	call	memmove
	addq	(%rbx), %rbp
	jmp	.L666
	.p2align 4,,10
	.p2align 3
.L684:
	movq	%r13, %rdi
	movq	%rax, %rdx
	movq	%r15, %rsi
	call	memmove
	movq	8(%rbx), %rdi
	movq	(%rbx), %r13
	movq	(%r12), %r15
	movq	8(%r12), %rdx
	movq	%rdi, %rax
	subq	%r13, %rax
	jmp	.L669
.L685:
	call	_ZSt17__throw_bad_allocv
	.cfi_endproc
.LFE7071:
	.size	_ZNSt6vectorIiSaIiEEaSERKS1_, .-_ZNSt6vectorIiSaIiEEaSERKS1_
	.section	.text.unlikely._ZNSt6vectorIiSaIiEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIiSaIiEEaSERKS1_,comdat
.LCOLDE9:
	.section	.text._ZNSt6vectorIiSaIiEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIiSaIiEEaSERKS1_,comdat
.LHOTE9:
	.section	.text.unlikely._Z4funcIiEvm,"axG",@progbits,_Z4funcIiEvm,comdat
.LCOLDB10:
	.section	.text._Z4funcIiEvm,"axG",@progbits,_Z4funcIiEvm,comdat
.LHOTB10:
	.p2align 4,,15
	.weak	_Z4funcIiEvm
	.type	_Z4funcIiEvm, @function
_Z4funcIiEvm:
.LFB6947:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA6947
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
.LEHB45:
	call	_Znwm
.LEHE45:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movq	%rax, 64(%rsp)
	movl	$104857600, %eax
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	divq	%r15
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, 48(%rsp)
	je	.L689
	leaq	0(,%rax,4), %rdi
	movq	%rdi, %r14
	movq	%rdi, 40(%rsp)
.LEHB46:
	call	_Znwm
.LEHE46:
	movq	%rbx, %r15
	movq	%rax, (%rbx)
	movq	%r14, %rbx
	addq	%rax, %rbx
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rbx, 16(%r15)
	movq	%rax, %rdi
	call	memset
	movq	%rbx, 8(%r15)
	movl	$24, %edi
.LEHB47:
	call	_Znwm
.LEHE47:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, 56(%rsp)
.LEHB48:
	call	_Znwm
.LEHE48:
	movq	%r15, %rdi
	movq	%rax, %rbx
	movq	%r14, %rdx
	movq	%rax, (%rdi)
	movq	%rax, 8(%rdi)
	leaq	(%rax,%r14), %rax
	xorl	%esi, %esi
	movq	%rbx, %rdi
	movq	%r14, %rbp
	movq	%rax, 16(%r15)
	addq	%rbx, %rbp
	call	memset
	movq	56(%rsp), %rax
.L772:
	movq	%rbp, 8(%rax)
	movq	64(%rsp), %rax
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
	leaq	16(%rdi), %rcx
	shrq	$2, %rax
	cmpq	%rcx, %rbx
	leaq	16(%rbx), %rcx
	leaq	1(%rax), %rdx
	setnb	%r11b
	cmpq	%rcx, %rdi
	setnb	%cl
	orl	%r11d, %ecx
	cmpq	$12, %rdx
	seta	%r11b
	andl	$15, %r10d
	shrq	$2, %r10
	andl	%ecx, %r11d
	negq	%r10
	andl	$3, %r10d
	cmpq	%rdx, %r10
	cmova	%rdx, %r10
	subq	%r10, %rdx
	subq	%r10, %rax
	leaq	0(,%r10,4), %r12
	leaq	-4(%rdx), %rbp
	movq	%rax, (%rsp)
	movq	%rdx, 16(%rsp)
	leaq	(%rbx,%r12), %r13
	addq	%rdi, %r12
	shrq	$2, %rbp
	addq	$1, %rbp
	leaq	0(,%rbp,4), %rcx
	movq	%rbp, %rax
	salq	$4, %rax
	movq	%rcx, 24(%rsp)
	movq	%rax, 32(%rsp)
	jmp	.L692
	.p2align 4,,10
	.p2align 3
.L885:
	movl	(%rbx), %eax
	cmpq	$1, %r10
	leaq	4(%rbx), %rdx
	movl	%eax, (%rdi)
	movq	8(%rsp), %rax
	je	.L694
	movl	4(%rbx), %eax
	cmpq	$3, %r10
	leaq	8(%rbx), %rdx
	movl	%eax, 4(%rdi)
	leaq	8(%rdi), %rax
	jne	.L694
	movl	8(%rbx), %eax
	leaq	12(%rbx), %rdx
	movl	%eax, 8(%rdi)
	leaq	12(%rdi), %rax
.L694:
	cmpq	$2, (%rsp)
	jbe	.L696
	xorl	%r14d, %r14d
	xorl	%r15d, %r15d
.L697:
	movdqa	0(%r13,%r14), %xmm0
	addq	$1, %r15
	movups	%xmm0, (%r12,%r14)
	addq	$16, %r14
	cmpq	%rbp, %r15
	jb	.L697
	movq	32(%rsp), %r15
	movq	24(%rsp), %r14
	addq	%r15, %rdx
	addq	%r15, %rax
	cmpq	%r14, 16(%rsp)
	je	.L701
.L696:
	movl	(%rdx), %r14d
	movl	%r14d, (%rax)
	leaq	4(%rax), %r14
	cmpq	%r14, %rsi
	je	.L701
	movl	4(%rdx), %r14d
	movl	%r14d, 4(%rax)
	leaq	8(%rax), %r14
	cmpq	%r14, %rsi
	je	.L701
	movl	8(%rdx), %edx
	movl	%edx, 8(%rax)
.L701:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	%rcx, %rdx
	cmpq	%rdx, %r8
	cmova	%rdx, %r8
	subq	$1, %r9
	je	.L884
.L692:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %ecx
	orq	%rdx, %rcx
	cmpq	%rdi, %rsi
	je	.L701
	testb	%r11b, %r11b
	je	.L693
	testq	%r10, %r10
	jne	.L885
	movq	%rdi, %rax
	movq	%rbx, %rdx
	jmp	.L694
	.p2align 4,,10
	.p2align 3
.L693:
	movq	%rdi, %rax
	movq	%rbx, %rdx
	.p2align 4,,10
	.p2align 3
.L702:
	movl	(%rdx), %r14d
	addq	$4, %rax
	addq	$4, %rdx
	movl	%r14d, -4(%rax)
	cmpq	%rax, %rsi
	jne	.L702
	jmp	.L701
.L884:
	pxor	%xmm4, %xmm4
	testq	%r8, %r8
	movl	400(%rbx), %ebx
	movl	400(%rdi), %ebp
	cvtsi2sdq	48(%rsp), %xmm4
	movsd	%xmm4, (%rsp)
	js	.L704
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r8, %xmm0
.L705:
	divsd	(%rsp), %xmm0
	movq	72(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movsd	%xmm0, 8(%rsp)
.LEHB49:
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r12
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r13
	testq	%r13, %r13
	je	.L709
	cmpb	$0, 56(%r13)
	je	.L707
	movsbl	67(%r13), %esi
.L708:
	movq	%r12, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movsd	8(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L709
	cmpb	$0, 56(%rbx)
	je	.L710
	movsbl	67(%rbx), %esi
.L711:
	movq	%rbp, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	64(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L712
	call	_ZdlPv
.L712:
	movq	64(%rsp), %rdi
	call	_ZdlPv
	movq	56(%rsp), %rbx
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L877
	call	_ZdlPv
.L877:
	movq	%rbx, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE49:
	cmpq	$0, 48(%rsp)
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L714
	movq	40(%rsp), %r15
	movq	%r15, %rdi
.LEHB50:
	call	_Znwm
.LEHE50:
	movq	48(%rsp), %r14
	movq	%rax, %rbp
	movq	%rax, 0(%r13)
	movq	%r15, %rax
	xorl	%esi, %esi
	movq	%rbp, %rdi
	addq	%rbp, %rax
	leaq	0(,%r14,4), %rbx
	movq	%rax, 16(%r13)
	movq	%rbx, %rdx
	addq	%rbp, %rbx
	call	memset
	movl	$24, %edi
	movq	%rbx, 8(%r13)
.LEHB51:
	call	_Znwm
.LEHE51:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB52:
	call	_Znwm
.LEHE52:
	movq	%rax, %rbx
	movq	%rax, (%r12)
	movq	%rax, 8(%r12)
	movq	%r15, %rax
	addq	%rbx, %rax
	testq	%r14, %r14
	movq	%rax, 16(%r12)
	je	.L715
	leaq	0(,%r14,4), %rbp
	movq	%rbx, %rdi
	xorl	%esi, %esi
	movq	%rbp, %rdx
	addq	%rbp, %rbx
	call	memset
.L715:
	movq	%rbx, 8(%r12)
	movl	$100, %ebp
	movq	$-1, %r14
	.p2align 4,,10
	.p2align 3
.L716:
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
.LEHB53:
	call	_ZNSt6vectorIiSaIiEEaSERKS1_
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	%rbx, %rdx
	cmpq	%rdx, %r14
	cmova	%rdx, %r14
	subq	$1, %rbp
	jne	.L716
	movq	(%r12), %rax
	testq	%r14, %r14
	movl	400(%rax), %ebx
	movq	0(%r13), %rax
	movl	400(%rax), %ebp
	js	.L717
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r14, %xmm0
.L718:
	divsd	(%rsp), %xmm0
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L709
	cmpb	$0, 56(%rbx)
	je	.L719
	movsbl	67(%rbx), %esi
.L720:
	movq	%rbp, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L721
	call	_ZdlPv
.L721:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L878
	call	_ZdlPv
.L878:
	movq	%r12, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE53:
	cmpq	$0, 48(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L723
	movq	40(%rsp), %r14
	movq	%r14, %rdi
.LEHB54:
	call	_Znwm
.LEHE54:
	movq	48(%rsp), %r13
	movq	%rax, %r12
	movq	%rax, (%rbx)
	movq	%r14, %rax
	xorl	%esi, %esi
	movq	%r12, %rdi
	addq	%r12, %rax
	leaq	0(,%r13,4), %rbp
	movq	%rax, 16(%rbx)
	movq	%rbp, %rdx
	addq	%r12, %rbp
	call	memset
	movl	$24, %edi
	movq	%rbp, 8(%rbx)
.LEHB55:
	call	_Znwm
.LEHE55:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, (%rsp)
.LEHB56:
	call	_Znwm
.LEHE56:
	movq	%rax, %rbp
	movq	%r14, %rax
	addq	%rbp, %rax
	testq	%r13, %r13
	movq	%rbp, (%r15)
	movq	%rbp, 8(%r15)
	movq	%rax, 16(%r15)
	je	.L724
	leaq	0(,%r13,4), %r12
	movq	%rbp, %rdi
	xorl	%esi, %esi
	movq	%r12, %rdx
	addq	%r12, %rbp
	call	memset
.L724:
	movq	(%rsp), %rax
	movl	$100, %r14d
	leaq	96(%rsp), %r15
	movq	%rbp, 8(%rax)
	movabsq	$9223372036854775807, %rax
	movq	%rax, 80(%rsp)
	movq	%rax, 88(%rsp)
	movq	%rax, %rbp
	jmp	.L739
	.p2align 4,,10
	.p2align 3
.L886:
	movl	(%rax), %edi
	cmpq	$1, %rdx
	leaq	4(%rax), %r8
	movl	%edi, (%r9)
	je	.L729
	movl	4(%rax), %edi
	cmpq	$3, %rdx
	leaq	8(%r9), %r10
	leaq	8(%rax), %r8
	movl	%edi, 4(%r9)
	jne	.L729
	movl	8(%rax), %edi
	leaq	12(%r9), %r10
	leaq	12(%rax), %r8
	movl	%edi, 8(%r9)
.L729:
	subq	%rdx, %rcx
	salq	$2, %rdx
	leaq	-4(%rcx), %rdi
	addq	%rdx, %rax
	addq	%r9, %rdx
	xorl	%r9d, %r9d
	shrq	$2, %rdi
	addq	$1, %rdi
	leaq	0(,%rdi,4), %r11
	movq	%r11, 8(%rsp)
	xorl	%r11d, %r11d
.L731:
	movdqa	(%rax,%r9), %xmm0
	addq	$1, %r11
	movups	%xmm0, (%rdx,%r9)
	addq	$16, %r9
	cmpq	%rdi, %r11
	jb	.L731
	movq	8(%rsp), %rdi
	movq	%rdi, %rax
	salq	$2, %rax
	addq	%rax, %r8
	addq	%rax, %r10
	cmpq	%rcx, %rdi
	je	.L735
	movl	(%r8), %eax
	movl	%eax, (%r10)
	leaq	4(%r10), %rax
	cmpq	%rax, %rsi
	je	.L735
	movl	4(%r8), %eax
	movl	%eax, 4(%r10)
	leaq	8(%r10), %rax
	cmpq	%rax, %rsi
	je	.L735
	movl	8(%r8), %eax
	movl	%eax, 8(%r10)
.L735:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
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
	leaq	80(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%rbp, %rsi
	movq	%rcx, 104(%rsp)
	jg	.L727
	cmpq	88(%rsp), %rcx
	leaq	80(%rsp), %rdi
	movq	%r15, %rax
	cmovg	%rdi, %rax
.L727:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %r14
	movq	%rax, 80(%rsp)
	movq	%rdx, 88(%rsp)
	je	.L738
	movq	80(%rsp), %rbp
.L739:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	(%rbx), %r9
	movq	8(%rbx), %rsi
	movq	(%rsp), %rax
	movq	96(%rsp), %r12
	movq	104(%rsp), %r13
	cmpq	%rsi, %r9
	movq	(%rax), %rax
	je	.L735
	leaq	4(%r9), %r10
	movq	%rsi, %rcx
	leaq	16(%r9), %rdx
	subq	%r10, %rcx
	shrq	$2, %rcx
	addq	$1, %rcx
	cmpq	%rdx, %rax
	leaq	16(%rax), %rdx
	setnb	%dil
	cmpq	%rdx, %r9
	setnb	%dl
	orb	%dl, %dil
	je	.L728
	cmpq	$12, %rcx
	jbe	.L728
	movq	%rax, %rdx
	andl	$15, %edx
	shrq	$2, %rdx
	negq	%rdx
	andl	$3, %edx
	cmpq	%rcx, %rdx
	cmova	%rcx, %rdx
	testq	%rdx, %rdx
	jne	.L886
	movq	%r9, %r10
	movq	%rax, %r8
	jmp	.L729
	.p2align 4,,10
	.p2align 3
.L728:
	movq	%r9, %rdx
	.p2align 4,,10
	.p2align 3
.L736:
	movl	(%rax), %ecx
	addq	$4, %rdx
	addq	$4, %rax
	movl	%ecx, -4(%rdx)
	cmpq	%rdx, %rsi
	jne	.L736
	jmp	.L735
.L738:
	movq	(%rsp), %rax
	movq	72(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movq	(%rax), %rax
	movl	400(%rax), %ebp
	movq	(%rbx), %rax
	movl	400(%rax), %r12d
.LEHB57:
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r13
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	%r12d, %esi
	movq	%r13, %rdi
	call	_ZNSolsEi
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L709
	cmpb	$0, 56(%rbp)
	je	.L740
	movsbl	67(%rbp), %esi
.L741:
	movq	%r12, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	movsd	.LC2(%rip), %xmm1
	movl	$.LC4, %esi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	80(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L742
	call	_ZdlPv
.L742:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	(%rsp), %rbx
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L879
	call	_ZdlPv
.L879:
	movq	%rbx, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE57:
	cmpq	$0, 48(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L744
	movq	40(%rsp), %r14
	movq	%r14, %rdi
.LEHB58:
	call	_Znwm
.LEHE58:
	movq	48(%rsp), %r13
	movq	%rax, %r12
	movq	%rax, (%rbx)
	movq	%r14, %rax
	xorl	%esi, %esi
	movq	%r12, %rdi
	addq	%r12, %rax
	leaq	0(,%r13,4), %rbp
	movq	%rax, 16(%rbx)
	movq	%rbp, %rdx
	addq	%r12, %rbp
	call	memset
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB59:
	call	_Znwm
.LEHE59:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbp
.LEHB60:
	call	_Znwm
.LEHE60:
	movq	%rax, %r12
	movq	%rax, 0(%rbp)
	movq	%rax, 8(%rbp)
	movq	%r14, %rax
	addq	%r12, %rax
	testq	%r13, %r13
	movq	%rax, 16(%rbp)
	movq	%r13, %rax
	je	.L745
	salq	$2, %rax
	movq	%r12, %rdi
	xorl	%esi, %esi
	movq	%rax, %r13
	movq	%rax, %rdx
	addq	%r13, %r12
	call	memset
.L745:
	movabsq	$9223372036854775807, %rax
	movq	%r12, 8(%rbp)
	movq	$100, (%rsp)
	movq	%rax, 80(%rsp)
	movq	%rax, 88(%rsp)
	jmp	.L759
	.p2align 4,,10
	.p2align 3
.L890:
	testq	%r9, %r9
	jne	.L887
.L875:
	leaq	(%r8,%r12), %rcx
.L753:
	movq	%rcx, 8(%rbx)
.L746:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	104(%rsp), %rcx
	movq	96(%rsp), %rsi
	subq	%r14, %rcx
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
	leaq	80(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	80(%rsp), %rsi
	movq	%rcx, 104(%rsp)
	jg	.L758
	cmpq	88(%rsp), %rcx
	cmovle	%r15, %rax
.L758:
	subq	$1, (%rsp)
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rdx, 88(%rsp)
	movq	%rax, 80(%rsp)
	je	.L888
.L759:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
	cmpq	%rbp, %rbx
	movq	96(%rsp), %r13
	movq	104(%rsp), %r14
	je	.L746
	movq	8(%rbp), %r10
	movq	0(%rbp), %rsi
	movq	(%rbx), %r8
	movq	16(%rbx), %rax
	movq	%r10, %r12
	subq	%rsi, %r12
	subq	%r8, %rax
	movq	%r12, %r9
	sarq	$2, %rax
	sarq	$2, %r9
	cmpq	%rax, %r9
	ja	.L889
	movq	8(%rbx), %rdi
	movq	%rdi, %rax
	subq	%r8, %rax
	movq	%rax, %rdx
	sarq	$2, %rdx
	cmpq	%rdx, %r9
	jbe	.L890
	testq	%rdx, %rdx
	jne	.L891
.L756:
	addq	%rax, %rsi
	movq	%r10, %rdx
	subq	%rsi, %rdx
	movq	%rdx, %rax
	sarq	$2, %rax
	testq	%rax, %rax
	je	.L875
	call	memmove
	movq	%r12, %rcx
	addq	(%rbx), %rcx
	jmp	.L753
	.p2align 4,,10
	.p2align 3
.L889:
	xorl	%r10d, %r10d
	testq	%r9, %r9
	je	.L751
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %r9
	ja	.L892
	movq	%r12, %rdi
	movq	%r9, 16(%rsp)
	movq	%rsi, 8(%rsp)
.LEHB61:
	call	_Znwm
	movq	16(%rsp), %r9
	movq	%rax, %r10
	movq	(%rbx), %r8
	movq	8(%rsp), %rsi
	testq	%r9, %r9
	je	.L751
	movq	%r12, %rdx
	movq	%rax, %rdi
	movq	%r8, 8(%rsp)
	call	memmove
	movq	8(%rsp), %r8
	movq	%rax, %r10
.L751:
	testq	%r8, %r8
	je	.L752
	movq	%r8, %rdi
	movq	%r10, 8(%rsp)
	call	_ZdlPv
	movq	8(%rsp), %r10
.L752:
	leaq	(%r10,%r12), %rcx
	movq	%r10, (%rbx)
	movq	%rcx, 16(%rbx)
	jmp	.L753
	.p2align 4,,10
	.p2align 3
.L891:
	movq	%r8, %rdi
	movq	%rax, %rdx
	call	memmove
	movq	8(%rbx), %rdi
	movq	(%rbx), %r8
	movq	0(%rbp), %rsi
	movq	8(%rbp), %r10
	movq	%rdi, %rax
	subq	%r8, %rax
	jmp	.L756
	.p2align 4,,10
	.p2align 3
.L887:
	movq	%r12, %rdx
	movq	%r8, %rdi
	call	memmove
	movq	%r12, %rcx
	addq	(%rbx), %rcx
	jmp	.L753
.L888:
	pxor	%xmm0, %xmm0
	movl	$.LC4, %esi
	movsd	.LC2(%rip), %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	80(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk
	movq	0(%rbp), %rax
	movl	$_ZSt4cout, %edi
	movl	400(%rax), %r12d
	movq	(%rbx), %rax
	movl	400(%rax), %esi
	call	_ZNSolsEi
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L709
	cmpb	$0, 56(%r12)
	je	.L760
	movsbl	67(%r12), %esi
.L761:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L762
	call	_ZdlPv
.L762:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L763
	call	_ZdlPv
.L763:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	120(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L893
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
.L740:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%rbp), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L741
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L741
.L719:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L720
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L720
.L710:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L711
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L711
.L707:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%r13), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L708
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L708
.L760:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L761
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L761
.L717:
	movq	%r14, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r14d
	orq	%r14, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L718
.L704:
	movq	%r8, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r8d
	orq	%r8, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L705
.L689:
	movq	$0, 16(%rbx)
	movl	$24, %edi
	xorl	%ebx, %ebx
	call	_Znwm
	xorl	%ebp, %ebp
	movq	%rax, 56(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, 40(%rsp)
	jmp	.L772
.L714:
	movq	40(%rsp), %rax
	movl	$24, %edi
	xorl	%ebx, %ebx
	movq	%rax, 16(%r13)
	call	_Znwm
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	40(%rsp), %rax
	movq	%rax, 16(%r12)
	jmp	.L715
.L723:
	movq	40(%rsp), %rax
	movl	$24, %edi
	xorl	%ebp, %ebp
	movq	%rax, 16(%rbx)
	call	_Znwm
	movq	40(%rsp), %rdi
	movq	%rax, (%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rdi, 16(%rax)
	jmp	.L724
.L744:
	movq	40(%rsp), %rax
	movl	$24, %edi
	xorl	%r12d, %r12d
	movq	%rax, 16(%rbx)
	call	_Znwm
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	40(%rsp), %rax
	movq	%rax, 16(%rbp)
	jmp	.L745
.L800:
.L876:
	movq	%rax, %rbp
	jmp	.L770
.L798:
	jmp	.L876
.L799:
	movq	%rax, %rbx
	jmp	.L769
.L770:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	%rbp, %rdi
	call	_Unwind_Resume
.L769:
	movq	(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L893:
	call	__stack_chk_fail
.L709:
	call	_ZSt16__throw_bad_castv
.L796:
	movq	%rax, %rbx
	jmp	.L766
.L797:
	movq	%rax, %rbx
	jmp	.L767
.L766:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L767:
	movq	%r12, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L794:
	movq	%rax, %rbx
	jmp	.L764
.L795:
	movq	%rax, %rbx
	jmp	.L765
.L764:
	movq	64(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L765:
	movq	56(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L801:
	movq	%rax, %rbx
	jmp	.L771
.L892:
	call	_ZSt17__throw_bad_allocv
.L771:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.LEHE61:
	.cfi_endproc
.LFE6947:
	.section	.gcc_except_table._Z4funcIiEvm,"aG",@progbits,_Z4funcIiEvm,comdat
.LLSDA6947:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE6947-.LLSDACSB6947
.LLSDACSB6947:
	.uleb128 .LEHB45-.LFB6947
	.uleb128 .LEHE45-.LEHB45
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB46-.LFB6947
	.uleb128 .LEHE46-.LEHB46
	.uleb128 .L794-.LFB6947
	.uleb128 0
	.uleb128 .LEHB47-.LFB6947
	.uleb128 .LEHE47-.LEHB47
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB48-.LFB6947
	.uleb128 .LEHE48-.LEHB48
	.uleb128 .L795-.LFB6947
	.uleb128 0
	.uleb128 .LEHB49-.LFB6947
	.uleb128 .LEHE49-.LEHB49
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB50-.LFB6947
	.uleb128 .LEHE50-.LEHB50
	.uleb128 .L796-.LFB6947
	.uleb128 0
	.uleb128 .LEHB51-.LFB6947
	.uleb128 .LEHE51-.LEHB51
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB52-.LFB6947
	.uleb128 .LEHE52-.LEHB52
	.uleb128 .L797-.LFB6947
	.uleb128 0
	.uleb128 .LEHB53-.LFB6947
	.uleb128 .LEHE53-.LEHB53
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB54-.LFB6947
	.uleb128 .LEHE54-.LEHB54
	.uleb128 .L798-.LFB6947
	.uleb128 0
	.uleb128 .LEHB55-.LFB6947
	.uleb128 .LEHE55-.LEHB55
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB56-.LFB6947
	.uleb128 .LEHE56-.LEHB56
	.uleb128 .L799-.LFB6947
	.uleb128 0
	.uleb128 .LEHB57-.LFB6947
	.uleb128 .LEHE57-.LEHB57
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB58-.LFB6947
	.uleb128 .LEHE58-.LEHB58
	.uleb128 .L800-.LFB6947
	.uleb128 0
	.uleb128 .LEHB59-.LFB6947
	.uleb128 .LEHE59-.LEHB59
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB60-.LFB6947
	.uleb128 .LEHE60-.LEHB60
	.uleb128 .L801-.LFB6947
	.uleb128 0
	.uleb128 .LEHB61-.LFB6947
	.uleb128 .LEHE61-.LEHB61
	.uleb128 0
	.uleb128 0
.LLSDACSE6947:
	.section	.text._Z4funcIiEvm,"axG",@progbits,_Z4funcIiEvm,comdat
	.size	_Z4funcIiEvm, .-_Z4funcIiEvm
	.section	.text.unlikely._Z4funcIiEvm,"axG",@progbits,_Z4funcIiEvm,comdat
.LCOLDE10:
	.section	.text._Z4funcIiEvm,"axG",@progbits,_Z4funcIiEvm,comdat
.LHOTE10:
	.section	.text.unlikely._ZNSt6vectorIlSaIlEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIlSaIlEEaSERKS1_,comdat
	.align 2
.LCOLDB11:
	.section	.text._ZNSt6vectorIlSaIlEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIlSaIlEEaSERKS1_,comdat
.LHOTB11:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIlSaIlEEaSERKS1_
	.type	_ZNSt6vectorIlSaIlEEaSERKS1_, @function
_ZNSt6vectorIlSaIlEEaSERKS1_:
.LFB7092:
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
	je	.L895
	movq	8(%rsi), %rdx
	movq	(%rsi), %r15
	movq	%rsi, %r12
	movq	(%rdi), %r13
	movq	16(%rdi), %rcx
	movq	%rdx, %rbp
	subq	%r15, %rbp
	subq	%r13, %rcx
	movq	%rbp, %r14
	sarq	$3, %rcx
	sarq	$3, %r14
	cmpq	%rcx, %r14
	ja	.L918
	movq	8(%rdi), %rdi
	movq	%rdi, %rax
	subq	%r13, %rax
	movq	%rax, %rcx
	sarq	$3, %rcx
	cmpq	%rcx, %r14
	jbe	.L919
	testq	%rcx, %rcx
	jne	.L920
.L905:
	leaq	(%r15,%rax), %rsi
	subq	%rsi, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	jne	.L906
.L917:
	addq	%r13, %rbp
.L902:
	movq	%rbp, 8(%rbx)
.L895:
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
.L919:
	.cfi_restore_state
	testq	%r14, %r14
	je	.L917
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%r13, %rdi
	call	memmove
	addq	(%rbx), %rbp
	jmp	.L902
	.p2align 4,,10
	.p2align 3
.L918:
	xorl	%r12d, %r12d
	testq	%r14, %r14
	je	.L900
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %r14
	ja	.L921
	movq	%rbp, %rdi
	call	_Znwm
	testq	%r14, %r14
	movq	%rax, %r12
	movq	(%rbx), %r13
	jne	.L922
.L900:
	testq	%r13, %r13
	je	.L901
.L923:
	movq	%r13, %rdi
	call	_ZdlPv
.L901:
	addq	%r12, %rbp
	movq	%r12, (%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L902
	.p2align 4,,10
	.p2align 3
.L922:
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%rax, %rdi
	call	memmove
	testq	%r13, %r13
	jne	.L923
	jmp	.L901
	.p2align 4,,10
	.p2align 3
.L906:
	call	memmove
	addq	(%rbx), %rbp
	jmp	.L902
	.p2align 4,,10
	.p2align 3
.L920:
	movq	%r13, %rdi
	movq	%rax, %rdx
	movq	%r15, %rsi
	call	memmove
	movq	8(%rbx), %rdi
	movq	(%rbx), %r13
	movq	(%r12), %r15
	movq	8(%r12), %rdx
	movq	%rdi, %rax
	subq	%r13, %rax
	jmp	.L905
.L921:
	call	_ZSt17__throw_bad_allocv
	.cfi_endproc
.LFE7092:
	.size	_ZNSt6vectorIlSaIlEEaSERKS1_, .-_ZNSt6vectorIlSaIlEEaSERKS1_
	.section	.text.unlikely._ZNSt6vectorIlSaIlEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIlSaIlEEaSERKS1_,comdat
.LCOLDE11:
	.section	.text._ZNSt6vectorIlSaIlEEaSERKS1_,"axG",@progbits,_ZNSt6vectorIlSaIlEEaSERKS1_,comdat
.LHOTE11:
	.section	.text.unlikely._Z4funcIlEvm,"axG",@progbits,_Z4funcIlEvm,comdat
.LCOLDB12:
	.section	.text._Z4funcIlEvm,"axG",@progbits,_Z4funcIlEvm,comdat
.LHOTB12:
	.p2align 4,,15
	.weak	_Z4funcIlEvm
	.type	_Z4funcIlEvm, @function
_Z4funcIlEvm:
.LFB6948:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA6948
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
.LEHB62:
	call	_Znwm
.LEHE62:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movq	%rax, 64(%rsp)
	movl	$104857600, %eax
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	divq	%r15
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, 48(%rsp)
	je	.L925
	leaq	0(,%rax,8), %rdi
	movq	%rdi, %r14
	movq	%rdi, 40(%rsp)
.LEHB63:
	call	_Znwm
.LEHE63:
	movq	%rbx, %r15
	movq	%rax, (%rbx)
	movq	%r14, %rbx
	addq	%rax, %rbx
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rbx, 16(%r15)
	movq	%rax, %rdi
	call	memset
	movq	%rbx, 8(%r15)
	movl	$24, %edi
.LEHB64:
	call	_Znwm
.LEHE64:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, 56(%rsp)
.LEHB65:
	call	_Znwm
.LEHE65:
	movq	%r15, %rdi
	movq	%rax, %rbx
	movq	%r14, %rdx
	movq	%rax, (%rdi)
	movq	%rax, 8(%rdi)
	leaq	(%rax,%r14), %rax
	xorl	%esi, %esi
	movq	%rbx, %rdi
	movq	%r14, %rbp
	movq	%rax, 16(%r15)
	addq	%rbx, %rbp
	call	memset
	movq	56(%rsp), %rax
.L1001:
	movq	%rbp, 8(%rax)
	movq	64(%rsp), %rax
	movq	%rbx, %r13
	movl	$100, %r8d
	movq	(%rax), %r9
	movq	8(%rax), %rdi
	leaq	8(%r9), %rax
	movq	%rdi, %rsi
	leaq	16(%r9), %rdx
	subq	%rax, %rsi
	movq	%rax, 8(%rsp)
	movq	%rsi, %rax
	movq	$-1, %rsi
	shrq	$3, %rax
	addq	$1, %rax
	cmpq	%rdx, %rbx
	leaq	16(%rbx), %rdx
	setnb	%r12b
	cmpq	%rdx, %r9
	setnb	%dl
	orl	%r12d, %edx
	cmpq	$24, %rax
	seta	%r12b
	salq	$60, %r13
	shrq	$63, %r13
	andl	%edx, %r12d
	cmpq	%rax, %r13
	cmova	%rax, %r13
	subq	%r13, %rax
	leaq	0(,%r13,8), %r11
	leaq	-2(%rax), %r10
	movq	%rax, 16(%rsp)
	leaq	(%rbx,%r11), %rbp
	addq	%r9, %r11
	shrq	%r10
	addq	$1, %r10
	leaq	(%r10,%r10), %rax
	movq	%rax, 24(%rsp)
	movq	%r10, %rax
	salq	$4, %rax
	movq	%rax, 32(%rsp)
	.p2align 4,,10
	.p2align 3
.L928:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %r14d
	orq	%rdx, %r14
	cmpq	%rdi, %r9
	je	.L933
	testb	%r12b, %r12b
	je	.L929
	testq	%r13, %r13
	je	.L1012
	movq	(%rbx), %rax
	movq	8(%rsp), %rdx
	leaq	8(%rbx), %r15
	movq	%rax, (%r9)
.L930:
	xorl	%eax, %eax
	xorl	%ecx, %ecx
.L931:
	movdqa	0(%rbp,%rax), %xmm0
	addq	$1, %rcx
	movups	%xmm0, (%r11,%rax)
	addq	$16, %rax
	cmpq	%r10, %rcx
	jb	.L931
	movq	32(%rsp), %rax
	movq	24(%rsp), %rcx
	addq	%rax, %r15
	addq	%rax, %rdx
	cmpq	%rcx, 16(%rsp)
	je	.L933
	movq	(%r15), %rax
	movq	%rax, (%rdx)
.L933:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	%r14, %rdx
	cmpq	%rdx, %rsi
	cmova	%rdx, %rsi
	subq	$1, %r8
	jne	.L928
	pxor	%xmm4, %xmm4
	testq	%rsi, %rsi
	movl	800(%rbx), %ebx
	movl	800(%r9), %ebp
	cvtsi2sdq	48(%rsp), %xmm4
	movsd	%xmm4, 8(%rsp)
	js	.L936
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rsi, %xmm0
.L937:
	divsd	8(%rsp), %xmm0
	movq	72(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movsd	%xmm0, 16(%rsp)
.LEHB66:
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r12
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r13
	testq	%r13, %r13
	je	.L941
	cmpb	$0, 56(%r13)
	je	.L939
	movsbl	67(%r13), %esi
.L940:
	movq	%r12, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movsd	16(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L941
	cmpb	$0, 56(%rbx)
	je	.L942
	movsbl	67(%rbx), %esi
.L943:
	movq	%rbp, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	64(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L944
	call	_ZdlPv
.L944:
	movq	64(%rsp), %rdi
	call	_ZdlPv
	movq	56(%rsp), %rbx
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L1099
	call	_ZdlPv
.L1099:
	movq	%rbx, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE66:
	cmpq	$0, 48(%rsp)
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L946
	movq	40(%rsp), %r15
	movq	%r15, %rdi
.LEHB67:
	call	_Znwm
.LEHE67:
	movq	48(%rsp), %r14
	movq	%rax, %rbp
	movq	%rax, 0(%r13)
	movq	%r15, %rax
	xorl	%esi, %esi
	movq	%rbp, %rdi
	addq	%rbp, %rax
	leaq	0(,%r14,8), %rbx
	movq	%rax, 16(%r13)
	movq	%rbx, %rdx
	addq	%rbp, %rbx
	call	memset
	movl	$24, %edi
	movq	%rbx, 8(%r13)
.LEHB68:
	call	_Znwm
.LEHE68:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB69:
	call	_Znwm
.LEHE69:
	movq	%rax, %rbx
	movq	%rax, (%r12)
	movq	%rax, 8(%r12)
	movq	%r15, %rax
	addq	%rbx, %rax
	testq	%r14, %r14
	movq	%rax, 16(%r12)
	je	.L947
	leaq	0(,%r14,8), %rbp
	movq	%rbx, %rdi
	xorl	%esi, %esi
	movq	%rbp, %rdx
	addq	%rbp, %rbx
	call	memset
.L947:
	movq	%rbx, 8(%r12)
	movl	$100, %ebp
	movq	$-1, %r14
	.p2align 4,,10
	.p2align 3
.L948:
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
.LEHB70:
	call	_ZNSt6vectorIlSaIlEEaSERKS1_
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	%rbx, %rdx
	cmpq	%rdx, %r14
	cmova	%rdx, %r14
	subq	$1, %rbp
	jne	.L948
	movq	(%r12), %rax
	testq	%r14, %r14
	movl	800(%rax), %ebx
	movq	0(%r13), %rax
	movl	800(%rax), %ebp
	js	.L949
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r14, %xmm0
.L950:
	divsd	8(%rsp), %xmm0
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L941
	cmpb	$0, 56(%rbx)
	je	.L951
	movsbl	67(%rbx), %esi
.L952:
	movq	%rbp, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L953
	call	_ZdlPv
.L953:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L1100
	call	_ZdlPv
.L1100:
	movq	%r12, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE70:
	cmpq	$0, 48(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L955
	movq	40(%rsp), %r14
	movq	%r14, %rdi
.LEHB71:
	call	_Znwm
.LEHE71:
	movq	48(%rsp), %r13
	movq	%rax, %r12
	movq	%rax, 0(%rbp)
	movq	%r14, %rax
	xorl	%esi, %esi
	movq	%r12, %rdi
	addq	%r12, %rax
	leaq	0(,%r13,8), %rbx
	movq	%rax, 16(%rbp)
	movq	%rbx, %rdx
	addq	%r12, %rbx
	call	memset
	movl	$24, %edi
	movq	%rbx, 8(%rbp)
.LEHB72:
	call	_Znwm
.LEHE72:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, 8(%rsp)
.LEHB73:
	call	_Znwm
.LEHE73:
	movq	%rax, %rbx
	movq	%r14, %rax
	addq	%rbx, %rax
	testq	%r13, %r13
	movq	%rbx, (%r15)
	movq	%rbx, 8(%r15)
	movq	%rax, 16(%r15)
	je	.L956
	leaq	0(,%r13,8), %r12
	movq	%rbx, %rdi
	xorl	%esi, %esi
	movq	%r12, %rdx
	addq	%r12, %rbx
	call	memset
.L956:
	movq	8(%rsp), %rax
	leaq	96(%rsp), %r15
	movq	%rbx, 8(%rax)
	movabsq	$9223372036854775807, %rax
	movl	$100, %ebx
	movq	%rax, 80(%rsp)
	movq	%rax, 88(%rsp)
	movq	%rax, %r12
	.p2align 4,,10
	.p2align 3
.L968:
	movl	$4, %edi
	movq	%r15, %rsi
	call	clock_gettime
	movq	0(%rbp), %rdx
	movq	8(%rbp), %rdi
	movq	8(%rsp), %rax
	movq	96(%rsp), %r13
	movq	104(%rsp), %r14
	cmpq	%rdi, %rdx
	movq	(%rax), %rax
	je	.L964
	leaq	8(%rdx), %r10
	movq	%rdi, %rsi
	leaq	16(%rdx), %rcx
	subq	%r10, %rsi
	shrq	$3, %rsi
	addq	$1, %rsi
	cmpq	%rcx, %rax
	leaq	16(%rax), %rcx
	setnb	%r8b
	cmpq	%rcx, %rdx
	setnb	%cl
	orb	%cl, %r8b
	je	.L965
	cmpq	$24, %rsi
	jbe	.L965
	movq	%rax, %rcx
	salq	$60, %rcx
	shrq	$63, %rcx
	cmpq	%rsi, %rcx
	cmova	%rsi, %rcx
	testq	%rcx, %rcx
	je	.L1016
	movq	(%rax), %rdi
	leaq	8(%rax), %r9
	movq	%rdi, (%rdx)
.L961:
	movq	%rsi, %rdi
	xorl	%esi, %esi
	subq	%rcx, %rdi
	salq	$3, %rcx
	leaq	-2(%rdi), %r8
	addq	%rcx, %rax
	addq	%rcx, %rdx
	xorl	%ecx, %ecx
	shrq	%r8
	addq	$1, %r8
	leaq	(%r8,%r8), %r11
.L962:
	movdqa	(%rax,%rsi), %xmm0
	addq	$1, %rcx
	movups	%xmm0, (%rdx,%rsi)
	addq	$16, %rsi
	cmpq	%r8, %rcx
	jb	.L962
	leaq	0(,%r11,8), %rax
	addq	%rax, %r9
	addq	%rax, %r10
	cmpq	%rdi, %r11
	je	.L964
	movq	(%r9), %rax
	movq	%rax, (%r10)
.L964:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	104(%rsp), %rcx
	movq	96(%rsp), %rsi
	subq	%r14, %rcx
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
	leaq	80(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r12, %rsi
	movq	%rcx, 104(%rsp)
	jg	.L959
	cmpq	88(%rsp), %rcx
	leaq	80(%rsp), %rdi
	movq	%r15, %rax
	cmovg	%rdi, %rax
.L959:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbx
	movq	%rax, 80(%rsp)
	movq	%rdx, 88(%rsp)
	je	.L967
	movq	80(%rsp), %r12
	jmp	.L968
	.p2align 4,,10
	.p2align 3
.L965:
	movq	(%rax), %rcx
	addq	$8, %rdx
	addq	$8, %rax
	movq	%rcx, -8(%rdx)
	cmpq	%rdx, %rdi
	jne	.L965
	jmp	.L964
	.p2align 4,,10
	.p2align 3
.L1016:
	movq	%rdx, %r10
	movq	%rax, %r9
	jmp	.L961
	.p2align 4,,10
	.p2align 3
.L1012:
	movq	%r9, %rdx
	movq	%rbx, %r15
	jmp	.L930
	.p2align 4,,10
	.p2align 3
.L929:
	movq	%r9, %rax
	movq	%rbx, %rdx
	.p2align 4,,10
	.p2align 3
.L934:
	movq	(%rdx), %rcx
	addq	$8, %rax
	addq	$8, %rdx
	movq	%rcx, -8(%rax)
	cmpq	%rax, %rdi
	jne	.L934
	jmp	.L933
.L967:
	movq	8(%rsp), %rax
	movq	72(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movq	(%rax), %rax
	movl	800(%rax), %ebx
	movq	0(%rbp), %rax
	movl	800(%rax), %r12d
.LEHB74:
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r13
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	%r12d, %esi
	movq	%r13, %rdi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L941
	cmpb	$0, 56(%rbx)
	je	.L969
	movsbl	67(%rbx), %esi
.L970:
	movq	%r12, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	movsd	.LC2(%rip), %xmm1
	movl	$.LC4, %esi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	80(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L971
	call	_ZdlPv
.L971:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	8(%rsp), %rbx
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L1101
	call	_ZdlPv
.L1101:
	movq	%rbx, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE74:
	cmpq	$0, 48(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L973
	movq	40(%rsp), %r14
	movq	%r14, %rdi
.LEHB75:
	call	_Znwm
.LEHE75:
	movq	48(%rsp), %r13
	movq	%rax, %r12
	movq	%rax, (%rbx)
	movq	%r14, %rax
	xorl	%esi, %esi
	movq	%r12, %rdi
	addq	%r12, %rax
	leaq	0(,%r13,8), %rbp
	movq	%rax, 16(%rbx)
	movq	%rbp, %rdx
	addq	%r12, %rbp
	call	memset
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB76:
	call	_Znwm
.LEHE76:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbp
.LEHB77:
	call	_Znwm
.LEHE77:
	movq	%rax, %r12
	movq	%rax, 0(%rbp)
	movq	%rax, 8(%rbp)
	movq	%r14, %rax
	addq	%r12, %rax
	testq	%r13, %r13
	movq	%rax, 16(%rbp)
	movq	%r13, %rax
	je	.L974
	salq	$3, %rax
	movq	%r12, %rdi
	xorl	%esi, %esi
	movq	%rax, %r13
	movq	%rax, %rdx
	addq	%r13, %r12
	call	memset
.L974:
	movabsq	$9223372036854775807, %rax
	movq	%r12, 8(%rbp)
	movq	$100, 8(%rsp)
	movq	%rax, 80(%rsp)
	movq	%rax, 88(%rsp)
	jmp	.L988
	.p2align 4,,10
	.p2align 3
.L1107:
	testq	%r9, %r9
	jne	.L1104
.L1097:
	leaq	(%r8,%r12), %rcx
.L982:
	movq	%rcx, 8(%rbx)
.L975:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	104(%rsp), %rcx
	movq	96(%rsp), %rsi
	subq	%r14, %rcx
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
	leaq	80(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	80(%rsp), %rsi
	movq	%rcx, 104(%rsp)
	jg	.L987
	cmpq	88(%rsp), %rcx
	cmovle	%r15, %rax
.L987:
	subq	$1, 8(%rsp)
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rdx, 88(%rsp)
	movq	%rax, 80(%rsp)
	je	.L1105
.L988:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime
	cmpq	%rbp, %rbx
	movq	96(%rsp), %r13
	movq	104(%rsp), %r14
	je	.L975
	movq	8(%rbp), %r10
	movq	0(%rbp), %rsi
	movq	(%rbx), %r8
	movq	16(%rbx), %rax
	movq	%r10, %r12
	subq	%rsi, %r12
	subq	%r8, %rax
	movq	%r12, %r9
	sarq	$3, %rax
	sarq	$3, %r9
	cmpq	%rax, %r9
	ja	.L1106
	movq	8(%rbx), %rdi
	movq	%rdi, %rax
	subq	%r8, %rax
	movq	%rax, %rdx
	sarq	$3, %rdx
	cmpq	%rdx, %r9
	jbe	.L1107
	testq	%rdx, %rdx
	jne	.L1108
.L985:
	addq	%rax, %rsi
	movq	%r10, %rdx
	subq	%rsi, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	je	.L1097
	call	memmove
	movq	%r12, %rcx
	addq	(%rbx), %rcx
	jmp	.L982
	.p2align 4,,10
	.p2align 3
.L1106:
	xorl	%r10d, %r10d
	testq	%r9, %r9
	je	.L980
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %r9
	ja	.L1109
	movq	%r12, %rdi
	movq	%r9, 24(%rsp)
	movq	%rsi, 16(%rsp)
.LEHB78:
	call	_Znwm
	movq	24(%rsp), %r9
	movq	%rax, %r10
	movq	(%rbx), %r8
	movq	16(%rsp), %rsi
	testq	%r9, %r9
	je	.L980
	movq	%r12, %rdx
	movq	%rax, %rdi
	movq	%r8, 16(%rsp)
	call	memmove
	movq	16(%rsp), %r8
	movq	%rax, %r10
.L980:
	testq	%r8, %r8
	je	.L981
	movq	%r8, %rdi
	movq	%r10, 16(%rsp)
	call	_ZdlPv
	movq	16(%rsp), %r10
.L981:
	leaq	(%r10,%r12), %rcx
	movq	%r10, (%rbx)
	movq	%rcx, 16(%rbx)
	jmp	.L982
	.p2align 4,,10
	.p2align 3
.L1108:
	movq	%r8, %rdi
	movq	%rax, %rdx
	call	memmove
	movq	8(%rbx), %rdi
	movq	(%rbx), %r8
	movq	0(%rbp), %rsi
	movq	8(%rbp), %r10
	movq	%rdi, %rax
	subq	%r8, %rax
	jmp	.L985
	.p2align 4,,10
	.p2align 3
.L1104:
	movq	%r12, %rdx
	movq	%r8, %rdi
	call	memmove
	movq	%r12, %rcx
	addq	(%rbx), %rcx
	jmp	.L982
.L1105:
	pxor	%xmm0, %xmm0
	movl	$.LC4, %esi
	movsd	.LC2(%rip), %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	88(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	80(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk
	movq	0(%rbp), %rax
	movl	$_ZSt4cout, %edi
	movl	800(%rax), %r12d
	movq	(%rbx), %rax
	movl	800(%rax), %esi
	call	_ZNSolsEi
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L941
	cmpb	$0, 56(%r12)
	je	.L989
	movsbl	67(%r12), %esi
.L990:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L991
	call	_ZdlPv
.L991:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L992
	call	_ZdlPv
.L992:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	120(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L1110
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
.L969:
	.cfi_restore_state
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L970
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L970
.L951:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L952
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L952
.L942:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L943
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L943
.L939:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%r13), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L940
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L940
.L989:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L990
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L990
.L949:
	movq	%r14, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r14d
	orq	%r14, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L950
.L936:
	movq	%rsi, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %esi
	orq	%rsi, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L937
.L925:
	movq	$0, 16(%rbx)
	movl	$24, %edi
	xorl	%ebx, %ebx
	call	_Znwm
	xorl	%ebp, %ebp
	movq	%rax, 56(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, 40(%rsp)
	jmp	.L1001
.L946:
	movq	40(%rsp), %rax
	movl	$24, %edi
	xorl	%ebx, %ebx
	movq	%rax, 16(%r13)
	call	_Znwm
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	40(%rsp), %rax
	movq	%rax, 16(%r12)
	jmp	.L947
.L955:
	movq	40(%rsp), %rax
	movl	$24, %edi
	movq	%rax, 16(%rbp)
	call	_Znwm
	movq	40(%rsp), %rbx
	movq	%rax, 8(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rbx, 16(%rax)
	xorl	%ebx, %ebx
	jmp	.L956
.L973:
	movq	40(%rsp), %rax
	movl	$24, %edi
	xorl	%r12d, %r12d
	movq	%rax, 16(%rbx)
	call	_Znwm
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	40(%rsp), %rax
	movq	%rax, 16(%rbp)
	jmp	.L974
.L1028:
	movq	%rax, %rbp
	jmp	.L999
.L1026:
.L1098:
	movq	%rax, %rbx
	jmp	.L1000
.L1027:
	movq	%rax, %rbx
	jmp	.L998
.L999:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	%rbp, %rdi
	call	_Unwind_Resume
.L1000:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L998:
	movq	8(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L1110:
	call	__stack_chk_fail
.L941:
	call	_ZSt16__throw_bad_castv
.L1024:
	movq	%rax, %rbx
	jmp	.L995
.L1025:
	movq	%rax, %rbx
	jmp	.L996
.L995:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L996:
	movq	%r12, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L1022:
	movq	%rax, %rbx
	jmp	.L993
.L1023:
	movq	%rax, %rbx
	jmp	.L994
.L993:
	movq	64(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L994:
	movq	56(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L1029:
	jmp	.L1098
.L1109:
	call	_ZSt17__throw_bad_allocv
.LEHE78:
	.cfi_endproc
.LFE6948:
	.section	.gcc_except_table._Z4funcIlEvm,"aG",@progbits,_Z4funcIlEvm,comdat
.LLSDA6948:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE6948-.LLSDACSB6948
.LLSDACSB6948:
	.uleb128 .LEHB62-.LFB6948
	.uleb128 .LEHE62-.LEHB62
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB63-.LFB6948
	.uleb128 .LEHE63-.LEHB63
	.uleb128 .L1022-.LFB6948
	.uleb128 0
	.uleb128 .LEHB64-.LFB6948
	.uleb128 .LEHE64-.LEHB64
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB65-.LFB6948
	.uleb128 .LEHE65-.LEHB65
	.uleb128 .L1023-.LFB6948
	.uleb128 0
	.uleb128 .LEHB66-.LFB6948
	.uleb128 .LEHE66-.LEHB66
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB67-.LFB6948
	.uleb128 .LEHE67-.LEHB67
	.uleb128 .L1024-.LFB6948
	.uleb128 0
	.uleb128 .LEHB68-.LFB6948
	.uleb128 .LEHE68-.LEHB68
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB69-.LFB6948
	.uleb128 .LEHE69-.LEHB69
	.uleb128 .L1025-.LFB6948
	.uleb128 0
	.uleb128 .LEHB70-.LFB6948
	.uleb128 .LEHE70-.LEHB70
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB71-.LFB6948
	.uleb128 .LEHE71-.LEHB71
	.uleb128 .L1026-.LFB6948
	.uleb128 0
	.uleb128 .LEHB72-.LFB6948
	.uleb128 .LEHE72-.LEHB72
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB73-.LFB6948
	.uleb128 .LEHE73-.LEHB73
	.uleb128 .L1027-.LFB6948
	.uleb128 0
	.uleb128 .LEHB74-.LFB6948
	.uleb128 .LEHE74-.LEHB74
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB75-.LFB6948
	.uleb128 .LEHE75-.LEHB75
	.uleb128 .L1028-.LFB6948
	.uleb128 0
	.uleb128 .LEHB76-.LFB6948
	.uleb128 .LEHE76-.LEHB76
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB77-.LFB6948
	.uleb128 .LEHE77-.LEHB77
	.uleb128 .L1029-.LFB6948
	.uleb128 0
	.uleb128 .LEHB78-.LFB6948
	.uleb128 .LEHE78-.LEHB78
	.uleb128 0
	.uleb128 0
.LLSDACSE6948:
	.section	.text._Z4funcIlEvm,"axG",@progbits,_Z4funcIlEvm,comdat
	.size	_Z4funcIlEvm, .-_Z4funcIlEvm
	.section	.text.unlikely._Z4funcIlEvm,"axG",@progbits,_Z4funcIlEvm,comdat
.LCOLDE12:
	.section	.text._Z4funcIlEvm,"axG",@progbits,_Z4funcIlEvm,comdat
.LHOTE12:
	.section	.text.unlikely._ZNSt6vectorInSaInEEaSERKS1_,"axG",@progbits,_ZNSt6vectorInSaInEEaSERKS1_,comdat
	.align 2
.LCOLDB13:
	.section	.text._ZNSt6vectorInSaInEEaSERKS1_,"axG",@progbits,_ZNSt6vectorInSaInEEaSERKS1_,comdat
.LHOTB13:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorInSaInEEaSERKS1_
	.type	_ZNSt6vectorInSaInEEaSERKS1_, @function
_ZNSt6vectorInSaInEEaSERKS1_:
.LFB7113:
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
	je	.L1112
	movq	8(%rsi), %rdx
	movq	(%rsi), %r15
	movq	%rsi, %r12
	movq	(%rdi), %r13
	movq	16(%rdi), %rcx
	movq	%rdx, %rbp
	subq	%r15, %rbp
	subq	%r13, %rcx
	movq	%rbp, %r14
	sarq	$4, %rcx
	sarq	$4, %r14
	cmpq	%rcx, %r14
	ja	.L1135
	movq	8(%rdi), %rdi
	movq	%rdi, %rax
	subq	%r13, %rax
	movq	%rax, %rcx
	sarq	$4, %rcx
	cmpq	%rcx, %r14
	jbe	.L1136
	testq	%rcx, %rcx
	jne	.L1137
.L1122:
	leaq	(%r15,%rax), %rsi
	subq	%rsi, %rdx
	movq	%rdx, %rax
	sarq	$4, %rax
	testq	%rax, %rax
	jne	.L1123
.L1134:
	addq	%r13, %rbp
.L1119:
	movq	%rbp, 8(%rbx)
.L1112:
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
.L1136:
	.cfi_restore_state
	testq	%r14, %r14
	je	.L1134
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%r13, %rdi
	call	memmove
	addq	(%rbx), %rbp
	jmp	.L1119
	.p2align 4,,10
	.p2align 3
.L1135:
	xorl	%r12d, %r12d
	testq	%r14, %r14
	je	.L1117
	movabsq	$1152921504606846975, %rax
	cmpq	%rax, %r14
	ja	.L1138
	movq	%rbp, %rdi
	call	_Znwm
	testq	%r14, %r14
	movq	%rax, %r12
	movq	(%rbx), %r13
	jne	.L1139
.L1117:
	testq	%r13, %r13
	je	.L1118
.L1140:
	movq	%r13, %rdi
	call	_ZdlPv
.L1118:
	addq	%r12, %rbp
	movq	%r12, (%rbx)
	movq	%rbp, 16(%rbx)
	jmp	.L1119
	.p2align 4,,10
	.p2align 3
.L1139:
	movq	%rbp, %rdx
	movq	%r15, %rsi
	movq	%rax, %rdi
	call	memmove
	testq	%r13, %r13
	jne	.L1140
	jmp	.L1118
	.p2align 4,,10
	.p2align 3
.L1123:
	call	memmove
	addq	(%rbx), %rbp
	jmp	.L1119
	.p2align 4,,10
	.p2align 3
.L1137:
	movq	%r13, %rdi
	movq	%rax, %rdx
	movq	%r15, %rsi
	call	memmove
	movq	8(%rbx), %rdi
	movq	(%rbx), %r13
	movq	(%r12), %r15
	movq	8(%r12), %rdx
	movq	%rdi, %rax
	subq	%r13, %rax
	jmp	.L1122
.L1138:
	call	_ZSt17__throw_bad_allocv
	.cfi_endproc
.LFE7113:
	.size	_ZNSt6vectorInSaInEEaSERKS1_, .-_ZNSt6vectorInSaInEEaSERKS1_
	.section	.text.unlikely._ZNSt6vectorInSaInEEaSERKS1_,"axG",@progbits,_ZNSt6vectorInSaInEEaSERKS1_,comdat
.LCOLDE13:
	.section	.text._ZNSt6vectorInSaInEEaSERKS1_,"axG",@progbits,_ZNSt6vectorInSaInEEaSERKS1_,comdat
.LHOTE13:
	.section	.text.unlikely._Z4funcInEvm,"axG",@progbits,_Z4funcInEvm,comdat
.LCOLDB14:
	.section	.text._Z4funcInEvm,"axG",@progbits,_Z4funcInEvm,comdat
.LHOTB14:
	.p2align 4,,15
	.weak	_Z4funcInEvm
	.type	_Z4funcInEvm, @function
_Z4funcInEvm:
.LFB6949:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA6949
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
	movq	%rdi, 32(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 88(%rsp)
	xorl	%eax, %eax
.LEHB79:
	call	_Znwm
.LEHE79:
	xorl	%edx, %edx
	movq	%rax, %rbp
	movl	$104857600, %eax
	divq	%rbx
	movq	$0, 0(%rbp)
	movq	$0, 8(%rbp)
	movq	$0, 16(%rbp)
	testq	%rax, %rax
	movq	%rax, 24(%rsp)
	je	.L1142
	salq	$4, %rax
	movq	%rax, %rdi
	movq	%rax, %r15
	movq	%rax, 16(%rsp)
.LEHB80:
	call	_Znwm
.LEHE80:
	leaq	(%rax,%r15), %rbx
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, 0(%rbp)
	movq	%rbx, 16(%rbp)
	call	memset
	movq	%rbx, 8(%rbp)
	movl	$24, %edi
.LEHB81:
	call	_Znwm
.LEHE81:
	movq	%r15, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rbx
.LEHB82:
	call	_Znwm
.LEHE82:
	movq	%rax, %r12
	movq	%rax, (%rbx)
	movq	%rax, 8(%rbx)
	leaq	(%rax,%r15), %rax
	movq	%r15, %r13
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%r12, %rdi
	addq	%r12, %r13
	movq	%rax, 16(%rbx)
	call	memset
.L1197:
	movq	8(%rbp), %rdi
	movq	0(%rbp), %r10
	movl	$100, %r11d
	movq	%r13, 8(%rbx)
	movq	$-1, %r9
	movq	%rdi, %r8
	.p2align 4,,10
	.p2align 3
.L1145:
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
	je	.L1147
	.p2align 4,,10
	.p2align 3
.L1249:
	movq	(%rcx), %rsi
	movq	8(%rcx), %rdi
	addq	$16, %rax
	addq	$16, %rcx
	movq	%rsi, -16(%rax)
	movq	%rdi, -8(%rax)
	cmpq	%rax, %r8
	jne	.L1249
.L1147:
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	%r13, %rdx
	cmpq	%rdx, %r9
	cmova	%rdx, %r9
	subq	$1, %r11
	jne	.L1145
	pxor	%xmm4, %xmm4
	testq	%r9, %r9
	movl	1600(%r12), %r14d
	movl	1600(%r10), %r13d
	cvtsi2sdq	24(%rsp), %xmm4
	movsd	%xmm4, 8(%rsp)
	js	.L1148
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r9, %xmm0
.L1149:
	divsd	8(%rsp), %xmm0
	movq	32(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movsd	%xmm0, 40(%rsp)
.LEHB83:
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r12
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r15
	testq	%r15, %r15
	je	.L1153
	cmpb	$0, 56(%r15)
	je	.L1151
	movsbl	67(%r15), %esi
.L1152:
	movq	%r12, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movsd	40(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%r14d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L1153
	cmpb	$0, 56(%r12)
	je	.L1154
	movsbl	67(%r12), %esi
.L1155:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L1156
	call	_ZdlPv
.L1156:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L1278
	call	_ZdlPv
.L1278:
	movq	%rbx, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE83:
	cmpq	$0, 24(%rsp)
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1158
	movq	16(%rsp), %r14
	movq	%r14, %rdi
.LEHB84:
	call	_Znwm
.LEHE84:
	movq	24(%rsp), %r15
	movq	%rax, %rbp
	movq	%rax, 0(%r13)
	movq	%r14, %rax
	xorl	%esi, %esi
	movq	%rbp, %rdi
	addq	%rbp, %rax
	movq	%r15, %rbx
	movq	%rax, 16(%r13)
	salq	$4, %rbx
	movq	%rbx, %rdx
	addq	%rbp, %rbx
	call	memset
	movl	$24, %edi
	movq	%rbx, 8(%r13)
.LEHB85:
	call	_Znwm
.LEHE85:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r12
.LEHB86:
	call	_Znwm
.LEHE86:
	movq	%rax, %rbx
	movq	%rax, (%r12)
	movq	%rax, 8(%r12)
	movq	%r14, %rax
	addq	%rbx, %rax
	testq	%r15, %r15
	movq	%rax, 16(%r12)
	je	.L1159
	movq	%r15, %rbp
	movq	%rbx, %rdi
	xorl	%esi, %esi
	salq	$4, %rbp
	movq	%rbp, %rdx
	addq	%rbp, %rbx
	call	memset
.L1159:
	movq	%rbx, 8(%r12)
	movl	$100, %ebp
	movq	$-1, %r14
	.p2align 4,,10
	.p2align 3
.L1160:
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
.LEHB87:
	call	_ZNSt6vectorInSaInEEaSERKS1_
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	subq	%rbx, %rdx
	cmpq	%rdx, %r14
	cmova	%rdx, %r14
	subq	$1, %rbp
	jne	.L1160
	movq	(%r12), %rax
	testq	%r14, %r14
	movl	1600(%rax), %ebx
	movq	0(%r13), %rax
	movl	1600(%rax), %ebp
	js	.L1161
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r14, %xmm0
.L1162:
	divsd	8(%rsp), %xmm0
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertIdEERSoT_
	movl	%ebp, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L1153
	cmpb	$0, 56(%rbx)
	je	.L1163
	movsbl	67(%rbx), %esi
.L1164:
	movq	%rbp, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L1165
	call	_ZdlPv
.L1165:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L1279
	call	_ZdlPv
.L1279:
	movq	%r12, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE87:
	cmpq	$0, 24(%rsp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1167
	movq	16(%rsp), %r13
	movq	%r13, %rdi
.LEHB88:
	call	_Znwm
.LEHE88:
	movq	24(%rsp), %r14
	movq	%rax, %rbp
	movq	%rax, (%r12)
	movq	%r13, %rax
	xorl	%esi, %esi
	movq	%rbp, %rdi
	addq	%rbp, %rax
	movq	%r14, %rbx
	movq	%rax, 16(%r12)
	salq	$4, %rbx
	movq	%rbx, %rdx
	addq	%rbp, %rbx
	call	memset
	movl	$24, %edi
	movq	%rbx, 8(%r12)
.LEHB89:
	call	_Znwm
.LEHE89:
	movq	%r13, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
	movq	%rax, 8(%rsp)
.LEHB90:
	call	_Znwm
.LEHE90:
	movq	%rax, %rbx
	movq	%r13, %rax
	addq	%rbx, %rax
	testq	%r14, %r14
	movq	%rbx, (%r15)
	movq	%rbx, 8(%r15)
	movq	%rax, 16(%r15)
	je	.L1168
	movq	%r14, %rbp
	movq	%rbx, %rdi
	xorl	%esi, %esi
	salq	$4, %rbp
	movq	%rbp, %rdx
	addq	%rbp, %rbx
	call	memset
.L1168:
	movq	8(%rsp), %rax
	movl	$100, %ebp
	movq	%rbx, 8(%rax)
	movabsq	$9223372036854775807, %rax
	leaq	64(%rsp), %rbx
	movq	%rax, 48(%rsp)
	movq	%rax, 56(%rsp)
	movq	%rax, %r13
	.p2align 4,,10
	.p2align 3
.L1175:
	movl	$4, %edi
	movq	%rbx, %rsi
	call	clock_gettime
	movq	8(%r12), %rcx
	movq	(%r12), %rax
	movq	8(%rsp), %rdi
	movq	64(%rsp), %r14
	movq	72(%rsp), %r15
	cmpq	%rcx, %rax
	movq	(%rdi), %rdx
	je	.L1173
	.p2align 4,,10
	.p2align 3
.L1248:
	movq	(%rdx), %rsi
	movq	8(%rdx), %rdi
	addq	$16, %rax
	addq	$16, %rdx
	movq	%rsi, -16(%rax)
	movq	%rdi, -8(%rax)
	cmpq	%rax, %rcx
	jne	.L1248
.L1173:
	movq	%rbx, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	72(%rsp), %rcx
	movq	64(%rsp), %rsi
	subq	%r15, %rcx
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
	leaq	48(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%r13, %rsi
	movq	%rcx, 72(%rsp)
	jg	.L1171
	cmpq	56(%rsp), %rcx
	leaq	48(%rsp), %rdi
	movq	%rbx, %rax
	cmovg	%rdi, %rax
.L1171:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbp
	movq	%rax, 48(%rsp)
	movq	%rdx, 56(%rsp)
	je	.L1174
	movq	48(%rsp), %r13
	jmp	.L1175
.L1174:
	movq	8(%rsp), %rax
	movq	32(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	movq	(%rax), %rax
	movl	1600(%rax), %r13d
	movq	(%r12), %rax
	movl	1600(%rax), %ebp
.LEHB91:
	call	_ZNSo9_M_insertImEERSoT_
	movl	$3, %edx
	movq	%rax, %r14
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	%ebp, %esi
	movq	%r14, %rdi
	call	_ZNSolsEi
	movl	%r13d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L1153
	cmpb	$0, 56(%rbp)
	je	.L1176
	movsbl	67(%rbp), %esi
.L1177:
	movq	%r13, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	movsd	.LC2(%rip), %xmm1
	movl	$.LC4, %esi
	movsd	.LC3(%rip), %xmm2
	movl	$1, %eax
	cvtsi2sdq	56(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	48(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	__printf_chk
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L1178
	call	_ZdlPv
.L1178:
	movq	%r12, %rdi
	call	_ZdlPv
	movq	8(%rsp), %r15
	movq	(%r15), %rdi
	testq	%rdi, %rdi
	je	.L1280
	call	_ZdlPv
.L1280:
	movq	%r15, %rdi
	call	_ZdlPv
	movl	$24, %edi
	call	_Znwm
.LEHE91:
	cmpq	$0, 24(%rsp)
	movq	%rax, 8(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1180
	movq	16(%rsp), %r14
	movq	%r14, %rdi
.LEHB92:
	call	_Znwm
.LEHE92:
	movq	24(%rsp), %r13
	movq	8(%rsp), %r15
	movq	%rax, %r12
	movq	%r14, %rax
	xorl	%esi, %esi
	movq	%r12, %rdi
	addq	%r12, %rax
	movq	%r13, %rbp
	movq	%r12, (%r15)
	movq	%rax, 16(%r15)
	salq	$4, %rbp
	movq	%rbp, %rdx
	addq	%r12, %rbp
	call	memset
	movq	%rbp, 8(%r15)
	movl	$24, %edi
.LEHB93:
	call	_Znwm
.LEHE93:
	movq	%r14, %rdi
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %r15
.LEHB94:
	call	_Znwm
.LEHE94:
	movq	%rax, %rbp
	movq	%rax, (%r15)
	movq	%rax, 8(%r15)
	movq	%r14, %rax
	addq	%rbp, %rax
	testq	%r13, %r13
	movq	%rax, 16(%r15)
	je	.L1181
	movq	%r13, %r12
	movq	%rbp, %rdi
	xorl	%esi, %esi
	salq	$4, %r12
	movq	%r12, %rdx
	addq	%r12, %rbp
	call	memset
.L1181:
	movabsq	$9223372036854775807, %rax
	movq	%rbp, 8(%r15)
	movl	$100, %ebp
	movq	%rax, 48(%rsp)
	movq	%rax, 56(%rsp)
	movq	%rax, %r12
	jmp	.L1184
	.p2align 4,,10
	.p2align 3
.L1283:
	movq	48(%rsp), %r12
.L1184:
	movq	%rbx, %rsi
	movl	$4, %edi
	call	clock_gettime
	movq	8(%rsp), %rdi
	movq	%r15, %rsi
	movq	64(%rsp), %r13
	movq	72(%rsp), %r14
.LEHB95:
	call	_ZNSt6vectorInSaInEEaSERKS1_
	movq	%rbx, %rsi
	movl	$4, %edi
	call	clock_gettime
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
	leaq	48(%rsp), %rax
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	%rsi, %r12
	movq	%rcx, 72(%rsp)
	jl	.L1182
	cmpq	56(%rsp), %rcx
	cmovle	%rbx, %rax
.L1182:
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	subq	$1, %rbp
	movq	%rax, 48(%rsp)
	movq	%rdx, 56(%rsp)
	jne	.L1283
	pxor	%xmm0, %xmm0
	movl	$.LC4, %esi
	movsd	.LC2(%rip), %xmm1
	movl	$1, %edi
	movsd	.LC3(%rip), %xmm3
	movl	$1, %eax
	cvtsi2sdq	56(%rsp), %xmm0
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	48(%rsp), %xmm0
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	__printf_chk
	movq	(%r15), %rax
	movl	$_ZSt4cout, %edi
	movl	1600(%rax), %ebx
	movq	8(%rsp), %rax
	movq	(%rax), %rax
	movl	1600(%rax), %esi
	call	_ZNSolsEi
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L1153
	cmpb	$0, 56(%rbx)
	je	.L1185
	movsbl	67(%rbx), %esi
.L1186:
	movq	%rbp, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	$_ZSt4cout, %edi
	call	_ZNSo5flushEv
	movq	8(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L1187
	call	_ZdlPv
.L1187:
	movq	8(%rsp), %rdi
	call	_ZdlPv
	movq	(%r15), %rdi
	testq	%rdi, %rdi
	je	.L1188
	call	_ZdlPv
.L1188:
	movq	%r15, %rdi
	call	_ZdlPv
	movq	88(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L1284
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
.L1185:
	.cfi_restore_state
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L1186
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1186
.L1176:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%rbp), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L1177
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1177
.L1163:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L1164
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1164
.L1154:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L1155
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1155
.L1151:
	movq	%r15, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r15), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L1152
	movq	%r15, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1152
.L1161:
	movq	%r14, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r14d
	orq	%r14, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L1162
.L1148:
	movq	%r9, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r9d
	orq	%r9, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L1149
.L1180:
	movq	16(%rsp), %rdi
	xorl	%ebp, %ebp
	movq	%rdi, 16(%rax)
	movl	$24, %edi
	call	_Znwm
	movq	%rax, %r15
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	16(%rsp), %rax
	movq	%rax, 16(%r15)
	jmp	.L1181
.L1167:
	movq	16(%rsp), %rax
	movl	$24, %edi
	xorl	%ebx, %ebx
	movq	%rax, 16(%r12)
	call	_Znwm
	movq	16(%rsp), %rdi
	movq	%rax, 8(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rdi, 16(%rax)
	jmp	.L1168
.L1142:
	movq	$0, 16(%rbp)
	movl	$24, %edi
	xorl	%r12d, %r12d
	call	_Znwm
	xorl	%r13d, %r13d
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, 16(%rsp)
	jmp	.L1197
.L1158:
	movq	16(%rsp), %rax
	movl	$24, %edi
	xorl	%ebx, %ebx
	movq	%rax, 16(%r13)
	call	_Znwm
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	16(%rsp), %rax
	movq	%rax, 16(%r12)
	jmp	.L1159
.L1222:
.L1277:
	movq	%rax, %rbx
	jmp	.L1195
.L1223:
	movq	%rax, %rbx
	jmp	.L1196
.L1195:
	movq	8(%rsp), %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L1196:
	movq	%r15, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L1284:
	call	__stack_chk_fail
.L1220:
.L1276:
	movq	%rax, %rbx
	jmp	.L1193
.L1221:
	jmp	.L1277
.L1218:
	movq	%rax, %rbx
	jmp	.L1191
.L1193:
	movq	%r12, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L1191:
	movq	%r13, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L1219:
	jmp	.L1276
.L1153:
	call	_ZSt16__throw_bad_castv
.L1216:
	movq	%rax, %rbx
	jmp	.L1189
.L1217:
	movq	%rax, %rbp
	jmp	.L1190
.L1189:
	movq	%rbp, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_Unwind_Resume
.L1190:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	%rbp, %rdi
	call	_Unwind_Resume
.LEHE95:
	.cfi_endproc
.LFE6949:
	.section	.gcc_except_table._Z4funcInEvm,"aG",@progbits,_Z4funcInEvm,comdat
.LLSDA6949:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE6949-.LLSDACSB6949
.LLSDACSB6949:
	.uleb128 .LEHB79-.LFB6949
	.uleb128 .LEHE79-.LEHB79
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB80-.LFB6949
	.uleb128 .LEHE80-.LEHB80
	.uleb128 .L1216-.LFB6949
	.uleb128 0
	.uleb128 .LEHB81-.LFB6949
	.uleb128 .LEHE81-.LEHB81
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB82-.LFB6949
	.uleb128 .LEHE82-.LEHB82
	.uleb128 .L1217-.LFB6949
	.uleb128 0
	.uleb128 .LEHB83-.LFB6949
	.uleb128 .LEHE83-.LEHB83
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB84-.LFB6949
	.uleb128 .LEHE84-.LEHB84
	.uleb128 .L1218-.LFB6949
	.uleb128 0
	.uleb128 .LEHB85-.LFB6949
	.uleb128 .LEHE85-.LEHB85
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB86-.LFB6949
	.uleb128 .LEHE86-.LEHB86
	.uleb128 .L1219-.LFB6949
	.uleb128 0
	.uleb128 .LEHB87-.LFB6949
	.uleb128 .LEHE87-.LEHB87
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB88-.LFB6949
	.uleb128 .LEHE88-.LEHB88
	.uleb128 .L1220-.LFB6949
	.uleb128 0
	.uleb128 .LEHB89-.LFB6949
	.uleb128 .LEHE89-.LEHB89
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB90-.LFB6949
	.uleb128 .LEHE90-.LEHB90
	.uleb128 .L1221-.LFB6949
	.uleb128 0
	.uleb128 .LEHB91-.LFB6949
	.uleb128 .LEHE91-.LEHB91
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB92-.LFB6949
	.uleb128 .LEHE92-.LEHB92
	.uleb128 .L1222-.LFB6949
	.uleb128 0
	.uleb128 .LEHB93-.LFB6949
	.uleb128 .LEHE93-.LEHB93
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB94-.LFB6949
	.uleb128 .LEHE94-.LEHB94
	.uleb128 .L1223-.LFB6949
	.uleb128 0
	.uleb128 .LEHB95-.LFB6949
	.uleb128 .LEHE95-.LEHB95
	.uleb128 0
	.uleb128 0
.LLSDACSE6949:
	.section	.text._Z4funcInEvm,"axG",@progbits,_Z4funcInEvm,comdat
	.size	_Z4funcInEvm, .-_Z4funcInEvm
	.section	.text.unlikely._Z4funcInEvm,"axG",@progbits,_Z4funcInEvm,comdat
.LCOLDE14:
	.section	.text._Z4funcInEvm,"axG",@progbits,_Z4funcInEvm,comdat
.LHOTE14:
	.section	.text.unlikely,"ax",@progbits
.LCOLDB15:
	.section	.text.startup,"ax",@progbits
.LHOTB15:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB6886:
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
.LFE6886:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE15:
	.section	.text.startup
.LHOTE15:
	.section	.text.unlikely
.LCOLDB16:
	.section	.text.startup
.LHOTB16:
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB7743:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE7743:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.text.unlikely
.LCOLDE16:
	.section	.text.startup
.LHOTE16:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	3894859413
	.long	1041313291
	.align 8
.LC3:
	.long	0
	.long	1079574528
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
