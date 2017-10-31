	.file	"main100.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"100 : %llu\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB31:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$100000, %edi
	movq	$-1, %rsi
	.p2align 4,,10
	.p2align 3
.L3:
#APP
# 6 "main100.c" 1
	rdtsc

# 0 "" 2
#NO_APP
	movl	%eax, %ecx
	salq	$32, %rdx
	movl	$100, %eax
	orq	%rdx, %rcx
	.p2align 4,,10
	.p2align 3
.L2:
#APP
# 17 "main100.c" 1
	nop
# 0 "" 2
# 17 "main100.c" 1
	nop
# 0 "" 2
# 17 "main100.c" 1
	nop
# 0 "" 2
# 17 "main100.c" 1
	nop
# 0 "" 2
# 17 "main100.c" 1
	nop
# 0 "" 2
# 17 "main100.c" 1
	nop
# 0 "" 2
# 17 "main100.c" 1
	nop
# 0 "" 2
# 17 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 18 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 19 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 20 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 21 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 22 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 23 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 24 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 25 "main100.c" 1
	nop
# 0 "" 2
# 26 "main100.c" 1
	nop
# 0 "" 2
# 26 "main100.c" 1
	nop
# 0 "" 2
# 26 "main100.c" 1
	nop
# 0 "" 2
# 26 "main100.c" 1
	nop
# 0 "" 2
# 26 "main100.c" 1
	nop
# 0 "" 2
# 26 "main100.c" 1
	nop
# 0 "" 2
#NO_APP
	subl	$1, %eax
	jne	.L2
#APP
# 6 "main100.c" 1
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
	movq	%rsi, %rdx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE31:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
