	.file	"main1.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"1 : %llu\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB1:
	.section	.text.startup,"ax",@progbits
.LHOTB1:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB31:
	.cfi_startproc
	movl	$100000, %edi
	movq	$-1, %rsi
	.p2align 4,,10
	.p2align 3
.L3:
#APP
# 6 "main1.c" 1
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
.L2:
#APP
# 17 "main1.c" 1
	nop
# 0 "" 2
#NO_APP
	subl	$1, %eax
	jne	.L2
#APP
# 6 "main1.c" 1
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
	jne	.L3
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	%rsi, %rdx
	movl	$1, %edi
	movl	$.LC0, %esi
	xorl	%eax, %eax
	call	__printf_chk
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE31:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE1:
	.section	.text.startup
.LHOTE1:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
