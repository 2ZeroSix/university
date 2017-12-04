	.file	"main.c"
	.section	.text._Z5rdtscv,"axG",@progbits,_Z5rdtscv,comdat
	.weak	_Z5rdtscv
	.type	_Z5rdtscv, @function
_Z5rdtscv:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
#APP
# 5 "main.c" 1
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
.LFE0:
	.size	_Z5rdtscv, .-_Z5rdtscv
	.section	.rodata
.LC0:
	.string	"%llu\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	# movl	$1, -36(%rbp)
	movq	$-1, -24(%rbp)
	movl	$0, -32(%rbp)
.L7:
	cmpl	$9999, -32(%rbp)
	jg	.L4
	movl	$0, %ecx
	call	_Z5rdtscv
	movq	%rax, %rbx
.L6:
	cmpl	$999, %ecx
	jg	.L5
	imull	%eax, %eax
	imull	%eax, %eax
	imull	%eax, %eax
	imull	%eax, %eax
	imull	%eax, %eax
	imull	%eax, %eax
	imull	%eax, %eax
	imull	%eax, %eax
	addl	$1, %ecx
	jmp	.L6
.L5:
	call	_Z5rdtscv
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	%rbx, %rax
	movq	%rax, -24(%rbp)
	addl	$1, -32(%rbp)
	jmp	.L7
.L4:
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
