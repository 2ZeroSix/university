	.file	"main.cpp"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.section	.text.startup,"ax",@progbits
.LHOTB0:
	.p2align 4,,15
	.type	_Z41__static_initialization_and_destruction_0ii.constprop.4, @function
_Z41__static_initialization_and_destruction_0ii.constprop.4:
.LFB8094:
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
.LFE8094:
	.size	_Z41__static_initialization_and_destruction_0ii.constprop.4, .-_Z41__static_initialization_and_destruction_0ii.constprop.4
	.section	.text.unlikely
.LCOLDE0:
	.section	.text.startup
.LHOTE0:
	.section	.text.unlikely
	.align 2
.LCOLDB1:
	.text
.LHOTB1:
	.align 2
	.p2align 4,,15
	.type	_ZNSt8ios_base9precisionEl.isra.3.constprop.5, @function
_ZNSt8ios_base9precisionEl.isra.3.constprop.5:
.LFB8093:
	.cfi_startproc
	movq	_ZSt4cout+16(%rip), %rax
	movq	$10, _ZSt4cout+16(%rip)
	ret
	.cfi_endproc
.LFE8093:
	.size	_ZNSt8ios_base9precisionEl.isra.3.constprop.5, .-_ZNSt8ios_base9precisionEl.isra.3.constprop.5
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely._Z5rdtscv,"axG",@progbits,_Z5rdtscv,comdat
.LCOLDB2:
	.section	.text._Z5rdtscv,"axG",@progbits,_Z5rdtscv,comdat
.LHOTB2:
	.p2align 4,,15
	.weak	_Z5rdtscv
	.type	_Z5rdtscv, @function
_Z5rdtscv:
.LFB7835:
	.cfi_startproc
#APP
# 11 "main.cpp" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	ret
	.cfi_endproc
.LFE7835:
	.size	_Z5rdtscv, .-_Z5rdtscv
	.section	.text.unlikely._Z5rdtscv,"axG",@progbits,_Z5rdtscv,comdat
.LCOLDE2:
	.section	.text._Z5rdtscv,"axG",@progbits,_Z5rdtscv,comdat
.LHOTE2:
	.section	.text.unlikely._ZN10BarrierOMPILm64EEC2Em,"axG",@progbits,_ZN10BarrierOMPILm64EEC5Em,comdat
	.align 2
.LCOLDB3:
	.section	.text._ZN10BarrierOMPILm64EEC2Em,"axG",@progbits,_ZN10BarrierOMPILm64EEC5Em,comdat
.LHOTB3:
	.align 2
	.p2align 4,,15
	.weak	_ZN10BarrierOMPILm64EEC2Em
	.type	_ZN10BarrierOMPILm64EEC2Em, @function
_ZN10BarrierOMPILm64EEC2Em:
.LFB7974:
	.cfi_startproc
	movabsq	$35747322042253312, %rax
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rsi, 8(%rdi)
	cmpq	%rax, %rsi
	movb	$1, 16(%rdi)
	ja	.L6
	movq	%rdi, %rbx
	movq	%rsi, %rdi
	salq	$8, %rdi
	call	_Znam
	movq	%rax, (%rbx)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	call	__cxa_throw_bad_array_new_length
	.cfi_endproc
.LFE7974:
	.size	_ZN10BarrierOMPILm64EEC2Em, .-_ZN10BarrierOMPILm64EEC2Em
	.section	.text.unlikely._ZN10BarrierOMPILm64EEC2Em,"axG",@progbits,_ZN10BarrierOMPILm64EEC5Em,comdat
.LCOLDE3:
	.section	.text._ZN10BarrierOMPILm64EEC2Em,"axG",@progbits,_ZN10BarrierOMPILm64EEC5Em,comdat
.LHOTE3:
	.weak	_ZN10BarrierOMPILm64EEC1Em
	.set	_ZN10BarrierOMPILm64EEC1Em,_ZN10BarrierOMPILm64EEC2Em
	.section	.text.unlikely._ZN10BarrierOMPILm64EED2Ev,"axG",@progbits,_ZN10BarrierOMPILm64EED5Ev,comdat
	.align 2
.LCOLDB4:
	.section	.text._ZN10BarrierOMPILm64EED2Ev,"axG",@progbits,_ZN10BarrierOMPILm64EED5Ev,comdat
.LHOTB4:
	.align 2
	.p2align 4,,15
	.weak	_ZN10BarrierOMPILm64EED2Ev
	.type	_ZN10BarrierOMPILm64EED2Ev, @function
_ZN10BarrierOMPILm64EED2Ev:
.LFB7977:
	.cfi_startproc
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L10
	jmp	_ZdaPv
	.p2align 4,,10
	.p2align 3
.L10:
	rep ret
	.cfi_endproc
.LFE7977:
	.size	_ZN10BarrierOMPILm64EED2Ev, .-_ZN10BarrierOMPILm64EED2Ev
	.section	.text.unlikely._ZN10BarrierOMPILm64EED2Ev,"axG",@progbits,_ZN10BarrierOMPILm64EED5Ev,comdat
.LCOLDE4:
	.section	.text._ZN10BarrierOMPILm64EED2Ev,"axG",@progbits,_ZN10BarrierOMPILm64EED5Ev,comdat
.LHOTE4:
	.weak	_ZN10BarrierOMPILm64EED1Ev
	.set	_ZN10BarrierOMPILm64EED1Ev,_ZN10BarrierOMPILm64EED2Ev
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC5:
	.string	","
	.section	.text.unlikely._Z11recalcFieldILm64ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
.LCOLDB6:
	.section	.text._Z11recalcFieldILm64ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
.LHOTB6:
	.p2align 4,,15
	.weak	_Z11recalcFieldILm64ELi8EEvPcS0_mmm
	.type	_Z11recalcFieldILm64ELi8EEvPcS0_mmm, @function
_Z11recalcFieldILm64ELi8EEvPcS0_mmm:
.LFB7903:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA7903
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%r8, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rsi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbp
	movl	$8, %esi
	movq	%rdx, %r13
	movq	%rcx, %r14
	subq	$152, %rsp
	.cfi_def_cfa_offset 208
	leaq	32(%rsp), %rbx
	movq	%fs:40, %rax
	movq	%rax, 136(%rsp)
	xorl	%eax, %eax
	movq	%rbx, %rdi
.LEHB0:
	call	_ZN10BarrierOMPILm64EEC1Em
.LEHE0:
	movq	$-1, 8(%rsp)
	movq	$-1, 16(%rsp)
	leaq	64(%rsp), %rsi
	movq	8(%rsp), %rax
	movl	$_Z11recalcFieldILm64ELi8EEvPcS0_mmm._omp_fn.0, %edi
	xorl	%ecx, %ecx
	movl	$8, %edx
	movq	%rbp, 64(%rsp)
	movq	%r15, 96(%rsp)
	movq	%r14, 88(%rsp)
	movq	%r13, 80(%rsp)
	movq	%rax, 112(%rsp)
	movq	16(%rsp), %rax
	movq	%r12, 72(%rsp)
	movq	%rbx, 104(%rsp)
	movq	%rax, 120(%rsp)
	movq	24(%rsp), %rax
	movq	%rax, 128(%rsp)
	call	GOMP_parallel
	movq	112(%rsp), %rax
	movl	$_ZSt4cout, %edi
	movq	%rax, 8(%rsp)
	movq	120(%rsp), %rax
	movq	%rax, 16(%rsp)
	movq	128(%rsp), %rax
	movq	%rax, 24(%rsp)
	movq	16(%rsp), %rbp
	movq	8(%rsp), %rsi
.LEHB1:
	call	_ZNSolsEy
	movl	$.LC5, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rbp, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEy
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE1:
	movq	%rbx, %rdi
	call	_ZN10BarrierOMPILm64EED1Ev
	movq	136(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L19
	addq	$152, %rsp
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
.L19:
	.cfi_restore_state
	call	__stack_chk_fail
.L15:
	movq	%rax, %rbp
.L13:
	movq	%rbx, %rdi
	call	_ZN10BarrierOMPILm64EED1Ev
	movq	%rbp, %rdi
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
	.cfi_endproc
.LFE7903:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._Z11recalcFieldILm64ELi8EEvPcS0_mmm,"aG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
.LLSDA7903:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7903-.LLSDACSB7903
.LLSDACSB7903:
	.uleb128 .LEHB0-.LFB7903
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB7903
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L15-.LFB7903
	.uleb128 0
	.uleb128 .LEHB2-.LFB7903
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE7903:
	.section	.text._Z11recalcFieldILm64ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
	.size	_Z11recalcFieldILm64ELi8EEvPcS0_mmm, .-_Z11recalcFieldILm64ELi8EEvPcS0_mmm
	.section	.text.unlikely._Z11recalcFieldILm64ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
.LCOLDE6:
	.section	.text._Z11recalcFieldILm64ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
.LHOTE6:
	.section	.text.unlikely._ZN10BarrierOMPILm64EE4waitEv,"axG",@progbits,_ZN10BarrierOMPILm64EE4waitEv,comdat
	.align 2
.LCOLDB7:
	.section	.text._ZN10BarrierOMPILm64EE4waitEv,"axG",@progbits,_ZN10BarrierOMPILm64EE4waitEv,comdat
.LHOTB7:
	.align 2
	.p2align 4,,15
	.weak	_ZN10BarrierOMPILm64EE4waitEv
	.type	_ZN10BarrierOMPILm64EE4waitEv, @function
_ZN10BarrierOMPILm64EE4waitEv:
.LFB7979:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	omp_get_thread_num
	testl	%eax, %eax
	jne	.L21
	movq	8(%rbp), %r9
	movq	0(%rbp), %rbx
	.p2align 4,,10
	.p2align 3
.L28:
	cmpq	$1, %r9
	movzbl	16(%rbp), %r11d
	jbe	.L36
	movl	256(%rbx), %esi
	movzbl	%r11b, %r10d
	leaq	512(%rbx), %rdx
	movl	$1, %eax
	cmpl	%r10d, %esi
	sete	%r8b
	je	.L26
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L27:
	movl	(%rdx), %ecx
	cmpl	%esi, %ecx
	sete	%r8b
	addq	$256, %rdx
	cmpl	%esi, %ecx
	jne	.L24
.L26:
	addq	$1, %rax
	cmpq	%r9, %rax
	jne	.L27
.L24:
	testb	%r8b, %r8b
	je	.L28
.L23:
	xorl	$1, %r11d
	movb	%r11b, 16(%rbp)
	movl	%r10d, (%rbx)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L21:
	.cfi_restore_state
	movzbl	16(%rbp), %edx
	movq	0(%rbp), %rcx
	cltq
	movzbl	16(%rbp), %esi
	salq	$8, %rax
	addq	%rcx, %rax
	movl	%esi, (%rax)
	.p2align 4,,10
	.p2align 3
.L30:
	movl	(%rcx), %eax
	cmpl	%edx, %eax
	jne	.L30
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L36:
	.cfi_restore_state
	movzbl	%r11b, %r10d
	jmp	.L23
	.cfi_endproc
.LFE7979:
	.size	_ZN10BarrierOMPILm64EE4waitEv, .-_ZN10BarrierOMPILm64EE4waitEv
	.section	.text.unlikely._ZN10BarrierOMPILm64EE4waitEv,"axG",@progbits,_ZN10BarrierOMPILm64EE4waitEv,comdat
.LCOLDE7:
	.section	.text._ZN10BarrierOMPILm64EE4waitEv,"axG",@progbits,_ZN10BarrierOMPILm64EE4waitEv,comdat
.LHOTE7:
	.section	.text.unlikely._ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_,"axG",@progbits,_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_,comdat
.LCOLDB8:
	.section	.text._ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_,"axG",@progbits,_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_,comdat
.LHOTB8:
	.p2align 4,,15
	.weak	_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_
	.type	_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_, @function
_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_:
.LFB7981:
	.cfi_startproc
	movq	%rdi, %rax
	ret
	.cfi_endproc
.LFE7981:
	.size	_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_, .-_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_
	.section	.text.unlikely._ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_,"axG",@progbits,_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_,comdat
.LCOLDE8:
	.section	.text._ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_,"axG",@progbits,_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_,comdat
.LHOTE8:
	.section	.text.unlikely._ZSt4swapIPcEvRT_S2_,"axG",@progbits,_ZSt4swapIPcEvRT_S2_,comdat
.LCOLDB9:
	.section	.text._ZSt4swapIPcEvRT_S2_,"axG",@progbits,_ZSt4swapIPcEvRT_S2_,comdat
.LHOTB9:
	.p2align 4,,15
	.weak	_ZSt4swapIPcEvRT_S2_
	.type	_ZSt4swapIPcEvRT_S2_, @function
_ZSt4swapIPcEvRT_S2_:
.LFB7980:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	movq	%rsi, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_
	movq	(%rax), %rax
	movq	%rbx, %rdi
	movq	%rax, (%rsp)
	call	_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_
	movq	(%rax), %rax
	movq	%rsp, %rdi
	movq	%rax, 0(%rbp)
	call	_ZSt4moveIRPcEONSt16remove_referenceIT_E4typeEOS3_
	movq	(%rax), %rax
	movq	%rax, (%rbx)
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L41
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L41:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE7980:
	.size	_ZSt4swapIPcEvRT_S2_, .-_ZSt4swapIPcEvRT_S2_
	.section	.text.unlikely._ZSt4swapIPcEvRT_S2_,"axG",@progbits,_ZSt4swapIPcEvRT_S2_,comdat
.LCOLDE9:
	.section	.text._ZSt4swapIPcEvRT_S2_,"axG",@progbits,_ZSt4swapIPcEvRT_S2_,comdat
.LHOTE9:
	.section	.text.unlikely._Z11recalcFieldILm64ELi8EEvPcS0_mmm._omp_fn.0,"axG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
.LCOLDB10:
	.section	.text._Z11recalcFieldILm64ELi8EEvPcS0_mmm._omp_fn.0,"axG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
.LHOTB10:
	.p2align 4,,15
	.type	_Z11recalcFieldILm64ELi8EEvPcS0_mmm._omp_fn.0, @function
_Z11recalcFieldILm64ELi8EEvPcS0_mmm._omp_fn.0:
.LFB8089:
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
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	movq	(%rbx), %rdx
	movq	24(%rbx), %r12
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	movq	32(%rdi), %rax
	movq	$-1, 32(%rsp)
	movq	%rdx, 40(%rsp)
	movq	%rax, %rdi
	movq	%rax, 24(%rsp)
	movq	16(%rbx), %rax
	testq	%rdi, %rdi
	movq	%rax, 16(%rsp)
	movq	8(%rbx), %rax
	movq	%rax, 48(%rsp)
	je	.L50
	movq	16(%rsp), %rbp
	movq	%r12, %r13
	movq	$0, 8(%rsp)
	notq	%r13
	imulq	%r12, %rbp
.L51:
	cmpq	$0, 16(%rsp)
	je	.L58
	call	omp_get_num_threads
	movslq	%eax, %r14
	call	omp_get_thread_num
	movslq	%eax, %rcx
	movq	16(%rsp), %rax
	xorl	%edx, %edx
	divq	%r14
	cmpq	%rdx, %rcx
	jnb	.L75
	addq	$1, %rax
	xorl	%edx, %edx
.L75:
	imulq	%rax, %rcx
	addq	%rcx, %rdx
	leaq	(%rax,%rdx), %r15
	cmpq	%r15, %rdx
	jnb	.L58
	leaq	1(%rdx), %r14
	movq	%r14, %r11
	imulq	%r12, %r11
	.p2align 4,,10
	.p2align 3
.L60:
	movq	%r11, %r9
	subq	%r12, %r9
	testq	%r12, %r12
	je	.L64
	.p2align 4,,10
	.p2align 3
.L80:
	movq	40(%rsp), %r10
	leaq	0(%r13,%r9), %rsi
	movl	$-1, %ecx
	xorl	%r8d, %r8d
.L70:
	testl	%ecx, %ecx
	movq	%rsi, %rdx
	movl	$-1, %eax
	setne	%dil
.L61:
	testl	%eax, %eax
	je	.L74
	testb	%dil, %dil
	je	.L74
	cmpq	%rdx, %rbp
	jbe	.L74
	cmpb	$1, (%r10,%rdx)
	sbbl	$-1, %r8d
.L74:
	addl	$1, %eax
	addq	$1, %rdx
	cmpl	$2, %eax
	jne	.L61
	addl	$1, %ecx
	addq	%r12, %rsi
	cmpl	$2, %ecx
	jne	.L70
	cmpb	$0, (%r10,%r9)
	je	.L96
	subl	$2, %r8d
	cmpl	$1, %r8d
	jbe	.L89
.L68:
	movq	48(%rsp), %rax
	movb	$0, (%rax,%r9)
.L67:
	addq	$1, %r9
	cmpq	%r9, %r11
	jne	.L80
.L64:
	addq	%r12, %r11
	cmpq	%r14, %r15
	je	.L58
	addq	$1, %r14
	jmp	.L60
	.p2align 4,,10
	.p2align 3
.L96:
	cmpl	$3, %r8d
	jne	.L68
.L89:
	movq	48(%rsp), %rax
	movb	$1, (%rax,%r9)
	jmp	.L67
.L58:
	call	GOMP_barrier
	call	_Z5rdtscv
	movq	40(%rbx), %rdi
	movq	%rax, %r15
	call	_ZN10BarrierOMPILm64EE4waitEv
	call	_Z5rdtscv
	movq	%rax, %r14
	call	GOMP_single_start
	testb	%al, %al
	je	.L56
	movq	$0, 64(%rbx)
.L56:
	call	GOMP_barrier
	subq	%r15, %r14
	cmpq	%r14, 32(%rsp)
	movq	%r14, %rax
	cmovbe	32(%rsp), %rax
	shrq	$3, %r14
	movq	%rax, 32(%rsp)
	call	GOMP_critical_start
	movq	64(%rbx), %rax
	addq	%rax, %r14
	movq	%r14, 64(%rbx)
	call	GOMP_critical_end
	movq	40(%rbx), %rdi
	call	_ZN10BarrierOMPILm64EE4waitEv
	call	GOMP_single_start
	testb	%al, %al
	je	.L54
	movq	56(%rbx), %rdx
	movq	64(%rbx), %rax
	cmpq	%rax, %rdx
	ja	.L97
	movq	56(%rbx), %rax
.L55:
	movq	%rax, 56(%rbx)
.L54:
	call	GOMP_barrier
	movq	40(%rbx), %rdi
	call	_ZN10BarrierOMPILm64EE4waitEv
	leaq	48(%rsp), %rsi
	leaq	40(%rsp), %rdi
	call	_ZSt4swapIPcEvRT_S2_
	addq	$1, 8(%rsp)
	movq	8(%rsp), %rax
	cmpq	%rax, 24(%rsp)
	jne	.L51
.L50:
	call	GOMP_critical_start
	movq	48(%rbx), %rax
	cmpq	32(%rsp), %rax
	jbe	.L98
	movq	32(%rsp), %rax
.L46:
	movq	%rax, 48(%rbx)
	call	GOMP_critical_end
	movq	40(%rbx), %rdi
	call	_ZN10BarrierOMPILm64EE4waitEv
	movq	56(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L99
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
.L97:
	.cfi_restore_state
	movq	64(%rbx), %rax
	jmp	.L55
.L98:
	movq	48(%rbx), %rax
	jmp	.L46
.L99:
	call	__stack_chk_fail
	.cfi_endproc
.LFE8089:
	.size	_Z11recalcFieldILm64ELi8EEvPcS0_mmm._omp_fn.0, .-_Z11recalcFieldILm64ELi8EEvPcS0_mmm._omp_fn.0
	.section	.text.unlikely._Z11recalcFieldILm64ELi8EEvPcS0_mmm._omp_fn.0,"axG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
.LCOLDE10:
	.section	.text._Z11recalcFieldILm64ELi8EEvPcS0_mmm._omp_fn.0,"axG",@progbits,_Z11recalcFieldILm64ELi8EEvPcS0_mmm,comdat
.LHOTE10:
	.section	.text.unlikely._ZN10BarrierOMPILm4096EEC2Em,"axG",@progbits,_ZN10BarrierOMPILm4096EEC5Em,comdat
	.align 2
.LCOLDB11:
	.section	.text._ZN10BarrierOMPILm4096EEC2Em,"axG",@progbits,_ZN10BarrierOMPILm4096EEC5Em,comdat
.LHOTB11:
	.align 2
	.p2align 4,,15
	.weak	_ZN10BarrierOMPILm4096EEC2Em
	.type	_ZN10BarrierOMPILm4096EEC2Em, @function
_ZN10BarrierOMPILm4096EEC2Em:
.LFB7985:
	.cfi_startproc
	movabsq	$558551906910208, %rax
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rsi, 8(%rdi)
	cmpq	%rax, %rsi
	movb	$1, 16(%rdi)
	ja	.L101
	movq	%rdi, %rbx
	movq	%rsi, %rdi
	salq	$14, %rdi
	call	_Znam
	movq	%rax, (%rbx)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L101:
	.cfi_restore_state
	call	__cxa_throw_bad_array_new_length
	.cfi_endproc
.LFE7985:
	.size	_ZN10BarrierOMPILm4096EEC2Em, .-_ZN10BarrierOMPILm4096EEC2Em
	.section	.text.unlikely._ZN10BarrierOMPILm4096EEC2Em,"axG",@progbits,_ZN10BarrierOMPILm4096EEC5Em,comdat
.LCOLDE11:
	.section	.text._ZN10BarrierOMPILm4096EEC2Em,"axG",@progbits,_ZN10BarrierOMPILm4096EEC5Em,comdat
.LHOTE11:
	.weak	_ZN10BarrierOMPILm4096EEC1Em
	.set	_ZN10BarrierOMPILm4096EEC1Em,_ZN10BarrierOMPILm4096EEC2Em
	.section	.text.unlikely._ZN10BarrierOMPILm4096EED2Ev,"axG",@progbits,_ZN10BarrierOMPILm4096EED5Ev,comdat
	.align 2
.LCOLDB12:
	.section	.text._ZN10BarrierOMPILm4096EED2Ev,"axG",@progbits,_ZN10BarrierOMPILm4096EED5Ev,comdat
.LHOTB12:
	.align 2
	.p2align 4,,15
	.weak	_ZN10BarrierOMPILm4096EED2Ev
	.type	_ZN10BarrierOMPILm4096EED2Ev, @function
_ZN10BarrierOMPILm4096EED2Ev:
.LFB7988:
	.cfi_startproc
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L104
	jmp	_ZdaPv
	.p2align 4,,10
	.p2align 3
.L104:
	rep ret
	.cfi_endproc
.LFE7988:
	.size	_ZN10BarrierOMPILm4096EED2Ev, .-_ZN10BarrierOMPILm4096EED2Ev
	.section	.text.unlikely._ZN10BarrierOMPILm4096EED2Ev,"axG",@progbits,_ZN10BarrierOMPILm4096EED5Ev,comdat
.LCOLDE12:
	.section	.text._ZN10BarrierOMPILm4096EED2Ev,"axG",@progbits,_ZN10BarrierOMPILm4096EED5Ev,comdat
.LHOTE12:
	.weak	_ZN10BarrierOMPILm4096EED1Ev
	.set	_ZN10BarrierOMPILm4096EED1Ev,_ZN10BarrierOMPILm4096EED2Ev
	.section	.text.unlikely._Z11recalcFieldILm4096ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
.LCOLDB13:
	.section	.text._Z11recalcFieldILm4096ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
.LHOTB13:
	.p2align 4,,15
	.weak	_Z11recalcFieldILm4096ELi8EEvPcS0_mmm
	.type	_Z11recalcFieldILm4096ELi8EEvPcS0_mmm, @function
_Z11recalcFieldILm4096ELi8EEvPcS0_mmm:
.LFB7904:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA7904
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%r8, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rsi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbp
	movl	$8, %esi
	movq	%rdx, %r13
	movq	%rcx, %r14
	subq	$152, %rsp
	.cfi_def_cfa_offset 208
	leaq	32(%rsp), %rbx
	movq	%fs:40, %rax
	movq	%rax, 136(%rsp)
	xorl	%eax, %eax
	movq	%rbx, %rdi
.LEHB3:
	call	_ZN10BarrierOMPILm4096EEC1Em
.LEHE3:
	movq	$-1, 8(%rsp)
	movq	$-1, 16(%rsp)
	leaq	64(%rsp), %rsi
	movq	8(%rsp), %rax
	movl	$_Z11recalcFieldILm4096ELi8EEvPcS0_mmm._omp_fn.1, %edi
	xorl	%ecx, %ecx
	movl	$8, %edx
	movq	%rbp, 64(%rsp)
	movq	%r15, 96(%rsp)
	movq	%r14, 88(%rsp)
	movq	%r13, 80(%rsp)
	movq	%rax, 112(%rsp)
	movq	16(%rsp), %rax
	movq	%r12, 72(%rsp)
	movq	%rbx, 104(%rsp)
	movq	%rax, 120(%rsp)
	movq	24(%rsp), %rax
	movq	%rax, 128(%rsp)
	call	GOMP_parallel
	movq	112(%rsp), %rax
	movl	$_ZSt4cout, %edi
	movq	%rax, 8(%rsp)
	movq	120(%rsp), %rax
	movq	%rax, 16(%rsp)
	movq	128(%rsp), %rax
	movq	%rax, 24(%rsp)
	movq	16(%rsp), %rbp
	movq	8(%rsp), %rsi
.LEHB4:
	call	_ZNSolsEy
	movl	$.LC5, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rbp, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEy
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE4:
	movq	%rbx, %rdi
	call	_ZN10BarrierOMPILm4096EED1Ev
	movq	136(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L113
	addq	$152, %rsp
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
.L113:
	.cfi_restore_state
	call	__stack_chk_fail
.L109:
	movq	%rax, %rbp
.L107:
	movq	%rbx, %rdi
	call	_ZN10BarrierOMPILm4096EED1Ev
	movq	%rbp, %rdi
.LEHB5:
	call	_Unwind_Resume
.LEHE5:
	.cfi_endproc
.LFE7904:
	.section	.gcc_except_table._Z11recalcFieldILm4096ELi8EEvPcS0_mmm,"aG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
.LLSDA7904:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7904-.LLSDACSB7904
.LLSDACSB7904:
	.uleb128 .LEHB3-.LFB7904
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB7904
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L109-.LFB7904
	.uleb128 0
	.uleb128 .LEHB5-.LFB7904
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE7904:
	.section	.text._Z11recalcFieldILm4096ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
	.size	_Z11recalcFieldILm4096ELi8EEvPcS0_mmm, .-_Z11recalcFieldILm4096ELi8EEvPcS0_mmm
	.section	.text.unlikely._Z11recalcFieldILm4096ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
.LCOLDE13:
	.section	.text._Z11recalcFieldILm4096ELi8EEvPcS0_mmm,"axG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
.LHOTE13:
	.section	.text.unlikely
.LCOLDB14:
	.section	.text.startup
.LHOTB14:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB7837:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	call	_ZNSt8ios_base9precisionEl.isra.3.constprop.5
	movl	$2097152, %edi
	call	_Znam
	movl	$2097152, %edi
	movq	%rax, %rbp
	call	_Znam
	xorl	%ecx, %ecx
	movq	%rax, %rbx
	movabsq	$-3689348814741910323, %rsi
	.p2align 4,,10
	.p2align 3
.L115:
	movq	%rcx, %rax
	movq	%rcx, %rdi
	mulq	%rsi
	shrq	$2, %rdx
	leaq	(%rdx,%rdx,4), %rax
	subq	%rax, %rdi
	movb	%dil, 0(%rbp,%rcx)
	addq	$1, %rcx
	cmpq	$2097152, %rcx
	jne	.L115
	movl	$3, %r14d
	movl	$256, %r13d
	movl	$256, %r12d
	.p2align 4,,10
	.p2align 3
.L116:
	movq	%r13, %rcx
	movq	%r12, %rdx
	movl	$65536, %r8d
	movq	%rbx, %rsi
	movq	%rbp, %rdi
	call	_Z11recalcFieldILm64ELi8EEvPcS0_mmm
	movq	%r13, %rcx
	movq	%r12, %rdx
	movl	$65536, %r8d
	movq	%rbx, %rsi
	movq	%rbp, %rdi
	addq	%r12, %r12
	call	_Z11recalcFieldILm4096ELi8EEvPcS0_mmm
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movl	$_ZSt4cout, %edi
	salq	$2, %r13
	call	_ZNSolsEPFRSoS_E
	subl	$1, %r14d
	jne	.L116
	movq	%rbp, %rdi
	call	_ZdaPv
	movq	%rbx, %rdi
	call	_ZdaPv
	popq	%rbx
	.cfi_def_cfa_offset 40
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE7837:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE14:
	.section	.text.startup
.LHOTE14:
	.section	.text.unlikely._ZN10BarrierOMPILm4096EE4waitEv,"axG",@progbits,_ZN10BarrierOMPILm4096EE4waitEv,comdat
	.align 2
.LCOLDB15:
	.section	.text._ZN10BarrierOMPILm4096EE4waitEv,"axG",@progbits,_ZN10BarrierOMPILm4096EE4waitEv,comdat
.LHOTB15:
	.align 2
	.p2align 4,,15
	.weak	_ZN10BarrierOMPILm4096EE4waitEv
	.type	_ZN10BarrierOMPILm4096EE4waitEv, @function
_ZN10BarrierOMPILm4096EE4waitEv:
.LFB7990:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	omp_get_thread_num
	testl	%eax, %eax
	jne	.L121
	movq	8(%rbp), %r9
	movq	0(%rbp), %rbx
	.p2align 4,,10
	.p2align 3
.L128:
	cmpq	$1, %r9
	movzbl	16(%rbp), %r11d
	jbe	.L136
	movl	16384(%rbx), %esi
	movzbl	%r11b, %r10d
	leaq	32768(%rbx), %rdx
	movl	$1, %eax
	cmpl	%r10d, %esi
	sete	%r8b
	je	.L126
	jmp	.L124
	.p2align 4,,10
	.p2align 3
.L127:
	movl	(%rdx), %ecx
	cmpl	%esi, %ecx
	sete	%r8b
	addq	$16384, %rdx
	cmpl	%esi, %ecx
	jne	.L124
.L126:
	addq	$1, %rax
	cmpq	%r9, %rax
	jne	.L127
.L124:
	testb	%r8b, %r8b
	je	.L128
.L123:
	xorl	$1, %r11d
	movb	%r11b, 16(%rbp)
	movl	%r10d, (%rbx)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L121:
	.cfi_restore_state
	movzbl	16(%rbp), %edx
	movq	0(%rbp), %rcx
	cltq
	movzbl	16(%rbp), %esi
	salq	$14, %rax
	addq	%rcx, %rax
	movl	%esi, (%rax)
	.p2align 4,,10
	.p2align 3
.L130:
	movl	(%rcx), %eax
	cmpl	%edx, %eax
	jne	.L130
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L136:
	.cfi_restore_state
	movzbl	%r11b, %r10d
	jmp	.L123
	.cfi_endproc
.LFE7990:
	.size	_ZN10BarrierOMPILm4096EE4waitEv, .-_ZN10BarrierOMPILm4096EE4waitEv
	.section	.text.unlikely._ZN10BarrierOMPILm4096EE4waitEv,"axG",@progbits,_ZN10BarrierOMPILm4096EE4waitEv,comdat
.LCOLDE15:
	.section	.text._ZN10BarrierOMPILm4096EE4waitEv,"axG",@progbits,_ZN10BarrierOMPILm4096EE4waitEv,comdat
.LHOTE15:
	.section	.text.unlikely._Z11recalcFieldILm4096ELi8EEvPcS0_mmm._omp_fn.1,"axG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
.LCOLDB16:
	.section	.text._Z11recalcFieldILm4096ELi8EEvPcS0_mmm._omp_fn.1,"axG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
.LHOTB16:
	.p2align 4,,15
	.type	_Z11recalcFieldILm4096ELi8EEvPcS0_mmm._omp_fn.1, @function
_Z11recalcFieldILm4096ELi8EEvPcS0_mmm._omp_fn.1:
.LFB8090:
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
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	movq	(%rbx), %rdx
	movq	24(%rbx), %r12
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	movq	32(%rdi), %rax
	movq	$-1, 32(%rsp)
	movq	%rdx, 40(%rsp)
	movq	%rax, %rdi
	movq	%rax, 24(%rsp)
	movq	16(%rbx), %rax
	testq	%rdi, %rdi
	movq	%rax, 16(%rsp)
	movq	8(%rbx), %rax
	movq	%rax, 48(%rsp)
	je	.L145
	movq	16(%rsp), %rbp
	movq	%r12, %r13
	movq	$0, 8(%rsp)
	notq	%r13
	imulq	%r12, %rbp
.L146:
	cmpq	$0, 16(%rsp)
	je	.L153
	call	omp_get_num_threads
	movslq	%eax, %r14
	call	omp_get_thread_num
	movslq	%eax, %rcx
	movq	16(%rsp), %rax
	xorl	%edx, %edx
	divq	%r14
	cmpq	%rdx, %rcx
	jnb	.L170
	addq	$1, %rax
	xorl	%edx, %edx
.L170:
	imulq	%rax, %rcx
	addq	%rcx, %rdx
	leaq	(%rax,%rdx), %r15
	cmpq	%r15, %rdx
	jnb	.L153
	leaq	1(%rdx), %r14
	movq	%r14, %r11
	imulq	%r12, %r11
	.p2align 4,,10
	.p2align 3
.L155:
	movq	%r11, %r9
	subq	%r12, %r9
	testq	%r12, %r12
	je	.L159
	.p2align 4,,10
	.p2align 3
.L175:
	movq	40(%rsp), %r10
	leaq	0(%r13,%r9), %rsi
	movl	$-1, %ecx
	xorl	%r8d, %r8d
.L165:
	testl	%ecx, %ecx
	movq	%rsi, %rdx
	movl	$-1, %eax
	setne	%dil
.L156:
	testl	%eax, %eax
	je	.L169
	testb	%dil, %dil
	je	.L169
	cmpq	%rdx, %rbp
	jbe	.L169
	cmpb	$1, (%r10,%rdx)
	sbbl	$-1, %r8d
.L169:
	addl	$1, %eax
	addq	$1, %rdx
	cmpl	$2, %eax
	jne	.L156
	addl	$1, %ecx
	addq	%r12, %rsi
	cmpl	$2, %ecx
	jne	.L165
	cmpb	$0, (%r10,%r9)
	je	.L191
	subl	$2, %r8d
	cmpl	$1, %r8d
	jbe	.L184
.L163:
	movq	48(%rsp), %rax
	movb	$0, (%rax,%r9)
.L162:
	addq	$1, %r9
	cmpq	%r9, %r11
	jne	.L175
.L159:
	addq	%r12, %r11
	cmpq	%r14, %r15
	je	.L153
	addq	$1, %r14
	jmp	.L155
	.p2align 4,,10
	.p2align 3
.L191:
	cmpl	$3, %r8d
	jne	.L163
.L184:
	movq	48(%rsp), %rax
	movb	$1, (%rax,%r9)
	jmp	.L162
.L153:
	call	GOMP_barrier
	call	_Z5rdtscv
	movq	40(%rbx), %rdi
	movq	%rax, %r15
	call	_ZN10BarrierOMPILm4096EE4waitEv
	call	_Z5rdtscv
	movq	%rax, %r14
	call	GOMP_single_start
	testb	%al, %al
	je	.L151
	movq	$0, 64(%rbx)
.L151:
	call	GOMP_barrier
	subq	%r15, %r14
	cmpq	%r14, 32(%rsp)
	movq	%r14, %rax
	cmovbe	32(%rsp), %rax
	shrq	$3, %r14
	movq	%rax, 32(%rsp)
	call	GOMP_critical_start
	movq	64(%rbx), %rax
	addq	%rax, %r14
	movq	%r14, 64(%rbx)
	call	GOMP_critical_end
	movq	40(%rbx), %rdi
	call	_ZN10BarrierOMPILm4096EE4waitEv
	call	GOMP_single_start
	testb	%al, %al
	je	.L149
	movq	56(%rbx), %rdx
	movq	64(%rbx), %rax
	cmpq	%rax, %rdx
	ja	.L192
	movq	56(%rbx), %rax
.L150:
	movq	%rax, 56(%rbx)
.L149:
	call	GOMP_barrier
	movq	40(%rbx), %rdi
	call	_ZN10BarrierOMPILm4096EE4waitEv
	leaq	48(%rsp), %rsi
	leaq	40(%rsp), %rdi
	call	_ZSt4swapIPcEvRT_S2_
	addq	$1, 8(%rsp)
	movq	8(%rsp), %rax
	cmpq	%rax, 24(%rsp)
	jne	.L146
.L145:
	call	GOMP_critical_start
	movq	48(%rbx), %rax
	cmpq	32(%rsp), %rax
	jbe	.L193
	movq	32(%rsp), %rax
.L141:
	movq	%rax, 48(%rbx)
	call	GOMP_critical_end
	movq	40(%rbx), %rdi
	call	_ZN10BarrierOMPILm4096EE4waitEv
	movq	56(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L194
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
.L192:
	.cfi_restore_state
	movq	64(%rbx), %rax
	jmp	.L150
.L193:
	movq	48(%rbx), %rax
	jmp	.L141
.L194:
	call	__stack_chk_fail
	.cfi_endproc
.LFE8090:
	.size	_Z11recalcFieldILm4096ELi8EEvPcS0_mmm._omp_fn.1, .-_Z11recalcFieldILm4096ELi8EEvPcS0_mmm._omp_fn.1
	.section	.text.unlikely._Z11recalcFieldILm4096ELi8EEvPcS0_mmm._omp_fn.1,"axG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
.LCOLDE16:
	.section	.text._Z11recalcFieldILm4096ELi8EEvPcS0_mmm._omp_fn.1,"axG",@progbits,_Z11recalcFieldILm4096ELi8EEvPcS0_mmm,comdat
.LHOTE16:
	.section	.text.unlikely
.LCOLDB17:
	.section	.text.startup
.LHOTB17:
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB8088:
	.cfi_startproc
	jmp	_Z41__static_initialization_and_destruction_0ii.constprop.4
	.cfi_endproc
.LFE8088:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.text.unlikely
.LCOLDE17:
	.section	.text.startup
.LHOTE17:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
