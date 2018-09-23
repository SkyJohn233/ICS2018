	.file	"dixsix.cpp"
	.text
	.p2align 4,,15
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
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
	.size	_Z1fi, .-_Z1fi
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
