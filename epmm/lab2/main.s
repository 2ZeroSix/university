	.file	"main.cpp"
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1620:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1620:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.rodata._Z4funcIaEvm.str1.1,"aMS",@progbits,1
.LC0:
	.string	" : "
	.section	.text._Z4funcIaEvm,"axG",@progbits,_Z4funcIaEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIaEvm
	.type	_Z4funcIaEvm, @function
_Z4funcIaEvm:
.LFB7304:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7304
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r14
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
	xorl	%ebp, %ebp
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	movq	%rdi, 24(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
.LEHB0:
	call	_Znwm@PLT
	xorl	%edx, %edx
	movq	%rax, %rbx
	movl	$104857600, %eax
	divq	%r14
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	movq	$0, 16(%rbx)
	testq	%rax, %rax
	movq	%rax, 16(%rsp)
	jne	.L183
.L4:
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
	xorl	%r12d, %r12d
	call	_Znwm@PLT
	xorl	%r8d, %r8d
	cmpq	$0, 16(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L184
.L5:
	movq	8(%rbx), %rdi
	movq	%r12, 8(%rbp)
	movl	$100, %r9d
	movq	$-1, %r12
	movq	%r8, %rcx
	.p2align 4,,10
	.p2align 3
.L9:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	movq	(%rbx), %rax
	movq	%rdx, %r8
	cmpq	%rdi, %rax
	je	.L6
	.p2align 4,,10
	.p2align 3
.L7:
	movzbl	(%rcx), %esi
	addq	$1, %rax
	addq	$1, %rcx
	movb	%sil, -1(%rax)
	movq	8(%rbx), %rdi
	cmpq	%rdi, %rax
	jne	.L7
.L6:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%r8, %rax
	cmpq	%rax, %r12
	cmova	%rax, %r12
	subq	$1, %r9
	je	.L8
	movq	0(%rbp), %rcx
	jmp	.L9
.L8:
	movq	24(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
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
	je	.L15
	cmpb	$0, 56(%r14)
	je	.L11
	movsbl	67(%r14), %esi
.L12:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm4, %xmm4
	testq	%r12, %r12
	cvtsi2sdq	16(%rsp), %xmm4
	movsd	%xmm4, 8(%rsp)
	js	.L13
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r12, %xmm0
.L14:
	divsd	8(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	(%rbx), %rdx
	movq	%rax, %rdi
	movl	100(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	0(%rbp), %rdx
	movq	%rax, %rdi
	movl	100(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L15
	cmpb	$0, 56(%r12)
	je	.L16
	movsbl	67(%r12), %esi
.L17:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L18
	call	_ZdlPv@PLT
.L18:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L19
	call	_ZdlPv@PLT
.L19:
	movq	%rbp, %rdi
	xorl	%ebp, %ebp
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
	cmpq	$0, 16(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L185
.L20:
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
	xorl	%r12d, %r12d
	call	_Znwm@PLT
	cmpq	$0, 16(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L186
.L21:
	movq	%r12, 8(%rbp)
	movl	$100, %r13d
	movq	$-1, %r12
	jmp	.L30
	.p2align 4,,10
	.p2align 3
.L190:
	testq	%r15, %r15
	jne	.L187
.L26:
	movq	%rdi, 8(%rbx)
.L22:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%r14, %rax
	cmpq	%rax, %r12
	cmova	%rax, %r12
	subq	$1, %r13
	je	.L188
.L30:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%rbp, %rbx
	movq	%rdx, %r14
	je	.L22
	movq	8(%rbp), %rcx
	movq	0(%rbp), %rsi
	movq	(%rbx), %rdi
	movq	16(%rbx), %rax
	movq	%rcx, %r15
	subq	%rsi, %r15
	subq	%rdi, %rax
	cmpq	%rax, %r15
	ja	.L189
	movq	8(%rbx), %rax
	movq	%rax, %rdx
	subq	%rdi, %rdx
	cmpq	%rdx, %r15
	jbe	.L190
	xorl	%r8d, %r8d
	testq	%rdx, %rdx
	jne	.L191
.L28:
	addq	%r8, %rsi
	subq	%rsi, %rcx
	jne	.L29
	addq	%r15, %rdi
	jmp	.L26
	.p2align 4,,10
	.p2align 3
.L189:
	movq	%r15, %rdi
	movq	%rsi, (%rsp)
	call	_Znwm@PLT
	testq	%r15, %r15
	movq	%rax, %rcx
	movq	(%rsp), %rsi
	je	.L24
	movq	%r15, %rdx
	movq	%rax, %rdi
	call	memcpy@PLT
	movq	%rax, %rcx
.L24:
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L25
	movq	%rcx, (%rsp)
	call	_ZdlPv@PLT
	movq	(%rsp), %rcx
.L25:
	leaq	(%rcx,%r15), %rdi
	movq	%rcx, (%rbx)
	movq	%rdi, 16(%rbx)
	jmp	.L26
	.p2align 4,,10
	.p2align 3
.L187:
	movq	%r15, %rdx
	call	memmove@PLT
	movq	(%rbx), %rdi
	addq	%r15, %rdi
	jmp	.L26
	.p2align 4,,10
	.p2align 3
.L29:
	movq	%rax, %rdi
	movq	%rcx, %rdx
	call	memmove@PLT
	movq	(%rbx), %rdi
	addq	%r15, %rdi
	jmp	.L26
	.p2align 4,,10
	.p2align 3
.L191:
	call	memmove@PLT
	movq	8(%rbx), %rax
	movq	(%rbx), %rdi
	movq	0(%rbp), %rsi
	movq	8(%rbp), %rcx
	movq	%rax, %r8
	subq	%rdi, %r8
	jmp	.L28
.L188:
	testq	%r12, %r12
	js	.L31
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r12, %xmm0
.L32:
	divsd	8(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	(%rbx), %rdx
	movq	%rax, %rdi
	movl	100(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	0(%rbp), %rdx
	movq	%rax, %rdi
	movl	100(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L15
	cmpb	$0, 56(%r12)
	je	.L33
	movsbl	67(%r12), %esi
.L34:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L35
	call	_ZdlPv@PLT
.L35:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L36
	call	_ZdlPv@PLT
.L36:
	movq	%rbp, %rdi
	xorl	%ebp, %ebp
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
	cmpq	$0, 16(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L192
.L37:
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
	xorl	%ebp, %ebp
	call	_Znwm@PLT
	cmpq	$0, 16(%rsp)
	movq	%rax, (%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L193
.L38:
	movq	%rbp, 8(%rax)
	leaq	32(%rsp), %r15
	movabsq	$9223372036854775807, %rax
	movl	$100, %ebp
	movq	%rax, 8(%rsp)
	movq	%rax, %r14
	.p2align 4,,10
	.p2align 3
.L42:
	movl	$4, %edi
	movq	%r15, %rsi
	call	clock_gettime@PLT
	movq	(%rbx), %rax
	cmpq	8(%rbx), %rax
	movq	(%rsp), %rdi
	movq	32(%rsp), %r12
	movq	40(%rsp), %r13
	movq	(%rdi), %rdx
	je	.L39
	.p2align 4,,10
	.p2align 3
.L40:
	movzbl	(%rdx), %ecx
	addq	$1, %rax
	addq	$1, %rdx
	movb	%cl, -1(%rax)
	cmpq	%rax, 8(%rbx)
	jne	.L40
.L39:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	40(%rsp), %rax
	movq	32(%rsp), %rsi
	subq	%r13, %rax
	subq	%r12, %rsi
	movq	%rax, %rdx
	shrq	$63, %rdx
	subq	%rdx, %rsi
	cmpq	%r14, %rsi
	jg	.L41
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	8(%rsp), %rcx
	jg	.L41
	movq	%rcx, 8(%rsp)
	movq	%rsi, %r14
.L41:
	subq	$1, %rbp
	jne	.L42
	movq	24(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%rbx), %rax
	movq	%rbp, %rdi
	movl	100(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%rsp), %rdi
	movq	(%rdi), %rdx
	movq	%rax, %rdi
	movl	100(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L15
	cmpb	$0, 56(%rbp)
	je	.L43
	movsbl	67(%rbp), %esi
.L44:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm2
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	8(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	%r14, %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L15
	cmpb	$0, 56(%rbp)
	je	.L45
	movsbl	67(%rbp), %esi
.L46:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L47
	call	_ZdlPv@PLT
.L47:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L48
	call	_ZdlPv@PLT
.L48:
	movq	(%rsp), %rdi
	xorl	%ebp, %ebp
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
	cmpq	$0, 16(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L194
.L49:
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
	xorl	%ebp, %ebp
	call	_Znwm@PLT
	cmpq	$0, 16(%rsp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	jne	.L195
.L50:
	movabsq	$9223372036854775807, %rax
	movq	%rbp, 8(%r12)
	movl	$100, %ebp
	movq	%rax, 8(%rsp)
	movq	%rax, (%rsp)
	jmp	.L60
	.p2align 4,,10
	.p2align 3
.L199:
	testq	%rcx, %rcx
	jne	.L196
.L55:
	movq	%rdi, 8(%rbx)
.L51:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	40(%rsp), %rax
	movq	32(%rsp), %rsi
	subq	%r14, %rax
	subq	%r13, %rsi
	movq	%rax, %rdx
	shrq	$63, %rdx
	subq	%rdx, %rsi
	cmpq	%rsi, (%rsp)
	jl	.L59
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	8(%rsp), %rcx
	jg	.L59
	movq	%rcx, 8(%rsp)
	movq	%rsi, (%rsp)
.L59:
	subq	$1, %rbp
	je	.L197
.L60:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	cmpq	%r12, %rbx
	movq	32(%rsp), %r13
	movq	40(%rsp), %r14
	je	.L51
	movq	8(%r12), %r8
	movq	(%r12), %rsi
	movq	(%rbx), %rdi
	movq	16(%rbx), %rax
	movq	%r8, %rcx
	subq	%rsi, %rcx
	subq	%rdi, %rax
	cmpq	%rax, %rcx
	ja	.L198
	movq	8(%rbx), %rax
	movq	%rax, %rdx
	subq	%rdi, %rdx
	cmpq	%rdx, %rcx
	jbe	.L199
	xorl	%r9d, %r9d
	testq	%rdx, %rdx
	jne	.L200
.L57:
	addq	%r9, %rsi
	subq	%rsi, %r8
	jne	.L58
	addq	%rcx, %rdi
	jmp	.L55
	.p2align 4,,10
	.p2align 3
.L198:
	movq	%rcx, %rdi
	movq	%rsi, 24(%rsp)
	movq	%rcx, 16(%rsp)
	call	_Znwm@PLT
	movq	16(%rsp), %rcx
	movq	%rax, %r8
	movq	24(%rsp), %rsi
	testq	%rcx, %rcx
	je	.L53
	movq	%rcx, %rdx
	movq	%rax, %rdi
	call	memcpy@PLT
	movq	16(%rsp), %rcx
	movq	%rax, %r8
.L53:
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L54
	movq	%r8, 24(%rsp)
	movq	%rcx, 16(%rsp)
	call	_ZdlPv@PLT
	movq	24(%rsp), %r8
	movq	16(%rsp), %rcx
.L54:
	leaq	(%r8,%rcx), %rdi
	movq	%r8, (%rbx)
	movq	%rdi, 16(%rbx)
	jmp	.L55
	.p2align 4,,10
	.p2align 3
.L196:
	movq	%rcx, %rdx
	movq	%rcx, 16(%rsp)
	call	memmove@PLT
	movq	16(%rsp), %rcx
	movq	(%rbx), %rdi
	addq	%rcx, %rdi
	jmp	.L55
	.p2align 4,,10
	.p2align 3
.L58:
	movq	%rax, %rdi
	movq	%r8, %rdx
	movq	%rcx, 16(%rsp)
	call	memmove@PLT
	movq	16(%rsp), %rcx
	movq	(%rbx), %rdi
	addq	%rcx, %rdi
	jmp	.L55
	.p2align 4,,10
	.p2align 3
.L200:
	movq	%rcx, 16(%rsp)
	call	memmove@PLT
	movq	8(%rbx), %rax
	movq	(%rbx), %rdi
	movq	(%r12), %rsi
	movq	8(%r12), %r8
	movq	16(%rsp), %rcx
	movq	%rax, %r9
	subq	%rdi, %r9
	jmp	.L57
.L197:
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm3
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	8(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	addq	-24(%rax), %rdi
	pxor	%xmm0, %xmm0
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	(%rsp), %xmm0
	movl	24(%rdi), %edx
	andl	$-261, %edx
	orl	$4, %edx
	movl	%edx, 24(%rdi)
	leaq	_ZSt4cout(%rip), %rdi
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L15
	cmpb	$0, 56(%rbp)
	je	.L61
	movsbl	67(%rbp), %esi
.L62:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movl	100(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%r12), %rdx
	movq	%rax, %rdi
	movl	100(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L15
	cmpb	$0, 56(%rbp)
	je	.L63
	movsbl	67(%rbp), %esi
.L64:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L65
	call	_ZdlPv@PLT
.L65:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L66
	call	_ZdlPv@PLT
.L66:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	56(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L201
	addq	$72, %rsp
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
.L11:
	.cfi_restore_state
	movq	%r14, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r14), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L12
	movq	%r14, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L12
.L63:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L64
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L64
.L61:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L62
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L62
.L45:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L46
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L46
.L43:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L44
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L44
.L33:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L34
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L34
.L16:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L17
	movq	%r12, %rdi
	call	*%rax
.LEHE0:
	movsbl	%al, %esi
	jmp	.L17
.L184:
	movq	16(%rsp), %r14
	movq	%r14, %rdi
.LEHB1:
	call	_Znwm@PLT
.LEHE1:
	leaq	(%rax,%r14), %r12
	movq	%rax, 0(%rbp)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r12, 16(%rbp)
	call	memset@PLT
	movq	%rax, %r8
	jmp	.L5
.L183:
	movq	%rax, %rdi
	movq	%rax, %r14
.LEHB2:
	call	_Znwm@PLT
.LEHE2:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%rbx)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%rbx)
	call	memset@PLT
	jmp	.L4
.L31:
	movq	%r12, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r12d
	orq	%r12, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L32
.L13:
	movq	%r12, %rdx
	pxor	%xmm0, %xmm0
	shrq	%rdx
	andl	$1, %r12d
	orq	%r12, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L14
.L186:
	movq	16(%rsp), %r14
	movq	%r14, %rdi
.LEHB3:
	call	_Znwm@PLT
.LEHE3:
	leaq	(%rax,%r14), %r12
	movq	%rax, 0(%rbp)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r12, 16(%rbp)
	call	memset@PLT
	jmp	.L21
.L185:
	movq	16(%rsp), %r14
	movq	%r14, %rdi
.LEHB4:
	call	_Znwm@PLT
.LEHE4:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%rbx)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%rbx)
	call	memset@PLT
	jmp	.L20
.L195:
	movq	16(%rsp), %r14
	movq	%r14, %rdi
.LEHB5:
	call	_Znwm@PLT
.LEHE5:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%r12)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%r12)
	call	memset@PLT
	jmp	.L50
.L194:
	movq	16(%rsp), %r14
	movq	%r14, %rdi
.LEHB6:
	call	_Znwm@PLT
.LEHE6:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%rbx)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%rbx)
	call	memset@PLT
	jmp	.L49
.L193:
	movq	16(%rsp), %r14
	movq	%r14, %rdi
.LEHB7:
	call	_Znwm@PLT
.LEHE7:
	movq	(%rsp), %rdi
	leaq	(%rax,%r14), %rbp
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, (%rdi)
	movq	%rbp, 16(%rdi)
	movq	%rax, %rdi
	call	memset@PLT
	movq	(%rsp), %rax
	jmp	.L38
.L192:
	movq	16(%rsp), %r14
	movq	%r14, %rdi
.LEHB8:
	call	_Znwm@PLT
.LEHE8:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%rbx)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%rbx)
	call	memset@PLT
	jmp	.L37
.L201:
	call	__stack_chk_fail@PLT
.L15:
.LEHB9:
	call	_ZSt16__throw_bad_castv@PLT
.L99:
.L181:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
	call	_Unwind_Resume@PLT
.L100:
	movq	(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L101:
	jmp	.L181
.L102:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L97:
	jmp	.L181
.L98:
.L182:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.LEHE9:
.L95:
	jmp	.L181
.L96:
	jmp	.L182
	.cfi_endproc
.LFE7304:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._Z4funcIaEvm,"aG",@progbits,_Z4funcIaEvm,comdat
.LLSDA7304:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7304-.LLSDACSB7304
.LLSDACSB7304:
	.uleb128 .LEHB0-.LFB7304
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB7304
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L96-.LFB7304
	.uleb128 0
	.uleb128 .LEHB2-.LFB7304
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L95-.LFB7304
	.uleb128 0
	.uleb128 .LEHB3-.LFB7304
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L98-.LFB7304
	.uleb128 0
	.uleb128 .LEHB4-.LFB7304
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L97-.LFB7304
	.uleb128 0
	.uleb128 .LEHB5-.LFB7304
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L102-.LFB7304
	.uleb128 0
	.uleb128 .LEHB6-.LFB7304
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L101-.LFB7304
	.uleb128 0
	.uleb128 .LEHB7-.LFB7304
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L100-.LFB7304
	.uleb128 0
	.uleb128 .LEHB8-.LFB7304
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L99-.LFB7304
	.uleb128 0
	.uleb128 .LEHB9-.LFB7304
	.uleb128 .LEHE9-.LEHB9
	.uleb128 0
	.uleb128 0
.LLSDACSE7304:
	.section	.text._Z4funcIaEvm,"axG",@progbits,_Z4funcIaEvm,comdat
	.size	_Z4funcIaEvm, .-_Z4funcIaEvm
	.section	.text._Z4funcIsEvm,"axG",@progbits,_Z4funcIsEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIsEvm
	.type	_Z4funcIsEvm, @function
_Z4funcIsEvm:
.LFB7305:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7305
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r14
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
	subq	$184, %rsp
	.cfi_def_cfa_offset 240
	movq	%rdi, 136(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 168(%rsp)
	xorl	%eax, %eax
.LEHB10:
	call	_Znwm@PLT
.LEHE10:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movq	%rax, 120(%rsp)
	movl	$104857600, %eax
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	divq	%r14
	movq	$0, 16(%rbx)
	leaq	(%rax,%rax), %rdx
	testq	%rax, %rax
	movq	%rax, 104(%rsp)
	movq	%rdx, 112(%rsp)
	je	.L203
	movq	%rdx, %rdi
	movq	%rdx, %r14
.LEHB11:
	call	_Znwm@PLT
.LEHE11:
	movq	%rbx, %rdi
	movq	%rax, (%rbx)
	leaq	(%rax,%r14), %rbx
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rbx, 16(%rdi)
	movq	%rax, %rdi
	call	memset@PLT
.L292:
	movq	120(%rsp), %rax
	movl	$24, %edi
	movq	%rbx, 8(%rax)
.LEHB12:
	call	_Znwm@PLT
.LEHE12:
	cmpq	$0, 104(%rsp)
	movq	%rax, %rbx
	movq	%rax, 128(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L204
	movq	112(%rsp), %r14
	movq	%r14, %rdi
.LEHB13:
	call	_Znwm@PLT
.LEHE13:
	movq	%rax, %r10
	movq	%rbx, %rax
	movq	%r14, %rdx
	movq	%r10, (%rbx)
	leaq	(%r10,%r14), %rbx
	movq	%r10, %rdi
	xorl	%esi, %esi
	movq	%rbx, 16(%rax)
	call	memset@PLT
	movq	%rax, %r10
.L293:
	movq	128(%rsp), %rax
	leaq	16(%r10), %rdx
	movq	%r10, %r14
	movl	$100, %r13d
	movq	$-1, %r12
	movq	%rbx, 8(%rax)
	movq	120(%rsp), %rax
	movq	(%rax), %r8
	movq	8(%rax), %r9
	leaq	2(%r8), %rax
	movq	%r9, %rbx
	leaq	16(%r8), %rcx
	subq	%rax, %rbx
	movq	%rax, 96(%rsp)
	movq	%rbx, %rax
	shrq	%rax
	addq	$1, %rax
	cmpq	%rdx, %r8
	setnb	%dl
	cmpq	%rcx, %r10
	movq	%rax, %rdi
	setnb	%cl
	orl	%ecx, %edx
	cmpq	$14, %rax
	seta	%cl
	addq	%rax, %rax
	shrq	%r14
	movq	%rax, 88(%rsp)
	leaq	2(%r10), %rax
	negq	%r14
	andl	$7, %r14d
	andl	%ecx, %edx
	movq	%rax, 32(%rsp)
	leaq	4(%r8), %rax
	subq	%r14, %rdi
	movq	%rdi, %rbp
	leaq	(%r14,%r14), %r11
	movq	%rdi, 16(%rsp)
	movq	%rax, 40(%rsp)
	leaq	4(%r10), %rax
	andq	$-8, %rdi
	leaq	(%rdi,%rdi), %r15
	leaq	(%r10,%r11), %rbx
	movb	%dl, 8(%rsp)
	movq	%rax, 48(%rsp)
	leaq	6(%r8), %rax
	shrq	$3, %rbp
	addq	%r8, %r11
	movq	%rdi, 24(%rsp)
	movq	%rax, 56(%rsp)
	leaq	6(%r10), %rax
	movq	%rax, 64(%rsp)
	leaq	8(%r8), %rax
	movq	%rax, 72(%rsp)
	leaq	8(%r10), %rax
	movq	%rax, 80(%rsp)
	.p2align 4,,10
	.p2align 3
.L212:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%edx, %esi
	movl	%eax, %eax
	salq	$32, %rsi
	orq	%rax, %rsi
	cmpq	%r9, %r8
	je	.L205
	cmpb	$0, 8(%rsp)
	je	.L301
	testq	%r14, %r14
	je	.L302
	movzwl	(%r10), %eax
	cmpq	$1, %r14
	movq	32(%rsp), %rdi
	movw	%ax, (%r8)
	je	.L303
	movzwl	2(%r10), %eax
	cmpq	$2, %r14
	movq	40(%rsp), %rdx
	movq	48(%rsp), %rdi
	movw	%ax, 2(%r8)
	je	.L207
	movzwl	4(%r10), %eax
	cmpq	$3, %r14
	movq	56(%rsp), %rdx
	movq	64(%rsp), %rdi
	movw	%ax, 4(%r8)
	je	.L207
	movzwl	6(%r10), %eax
	cmpq	$4, %r14
	movq	72(%rsp), %rdx
	movq	80(%rsp), %rdi
	movw	%ax, 6(%r8)
	je	.L207
	movzwl	8(%r10), %eax
	cmpq	$5, %r14
	leaq	10(%r8), %rdx
	leaq	10(%r10), %rdi
	movw	%ax, 8(%r8)
	je	.L207
	movzwl	10(%r10), %eax
	cmpq	$7, %r14
	leaq	12(%r8), %rdx
	leaq	12(%r10), %rdi
	movw	%ax, 10(%r8)
	jne	.L207
	movzwl	12(%r10), %eax
	leaq	14(%r8), %rdx
	leaq	14(%r10), %rdi
	movw	%ax, 12(%r8)
.L207:
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L209:
	movdqa	(%rbx,%rax), %xmm0
	addq	$1, %rcx
	movups	%xmm0, (%r11,%rax)
	addq	$16, %rax
	cmpq	%rcx, %rbp
	ja	.L209
	addq	%r15, %rdi
	addq	%r15, %rdx
	movq	24(%rsp), %rcx
	cmpq	%rcx, 16(%rsp)
	je	.L205
	movzwl	(%rdi), %eax
	movw	%ax, (%rdx)
	leaq	2(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	2(%rdi), %eax
	movw	%ax, 2(%rdx)
	leaq	4(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	4(%rdi), %eax
	movw	%ax, 4(%rdx)
	leaq	6(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	6(%rdi), %eax
	movw	%ax, 6(%rdx)
	leaq	8(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	8(%rdi), %eax
	movw	%ax, 8(%rdx)
	leaq	10(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	10(%rdi), %eax
	movw	%ax, 10(%rdx)
	leaq	12(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	12(%rdi), %eax
	movw	%ax, 12(%rdx)
	leaq	14(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	14(%rdi), %eax
	movw	%ax, 14(%rdx)
	leaq	16(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	16(%rdi), %eax
	movw	%ax, 16(%rdx)
	leaq	18(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	18(%rdi), %eax
	movw	%ax, 18(%rdx)
	leaq	20(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	20(%rdi), %eax
	movw	%ax, 20(%rdx)
	leaq	22(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	22(%rdi), %eax
	movw	%ax, 22(%rdx)
	leaq	24(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	24(%rdi), %eax
	movw	%ax, 24(%rdx)
	leaq	26(%rdx), %rax
	cmpq	%rax, %r9
	je	.L205
	movzwl	26(%rdi), %eax
	movw	%ax, 26(%rdx)
	.p2align 4,,10
	.p2align 3
.L205:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%eax, %ecx
	movq	%rdx, %rax
	salq	$32, %rax
	orq	%rcx, %rax
	subq	%rsi, %rax
	cmpq	%rax, %r12
	cmova	%rax, %r12
	subq	$1, %r13
	jne	.L212
	movq	136(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB14:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rbx
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	240(%rbx,%rax), %rbp
	testq	%rbp, %rbp
	je	.L218
	cmpb	$0, 56(%rbp)
	je	.L214
	movsbl	67(%rbp), %esi
.L215:
	movq	%rbx, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm4, %xmm4
	testq	%r12, %r12
	cvtsi2sdq	104(%rsp), %xmm4
	movsd	%xmm4, 24(%rsp)
	js	.L216
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r12, %xmm0
.L217:
	divsd	24(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	120(%rsp), %rbx
	movq	%rax, %rdi
	movq	(%rbx), %rdx
	movl	200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	128(%rsp), %rbx
	movq	%rax, %rdi
	movq	(%rbx), %rdx
	movl	200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L218
	cmpb	$0, 56(%rbx)
	je	.L219
	movsbl	67(%rbx), %esi
.L220:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	120(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L221
	call	_ZdlPv@PLT
.L221:
	movq	120(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	128(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L222
	call	_ZdlPv@PLT
.L222:
	movq	128(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE14:
	cmpq	$0, 104(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L223
	movq	112(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB15:
	call	_Znwm@PLT
.LEHE15:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%rbp)
	call	memset@PLT
.L294:
	movq	%rbx, 8(%rbp)
	movl	$24, %edi
.LEHB16:
	call	_Znwm@PLT
.LEHE16:
	cmpq	$0, 104(%rsp)
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L224
	movq	112(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB17:
	call	_Znwm@PLT
.LEHE17:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%r13)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r13)
	call	memset@PLT
.L295:
	movq	%rbx, 8(%r13)
	movl	$100, %r12d
	movq	$-1, %r14
	jmp	.L237
	.p2align 4,,10
	.p2align 3
.L418:
	cmpq	%rsi, %r8
	je	.L413
	movq	%r15, %rdx
	movq	%rcx, %rdi
	call	memmove@PLT
	addq	0(%rbp), %r15
	.p2align 4,,10
	.p2align 3
.L232:
	movq	%r15, 8(%rbp)
.L225:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rbx, %rax
	cmpq	%rax, %r14
	cmova	%rax, %r14
	subq	$1, %r12
	je	.L416
.L237:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%rdx, %rbx
	orq	%rax, %rbx
	cmpq	%r13, %rbp
	je	.L225
	movq	8(%r13), %r8
	movq	0(%r13), %rsi
	movq	0(%rbp), %rcx
	movq	16(%rbp), %rax
	movq	%r8, %r15
	subq	%rsi, %r15
	subq	%rcx, %rax
	movq	%r15, %r9
	sarq	%rax
	sarq	%r9
	cmpq	%rax, %r9
	ja	.L417
	movq	8(%rbp), %rdi
	movq	%rdi, %rdx
	subq	%rcx, %rdx
	movq	%rdx, %rax
	sarq	%rax
	cmpq	%rax, %r9
	jbe	.L418
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L235
	movq	%rcx, %rdi
	call	memmove@PLT
	movq	8(%rbp), %rdi
	movq	0(%rbp), %rcx
	movq	8(%r13), %r8
	movq	%rdi, %rax
	subq	%rcx, %rax
	addq	0(%r13), %rax
.L235:
	cmpq	%rax, %r8
	je	.L413
	movq	%r8, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	addq	0(%rbp), %r15
	jmp	.L232
	.p2align 4,,10
	.p2align 3
.L413:
	addq	%rcx, %r15
	jmp	.L232
	.p2align 4,,10
	.p2align 3
.L417:
	testq	%r9, %r9
	je	.L228
	testq	%r15, %r15
	js	.L268
	movq	%r15, %rdi
	movq	%r8, 16(%rsp)
	movq	%rsi, 8(%rsp)
.LEHB18:
	call	_Znwm@PLT
	movq	0(%rbp), %rcx
	movq	16(%rsp), %r8
	movq	%rax, %r9
	movq	8(%rsp), %rsi
.L228:
	cmpq	%rsi, %r8
	je	.L230
	movq	%r9, %rdi
	movq	%r15, %rdx
	movq	%rcx, 8(%rsp)
	call	memmove@PLT
	movq	8(%rsp), %rcx
	movq	%rax, %r9
.L230:
	testq	%rcx, %rcx
	je	.L231
	movq	%rcx, %rdi
	movq	%r9, 8(%rsp)
	call	_ZdlPv@PLT
	movq	8(%rsp), %r9
.L231:
	addq	%r9, %r15
	movq	%r9, 0(%rbp)
	movq	%r15, 16(%rbp)
	jmp	.L232
	.p2align 4,,10
	.p2align 3
.L301:
	movq	88(%rsp), %rcx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L206:
	movzwl	(%r10,%rax), %edx
	movw	%dx, (%r8,%rax)
	addq	$2, %rax
	cmpq	%rcx, %rax
	jne	.L206
	jmp	.L205
	.p2align 4,,10
	.p2align 3
.L303:
	movq	96(%rsp), %rdx
	jmp	.L207
	.p2align 4,,10
	.p2align 3
.L302:
	movq	%r8, %rdx
	movq	%r10, %rdi
	jmp	.L207
.L416:
	testq	%r14, %r14
	js	.L238
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r14, %xmm0
.L239:
	divsd	24(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	0(%rbp), %rdx
	movq	%rax, %rdi
	movl	200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	0(%r13), %rdx
	movq	%rax, %rdi
	movl	200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L218
	cmpb	$0, 56(%rbx)
	je	.L240
	movsbl	67(%rbx), %esi
.L241:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L242
	call	_ZdlPv@PLT
.L242:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L243
	call	_ZdlPv@PLT
.L243:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE18:
	cmpq	$0, 104(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L244
	movq	112(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB19:
	call	_Znwm@PLT
.LEHE19:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%rbp)
	call	memset@PLT
.L296:
	movq	%rbx, 8(%rbp)
	movl	$24, %edi
.LEHB20:
	call	_Znwm@PLT
.LEHE20:
	cmpq	$0, 104(%rsp)
	movq	%rax, %r14
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L245
	movq	112(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB21:
	call	_Znwm@PLT
.LEHE21:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, (%r14)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r14)
	call	memset@PLT
.L297:
	movabsq	$9223372036854775807, %rax
	leaq	144(%rsp), %r15
	movq	%rbx, 8(%r14)
	movq	%rax, 16(%rsp)
	movl	$100, %ebx
	movq	%rax, 8(%rsp)
	.p2align 4,,10
	.p2align 3
.L255:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	0(%rbp), %rax
	movq	8(%rbp), %r9
	movq	144(%rsp), %r12
	movq	152(%rsp), %r13
	movq	(%r14), %rdx
	cmpq	%r9, %rax
	je	.L246
	leaq	2(%rax), %r11
	movq	%r9, %rdi
	leaq	16(%rdx), %rcx
	subq	%r11, %rdi
	shrq	%rdi
	addq	$1, %rdi
	cmpq	%rcx, %rax
	leaq	16(%rax), %rcx
	setnb	%sil
	cmpq	%rcx, %rdx
	setnb	%cl
	orb	%cl, %sil
	je	.L247
	cmpq	$14, %rdi
	jbe	.L247
	movq	%rdx, %rsi
	shrq	%rsi
	negq	%rsi
	andl	$7, %esi
	je	.L307
	movzwl	(%rdx), %ecx
	cmpq	$1, %rsi
	leaq	2(%rdx), %r8
	movw	%cx, (%rax)
	je	.L248
	movzwl	2(%rdx), %ecx
	cmpq	$2, %rsi
	leaq	4(%rax), %r11
	leaq	4(%rdx), %r8
	movw	%cx, 2(%rax)
	je	.L248
	movzwl	4(%rdx), %ecx
	cmpq	$3, %rsi
	leaq	6(%rax), %r11
	leaq	6(%rdx), %r8
	movw	%cx, 4(%rax)
	je	.L248
	movzwl	6(%rdx), %ecx
	cmpq	$4, %rsi
	leaq	8(%rax), %r11
	leaq	8(%rdx), %r8
	movw	%cx, 6(%rax)
	je	.L248
	movzwl	8(%rdx), %ecx
	cmpq	$5, %rsi
	leaq	10(%rax), %r11
	leaq	10(%rdx), %r8
	movw	%cx, 8(%rax)
	je	.L248
	movzwl	10(%rdx), %ecx
	cmpq	$7, %rsi
	leaq	12(%rax), %r11
	leaq	12(%rdx), %r8
	movw	%cx, 10(%rax)
	jne	.L248
	movzwl	12(%rdx), %ecx
	leaq	14(%rax), %r11
	leaq	14(%rdx), %r8
	movw	%cx, 12(%rax)
.L248:
	subq	%rsi, %rdi
	addq	%rsi, %rsi
	xorl	%ecx, %ecx
	movq	%rdi, %r10
	addq	%rsi, %rdx
	addq	%rax, %rsi
	shrq	$3, %r10
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L250:
	movdqa	(%rdx,%rax), %xmm0
	addq	$1, %rcx
	movups	%xmm0, (%rsi,%rax)
	addq	$16, %rax
	cmpq	%rcx, %r10
	ja	.L250
	movq	%rdi, %rax
	andq	$-8, %rax
	leaq	(%rax,%rax), %rdx
	addq	%rdx, %r8
	addq	%rdx, %r11
	cmpq	%rdi, %rax
	je	.L246
	movzwl	(%r8), %eax
	movw	%ax, (%r11)
	leaq	2(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	2(%r8), %eax
	movw	%ax, 2(%r11)
	leaq	4(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	4(%r8), %eax
	movw	%ax, 4(%r11)
	leaq	6(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	6(%r8), %eax
	movw	%ax, 6(%r11)
	leaq	8(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	8(%r8), %eax
	movw	%ax, 8(%r11)
	leaq	10(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	10(%r8), %eax
	movw	%ax, 10(%r11)
	leaq	12(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	12(%r8), %eax
	movw	%ax, 12(%r11)
	leaq	14(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	14(%r8), %eax
	movw	%ax, 14(%r11)
	leaq	16(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	16(%r8), %eax
	movw	%ax, 16(%r11)
	leaq	18(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	18(%r8), %eax
	movw	%ax, 18(%r11)
	leaq	20(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	20(%r8), %eax
	movw	%ax, 20(%r11)
	leaq	22(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	22(%r8), %eax
	movw	%ax, 22(%r11)
	leaq	24(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	24(%r8), %eax
	movw	%ax, 24(%r11)
	leaq	26(%r11), %rax
	cmpq	%rax, %r9
	je	.L246
	movzwl	26(%r8), %eax
	movw	%ax, 26(%r11)
	.p2align 4,,10
	.p2align 3
.L246:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	152(%rsp), %rax
	movq	144(%rsp), %rdx
	subq	%r13, %rax
	subq	%r12, %rdx
	movq	%rax, %rcx
	movq	%rdx, %rsi
	shrq	$63, %rcx
	subq	%rcx, %rsi
	cmpq	8(%rsp), %rsi
	jg	.L254
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	16(%rsp), %rcx
	jg	.L254
	movq	%rcx, 16(%rsp)
	movq	%rsi, 8(%rsp)
.L254:
	subq	$1, %rbx
	jne	.L255
	movq	136(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB22:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	movq	%rax, %rbx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	0(%rbp), %rax
	movq	%rbx, %rdi
	movl	200(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%r14), %rdx
	movq	%rax, %rdi
	movl	200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L218
	cmpb	$0, 56(%rbx)
	je	.L256
	movsbl	67(%rbx), %esi
.L257:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm2
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	16(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	8(%rsp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L218
	cmpb	$0, 56(%rbx)
	je	.L258
	movsbl	67(%rbx), %esi
.L259:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L260
	call	_ZdlPv@PLT
.L260:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	je	.L261
	call	_ZdlPv@PLT
.L261:
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE22:
	cmpq	$0, 104(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L262
	movq	112(%rsp), %r14
	movq	%r14, %rdi
.LEHB23:
	call	_Znwm@PLT
.LEHE23:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%rbx)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%rbx)
	call	memset@PLT
.L298:
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB24:
	call	_Znwm@PLT
.LEHE24:
	cmpq	$0, 104(%rsp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L263
	movq	112(%rsp), %r14
	movq	%r14, %rdi
.LEHB25:
	call	_Znwm@PLT
.LEHE25:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%r12)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%r12)
	call	memset@PLT
.L299:
	movabsq	$9223372036854775807, %rax
	movq	%rbp, 8(%r12)
	movq	$100, 16(%rsp)
	movq	%rax, 24(%rsp)
	movq	%rax, 8(%rsp)
	jmp	.L277
	.p2align 4,,10
	.p2align 3
.L421:
	cmpq	%rsi, %r9
	je	.L414
	movq	%rbp, %rdx
	movq	%r8, %rdi
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%rbp, %rax
	.p2align 4,,10
	.p2align 3
.L271:
	movq	%rax, 8(%rbx)
.L264:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	152(%rsp), %rax
	movq	144(%rsp), %rsi
	subq	%r14, %rax
	subq	%r13, %rsi
	movq	%rax, %rdx
	shrq	$63, %rdx
	subq	%rdx, %rsi
	cmpq	8(%rsp), %rsi
	jg	.L276
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	24(%rsp), %rcx
	jg	.L276
	movq	%rcx, 24(%rsp)
	movq	%rsi, 8(%rsp)
.L276:
	subq	$1, 16(%rsp)
	je	.L419
.L277:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	cmpq	%r12, %rbx
	movq	144(%rsp), %r13
	movq	152(%rsp), %r14
	je	.L264
	movq	8(%r12), %r9
	movq	(%r12), %rsi
	movq	(%rbx), %r8
	movq	16(%rbx), %rax
	movq	%r9, %rbp
	subq	%rsi, %rbp
	subq	%r8, %rax
	movq	%rbp, %r10
	sarq	%rax
	sarq	%r10
	cmpq	%rax, %r10
	ja	.L420
	movq	8(%rbx), %rdi
	movq	%rdi, %rdx
	subq	%r8, %rdx
	movq	%rdx, %rax
	sarq	%rax
	cmpq	%rax, %r10
	jbe	.L421
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L274
	movq	%r8, %rdi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r8
	movq	8(%r12), %r9
	movq	%rdi, %rax
	subq	%r8, %rax
	addq	(%r12), %rax
.L274:
	cmpq	%rax, %r9
	je	.L414
	movq	%r9, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%rbp, %rax
	jmp	.L271
	.p2align 4,,10
	.p2align 3
.L414:
	leaq	(%r8,%rbp), %rax
	jmp	.L271
	.p2align 4,,10
	.p2align 3
.L420:
	testq	%r10, %r10
	je	.L267
	testq	%rbp, %rbp
	movq	%rsi, 40(%rsp)
	movq	%r9, 32(%rsp)
	js	.L268
	movq	%rbp, %rdi
.LEHB26:
	call	_Znwm@PLT
	movq	(%rbx), %r8
	movq	40(%rsp), %rsi
	movq	%rax, %r10
	movq	32(%rsp), %r9
.L267:
	cmpq	%rsi, %r9
	je	.L269
	movq	%r10, %rdi
	movq	%rbp, %rdx
	movq	%r8, 32(%rsp)
	call	memmove@PLT
	movq	32(%rsp), %r8
	movq	%rax, %r10
.L269:
	testq	%r8, %r8
	je	.L270
	movq	%r8, %rdi
	movq	%r10, 32(%rsp)
	call	_ZdlPv@PLT
	movq	32(%rsp), %r10
.L270:
	leaq	(%r10,%rbp), %rax
	movq	%r10, (%rbx)
	movq	%rax, 16(%rbx)
	jmp	.L271
	.p2align 4,,10
	.p2align 3
.L247:
	addq	%rdi, %rdi
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L252:
	movzwl	(%rdx,%rcx), %esi
	movw	%si, (%rax,%rcx)
	addq	$2, %rcx
	cmpq	%rdi, %rcx
	jne	.L252
	jmp	.L246
	.p2align 4,,10
	.p2align 3
.L307:
	movq	%rax, %r11
	movq	%rdx, %r8
	jmp	.L248
.L419:
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm3
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	24(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	8(%rsp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L218
	cmpb	$0, 56(%rbp)
	je	.L278
	movsbl	67(%rbp), %esi
.L279:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movl	200(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%r12), %rdx
	movq	%rax, %rdi
	movl	200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L218
	cmpb	$0, 56(%rbp)
	je	.L280
	movsbl	67(%rbp), %esi
.L281:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L282
	call	_ZdlPv@PLT
.L282:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L283
	call	_ZdlPv@PLT
.L283:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	168(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L422
	addq	$184, %rsp
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
.L214:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L215
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L215
.L219:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L220
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L220
.L280:
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
.L278:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L279
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L279
.L216:
	movq	%r12, %rdx
	pxor	%xmm0, %xmm0
	shrq	%rdx
	andl	$1, %r12d
	orq	%r12, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L217
.L238:
	movq	%r14, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r14d
	orq	%r14, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L239
.L258:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L259
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L259
.L256:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L257
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L257
.L240:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L241
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L241
.L203:
	xorl	%ebx, %ebx
	jmp	.L292
.L204:
	xorl	%r10d, %r10d
	xorl	%ebx, %ebx
	jmp	.L293
.L263:
	xorl	%ebp, %ebp
	jmp	.L299
.L223:
	xorl	%ebx, %ebx
	jmp	.L294
.L262:
	xorl	%ebp, %ebp
	jmp	.L298
.L224:
	xorl	%ebx, %ebx
	jmp	.L295
.L245:
	xorl	%ebx, %ebx
	jmp	.L297
.L244:
	xorl	%ebx, %ebx
	jmp	.L296
.L321:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L422:
	call	__stack_chk_fail@PLT
.L316:
.L415:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L319:
	movq	%rax, %rbx
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L268:
	call	_ZSt17__throw_bad_allocv@PLT
.L218:
	call	_ZSt16__throw_bad_castv@PLT
.L317:
	movq	%rax, %rbx
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L318:
	jmp	.L415
.L315:
	movq	128(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L320:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
	call	_Unwind_Resume@PLT
.L314:
	movq	120(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.LEHE26:
	.cfi_endproc
.LFE7305:
	.section	.gcc_except_table._Z4funcIsEvm,"aG",@progbits,_Z4funcIsEvm,comdat
.LLSDA7305:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7305-.LLSDACSB7305
.LLSDACSB7305:
	.uleb128 .LEHB10-.LFB7305
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB11-.LFB7305
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L314-.LFB7305
	.uleb128 0
	.uleb128 .LEHB12-.LFB7305
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB13-.LFB7305
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L315-.LFB7305
	.uleb128 0
	.uleb128 .LEHB14-.LFB7305
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB15-.LFB7305
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L316-.LFB7305
	.uleb128 0
	.uleb128 .LEHB16-.LFB7305
	.uleb128 .LEHE16-.LEHB16
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB17-.LFB7305
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L317-.LFB7305
	.uleb128 0
	.uleb128 .LEHB18-.LFB7305
	.uleb128 .LEHE18-.LEHB18
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB19-.LFB7305
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L318-.LFB7305
	.uleb128 0
	.uleb128 .LEHB20-.LFB7305
	.uleb128 .LEHE20-.LEHB20
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB21-.LFB7305
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L319-.LFB7305
	.uleb128 0
	.uleb128 .LEHB22-.LFB7305
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB23-.LFB7305
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L320-.LFB7305
	.uleb128 0
	.uleb128 .LEHB24-.LFB7305
	.uleb128 .LEHE24-.LEHB24
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB25-.LFB7305
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L321-.LFB7305
	.uleb128 0
	.uleb128 .LEHB26-.LFB7305
	.uleb128 .LEHE26-.LEHB26
	.uleb128 0
	.uleb128 0
.LLSDACSE7305:
	.section	.text._Z4funcIsEvm,"axG",@progbits,_Z4funcIsEvm,comdat
	.size	_Z4funcIsEvm, .-_Z4funcIsEvm
	.section	.text._Z4funcIiEvm,"axG",@progbits,_Z4funcIiEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIiEvm
	.type	_Z4funcIiEvm, @function
_Z4funcIiEvm:
.LFB7306:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7306
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
	subq	$168, %rsp
	.cfi_def_cfa_offset 224
	movq	%rdi, 120(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 152(%rsp)
	xorl	%eax, %eax
.LEHB27:
	call	_Znwm@PLT
.LEHE27:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movq	%rax, 104(%rsp)
	movl	$104857600, %eax
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	divq	%r15
	movq	$0, 16(%rbx)
	leaq	0(,%rax,4), %rdx
	testq	%rax, %rax
	movq	%rax, 88(%rsp)
	movq	%rdx, 96(%rsp)
	je	.L424
	movq	%rdx, %rdi
	movq	%rdx, %r15
.LEHB28:
	call	_Znwm@PLT
.LEHE28:
	movq	%rbx, %rdi
	movq	%rax, (%rbx)
	leaq	(%rax,%r15), %rbx
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rbx, 16(%rdi)
	movq	%rax, %rdi
	call	memset@PLT
.L513:
	movq	104(%rsp), %rax
	movl	$24, %edi
	movq	%rbx, 8(%rax)
.LEHB29:
	call	_Znwm@PLT
.LEHE29:
	cmpq	$0, 88(%rsp)
	movq	%rax, %rbx
	movq	%rax, 112(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L425
	movq	96(%rsp), %r15
	movq	%r15, %rdi
.LEHB30:
	call	_Znwm@PLT
.LEHE30:
	movq	%rax, %r13
	movq	%rbx, %rax
	movq	%r15, %rdx
	movq	%r13, (%rbx)
	leaq	0(%r13,%r15), %rbx
	xorl	%esi, %esi
	movq	%r13, %rdi
	movq	%rbx, 16(%rax)
	call	memset@PLT
.L514:
	movq	112(%rsp), %rax
	leaq	16(%r13), %rdx
	movq	%r13, %r14
	movl	$100, %ebp
	movq	%rbx, 8(%rax)
	movq	104(%rsp), %rax
	movq	(%rax), %r11
	movq	8(%rax), %r12
	leaq	4(%r11), %rax
	movq	%r12, %rbx
	leaq	16(%r11), %rcx
	subq	%rax, %rbx
	movq	%rax, 32(%rsp)
	movq	%rbx, %rax
	shrq	$2, %rax
	addq	$1, %rax
	cmpq	%rdx, %r11
	setnb	%dl
	cmpq	%rcx, %r13
	movq	%rax, %rbx
	setnb	%cl
	orl	%ecx, %edx
	cmpq	$12, %rax
	seta	%cl
	salq	$2, %rax
	shrq	$2, %r14
	movq	%rax, 80(%rsp)
	leaq	4(%r13), %rax
	negq	%r14
	andl	$3, %r14d
	andl	%ecx, %edx
	movq	%rax, 40(%rsp)
	leaq	8(%r11), %rax
	subq	%r14, %rbx
	leaq	0(,%r14,4), %r8
	movq	%rbx, %r10
	movq	%rbx, 16(%rsp)
	movq	%rax, 48(%rsp)
	leaq	8(%r13), %rax
	andq	$-4, %rbx
	leaq	0(%r13,%r8), %r9
	movq	%rbx, 24(%rsp)
	leaq	0(,%rbx,4), %r15
	movq	%rax, 56(%rsp)
	leaq	12(%r11), %rax
	movb	%dl, 8(%rsp)
	shrq	$2, %r10
	addq	%r11, %r8
	movq	$-1, %rbx
	movq	%rax, 64(%rsp)
	leaq	12(%r13), %rax
	movq	%rax, 72(%rsp)
	.p2align 4,,10
	.p2align 3
.L433:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%edx, %esi
	movl	%eax, %eax
	salq	$32, %rsi
	orq	%rax, %rsi
	cmpq	%r12, %r11
	je	.L426
	cmpb	$0, 8(%rsp)
	je	.L522
	testq	%r14, %r14
	je	.L523
	movl	0(%r13), %eax
	cmpq	$1, %r14
	movq	40(%rsp), %rdi
	movq	32(%rsp), %rdx
	movl	%eax, (%r11)
	je	.L428
	movl	4(%r13), %eax
	cmpq	$3, %r14
	movq	48(%rsp), %rdx
	movq	56(%rsp), %rdi
	movl	%eax, 4(%r11)
	jne	.L428
	movl	8(%r13), %eax
	movq	64(%rsp), %rdx
	movq	72(%rsp), %rdi
	movl	%eax, 8(%r11)
.L428:
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L430:
	movdqa	(%r9,%rax), %xmm0
	addq	$1, %rcx
	movups	%xmm0, (%r8,%rax)
	addq	$16, %rax
	cmpq	%rcx, %r10
	ja	.L430
	addq	%r15, %rdi
	addq	%r15, %rdx
	movq	24(%rsp), %rcx
	cmpq	%rcx, 16(%rsp)
	je	.L426
	movl	(%rdi), %eax
	movl	%eax, (%rdx)
	leaq	4(%rdx), %rax
	cmpq	%rax, %r12
	je	.L426
	movl	4(%rdi), %eax
	movl	%eax, 4(%rdx)
	leaq	8(%rdx), %rax
	cmpq	%rax, %r12
	je	.L426
	movl	8(%rdi), %eax
	movl	%eax, 8(%rdx)
	leaq	12(%rdx), %rax
	cmpq	%rax, %r12
	je	.L426
	movl	12(%rdi), %eax
	movl	%eax, 12(%rdx)
	leaq	16(%rdx), %rax
	cmpq	%rax, %r12
	je	.L426
	movl	16(%rdi), %eax
	movl	%eax, 16(%rdx)
	leaq	20(%rdx), %rax
	cmpq	%rax, %r12
	je	.L426
	movl	20(%rdi), %eax
	movl	%eax, 20(%rdx)
.L426:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%eax, %ecx
	movq	%rdx, %rax
	salq	$32, %rax
	orq	%rcx, %rax
	subq	%rsi, %rax
	cmpq	%rax, %rbx
	cmova	%rax, %rbx
	subq	$1, %rbp
	jne	.L433
	movq	120(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB31:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rbp
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	0(%rbp), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %r12
	testq	%r12, %r12
	je	.L439
	cmpb	$0, 56(%r12)
	je	.L435
	movsbl	67(%r12), %esi
.L436:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm4, %xmm4
	testq	%rbx, %rbx
	cvtsi2sdq	88(%rsp), %xmm4
	movsd	%xmm4, 24(%rsp)
	js	.L437
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rbx, %xmm0
.L438:
	divsd	24(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	104(%rsp), %rbx
	movq	%rax, %rdi
	movq	(%rbx), %rdx
	movl	400(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	112(%rsp), %rbx
	movq	%rax, %rdi
	movq	(%rbx), %rdx
	movl	400(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L439
	cmpb	$0, 56(%rbx)
	je	.L440
	movsbl	67(%rbx), %esi
.L441:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	104(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L442
	call	_ZdlPv@PLT
.L442:
	movq	104(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	112(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L443
	call	_ZdlPv@PLT
.L443:
	movq	112(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE31:
	cmpq	$0, 88(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L444
	movq	96(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB32:
	call	_Znwm@PLT
.LEHE32:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%rbp)
	call	memset@PLT
.L515:
	movq	%rbx, 8(%rbp)
	movl	$24, %edi
.LEHB33:
	call	_Znwm@PLT
.LEHE33:
	cmpq	$0, 88(%rsp)
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L445
	movq	96(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB34:
	call	_Znwm@PLT
.LEHE34:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%r13)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r13)
	call	memset@PLT
.L516:
	movq	%rbx, 8(%r13)
	movl	$100, %r12d
	movq	$-1, %r15
	jmp	.L458
	.p2align 4,,10
	.p2align 3
.L616:
	cmpq	%rsi, %r8
	je	.L611
	movq	%r14, %rdx
	movq	%rcx, %rdi
	call	memmove@PLT
	addq	0(%rbp), %r14
	.p2align 4,,10
	.p2align 3
.L453:
	movq	%r14, 8(%rbp)
.L446:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rbx, %rax
	cmpq	%rax, %r15
	cmova	%rax, %r15
	subq	$1, %r12
	je	.L614
.L458:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%rdx, %rbx
	orq	%rax, %rbx
	cmpq	%r13, %rbp
	je	.L446
	movq	8(%r13), %r8
	movq	0(%r13), %rsi
	movq	0(%rbp), %rcx
	movq	16(%rbp), %rax
	movq	%r8, %r14
	subq	%rsi, %r14
	subq	%rcx, %rax
	movq	%r14, %r9
	sarq	$2, %rax
	sarq	$2, %r9
	cmpq	%rax, %r9
	ja	.L615
	movq	8(%rbp), %rdi
	movq	%rdi, %rdx
	subq	%rcx, %rdx
	movq	%rdx, %rax
	sarq	$2, %rax
	cmpq	%rax, %r9
	jbe	.L616
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L456
	movq	%rcx, %rdi
	call	memmove@PLT
	movq	8(%rbp), %rdi
	movq	0(%rbp), %rcx
	movq	8(%r13), %r8
	movq	%rdi, %rax
	subq	%rcx, %rax
	addq	0(%r13), %rax
.L456:
	cmpq	%r8, %rax
	je	.L611
	movq	%r8, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	addq	0(%rbp), %r14
	jmp	.L453
	.p2align 4,,10
	.p2align 3
.L611:
	addq	%rcx, %r14
	jmp	.L453
	.p2align 4,,10
	.p2align 3
.L615:
	testq	%r9, %r9
	je	.L449
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %r9
	ja	.L489
	movq	%r14, %rdi
	movq	%r8, 16(%rsp)
	movq	%rsi, 8(%rsp)
.LEHB35:
	call	_Znwm@PLT
	movq	0(%rbp), %rcx
	movq	16(%rsp), %r8
	movq	%rax, %r9
	movq	8(%rsp), %rsi
.L449:
	cmpq	%rsi, %r8
	je	.L451
	movq	%r9, %rdi
	movq	%r14, %rdx
	movq	%rcx, 8(%rsp)
	call	memmove@PLT
	movq	8(%rsp), %rcx
	movq	%rax, %r9
.L451:
	testq	%rcx, %rcx
	je	.L452
	movq	%rcx, %rdi
	movq	%r9, 8(%rsp)
	call	_ZdlPv@PLT
	movq	8(%rsp), %r9
.L452:
	addq	%r9, %r14
	movq	%r9, 0(%rbp)
	movq	%r14, 16(%rbp)
	jmp	.L453
	.p2align 4,,10
	.p2align 3
.L522:
	movq	80(%rsp), %rcx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L427:
	movl	0(%r13,%rax), %edx
	movl	%edx, (%r11,%rax)
	addq	$4, %rax
	cmpq	%rcx, %rax
	jne	.L427
	jmp	.L426
	.p2align 4,,10
	.p2align 3
.L523:
	movq	%r11, %rdx
	movq	%r13, %rdi
	jmp	.L428
.L614:
	testq	%r15, %r15
	js	.L459
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r15, %xmm0
.L460:
	divsd	24(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	0(%rbp), %rdx
	movq	%rax, %rdi
	movl	400(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	0(%r13), %rdx
	movq	%rax, %rdi
	movl	400(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L439
	cmpb	$0, 56(%rbx)
	je	.L461
	movsbl	67(%rbx), %esi
.L462:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L463
	call	_ZdlPv@PLT
.L463:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L464
	call	_ZdlPv@PLT
.L464:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE35:
	cmpq	$0, 88(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L465
	movq	96(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB36:
	call	_Znwm@PLT
.LEHE36:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%rbp)
	call	memset@PLT
.L517:
	movq	%rbx, 8(%rbp)
	movl	$24, %edi
.LEHB37:
	call	_Znwm@PLT
.LEHE37:
	cmpq	$0, 88(%rsp)
	movq	%rax, %r14
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L466
	movq	96(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB38:
	call	_Znwm@PLT
.LEHE38:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, (%r14)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r14)
	call	memset@PLT
.L518:
	movabsq	$9223372036854775807, %rax
	leaq	128(%rsp), %r15
	movq	%rbx, 8(%r14)
	movq	%rax, 16(%rsp)
	movl	$100, %ebx
	movq	%rax, 8(%rsp)
	.p2align 4,,10
	.p2align 3
.L476:
	movl	$4, %edi
	movq	%r15, %rsi
	call	clock_gettime@PLT
	movq	0(%rbp), %rax
	movq	8(%rbp), %rdi
	movq	128(%rsp), %r12
	movq	136(%rsp), %r13
	movq	(%r14), %r11
	cmpq	%rdi, %rax
	je	.L467
	leaq	4(%rax), %r10
	movq	%rdi, %rsi
	leaq	16(%r11), %rdx
	subq	%r10, %rsi
	shrq	$2, %rsi
	addq	$1, %rsi
	cmpq	%rdx, %rax
	leaq	16(%rax), %rdx
	setnb	%cl
	cmpq	%rdx, %r11
	setnb	%dl
	orb	%dl, %cl
	je	.L468
	cmpq	$12, %rsi
	jbe	.L468
	movq	%r11, %rcx
	shrq	$2, %rcx
	negq	%rcx
	andl	$3, %ecx
	je	.L528
	movl	(%r11), %edx
	cmpq	$1, %rcx
	leaq	4(%r11), %r8
	movl	%edx, (%rax)
	je	.L469
	movl	4(%r11), %edx
	cmpq	$3, %rcx
	leaq	8(%rax), %r10
	leaq	8(%r11), %r8
	movl	%edx, 4(%rax)
	jne	.L469
	movl	8(%r11), %edx
	leaq	12(%rax), %r10
	leaq	12(%r11), %r8
	movl	%edx, 8(%rax)
.L469:
	subq	%rcx, %rsi
	salq	$2, %rcx
	xorl	%edx, %edx
	movq	%rsi, %r9
	addq	%rcx, %r11
	addq	%rax, %rcx
	shrq	$2, %r9
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L471:
	movdqa	(%r11,%rax), %xmm0
	addq	$1, %rdx
	movups	%xmm0, (%rcx,%rax)
	addq	$16, %rax
	cmpq	%rdx, %r9
	ja	.L471
	movq	%rsi, %rax
	andq	$-4, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %r8
	addq	%rdx, %r10
	cmpq	%rsi, %rax
	je	.L467
	movl	(%r8), %eax
	movl	%eax, (%r10)
	leaq	4(%r10), %rax
	cmpq	%rax, %rdi
	je	.L467
	movl	4(%r8), %eax
	movl	%eax, 4(%r10)
	leaq	8(%r10), %rax
	cmpq	%rax, %rdi
	je	.L467
	movl	8(%r8), %eax
	movl	%eax, 8(%r10)
	leaq	12(%r10), %rax
	cmpq	%rax, %rdi
	je	.L467
	movl	12(%r8), %eax
	movl	%eax, 12(%r10)
	leaq	16(%r10), %rax
	cmpq	%rax, %rdi
	je	.L467
	movl	16(%r8), %eax
	movl	%eax, 16(%r10)
	leaq	20(%r10), %rax
	cmpq	%rax, %rdi
	je	.L467
	movl	20(%r8), %eax
	movl	%eax, 20(%r10)
.L467:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	136(%rsp), %rax
	movq	128(%rsp), %rdx
	subq	%r13, %rax
	subq	%r12, %rdx
	movq	%rax, %rcx
	movq	%rdx, %rsi
	shrq	$63, %rcx
	subq	%rcx, %rsi
	cmpq	8(%rsp), %rsi
	jg	.L475
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	16(%rsp), %rcx
	jg	.L475
	movq	%rcx, 16(%rsp)
	movq	%rsi, 8(%rsp)
.L475:
	subq	$1, %rbx
	jne	.L476
	movq	120(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB39:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	movq	%rax, %rbx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	0(%rbp), %rax
	movq	%rbx, %rdi
	movl	400(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%r14), %rdx
	movq	%rax, %rdi
	movl	400(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L439
	cmpb	$0, 56(%rbx)
	je	.L477
	movsbl	67(%rbx), %esi
.L478:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm2
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	16(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	8(%rsp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L439
	cmpb	$0, 56(%rbx)
	je	.L479
	movsbl	67(%rbx), %esi
.L480:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L481
	call	_ZdlPv@PLT
.L481:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	je	.L482
	call	_ZdlPv@PLT
.L482:
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE39:
	cmpq	$0, 88(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L483
	movq	96(%rsp), %r14
	movq	%r14, %rdi
.LEHB40:
	call	_Znwm@PLT
.LEHE40:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%rbx)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%rbx)
	call	memset@PLT
.L519:
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB41:
	call	_Znwm@PLT
.LEHE41:
	cmpq	$0, 88(%rsp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L484
	movq	96(%rsp), %r14
	movq	%r14, %rdi
.LEHB42:
	call	_Znwm@PLT
.LEHE42:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%r12)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%r12)
	call	memset@PLT
.L520:
	movabsq	$9223372036854775807, %rax
	movq	%rbp, 8(%r12)
	movq	$100, 16(%rsp)
	movq	%rax, 24(%rsp)
	movq	%rax, 8(%rsp)
	jmp	.L498
	.p2align 4,,10
	.p2align 3
.L619:
	cmpq	%rsi, %r9
	je	.L612
	movq	%rbp, %rdx
	movq	%r8, %rdi
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%rbp, %rax
	.p2align 4,,10
	.p2align 3
.L492:
	movq	%rax, 8(%rbx)
.L485:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	136(%rsp), %rax
	movq	128(%rsp), %rsi
	subq	%r14, %rax
	subq	%r13, %rsi
	movq	%rax, %rdx
	shrq	$63, %rdx
	subq	%rdx, %rsi
	cmpq	8(%rsp), %rsi
	jg	.L497
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	24(%rsp), %rcx
	jg	.L497
	movq	%rcx, 24(%rsp)
	movq	%rsi, 8(%rsp)
.L497:
	subq	$1, 16(%rsp)
	je	.L617
.L498:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	cmpq	%r12, %rbx
	movq	128(%rsp), %r13
	movq	136(%rsp), %r14
	je	.L485
	movq	8(%r12), %r9
	movq	(%r12), %rsi
	movq	(%rbx), %r8
	movq	16(%rbx), %rax
	movq	%r9, %rbp
	subq	%rsi, %rbp
	subq	%r8, %rax
	movq	%rbp, %r10
	sarq	$2, %rax
	sarq	$2, %r10
	cmpq	%rax, %r10
	ja	.L618
	movq	8(%rbx), %rdi
	movq	%rdi, %rdx
	subq	%r8, %rdx
	movq	%rdx, %rax
	sarq	$2, %rax
	cmpq	%rax, %r10
	jbe	.L619
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L495
	movq	%r8, %rdi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r8
	movq	8(%r12), %r9
	movq	%rdi, %rax
	subq	%r8, %rax
	addq	(%r12), %rax
.L495:
	cmpq	%r9, %rax
	je	.L612
	movq	%r9, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%rbp, %rax
	jmp	.L492
	.p2align 4,,10
	.p2align 3
.L612:
	leaq	(%r8,%rbp), %rax
	jmp	.L492
	.p2align 4,,10
	.p2align 3
.L618:
	testq	%r10, %r10
	je	.L488
	movabsq	$4611686018427387903, %rax
	movq	%rsi, 40(%rsp)
	movq	%r9, 32(%rsp)
	cmpq	%rax, %r10
	ja	.L489
	movq	%rbp, %rdi
.LEHB43:
	call	_Znwm@PLT
	movq	(%rbx), %r8
	movq	40(%rsp), %rsi
	movq	%rax, %r10
	movq	32(%rsp), %r9
.L488:
	cmpq	%rsi, %r9
	je	.L490
	movq	%r10, %rdi
	movq	%rbp, %rdx
	movq	%r8, 32(%rsp)
	call	memmove@PLT
	movq	32(%rsp), %r8
	movq	%rax, %r10
.L490:
	testq	%r8, %r8
	je	.L491
	movq	%r8, %rdi
	movq	%r10, 32(%rsp)
	call	_ZdlPv@PLT
	movq	32(%rsp), %r10
.L491:
	leaq	(%r10,%rbp), %rax
	movq	%r10, (%rbx)
	movq	%rax, 16(%rbx)
	jmp	.L492
	.p2align 4,,10
	.p2align 3
.L528:
	movq	%rax, %r10
	movq	%r11, %r8
	jmp	.L469
	.p2align 4,,10
	.p2align 3
.L468:
	salq	$2, %rsi
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L473:
	movl	(%r11,%rdx), %ecx
	movl	%ecx, (%rax,%rdx)
	addq	$4, %rdx
	cmpq	%rdx, %rsi
	jne	.L473
	jmp	.L467
.L617:
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm3
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	24(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	8(%rsp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L439
	cmpb	$0, 56(%rbp)
	je	.L499
	movsbl	67(%rbp), %esi
.L500:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movl	400(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%r12), %rdx
	movq	%rax, %rdi
	movl	400(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L439
	cmpb	$0, 56(%rbp)
	je	.L501
	movsbl	67(%rbp), %esi
.L502:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L503
	call	_ZdlPv@PLT
.L503:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L504
	call	_ZdlPv@PLT
.L504:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	152(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L620
	addq	$168, %rsp
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
.L435:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L436
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L436
.L440:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L441
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L441
.L501:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L502
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L502
.L499:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L500
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L500
.L437:
	movq	%rbx, %rdx
	pxor	%xmm0, %xmm0
	shrq	%rdx
	andl	$1, %ebx
	orq	%rbx, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L438
.L459:
	movq	%r15, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r15d
	orq	%r15, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L460
.L479:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L480
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L480
.L477:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L478
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L478
.L461:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L462
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L462
.L424:
	xorl	%ebx, %ebx
	jmp	.L513
.L425:
	xorl	%r13d, %r13d
	xorl	%ebx, %ebx
	jmp	.L514
.L484:
	xorl	%ebp, %ebp
	jmp	.L520
.L444:
	xorl	%ebx, %ebx
	jmp	.L515
.L483:
	xorl	%ebp, %ebp
	jmp	.L519
.L445:
	xorl	%ebx, %ebx
	jmp	.L516
.L466:
	xorl	%ebx, %ebx
	jmp	.L518
.L465:
	xorl	%ebx, %ebx
	jmp	.L517
.L542:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L620:
	call	__stack_chk_fail@PLT
.L537:
.L613:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L540:
	movq	%rax, %rbx
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L489:
	call	_ZSt17__throw_bad_allocv@PLT
.L439:
	call	_ZSt16__throw_bad_castv@PLT
.L538:
	movq	%rax, %rbx
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L539:
	jmp	.L613
.L536:
	movq	112(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L541:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
	call	_Unwind_Resume@PLT
.L535:
	movq	104(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.LEHE43:
	.cfi_endproc
.LFE7306:
	.section	.gcc_except_table._Z4funcIiEvm,"aG",@progbits,_Z4funcIiEvm,comdat
.LLSDA7306:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7306-.LLSDACSB7306
.LLSDACSB7306:
	.uleb128 .LEHB27-.LFB7306
	.uleb128 .LEHE27-.LEHB27
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB28-.LFB7306
	.uleb128 .LEHE28-.LEHB28
	.uleb128 .L535-.LFB7306
	.uleb128 0
	.uleb128 .LEHB29-.LFB7306
	.uleb128 .LEHE29-.LEHB29
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB30-.LFB7306
	.uleb128 .LEHE30-.LEHB30
	.uleb128 .L536-.LFB7306
	.uleb128 0
	.uleb128 .LEHB31-.LFB7306
	.uleb128 .LEHE31-.LEHB31
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB32-.LFB7306
	.uleb128 .LEHE32-.LEHB32
	.uleb128 .L537-.LFB7306
	.uleb128 0
	.uleb128 .LEHB33-.LFB7306
	.uleb128 .LEHE33-.LEHB33
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB34-.LFB7306
	.uleb128 .LEHE34-.LEHB34
	.uleb128 .L538-.LFB7306
	.uleb128 0
	.uleb128 .LEHB35-.LFB7306
	.uleb128 .LEHE35-.LEHB35
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB36-.LFB7306
	.uleb128 .LEHE36-.LEHB36
	.uleb128 .L539-.LFB7306
	.uleb128 0
	.uleb128 .LEHB37-.LFB7306
	.uleb128 .LEHE37-.LEHB37
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB38-.LFB7306
	.uleb128 .LEHE38-.LEHB38
	.uleb128 .L540-.LFB7306
	.uleb128 0
	.uleb128 .LEHB39-.LFB7306
	.uleb128 .LEHE39-.LEHB39
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB40-.LFB7306
	.uleb128 .LEHE40-.LEHB40
	.uleb128 .L541-.LFB7306
	.uleb128 0
	.uleb128 .LEHB41-.LFB7306
	.uleb128 .LEHE41-.LEHB41
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB42-.LFB7306
	.uleb128 .LEHE42-.LEHB42
	.uleb128 .L542-.LFB7306
	.uleb128 0
	.uleb128 .LEHB43-.LFB7306
	.uleb128 .LEHE43-.LEHB43
	.uleb128 0
	.uleb128 0
.LLSDACSE7306:
	.section	.text._Z4funcIiEvm,"axG",@progbits,_Z4funcIiEvm,comdat
	.size	_Z4funcIiEvm, .-_Z4funcIiEvm
	.section	.text._Z4funcIlEvm,"axG",@progbits,_Z4funcIlEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIlEvm
	.type	_Z4funcIlEvm, @function
_Z4funcIlEvm:
.LFB7307:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7307
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
	movq	%rdi, 88(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 120(%rsp)
	xorl	%eax, %eax
.LEHB44:
	call	_Znwm@PLT
.LEHE44:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movq	%rax, 72(%rsp)
	movl	$104857600, %eax
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	divq	%r15
	movq	$0, 16(%rbx)
	leaq	0(,%rax,8), %rdx
	testq	%rax, %rax
	movq	%rax, 56(%rsp)
	movq	%rdx, 64(%rsp)
	je	.L622
	movq	%rdx, %rdi
	movq	%rdx, %r15
.LEHB45:
	call	_Znwm@PLT
.LEHE45:
	movq	%rbx, %rdi
	movq	%rax, (%rbx)
	leaq	(%rax,%r15), %rbx
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rbx, 16(%rdi)
	movq	%rax, %rdi
	call	memset@PLT
.L709:
	movq	72(%rsp), %rax
	movl	$24, %edi
	movq	%rbx, 8(%rax)
.LEHB46:
	call	_Znwm@PLT
.LEHE46:
	cmpq	$0, 56(%rsp)
	movq	%rax, %rbx
	movq	%rax, 80(%rsp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L623
	movq	64(%rsp), %r15
	movq	%r15, %rdi
.LEHB47:
	call	_Znwm@PLT
.LEHE47:
	movq	%rax, %r12
	movq	%rbx, %rax
	movq	%r15, %rdx
	movq	%r12, (%rbx)
	leaq	(%r12,%r15), %rbx
	xorl	%esi, %esi
	movq	%r12, %rdi
	movq	%rbx, 16(%rax)
	call	memset@PLT
.L710:
	movq	80(%rsp), %rax
	movl	$100, %r11d
	movq	%rbx, 8(%rax)
	movq	72(%rsp), %rax
	movq	(%rax), %rbp
	movq	8(%rax), %r13
	leaq	8(%rbp), %rax
	movq	%r13, %r15
	leaq	16(%rbp), %rdx
	subq	%rax, %r15
	movq	%rax, 40(%rsp)
	leaq	16(%r12), %rax
	shrq	$3, %r15
	addq	$1, %r15
	cmpq	%rax, %rbp
	setnb	%al
	cmpq	%rdx, %r12
	setnb	%dl
	orl	%edx, %eax
	cmpq	$24, %r15
	seta	%dl
	andl	%edx, %eax
	movb	%al, 8(%rsp)
	movq	%r12, %rax
	shrq	$3, %rax
	andl	$1, %eax
	movq	%rax, %rbx
	movq	%rax, 16(%rsp)
	movq	%r15, %rax
	subq	%rbx, %rax
	leaq	0(,%rbx,8), %r8
	salq	$3, %r15
	movq	%rax, %r10
	movq	%rax, 24(%rsp)
	andq	$-2, %rax
	movq	%rax, 32(%rsp)
	leaq	0(,%rax,8), %r14
	leaq	8(%r12), %rax
	leaq	(%r12,%r8), %r9
	shrq	%r10
	addq	%rbp, %r8
	movq	$-1, %rbx
	movq	%rax, 48(%rsp)
	.p2align 4,,10
	.p2align 3
.L630:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%edx, %esi
	movl	%eax, %eax
	salq	$32, %rsi
	orq	%rax, %rsi
	cmpq	%r13, %rbp
	je	.L624
	cmpb	$0, 8(%rsp)
	je	.L718
	cmpq	$0, 16(%rsp)
	je	.L719
	movq	(%r12), %rax
	movq	48(%rsp), %rdi
	movq	40(%rsp), %rdx
	movq	%rax, 0(%rbp)
.L626:
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L627:
	movdqa	(%r9,%rax), %xmm0
	addq	$1, %rcx
	movups	%xmm0, (%r8,%rax)
	addq	$16, %rax
	cmpq	%r10, %rcx
	jb	.L627
	addq	%r14, %rdi
	addq	%r14, %rdx
	movq	32(%rsp), %rcx
	cmpq	%rcx, 24(%rsp)
	je	.L624
	movq	(%rdi), %rax
	movq	%rax, (%rdx)
	leaq	8(%rdx), %rax
	cmpq	%rax, %r13
	je	.L624
	movq	8(%rdi), %rax
	movq	%rax, 8(%rdx)
.L624:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%eax, %ecx
	movq	%rdx, %rax
	salq	$32, %rax
	orq	%rcx, %rax
	subq	%rsi, %rax
	cmpq	%rax, %rbx
	cmova	%rax, %rbx
	subq	$1, %r11
	jne	.L630
	movq	88(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB48:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rbp
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	0(%rbp), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %r12
	testq	%r12, %r12
	je	.L636
	cmpb	$0, 56(%r12)
	je	.L632
	movsbl	67(%r12), %esi
.L633:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm4, %xmm4
	testq	%rbx, %rbx
	cvtsi2sdq	56(%rsp), %xmm4
	movsd	%xmm4, 24(%rsp)
	js	.L634
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rbx, %xmm0
.L635:
	divsd	24(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	72(%rsp), %rbx
	movq	%rax, %rdi
	movq	(%rbx), %rdx
	movl	800(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	80(%rsp), %rbx
	movq	%rax, %rdi
	movq	(%rbx), %rdx
	movl	800(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %rbp
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbp,%rax), %rbx
	testq	%rbx, %rbx
	je	.L636
	cmpb	$0, 56(%rbx)
	je	.L637
	movsbl	67(%rbx), %esi
.L638:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	72(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L639
	call	_ZdlPv@PLT
.L639:
	movq	72(%rsp), %rdi
	call	_ZdlPv@PLT
	movq	80(%rsp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L640
	call	_ZdlPv@PLT
.L640:
	movq	80(%rsp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE48:
	cmpq	$0, 56(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L641
	movq	64(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB49:
	call	_Znwm@PLT
.LEHE49:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%rbp)
	call	memset@PLT
.L711:
	movq	%rbx, 8(%rbp)
	movl	$24, %edi
.LEHB50:
	call	_Znwm@PLT
.LEHE50:
	cmpq	$0, 56(%rsp)
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L642
	movq	64(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB51:
	call	_Znwm@PLT
.LEHE51:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%r13)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r13)
	call	memset@PLT
.L712:
	movq	%rbx, 8(%r13)
	movl	$100, %r12d
	movq	$-1, %r15
	jmp	.L655
	.p2align 4,,10
	.p2align 3
.L807:
	cmpq	%rsi, %r8
	je	.L802
	movq	%r14, %rdx
	movq	%rcx, %rdi
	call	memmove@PLT
	addq	0(%rbp), %r14
	.p2align 4,,10
	.p2align 3
.L650:
	movq	%r14, 8(%rbp)
.L643:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rbx, %rax
	cmpq	%rax, %r15
	cmova	%rax, %r15
	subq	$1, %r12
	je	.L805
.L655:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%rdx, %rbx
	orq	%rax, %rbx
	cmpq	%r13, %rbp
	je	.L643
	movq	8(%r13), %r8
	movq	0(%r13), %rsi
	movq	0(%rbp), %rcx
	movq	16(%rbp), %rax
	movq	%r8, %r14
	subq	%rsi, %r14
	subq	%rcx, %rax
	movq	%r14, %r9
	sarq	$3, %rax
	sarq	$3, %r9
	cmpq	%rax, %r9
	ja	.L806
	movq	8(%rbp), %rdi
	movq	%rdi, %rdx
	subq	%rcx, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	cmpq	%rax, %r9
	jbe	.L807
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L653
	movq	%rcx, %rdi
	call	memmove@PLT
	movq	8(%rbp), %rdi
	movq	0(%rbp), %rcx
	movq	8(%r13), %r8
	movq	%rdi, %rax
	subq	%rcx, %rax
	addq	0(%r13), %rax
.L653:
	cmpq	%r8, %rax
	je	.L802
	movq	%r8, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	addq	0(%rbp), %r14
	jmp	.L650
	.p2align 4,,10
	.p2align 3
.L802:
	addq	%rcx, %r14
	jmp	.L650
	.p2align 4,,10
	.p2align 3
.L806:
	testq	%r9, %r9
	je	.L646
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %r9
	ja	.L685
	movq	%r14, %rdi
	movq	%r8, 16(%rsp)
	movq	%rsi, 8(%rsp)
.LEHB52:
	call	_Znwm@PLT
	movq	0(%rbp), %rcx
	movq	16(%rsp), %r8
	movq	%rax, %r9
	movq	8(%rsp), %rsi
.L646:
	cmpq	%rsi, %r8
	je	.L648
	movq	%r9, %rdi
	movq	%r14, %rdx
	movq	%rcx, 8(%rsp)
	call	memmove@PLT
	movq	8(%rsp), %rcx
	movq	%rax, %r9
.L648:
	testq	%rcx, %rcx
	je	.L649
	movq	%rcx, %rdi
	movq	%r9, 8(%rsp)
	call	_ZdlPv@PLT
	movq	8(%rsp), %r9
.L649:
	addq	%r9, %r14
	movq	%r9, 0(%rbp)
	movq	%r14, 16(%rbp)
	jmp	.L650
	.p2align 4,,10
	.p2align 3
.L719:
	movq	%rbp, %rdx
	movq	%r12, %rdi
	jmp	.L626
	.p2align 4,,10
	.p2align 3
.L718:
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L625:
	movq	(%r12,%rax), %rdx
	movq	%rdx, 0(%rbp,%rax)
	addq	$8, %rax
	cmpq	%r15, %rax
	jne	.L625
	jmp	.L624
.L805:
	testq	%r15, %r15
	js	.L656
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r15, %xmm0
.L657:
	divsd	24(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	0(%rbp), %rdx
	movq	%rax, %rdi
	movl	800(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	0(%r13), %rdx
	movq	%rax, %rdi
	movl	800(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L636
	cmpb	$0, 56(%rbx)
	je	.L658
	movsbl	67(%rbx), %esi
.L659:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L660
	call	_ZdlPv@PLT
.L660:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L661
	call	_ZdlPv@PLT
.L661:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE52:
	cmpq	$0, 56(%rsp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L662
	movq	64(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB53:
	call	_Znwm@PLT
.LEHE53:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, (%r12)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r12)
	call	memset@PLT
.L713:
	movq	%rbx, 8(%r12)
	movl	$24, %edi
.LEHB54:
	call	_Znwm@PLT
.LEHE54:
	cmpq	$0, 56(%rsp)
	movq	%rax, %r15
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L663
	movq	64(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB55:
	call	_Znwm@PLT
.LEHE55:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, (%r15)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r15)
	call	memset@PLT
.L714:
	movabsq	$9223372036854775807, %rax
	leaq	96(%rsp), %rbp
	movq	%rbx, 8(%r15)
	movq	%rax, 16(%rsp)
	movl	$100, %ebx
	movq	%rax, 8(%rsp)
	.p2align 4,,10
	.p2align 3
.L672:
	movq	%rbp, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	(%r12), %rax
	movq	8(%r12), %r10
	movq	96(%rsp), %r13
	movq	104(%rsp), %r14
	movq	(%r15), %rcx
	cmpq	%r10, %rax
	je	.L664
	leaq	8(%rax), %r8
	movq	%r10, %rdi
	leaq	16(%rcx), %rdx
	subq	%r8, %rdi
	shrq	$3, %rdi
	addq	$1, %rdi
	cmpq	%rdx, %rax
	leaq	16(%rax), %rdx
	setnb	%sil
	cmpq	%rdx, %rcx
	setnb	%dl
	orb	%dl, %sil
	je	.L665
	cmpq	$24, %rdi
	jbe	.L665
	movq	%rcx, %rsi
	shrq	$3, %rsi
	andl	$1, %esi
	je	.L723
	movq	(%rcx), %rdx
	leaq	8(%rcx), %r11
	movq	%rdx, (%rax)
.L666:
	subq	%rsi, %rdi
	salq	$3, %rsi
	xorl	%edx, %edx
	movq	%rdi, %r9
	addq	%rsi, %rcx
	addq	%rax, %rsi
	shrq	%r9
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L667:
	movdqa	(%rcx,%rax), %xmm0
	addq	$1, %rdx
	movups	%xmm0, (%rsi,%rax)
	addq	$16, %rax
	cmpq	%rdx, %r9
	ja	.L667
	movq	%rdi, %rax
	andq	$-2, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %r11
	addq	%rdx, %r8
	cmpq	%rdi, %rax
	je	.L664
	movq	(%r11), %rax
	movq	%rax, (%r8)
	leaq	8(%r8), %rax
	cmpq	%rax, %r10
	je	.L664
	movq	8(%r11), %rax
	movq	%rax, 8(%r8)
.L664:
	movq	%rbp, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	104(%rsp), %rax
	movq	96(%rsp), %rdx
	subq	%r14, %rax
	subq	%r13, %rdx
	movq	%rax, %rcx
	movq	%rdx, %rsi
	shrq	$63, %rcx
	subq	%rcx, %rsi
	cmpq	8(%rsp), %rsi
	jg	.L671
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	16(%rsp), %rcx
	jg	.L671
	movq	%rcx, 16(%rsp)
	movq	%rsi, 8(%rsp)
.L671:
	subq	$1, %rbx
	jne	.L672
	movq	88(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB56:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	movq	%rax, %rbx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rax
	movq	%rbx, %rdi
	movl	800(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%r15), %rdx
	movq	%rax, %rdi
	movl	800(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbx
	testq	%rbx, %rbx
	je	.L636
	cmpb	$0, 56(%rbx)
	je	.L673
	movsbl	67(%rbx), %esi
.L674:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm2
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	16(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	8(%rsp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbx
	testq	%rbx, %rbx
	je	.L636
	cmpb	$0, 56(%rbx)
	je	.L675
	movsbl	67(%rbx), %esi
.L676:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L677
	call	_ZdlPv@PLT
.L677:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	(%r15), %rdi
	testq	%rdi, %rdi
	je	.L678
	call	_ZdlPv@PLT
.L678:
	movq	%r15, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE56:
	cmpq	$0, 56(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L679
	movq	64(%rsp), %r15
	movq	%r15, %rdi
.LEHB57:
	call	_Znwm@PLT
.LEHE57:
	leaq	(%rax,%r15), %r12
	movq	%rax, (%rbx)
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r12, 16(%rbx)
	call	memset@PLT
.L715:
	movq	%r12, 8(%rbx)
	movl	$24, %edi
.LEHB58:
	call	_Znwm@PLT
.LEHE58:
	cmpq	$0, 56(%rsp)
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L680
	movq	64(%rsp), %r15
	movq	%r15, %rdi
.LEHB59:
	call	_Znwm@PLT
.LEHE59:
	leaq	(%rax,%r15), %r12
	movq	%rax, 0(%r13)
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r12, 16(%r13)
	call	memset@PLT
.L716:
	movabsq	$9223372036854775807, %rax
	movq	%r12, 8(%r13)
	movq	$100, 16(%rsp)
	movq	%rax, 24(%rsp)
	movq	%rax, 8(%rsp)
	jmp	.L694
	.p2align 4,,10
	.p2align 3
.L810:
	cmpq	%rsi, %r9
	je	.L803
	movq	%r12, %rdx
	movq	%r8, %rdi
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%r12, %rax
	.p2align 4,,10
	.p2align 3
.L688:
	movq	%rax, 8(%rbx)
.L681:
	movq	%rbp, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	104(%rsp), %rax
	movq	96(%rsp), %rsi
	subq	%r15, %rax
	subq	%r14, %rsi
	movq	%rax, %rdx
	shrq	$63, %rdx
	subq	%rdx, %rsi
	cmpq	8(%rsp), %rsi
	jg	.L693
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	24(%rsp), %rcx
	jg	.L693
	movq	%rcx, 24(%rsp)
	movq	%rsi, 8(%rsp)
.L693:
	subq	$1, 16(%rsp)
	je	.L808
.L694:
	movq	%rbp, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	cmpq	%r13, %rbx
	movq	96(%rsp), %r14
	movq	104(%rsp), %r15
	je	.L681
	movq	8(%r13), %r9
	movq	0(%r13), %rsi
	movq	(%rbx), %r8
	movq	16(%rbx), %rax
	movq	%r9, %r12
	subq	%rsi, %r12
	subq	%r8, %rax
	movq	%r12, %r10
	sarq	$3, %rax
	sarq	$3, %r10
	cmpq	%rax, %r10
	ja	.L809
	movq	8(%rbx), %rdi
	movq	%rdi, %rdx
	subq	%r8, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	cmpq	%rax, %r10
	jbe	.L810
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L691
	movq	%r8, %rdi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r8
	movq	8(%r13), %r9
	movq	%rdi, %rax
	subq	%r8, %rax
	addq	0(%r13), %rax
.L691:
	cmpq	%r9, %rax
	je	.L803
	movq	%r9, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%r12, %rax
	jmp	.L688
	.p2align 4,,10
	.p2align 3
.L803:
	leaq	(%r8,%r12), %rax
	jmp	.L688
	.p2align 4,,10
	.p2align 3
.L809:
	testq	%r10, %r10
	je	.L684
	movabsq	$2305843009213693951, %rax
	movq	%rsi, 40(%rsp)
	movq	%r9, 32(%rsp)
	cmpq	%rax, %r10
	ja	.L685
	movq	%r12, %rdi
.LEHB60:
	call	_Znwm@PLT
	movq	(%rbx), %r8
	movq	40(%rsp), %rsi
	movq	%rax, %r10
	movq	32(%rsp), %r9
.L684:
	cmpq	%rsi, %r9
	je	.L686
	movq	%r10, %rdi
	movq	%r12, %rdx
	movq	%r8, 32(%rsp)
	call	memmove@PLT
	movq	32(%rsp), %r8
	movq	%rax, %r10
.L686:
	testq	%r8, %r8
	je	.L687
	movq	%r8, %rdi
	movq	%r10, 32(%rsp)
	call	_ZdlPv@PLT
	movq	32(%rsp), %r10
.L687:
	leaq	(%r10,%r12), %rax
	movq	%r10, (%rbx)
	movq	%rax, 16(%rbx)
	jmp	.L688
	.p2align 4,,10
	.p2align 3
.L723:
	movq	%rax, %r8
	movq	%rcx, %r11
	jmp	.L666
	.p2align 4,,10
	.p2align 3
.L665:
	salq	$3, %rdi
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L669:
	movq	(%rcx,%rdx), %rsi
	movq	%rsi, (%rax,%rdx)
	addq	$8, %rdx
	cmpq	%rdi, %rdx
	jne	.L669
	jmp	.L664
.L808:
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm3
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	24(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	8(%rsp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L636
	cmpb	$0, 56(%rbp)
	je	.L695
	movsbl	67(%rbp), %esi
.L696:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movl	800(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	0(%r13), %rdx
	movq	%rax, %rdi
	movl	800(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L636
	cmpb	$0, 56(%rbp)
	je	.L697
	movsbl	67(%rbp), %esi
.L698:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L699
	call	_ZdlPv@PLT
.L699:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L700
	call	_ZdlPv@PLT
.L700:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	120(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L811
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
.L632:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L633
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L633
.L637:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L638
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L638
.L697:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L698
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L698
.L695:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L696
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L696
.L634:
	movq	%rbx, %rdx
	pxor	%xmm0, %xmm0
	shrq	%rdx
	andl	$1, %ebx
	orq	%rbx, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L635
.L656:
	movq	%r15, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r15d
	orq	%r15, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L657
.L675:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L676
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L676
.L673:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L674
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L674
.L658:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L659
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L659
.L622:
	xorl	%ebx, %ebx
	jmp	.L709
.L623:
	xorl	%r12d, %r12d
	xorl	%ebx, %ebx
	jmp	.L710
.L680:
	xorl	%r12d, %r12d
	jmp	.L716
.L641:
	xorl	%ebx, %ebx
	jmp	.L711
.L679:
	xorl	%r12d, %r12d
	jmp	.L715
.L642:
	xorl	%ebx, %ebx
	jmp	.L712
.L663:
	xorl	%ebx, %ebx
	jmp	.L714
.L662:
	xorl	%ebx, %ebx
	jmp	.L713
.L737:
.L804:
	movq	%rax, %rbx
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L811:
	call	__stack_chk_fail@PLT
.L732:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L735:
	movq	%rax, %rbx
	movq	%r15, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L685:
	call	_ZSt17__throw_bad_allocv@PLT
.L636:
	call	_ZSt16__throw_bad_castv@PLT
.L733:
	jmp	.L804
.L734:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L731:
	movq	80(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L736:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
	call	_Unwind_Resume@PLT
.L730:
	movq	72(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.LEHE60:
	.cfi_endproc
.LFE7307:
	.section	.gcc_except_table._Z4funcIlEvm,"aG",@progbits,_Z4funcIlEvm,comdat
.LLSDA7307:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7307-.LLSDACSB7307
.LLSDACSB7307:
	.uleb128 .LEHB44-.LFB7307
	.uleb128 .LEHE44-.LEHB44
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB45-.LFB7307
	.uleb128 .LEHE45-.LEHB45
	.uleb128 .L730-.LFB7307
	.uleb128 0
	.uleb128 .LEHB46-.LFB7307
	.uleb128 .LEHE46-.LEHB46
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB47-.LFB7307
	.uleb128 .LEHE47-.LEHB47
	.uleb128 .L731-.LFB7307
	.uleb128 0
	.uleb128 .LEHB48-.LFB7307
	.uleb128 .LEHE48-.LEHB48
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB49-.LFB7307
	.uleb128 .LEHE49-.LEHB49
	.uleb128 .L732-.LFB7307
	.uleb128 0
	.uleb128 .LEHB50-.LFB7307
	.uleb128 .LEHE50-.LEHB50
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB51-.LFB7307
	.uleb128 .LEHE51-.LEHB51
	.uleb128 .L733-.LFB7307
	.uleb128 0
	.uleb128 .LEHB52-.LFB7307
	.uleb128 .LEHE52-.LEHB52
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB53-.LFB7307
	.uleb128 .LEHE53-.LEHB53
	.uleb128 .L734-.LFB7307
	.uleb128 0
	.uleb128 .LEHB54-.LFB7307
	.uleb128 .LEHE54-.LEHB54
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB55-.LFB7307
	.uleb128 .LEHE55-.LEHB55
	.uleb128 .L735-.LFB7307
	.uleb128 0
	.uleb128 .LEHB56-.LFB7307
	.uleb128 .LEHE56-.LEHB56
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB57-.LFB7307
	.uleb128 .LEHE57-.LEHB57
	.uleb128 .L736-.LFB7307
	.uleb128 0
	.uleb128 .LEHB58-.LFB7307
	.uleb128 .LEHE58-.LEHB58
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB59-.LFB7307
	.uleb128 .LEHE59-.LEHB59
	.uleb128 .L737-.LFB7307
	.uleb128 0
	.uleb128 .LEHB60-.LFB7307
	.uleb128 .LEHE60-.LEHB60
	.uleb128 0
	.uleb128 0
.LLSDACSE7307:
	.section	.text._Z4funcIlEvm,"axG",@progbits,_Z4funcIlEvm,comdat
	.size	_Z4funcIlEvm, .-_Z4funcIlEvm
	.section	.text._Z4funcInEvm,"axG",@progbits,_Z4funcInEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcInEvm
	.type	_Z4funcInEvm, @function
_Z4funcInEvm:
.LFB7308:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7308
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
	subq	$88, %rsp
	.cfi_def_cfa_offset 144
	movq	%rdi, 40(%rsp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, 72(%rsp)
	xorl	%eax, %eax
.LEHB61:
	call	_Znwm@PLT
.LEHE61:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movl	$104857600, %eax
	divq	%r15
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	movq	$0, 16(%rbx)
	movq	%rax, %rdx
	movq	%rax, 16(%rsp)
	salq	$4, %rdx
	testq	%rax, %rax
	movq	%rdx, 24(%rsp)
	je	.L813
	movq	%rdx, %rdi
	movq	%rdx, %r15
.LEHB62:
	call	_Znwm@PLT
.LEHE62:
	leaq	(%rax,%r15), %rbp
	movq	%rax, (%rbx)
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%rbx)
	call	memset@PLT
.L891:
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB63:
	call	_Znwm@PLT
.LEHE63:
	cmpq	$0, 16(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L814
	movq	24(%rsp), %r15
	movq	%r15, %rdi
.LEHB64:
	call	_Znwm@PLT
.LEHE64:
	leaq	(%rax,%r15), %r12
	movq	%rax, 0(%rbp)
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r12, 16(%rbp)
	call	memset@PLT
	movq	%rax, %r8
.L892:
	movq	(%rbx), %rsi
	movq	8(%rbx), %r10
	movl	$100, %r9d
	movq	%r12, 8(%rbp)
	movq	$-1, %r13
	leaq	16(%rsi), %rax
	movq	%r10, %rdi
	subq	%rax, %rdi
	movq	%rdi, %rax
	andq	$-16, %rax
	leaq	16(%rax), %rdi
	.p2align 4,,10
	.p2align 3
.L817:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%rdx, %rcx
	orq	%rax, %rcx
	cmpq	%r10, %rsi
	je	.L815
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L816:
	movdqa	(%r8,%rax), %xmm0
	movaps	%xmm0, (%rsi,%rax)
	addq	$16, %rax
	cmpq	%rax, %rdi
	jne	.L816
.L815:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rcx, %rax
	cmpq	%rax, %r13
	cmova	%rax, %r13
	subq	$1, %r9
	jne	.L817
	movq	40(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB65:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %r12
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r14
	testq	%r14, %r14
	je	.L823
	cmpb	$0, 56(%r14)
	je	.L819
	movsbl	67(%r14), %esi
.L820:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm4, %xmm4
	testq	%r13, %r13
	cvtsi2sdq	16(%rsp), %xmm4
	movsd	%xmm4, 32(%rsp)
	js	.L821
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r13, %xmm0
.L822:
	divsd	32(%rsp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	(%rbx), %rdx
	movq	%rax, %rdi
	movl	1600(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	0(%rbp), %rdx
	movq	%rax, %rdi
	movl	1600(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r12
	testq	%r12, %r12
	je	.L823
	cmpb	$0, 56(%r12)
	je	.L824
	movsbl	67(%r12), %esi
.L825:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L826
	call	_ZdlPv@PLT
.L826:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L827
	call	_ZdlPv@PLT
.L827:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE65:
	cmpq	$0, 16(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L828
	movq	24(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB66:
	call	_Znwm@PLT
.LEHE66:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%rbp)
	call	memset@PLT
.L893:
	movq	%rbx, 8(%rbp)
	movl	$24, %edi
.LEHB67:
	call	_Znwm@PLT
.LEHE67:
	cmpq	$0, 16(%rsp)
	movq	%rax, %r13
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L829
	movq	24(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB68:
	call	_Znwm@PLT
.LEHE68:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%r13)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r13)
	call	memset@PLT
.L894:
	movq	%rbx, 8(%r13)
	movl	$100, %r12d
	movq	$-1, %r15
	jmp	.L842
	.p2align 4,,10
	.p2align 3
.L979:
	cmpq	%rsi, %r8
	je	.L973
	movq	%r14, %rdx
	movq	%rcx, %rdi
	call	memmove@PLT
	addq	0(%rbp), %r14
	.p2align 4,,10
	.p2align 3
.L837:
	movq	%r14, 8(%rbp)
.L830:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rbx, %rax
	cmpq	%rax, %r15
	cmova	%rax, %r15
	subq	$1, %r12
	je	.L977
.L842:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%rdx, %rbx
	orq	%rax, %rbx
	cmpq	%r13, %rbp
	je	.L830
	movq	8(%r13), %r8
	movq	0(%r13), %rsi
	movq	0(%rbp), %rcx
	movq	16(%rbp), %rax
	movq	%r8, %r14
	subq	%rsi, %r14
	subq	%rcx, %rax
	movq	%r14, %r9
	sarq	$4, %rax
	sarq	$4, %r9
	cmpq	%rax, %r9
	ja	.L978
	movq	8(%rbp), %rdi
	movq	%rdi, %rdx
	subq	%rcx, %rdx
	movq	%rdx, %rax
	sarq	$4, %rax
	cmpq	%rax, %r9
	jbe	.L979
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L840
	movq	%rcx, %rdi
	call	memmove@PLT
	movq	8(%rbp), %rdi
	movq	0(%rbp), %rcx
	movq	8(%r13), %r8
	movq	%rdi, %rax
	subq	%rcx, %rax
	addq	0(%r13), %rax
.L840:
	cmpq	%r8, %rax
	je	.L973
	movq	%r8, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	addq	0(%rbp), %r14
	jmp	.L837
	.p2align 4,,10
	.p2align 3
.L973:
	addq	%rcx, %r14
	jmp	.L837
	.p2align 4,,10
	.p2align 3
.L978:
	testq	%r9, %r9
	je	.L833
	movabsq	$1152921504606846975, %rax
	cmpq	%rax, %r9
	ja	.L867
	movq	%r14, %rdi
	movq	%r8, 8(%rsp)
	movq	%rsi, (%rsp)
.LEHB69:
	call	_Znwm@PLT
	movq	0(%rbp), %rcx
	movq	8(%rsp), %r8
	movq	%rax, %r9
	movq	(%rsp), %rsi
.L833:
	cmpq	%rsi, %r8
	je	.L835
	movq	%r9, %rdi
	movq	%r14, %rdx
	movq	%rcx, (%rsp)
	call	memmove@PLT
	movq	(%rsp), %rcx
	movq	%rax, %r9
.L835:
	testq	%rcx, %rcx
	je	.L836
	movq	%rcx, %rdi
	movq	%r9, (%rsp)
	call	_ZdlPv@PLT
	movq	(%rsp), %r9
.L836:
	addq	%r9, %r14
	movq	%r9, 0(%rbp)
	movq	%r14, 16(%rbp)
	jmp	.L837
.L977:
	testq	%r15, %r15
	js	.L843
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r15, %xmm0
.L844:
	divsd	32(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	0(%rbp), %rdx
	movq	%rax, %rdi
	movl	1600(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	0(%r13), %rdx
	movq	%rax, %rdi
	movl	1600(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L823
	cmpb	$0, 56(%rbx)
	je	.L845
	movsbl	67(%rbx), %esi
.L846:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L847
	call	_ZdlPv@PLT
.L847:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	0(%r13), %rdi
	testq	%rdi, %rdi
	je	.L848
	call	_ZdlPv@PLT
.L848:
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE69:
	cmpq	$0, 16(%rsp)
	movq	%rax, %rbp
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L849
	movq	24(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB70:
	call	_Znwm@PLT
.LEHE70:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, 0(%rbp)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%rbp)
	call	memset@PLT
.L895:
	movq	%rbx, 8(%rbp)
	movl	$24, %edi
.LEHB71:
	call	_Znwm@PLT
.LEHE71:
	cmpq	$0, 16(%rsp)
	movq	%rax, %r14
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L850
	movq	24(%rsp), %rbx
	movq	%rbx, %rdi
.LEHB72:
	call	_Znwm@PLT
.LEHE72:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, (%r14)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r14)
	call	memset@PLT
.L896:
	movabsq	$9223372036854775807, %rax
	leaq	48(%rsp), %r15
	movq	%rbx, 8(%r14)
	movq	%rax, 8(%rsp)
	movl	$100, %ebx
	movq	%rax, (%rsp)
	.p2align 4,,10
	.p2align 3
.L854:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	0(%rbp), %rdx
	movq	8(%rbp), %rax
	movq	48(%rsp), %r12
	movq	56(%rsp), %r13
	movq	(%r14), %rcx
	cmpq	%rax, %rdx
	je	.L851
	leaq	16(%rdx), %rsi
	subq	%rsi, %rax
	andq	$-16, %rax
	leaq	16(%rax), %rsi
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L852:
	movdqa	(%rcx,%rax), %xmm0
	movaps	%xmm0, (%rdx,%rax)
	addq	$16, %rax
	cmpq	%rax, %rsi
	jne	.L852
.L851:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	56(%rsp), %rax
	movq	48(%rsp), %rsi
	subq	%r13, %rax
	subq	%r12, %rsi
	movq	%rax, %rdx
	shrq	$63, %rdx
	subq	%rdx, %rsi
	cmpq	(%rsp), %rsi
	jg	.L853
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	8(%rsp), %rcx
	jg	.L853
	movq	%rcx, 8(%rsp)
	movq	%rsi, (%rsp)
.L853:
	subq	$1, %rbx
	jne	.L854
	movq	40(%rsp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB73:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	movq	%rax, %rbx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	0(%rbp), %rax
	movq	%rbx, %rdi
	movl	1600(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%r14), %rdx
	movq	%rax, %rdi
	movl	1600(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L823
	cmpb	$0, 56(%rbx)
	je	.L855
	movsbl	67(%rbx), %esi
.L856:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm2
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	8(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	(%rsp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.L823
	cmpb	$0, 56(%rbx)
	je	.L857
	movsbl	67(%rbx), %esi
.L858:
	movq	%r12, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L859
	call	_ZdlPv@PLT
.L859:
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	je	.L860
	call	_ZdlPv@PLT
.L860:
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE73:
	cmpq	$0, 16(%rsp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L861
	movq	24(%rsp), %r14
	movq	%r14, %rdi
.LEHB74:
	call	_Znwm@PLT
.LEHE74:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%rbx)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%rbx)
	call	memset@PLT
.L897:
	movq	%rbp, 8(%rbx)
	movl	$24, %edi
.LEHB75:
	call	_Znwm@PLT
.LEHE75:
	cmpq	$0, 16(%rsp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L862
	movq	24(%rsp), %r14
	movq	%r14, %rdi
.LEHB76:
	call	_Znwm@PLT
.LEHE76:
	leaq	(%rax,%r14), %rbp
	movq	%rax, (%r12)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbp, 16(%r12)
	call	memset@PLT
.L898:
	movabsq	$9223372036854775807, %rax
	movq	%rbp, 8(%r12)
	movq	$100, 8(%rsp)
	movq	%rax, 16(%rsp)
	movq	%rax, (%rsp)
	jmp	.L876
	.p2align 4,,10
	.p2align 3
.L982:
	cmpq	%rsi, %r9
	je	.L974
	movq	%rbp, %rdx
	movq	%r8, %rdi
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%rbp, %rax
	.p2align 4,,10
	.p2align 3
.L870:
	movq	%rax, 8(%rbx)
.L863:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	56(%rsp), %rax
	movq	48(%rsp), %rsi
	subq	%r14, %rax
	subq	%r13, %rsi
	movq	%rax, %rdx
	shrq	$63, %rdx
	subq	%rdx, %rsi
	cmpq	(%rsp), %rsi
	jg	.L875
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	16(%rsp), %rcx
	jg	.L875
	movq	%rcx, 16(%rsp)
	movq	%rsi, (%rsp)
.L875:
	subq	$1, 8(%rsp)
	je	.L980
.L876:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	cmpq	%r12, %rbx
	movq	48(%rsp), %r13
	movq	56(%rsp), %r14
	je	.L863
	movq	8(%r12), %r9
	movq	(%r12), %rsi
	movq	(%rbx), %r8
	movq	16(%rbx), %rax
	movq	%r9, %rbp
	subq	%rsi, %rbp
	subq	%r8, %rax
	movq	%rbp, %r10
	sarq	$4, %rax
	sarq	$4, %r10
	cmpq	%rax, %r10
	ja	.L981
	movq	8(%rbx), %rdi
	movq	%rdi, %rdx
	subq	%r8, %rdx
	movq	%rdx, %rax
	sarq	$4, %rax
	cmpq	%rax, %r10
	jbe	.L982
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L873
	movq	%r8, %rdi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r8
	movq	8(%r12), %r9
	movq	%rdi, %rax
	subq	%r8, %rax
	addq	(%r12), %rax
.L873:
	cmpq	%r9, %rax
	je	.L974
	movq	%r9, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%rbp, %rax
	jmp	.L870
	.p2align 4,,10
	.p2align 3
.L974:
	leaq	(%r8,%rbp), %rax
	jmp	.L870
	.p2align 4,,10
	.p2align 3
.L981:
	testq	%r10, %r10
	je	.L866
	movabsq	$1152921504606846975, %rax
	movq	%rsi, 32(%rsp)
	movq	%r9, 24(%rsp)
	cmpq	%rax, %r10
	ja	.L867
	movq	%rbp, %rdi
.LEHB77:
	call	_Znwm@PLT
	movq	(%rbx), %r8
	movq	32(%rsp), %rsi
	movq	%rax, %r10
	movq	24(%rsp), %r9
.L866:
	cmpq	%rsi, %r9
	je	.L868
	movq	%r10, %rdi
	movq	%rbp, %rdx
	movq	%r8, 24(%rsp)
	call	memmove@PLT
	movq	24(%rsp), %r8
	movq	%rax, %r10
.L868:
	testq	%r8, %r8
	je	.L869
	movq	%r8, %rdi
	movq	%r10, 24(%rsp)
	call	_ZdlPv@PLT
	movq	24(%rsp), %r10
.L869:
	leaq	(%r10,%rbp), %rax
	movq	%r10, (%rbx)
	movq	%rax, 16(%rbx)
	jmp	.L870
.L980:
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm3
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	16(%rsp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	(%rsp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L823
	cmpb	$0, 56(%rbp)
	je	.L877
	movsbl	67(%rbp), %esi
.L878:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movl	1600(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%r12), %rdx
	movq	%rax, %rdi
	movl	1600(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L823
	cmpb	$0, 56(%rbp)
	je	.L879
	movsbl	67(%rbp), %esi
.L880:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L881
	call	_ZdlPv@PLT
.L881:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L882
	call	_ZdlPv@PLT
.L882:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	72(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L983
	addq	$88, %rsp
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
.L819:
	.cfi_restore_state
	movq	%r14, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r14), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L820
	movq	%r14, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L820
.L824:
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L825
	movq	%r12, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L825
.L879:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L880
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L880
.L877:
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L878
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L878
.L821:
	movq	%r13, %rdx
	pxor	%xmm0, %xmm0
	shrq	%rdx
	andl	$1, %r13d
	orq	%r13, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L822
.L843:
	movq	%r15, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %r15d
	orq	%r15, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L844
.L857:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L858
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L858
.L855:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L856
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L856
.L845:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L846
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L846
.L813:
	xorl	%ebp, %ebp
	jmp	.L891
.L814:
	xorl	%r8d, %r8d
	xorl	%r12d, %r12d
	jmp	.L892
.L862:
	xorl	%ebp, %ebp
	jmp	.L898
.L828:
	xorl	%ebx, %ebx
	jmp	.L893
.L861:
	xorl	%ebp, %ebp
	jmp	.L897
.L829:
	xorl	%ebx, %ebx
	jmp	.L894
.L850:
	xorl	%ebx, %ebx
	jmp	.L896
.L849:
	xorl	%ebx, %ebx
	jmp	.L895
.L916:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L983:
	call	__stack_chk_fail@PLT
.L911:
.L976:
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L914:
	movq	%rax, %rbx
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L867:
	call	_ZSt17__throw_bad_allocv@PLT
.L823:
	call	_ZSt16__throw_bad_castv@PLT
.L912:
	movq	%rax, %rbx
	movq	%r13, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L913:
	jmp	.L976
.L910:
	jmp	.L976
.L915:
.L975:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%rbp, %rdi
	call	_Unwind_Resume@PLT
.LEHE77:
.L909:
	jmp	.L975
	.cfi_endproc
.LFE7308:
	.section	.gcc_except_table._Z4funcInEvm,"aG",@progbits,_Z4funcInEvm,comdat
.LLSDA7308:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7308-.LLSDACSB7308
.LLSDACSB7308:
	.uleb128 .LEHB61-.LFB7308
	.uleb128 .LEHE61-.LEHB61
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB62-.LFB7308
	.uleb128 .LEHE62-.LEHB62
	.uleb128 .L909-.LFB7308
	.uleb128 0
	.uleb128 .LEHB63-.LFB7308
	.uleb128 .LEHE63-.LEHB63
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB64-.LFB7308
	.uleb128 .LEHE64-.LEHB64
	.uleb128 .L910-.LFB7308
	.uleb128 0
	.uleb128 .LEHB65-.LFB7308
	.uleb128 .LEHE65-.LEHB65
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB66-.LFB7308
	.uleb128 .LEHE66-.LEHB66
	.uleb128 .L911-.LFB7308
	.uleb128 0
	.uleb128 .LEHB67-.LFB7308
	.uleb128 .LEHE67-.LEHB67
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB68-.LFB7308
	.uleb128 .LEHE68-.LEHB68
	.uleb128 .L912-.LFB7308
	.uleb128 0
	.uleb128 .LEHB69-.LFB7308
	.uleb128 .LEHE69-.LEHB69
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB70-.LFB7308
	.uleb128 .LEHE70-.LEHB70
	.uleb128 .L913-.LFB7308
	.uleb128 0
	.uleb128 .LEHB71-.LFB7308
	.uleb128 .LEHE71-.LEHB71
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB72-.LFB7308
	.uleb128 .LEHE72-.LEHB72
	.uleb128 .L914-.LFB7308
	.uleb128 0
	.uleb128 .LEHB73-.LFB7308
	.uleb128 .LEHE73-.LEHB73
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB74-.LFB7308
	.uleb128 .LEHE74-.LEHB74
	.uleb128 .L915-.LFB7308
	.uleb128 0
	.uleb128 .LEHB75-.LFB7308
	.uleb128 .LEHE75-.LEHB75
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB76-.LFB7308
	.uleb128 .LEHE76-.LEHB76
	.uleb128 .L916-.LFB7308
	.uleb128 0
	.uleb128 .LEHB77-.LFB7308
	.uleb128 .LEHE77-.LEHB77
	.uleb128 0
	.uleb128 0
.LLSDACSE7308:
	.section	.text._Z4funcInEvm,"axG",@progbits,_Z4funcInEvm,comdat
	.size	_Z4funcInEvm, .-_Z4funcInEvm
	.section	.text._Z4funcIDv4_xEvm,"axG",@progbits,_Z4funcIDv4_xEvm,comdat
	.p2align 4,,15
	.weak	_Z4funcIDv4_xEvm
	.type	_Z4funcIDv4_xEvm, @function
_Z4funcIDv4_xEvm:
.LFB7309:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7309
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
	movq	%rdi, -216(%rbp)
	movl	$24, %edi
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
.LEHB78:
	call	_Znwm@PLT
.LEHE78:
	xorl	%edx, %edx
	movq	%rax, %rbx
	movl	$104857600, %eax
	divq	%r15
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	movq	$0, 16(%rbx)
	movq	%rax, %rdx
	movq	%rax, -192(%rbp)
	salq	$5, %rdx
	testq	%rax, %rax
	movq	%rdx, -200(%rbp)
	je	.L985
	movq	%rdx, %rdi
	movq	%rdx, %r15
.LEHB79:
	call	_Znwm@PLT
.LEHE79:
	leaq	(%rax,%r15), %r12
	movq	%rax, (%rbx)
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r12, 16(%rbx)
	call	memset@PLT
.L1063:
	movq	%r12, 8(%rbx)
	movl	$24, %edi
.LEHB80:
	call	_Znwm@PLT
.LEHE80:
	cmpq	$0, -192(%rbp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L986
	movq	-200(%rbp), %r14
	movq	%r14, %rdi
.LEHB81:
	call	_Znwm@PLT
.LEHE81:
	leaq	(%rax,%r14), %r13
	movq	%rax, (%r12)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r13, 16(%r12)
	call	memset@PLT
	movq	%rax, %r8
.L1064:
	movq	(%rbx), %rcx
	movq	8(%rbx), %r10
	movl	$100, %r9d
	movq	%r13, 8(%r12)
	movq	$-1, %r14
	leaq	32(%rcx), %rax
	movq	%r10, %rdi
	subq	%rax, %rdi
	movq	%rdi, %rax
	andq	$-32, %rax
	leaq	32(%rax), %rdi
	.p2align 4,,10
	.p2align 3
.L989:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%rdx, %rsi
	orq	%rax, %rsi
	cmpq	%r10, %rcx
	je	.L987
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L988:
	movdqa	(%r8,%rax), %xmm0
	movaps	%xmm0, -144(%rbp)
	movdqa	16(%r8,%rax), %xmm1
	movaps	%xmm1, -128(%rbp)
	movaps	%xmm0, (%rcx,%rax)
	movdqa	-128(%rbp), %xmm0
	movaps	%xmm0, 16(%rcx,%rax)
	addq	$32, %rax
	cmpq	%rax, %rdi
	jne	.L988
.L987:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rsi, %rax
	cmpq	%rax, %r14
	cmova	%rax, %r14
	subq	$1, %r9
	jne	.L989
	movq	-216(%rbp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB82:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movq	%rax, %r13
	movl	$3, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	0(%r13), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %r15
	testq	%r15, %r15
	je	.L995
	cmpb	$0, 56(%r15)
	je	.L991
	movsbl	67(%r15), %esi
.L992:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm4, %xmm4
	testq	%r14, %r14
	cvtsi2sdq	-192(%rbp), %xmm4
	movsd	%xmm4, -208(%rbp)
	js	.L993
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r14, %xmm0
.L994:
	divsd	-208(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	(%rbx), %rdx
	movq	%rax, %rdi
	movl	3200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	(%r12), %rdx
	movq	%rax, %rdi
	movl	3200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r14
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r13
	testq	%r13, %r13
	je	.L995
	cmpb	$0, 56(%r13)
	je	.L996
	movsbl	67(%r13), %esi
.L997:
	movq	%r14, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L998
	call	_ZdlPv@PLT
.L998:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L999
	call	_ZdlPv@PLT
.L999:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE82:
	cmpq	$0, -192(%rbp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1000
	movq	-200(%rbp), %rbx
	movq	%rbx, %rdi
.LEHB83:
	call	_Znwm@PLT
.LEHE83:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, (%r12)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r12)
	call	memset@PLT
.L1065:
	movq	%rbx, 8(%r12)
	movl	$24, %edi
.LEHB84:
	call	_Znwm@PLT
.LEHE84:
	cmpq	$0, -192(%rbp)
	movq	%rax, %r14
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1001
	movq	-200(%rbp), %rbx
	movq	%rbx, %rdi
.LEHB85:
	call	_Znwm@PLT
.LEHE85:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, (%r14)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r14)
	call	memset@PLT
.L1066:
	movq	%rbx, 8(%r14)
	movq	$100, -168(%rbp)
	movq	$-1, %r15
	jmp	.L1014
	.p2align 4,,10
	.p2align 3
.L1151:
	cmpq	%rsi, %r9
	je	.L1145
	movq	%rbx, %rdx
	movq	%rcx, %rdi
	call	memmove@PLT
	addq	(%r12), %rbx
	movq	%rbx, %rcx
	.p2align 4,,10
	.p2align 3
.L1009:
	movq	%rcx, 8(%r12)
.L1002:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%r13, %rax
	cmpq	%rax, %r15
	cmova	%rax, %r15
	subq	$1, -168(%rbp)
	je	.L1149
.L1014:
#APP
# 10 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rax, %rdx
	cmpq	%r14, %r12
	movq	%rdx, %r13
	je	.L1002
	movq	8(%r14), %r9
	movq	(%r14), %rsi
	movq	(%r12), %rcx
	movq	16(%r12), %rax
	movq	%r9, %rbx
	subq	%rsi, %rbx
	subq	%rcx, %rax
	movq	%rbx, %r10
	sarq	$5, %rax
	sarq	$5, %r10
	cmpq	%rax, %r10
	ja	.L1150
	movq	8(%r12), %rdi
	movq	%rdi, %rdx
	subq	%rcx, %rdx
	movq	%rdx, %rax
	sarq	$5, %rax
	cmpq	%rax, %r10
	jbe	.L1151
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L1012
	movq	%rcx, %rdi
	call	memmove@PLT
	movq	8(%r12), %rdi
	movq	(%r12), %rcx
	movq	8(%r14), %r9
	movq	%rdi, %rax
	subq	%rcx, %rax
	addq	(%r14), %rax
.L1012:
	cmpq	%r9, %rax
	je	.L1145
	movq	%r9, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	addq	(%r12), %rbx
	movq	%rbx, %rcx
	jmp	.L1009
	.p2align 4,,10
	.p2align 3
.L1145:
	addq	%rbx, %rcx
	jmp	.L1009
	.p2align 4,,10
	.p2align 3
.L1150:
	testq	%r10, %r10
	je	.L1005
	movabsq	$576460752303423487, %rax
	cmpq	%rax, %r10
	ja	.L1039
	movq	%rbx, %rdi
	movq	%r9, -184(%rbp)
	movq	%rsi, -176(%rbp)
.LEHB86:
	call	_Znwm@PLT
	movq	(%r12), %rcx
	movq	-184(%rbp), %r9
	movq	%rax, %r10
	movq	-176(%rbp), %rsi
.L1005:
	cmpq	%rsi, %r9
	je	.L1007
	movq	%r10, %rdi
	movq	%rbx, %rdx
	movq	%rcx, -176(%rbp)
	call	memmove@PLT
	movq	-176(%rbp), %rcx
	movq	%rax, %r10
.L1007:
	testq	%rcx, %rcx
	je	.L1008
	movq	%rcx, %rdi
	movq	%r10, -176(%rbp)
	call	_ZdlPv@PLT
	movq	-176(%rbp), %r10
.L1008:
	leaq	(%r10,%rbx), %rcx
	movq	%r10, (%r12)
	movq	%rcx, 16(%r12)
	jmp	.L1009
.L1149:
	testq	%r15, %r15
	js	.L1015
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r15, %xmm0
.L1016:
	divsd	-208(%rbp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	(%r12), %rdx
	movq	%rax, %rdi
	movl	3200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	(%r14), %rdx
	movq	%rax, %rdi
	movl	3200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbx
	testq	%rbx, %rbx
	je	.L995
	cmpb	$0, 56(%rbx)
	je	.L1017
	movsbl	67(%rbx), %esi
.L1018:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L1019
	call	_ZdlPv@PLT
.L1019:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	(%r14), %rdi
	testq	%rdi, %rdi
	je	.L1020
	call	_ZdlPv@PLT
.L1020:
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE86:
	cmpq	$0, -192(%rbp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1021
	movq	-200(%rbp), %rbx
	movq	%rbx, %rdi
.LEHB87:
	call	_Znwm@PLT
.LEHE87:
	movq	%rbx, %rdx
	leaq	(%rax,%rbx), %rbx
	movq	%rax, (%r12)
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rbx, 16(%r12)
	call	memset@PLT
.L1067:
	movq	%rbx, 8(%r12)
	movl	$24, %edi
.LEHB88:
	call	_Znwm@PLT
.LEHE88:
	cmpq	$0, -192(%rbp)
	movq	%rax, %rbx
	movq	%rax, -176(%rbp)
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1022
	movq	-200(%rbp), %r15
	movq	%r15, %rdi
.LEHB89:
	call	_Znwm@PLT
.LEHE89:
	movq	%rbx, %rdi
	movq	%rax, (%rbx)
	leaq	(%rax,%r15), %rbx
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rbx, 16(%rdi)
	movq	%rax, %rdi
	call	memset@PLT
.L1068:
	movq	-176(%rbp), %rax
	leaq	-160(%rbp), %r15
	movq	%rbx, 8(%rax)
	movabsq	$9223372036854775807, %rax
	movl	$100, %ebx
	movq	%rax, -184(%rbp)
	movq	%rax, -168(%rbp)
	.p2align 4,,10
	.p2align 3
.L1026:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	-176(%rbp), %rax
	movq	(%r12), %rdx
	movq	-160(%rbp), %r13
	movq	-152(%rbp), %r14
	movq	(%rax), %rcx
	movq	8(%r12), %rax
	cmpq	%rax, %rdx
	je	.L1023
	leaq	32(%rdx), %rsi
	subq	%rsi, %rax
	andq	$-32, %rax
	leaq	32(%rax), %rsi
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L1024:
	movdqa	(%rcx,%rax), %xmm0
	movaps	%xmm0, -112(%rbp)
	movdqa	16(%rcx,%rax), %xmm1
	movaps	%xmm1, -96(%rbp)
	movaps	%xmm0, (%rdx,%rax)
	movdqa	-96(%rbp), %xmm0
	movaps	%xmm0, 16(%rdx,%rax)
	addq	$32, %rax
	cmpq	%rax, %rsi
	jne	.L1024
.L1023:
	movq	%r15, %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	-152(%rbp), %rax
	movq	-160(%rbp), %rsi
	subq	%r14, %rax
	subq	%r13, %rsi
	movq	%rax, %rdx
	shrq	$63, %rdx
	subq	%rdx, %rsi
	cmpq	-168(%rbp), %rsi
	jg	.L1025
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	-184(%rbp), %rcx
	jg	.L1025
	movq	%rcx, -184(%rbp)
	movq	%rsi, -168(%rbp)
.L1025:
	subq	$1, %rbx
	jne	.L1026
	movq	-216(%rbp), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB90:
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	.LC0(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	movq	%rax, %rbx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rax
	movq	%rbx, %rdi
	movl	3200(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	-176(%rbp), %rbx
	movq	%rax, %rdi
	movq	(%rbx), %rdx
	movl	3200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbx
	testq	%rbx, %rbx
	je	.L995
	cmpb	$0, 56(%rbx)
	je	.L1027
	movsbl	67(%rbx), %esi
.L1028:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm2
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	-184(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	-168(%rbp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbx
	testq	%rbx, %rbx
	je	.L995
	cmpb	$0, 56(%rbx)
	je	.L1029
	movsbl	67(%rbx), %esi
.L1030:
	movq	%r13, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L1031
	call	_ZdlPv@PLT
.L1031:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	-176(%rbp), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.L1032
	call	_ZdlPv@PLT
.L1032:
	movq	-176(%rbp), %rdi
	call	_ZdlPv@PLT
	movl	$24, %edi
	call	_Znwm@PLT
.LEHE90:
	cmpq	$0, -192(%rbp)
	movq	%rax, %rbx
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1033
	movq	-200(%rbp), %r14
	movq	%r14, %rdi
.LEHB91:
	call	_Znwm@PLT
.LEHE91:
	leaq	(%rax,%r14), %r12
	movq	%rax, (%rbx)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r12, 16(%rbx)
	call	memset@PLT
.L1069:
	movq	%r12, 8(%rbx)
	movl	$24, %edi
.LEHB92:
	call	_Znwm@PLT
.LEHE92:
	cmpq	$0, -192(%rbp)
	movq	%rax, %r12
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	je	.L1034
	movq	-200(%rbp), %r14
	movq	%r14, %rdi
.LEHB93:
	call	_Znwm@PLT
.LEHE93:
	leaq	(%rax,%r14), %r13
	movq	%rax, (%r12)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%r13, 16(%r12)
	call	memset@PLT
.L1070:
	movabsq	$9223372036854775807, %rax
	movq	%r13, 8(%r12)
	movq	$100, -184(%rbp)
	movq	%rax, -192(%rbp)
	movq	%rax, -176(%rbp)
	movq	%r15, -168(%rbp)
	jmp	.L1048
	.p2align 4,,10
	.p2align 3
.L1154:
	cmpq	%rsi, %r9
	je	.L1146
	movq	%r15, %rdx
	movq	%r8, %rdi
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%r15, %rax
	.p2align 4,,10
	.p2align 3
.L1042:
	movq	%rax, 8(%rbx)
.L1035:
	movq	-168(%rbp), %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	movq	-152(%rbp), %rax
	movq	-160(%rbp), %rsi
	subq	%r14, %rax
	subq	%r13, %rsi
	movq	%rax, %rdx
	shrq	$63, %rdx
	subq	%rdx, %rsi
	cmpq	-176(%rbp), %rsi
	jg	.L1047
	leaq	1000000000(%rax), %rcx
	movabsq	$1237940039285380275, %rax
	imulq	%rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$26, %rdx
	subq	%rax, %rdx
	imulq	$1000000000, %rdx, %rdx
	subq	%rdx, %rcx
	cmpq	-192(%rbp), %rcx
	jg	.L1047
	movq	%rcx, -192(%rbp)
	movq	%rsi, -176(%rbp)
.L1047:
	subq	$1, -184(%rbp)
	je	.L1152
.L1048:
	movq	-168(%rbp), %rsi
	movl	$4, %edi
	call	clock_gettime@PLT
	cmpq	%r12, %rbx
	movq	-160(%rbp), %r13
	movq	-152(%rbp), %r14
	je	.L1035
	movq	8(%r12), %r9
	movq	(%r12), %rsi
	movq	(%rbx), %r8
	movq	16(%rbx), %rax
	movq	%r9, %r15
	subq	%rsi, %r15
	subq	%r8, %rax
	movq	%r15, %r10
	sarq	$5, %rax
	sarq	$5, %r10
	cmpq	%rax, %r10
	ja	.L1153
	movq	8(%rbx), %rdi
	movq	%rdi, %rdx
	subq	%r8, %rdx
	movq	%rdx, %rax
	sarq	$5, %rax
	cmpq	%rax, %r10
	jbe	.L1154
	leaq	(%rsi,%rdx), %rax
	cmpq	%rax, %rsi
	je	.L1045
	movq	%r8, %rdi
	call	memmove@PLT
	movq	8(%rbx), %rdi
	movq	(%rbx), %r8
	movq	8(%r12), %r9
	movq	%rdi, %rax
	subq	%r8, %rax
	addq	(%r12), %rax
.L1045:
	cmpq	%r9, %rax
	je	.L1146
	movq	%r9, %rdx
	movq	%rax, %rsi
	subq	%rax, %rdx
	call	memmove@PLT
	movq	(%rbx), %rax
	addq	%r15, %rax
	jmp	.L1042
	.p2align 4,,10
	.p2align 3
.L1146:
	leaq	(%r8,%r15), %rax
	jmp	.L1042
	.p2align 4,,10
	.p2align 3
.L1153:
	testq	%r10, %r10
	je	.L1038
	movabsq	$576460752303423487, %rax
	movq	%rsi, -208(%rbp)
	movq	%r9, -200(%rbp)
	cmpq	%rax, %r10
	ja	.L1039
	movq	%r15, %rdi
.LEHB94:
	call	_Znwm@PLT
	movq	(%rbx), %r8
	movq	-208(%rbp), %rsi
	movq	%rax, %r10
	movq	-200(%rbp), %r9
.L1038:
	cmpq	%rsi, %r9
	je	.L1040
	movq	%r10, %rdi
	movq	%r15, %rdx
	movq	%r8, -200(%rbp)
	call	memmove@PLT
	movq	-200(%rbp), %r8
	movq	%rax, %r10
.L1040:
	testq	%r8, %r8
	je	.L1041
	movq	%r8, %rdi
	movq	%r10, -200(%rbp)
	call	_ZdlPv@PLT
	movq	-200(%rbp), %r10
.L1041:
	leaq	(%r10,%r15), %rax
	movq	%r10, (%rbx)
	movq	%rax, 16(%rbx)
	jmp	.L1042
.L1152:
	pxor	%xmm0, %xmm0
	movq	_ZSt4cout(%rip), %rax
	movsd	.LC2(%rip), %xmm3
	leaq	_ZSt4cout(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rdi
	cvtsi2sdq	-192(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	addq	-24(%rax), %rdx
	divsd	.LC1(%rip), %xmm1
	cvtsi2sdq	-176(%rbp), %xmm0
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	addsd	%xmm1, %xmm0
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movq	%rax, %r14
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r13
	testq	%r13, %r13
	je	.L995
	cmpb	$0, 56(%r13)
	je	.L1049
	movsbl	67(%r13), %esi
.L1050:
	movq	%r14, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rax
	leaq	_ZSt4cout(%rip), %rdi
	movl	3200(%rax), %esi
	call	_ZNSolsEi@PLT
	movq	(%r12), %rdx
	movq	%rax, %rdi
	movl	3200(%rdx), %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %r14
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r13
	testq	%r13, %r13
	je	.L995
	cmpb	$0, 56(%r13)
	je	.L1051
	movsbl	67(%r13), %esi
.L1052:
	movq	%r14, %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L1053
	call	_ZdlPv@PLT
.L1053:
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L1054
	call	_ZdlPv@PLT
.L1054:
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	-56(%rbp), %rax
	xorq	%fs:40, %rax
	jne	.L1155
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
.L991:
	.cfi_restore_state
	movq	%r15, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r15), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L992
	movq	%r15, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L992
.L996:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%r13), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L997
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L997
.L1051:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%r13), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L1052
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1052
.L1049:
	movq	%r13, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%r13), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L1050
	movq	%r13, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1050
.L993:
	movq	%r14, %rdx
	pxor	%xmm0, %xmm0
	shrq	%rdx
	andl	$1, %r14d
	orq	%r14, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L994
.L1015:
	movq	%r15, %rax
	movq	%r15, %rcx
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %ecx
	orq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
	jmp	.L1016
.L1029:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L1030
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1030
.L1027:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L1028
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1028
.L1017:
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L1018
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L1018
.L985:
	xorl	%r12d, %r12d
	jmp	.L1063
.L986:
	xorl	%r8d, %r8d
	xorl	%r13d, %r13d
	jmp	.L1064
.L1034:
	xorl	%r13d, %r13d
	jmp	.L1070
.L1000:
	xorl	%ebx, %ebx
	jmp	.L1065
.L1033:
	xorl	%r12d, %r12d
	jmp	.L1069
.L1001:
	xorl	%ebx, %ebx
	jmp	.L1066
.L1022:
	xorl	%ebx, %ebx
	jmp	.L1068
.L1021:
	xorl	%ebx, %ebx
	jmp	.L1067
.L1088:
.L1148:
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L1155:
	call	__stack_chk_fail@PLT
.L1083:
	jmp	.L1148
.L1086:
	movq	-176(%rbp), %rdi
	movq	%rax, %rbx
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L1039:
	call	_ZSt17__throw_bad_allocv@PLT
.L995:
	call	_ZSt16__throw_bad_castv@PLT
.L1084:
	movq	%rax, %rbx
	movq	%r14, %rdi
	call	_ZdlPv@PLT
	movq	%rbx, %rdi
	call	_Unwind_Resume@PLT
.L1085:
	jmp	.L1148
.L1082:
	jmp	.L1148
.L1087:
.L1147:
	movq	%rax, %r12
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
	movq	%r12, %rdi
	call	_Unwind_Resume@PLT
.LEHE94:
.L1081:
	jmp	.L1147
	.cfi_endproc
.LFE7309:
	.section	.gcc_except_table._Z4funcIDv4_xEvm,"aG",@progbits,_Z4funcIDv4_xEvm,comdat
.LLSDA7309:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7309-.LLSDACSB7309
.LLSDACSB7309:
	.uleb128 .LEHB78-.LFB7309
	.uleb128 .LEHE78-.LEHB78
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB79-.LFB7309
	.uleb128 .LEHE79-.LEHB79
	.uleb128 .L1081-.LFB7309
	.uleb128 0
	.uleb128 .LEHB80-.LFB7309
	.uleb128 .LEHE80-.LEHB80
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB81-.LFB7309
	.uleb128 .LEHE81-.LEHB81
	.uleb128 .L1082-.LFB7309
	.uleb128 0
	.uleb128 .LEHB82-.LFB7309
	.uleb128 .LEHE82-.LEHB82
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB83-.LFB7309
	.uleb128 .LEHE83-.LEHB83
	.uleb128 .L1083-.LFB7309
	.uleb128 0
	.uleb128 .LEHB84-.LFB7309
	.uleb128 .LEHE84-.LEHB84
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB85-.LFB7309
	.uleb128 .LEHE85-.LEHB85
	.uleb128 .L1084-.LFB7309
	.uleb128 0
	.uleb128 .LEHB86-.LFB7309
	.uleb128 .LEHE86-.LEHB86
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB87-.LFB7309
	.uleb128 .LEHE87-.LEHB87
	.uleb128 .L1085-.LFB7309
	.uleb128 0
	.uleb128 .LEHB88-.LFB7309
	.uleb128 .LEHE88-.LEHB88
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB89-.LFB7309
	.uleb128 .LEHE89-.LEHB89
	.uleb128 .L1086-.LFB7309
	.uleb128 0
	.uleb128 .LEHB90-.LFB7309
	.uleb128 .LEHE90-.LEHB90
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB91-.LFB7309
	.uleb128 .LEHE91-.LEHB91
	.uleb128 .L1087-.LFB7309
	.uleb128 0
	.uleb128 .LEHB92-.LFB7309
	.uleb128 .LEHE92-.LEHB92
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB93-.LFB7309
	.uleb128 .LEHE93-.LEHB93
	.uleb128 .L1088-.LFB7309
	.uleb128 0
	.uleb128 .LEHB94-.LFB7309
	.uleb128 .LEHE94-.LEHB94
	.uleb128 0
	.uleb128 0
.LLSDACSE7309:
	.section	.text._Z4funcIDv4_xEvm,"axG",@progbits,_Z4funcIDv4_xEvm,comdat
	.size	_Z4funcIDv4_xEvm, .-_Z4funcIDv4_xEvm
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB7120:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	movq	$15, 16+_ZSt4cout(%rip)
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
.LFE7120:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB8089:
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
.LFE8089:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.align 8
.LC2:
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
	.ident	"GCC: (Ubuntu 7.2.0-8ubuntu3) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
