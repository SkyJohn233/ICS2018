	.file	"divsix.cpp"
	.text
	.p2align 4,,15
	.globl	_Z6divSixi
	.type	_Z6divSixi, @function
_Z6divSixi:
.LFB0:
	.cfi_startproc
	movl	%edi, %eax
	movl	$715827883, %edx
	sarl	$31, %edi
	imull	%edx
	movl	%edx, %eax
	subl	%edi, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z6divSixi, .-_Z6divSixi
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
