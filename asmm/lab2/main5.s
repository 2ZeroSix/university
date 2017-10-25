	.file	"main5.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"5 : %llu\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB1:
	.section	.text.startup,"ax",@progbits
.LHOTB1:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB7346:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA7346
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$27765, %edx
	subq	$5040, %rsp
	.cfi_def_cfa_offset 5056
	movq	%fs:40, %rax
	movq	%rax, 5032(%rsp)
	xorl	%eax, %eax
	leaq	16(%rsp), %rax
	leaq	32(%rsp), %rdi
	movl	$1634100580, 16(%rsp)
	movq	%rsp, %rsi
	movq	$7, 8(%rsp)
	movw	%dx, 4(%rax)
	movb	$116, 6(%rax)
	movq	%rax, (%rsp)
	movb	$0, 23(%rsp)
.LEHB0:
	call	_ZNSt13random_device7_M_initERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.LEHE0:
	movq	(%rsp), %rdi
	leaq	16(%rsp), %rax
	cmpq	%rax, %rdi
	je	.L2
	call	_ZdlPv
.L2:
	movl	$26214400, %ebx
	.p2align 4,,10
	.p2align 3
.L3:
	leaq	32(%rsp), %rdi
.LEHB1:
	call	_ZNSt13random_device9_M_getvalEv
	subl	$1, %ebx
	jne	.L3
	movl	$100000, %edi
	movq	$-1, %rsi
	.p2align 4,,10
	.p2align 3
.L5:
#APP
# 8 "main5.c" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movq	%rdx, %rcx
	orq	%rax, %rcx
	movl	$100, %eax
	.p2align 4,,10
	.p2align 3
.L4:
#APP
# 26 "main5.c" 1
	nop
# 0 "" 2
# 26 "main5.c" 1
	nop
# 0 "" 2
# 26 "main5.c" 1
	nop
# 0 "" 2
# 26 "main5.c" 1
	nop
# 0 "" 2
# 26 "main5.c" 1
	nop
# 0 "" 2
#NO_APP
	subl	$1, %eax
	jne	.L4
#APP
# 8 "main5.c" 1
	rdtsc

# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	subq	%rcx, %rax
	cmpq	%rax, %rsi
	cmova	%rax, %rsi
	subl	$1, %edi
	jne	.L5
	movq	%rsi, %rdx
	movl	$1, %edi
	movl	$.LC0, %esi
	xorl	%eax, %eax
	call	__printf_chk
.LEHE1:
	leaq	32(%rsp), %rdi
	call	_ZNSt13random_device7_M_finiEv
	xorl	%eax, %eax
	movq	5032(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L20
	addq	$5040, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L11:
	.cfi_restore_state
	leaq	32(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZNSt13random_device7_M_finiEv
.L17:
	movq	%rbx, %rdi
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L10:
	movq	(%rsp), %rdi
	leaq	16(%rsp), %rdx
	movq	%rax, %rbx
	cmpq	%rdx, %rdi
	je	.L17
	call	_ZdlPv
	jmp	.L17
.L20:
	call	__stack_chk_fail
	.cfi_endproc
.LFE7346:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA7346:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7346-.LLSDACSB7346
.LLSDACSB7346:
	.uleb128 .LEHB0-.LFB7346
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L10-.LFB7346
	.uleb128 0
	.uleb128 .LEHB1-.LFB7346
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L11-.LFB7346
	.uleb128 0
	.uleb128 .LEHB2-.LFB7346
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE7346:
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE1:
	.section	.text.startup
.LHOTE1:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
