/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^512-569) from the paper       |
| "Efficient Inversion In (Pseudo-)Mersenne Prime Order Fields" authored by   |
| Kaushik Nath,  Indian Statistical Institute, Kolkata, India, and            |
| Palash Sarkar, Indian Statistical Institute, Kolkata, India.	              |
+-----------------------------------------------------------------------------+
| Copyright (c) 2018, Kaushik Nath and Palash Sarkar.                         |
|                                                                             |
| Permission to use this code is granted.                          	      |
|                                                                             |
| Redistribution and use in source and binary forms, with or without          |
| modification, are permitted provided that the following conditions are      |
| met:                                                                        |
|                                                                             |
| * Redistributions of source code must retain the above copyright notice,    |
|   this list of conditions and the following disclaimer.                     |
|                                                                             |
| * Redistributions in binary form must reproduce the above copyright         |
|   notice, this list of conditions and the following disclaimer in the       |
|   documentation and/or other materials provided with the distribution.      |
|                                                                             |
| * The names of the contributors may not be used to endorse or promote       |
|   products derived from this software without specific prior written        |
|   permission.                                                               |
+-----------------------------------------------------------------------------+
| THIS SOFTWARE IS PROVIDED BY THE AUTHORS ""AS IS"" AND ANY EXPRESS OR       |
| IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES   |
| OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.     |
| IN NO EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,      |
| INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT    |
| NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   |
| DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY       |
| THEORY LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING |
| NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,| 
| EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                          |
+-----------------------------------------------------------------------------+
*/

.p2align 5
.globl gfp512569mul
gfp512569mul:

movq	%rsp, %r11
subq	$184, %rsp

movq 	%r11,  0(%rsp)
movq 	%r12,  8(%rsp)
movq 	%r13, 16(%rsp)
movq 	%r14, 24(%rsp)
movq 	%r15, 32(%rsp)
movq 	%rbx, 40(%rsp)
movq 	%rbp, 48(%rsp)
movq 	%rdi, 56(%rsp)

movq	%rdx, %rcx

movq    8(%rsi), %rax
mulq	64(%rcx)		
movq    %rax, %r8
movq    %rdx, %r9

movq    16(%rsi), %rax
mulq    56(%rcx)		
addq    %rax, %r8
adcq    %rdx, %r9    		

movq    24(%rsi), %rax
mulq    48(%rcx)		
addq    %rax, %r8
adcq    %rdx, %r9    		

movq    32(%rsi), %rax
mulq    40(%rcx)		
addq    %rax, %r8
adcq    %rdx, %r9    		

movq    40(%rsi), %rax
mulq    32(%rcx)		
addq    %rax, %r8
adcq    %rdx, %r9    		

movq    48(%rsi), %rax
mulq    24(%rcx)		
addq    %rax, %r8
adcq    %rdx, %r9    		

movq    56(%rsi), %rax
mulq    16(%rcx)		
addq    %rax, %r8
adcq    %rdx, %r9    		

movq    64(%rsi), %rax
mulq    8(%rcx)		
addq    %rax, %r8
adcq    %rdx, %r9

movq	$1138, %rax
mulq	%r8
movq	%rax, %r8
imul 	$1138, %r9, %r9
addq	%rdx, %r9

movq	0(%rsi), %rax
mulq	0(%rcx)
addq    %rax, %r8	
adcq    %rdx, %r9

movq    16(%rsi), %rax
mulq    64(%rcx)		
movq    %rax, %r10
movq    %rdx, %r11    		

movq    24(%rsi), %rax
mulq    56(%rcx)		
addq    %rax, %r10
adcq    %rdx, %r11    		

movq    32(%rsi), %rax
mulq    48(%rcx)		
addq    %rax, %r10
adcq    %rdx, %r11    		

movq    40(%rsi), %rax
mulq    40(%rcx)		
addq    %rax, %r10
adcq    %rdx, %r11    		

movq    48(%rsi), %rax
mulq    32(%rcx)		
addq    %rax, %r10
adcq    %rdx, %r11    		

movq    56(%rsi), %rax
mulq    24(%rcx)		
addq    %rax, %r10
adcq    %rdx, %r11    		

movq    64(%rsi), %rax
mulq    16(%rcx)		
addq    %rax, %r10
adcq    %rdx, %r11

movq	$1138, %rax
mulq	%r10
movq	%rax, %r10
imul 	$1138, %r11, %r11
addq	%rdx, %r11
    		
movq	0(%rsi), %rax
mulq	8(%rcx)
addq    %rax, %r10
adcq    %rdx, %r11

movq	8(%rsi), %rax
mulq	0(%rcx)
addq    %rax, %r10
adcq    %rdx, %r11

movq    24(%rsi), %rax
mulq    64(%rcx)		
movq    %rax, %r12
movq    %rdx, %r13    		

movq    32(%rsi), %rax
mulq    56(%rcx)		
addq    %rax, %r12
adcq    %rdx, %r13    		

movq    40(%rsi), %rax
mulq    48(%rcx)		
addq    %rax, %r12
adcq    %rdx, %r13    		

movq    48(%rsi), %rax
mulq    40(%rcx)		
addq    %rax, %r12
adcq    %rdx, %r13    		

movq    56(%rsi), %rax
mulq    32(%rcx)		
addq    %rax, %r12
adcq    %rdx, %r13    		

movq    64(%rsi), %rax
mulq    24(%rcx)		
addq    %rax, %r12
adcq    %rdx, %r13

movq	$1138, %rax
mulq	%r12
movq	%rax, %r12
imul 	$1138, %r13, %r13
addq	%rdx, %r13

movq	0(%rsi), %rax
mulq	16(%rcx)
addq    %rax, %r12
adcq    %rdx, %r13

movq	8(%rsi), %rax
mulq	8(%rcx)	
addq    %rax, %r12
adcq    %rdx, %r13

movq	16(%rsi), %rax
mulq	0(%rcx)	
addq    %rax, %r12
adcq    %rdx, %r13

movq    32(%rsi), %rax
mulq    64(%rcx)		
movq    %rax, %r14
movq    %rdx, %r15    		

movq    40(%rsi), %rax
mulq    56(%rcx)		
addq    %rax, %r14
adcq    %rdx, %r15    		

movq    48(%rsi), %rax
mulq    48(%rcx)		
addq    %rax, %r14
adcq    %rdx, %r15    		

movq    56(%rsi), %rax
mulq    40(%rcx)		
addq    %rax, %r14
adcq    %rdx, %r15    		

movq    64(%rsi), %rax
mulq    32(%rcx)		
addq    %rax, %r14
adcq    %rdx, %r15

movq	$1138, %rax
mulq	%r14
movq	%rax, %r14
imul 	$1138, %r15, %r15
addq	%rdx, %r15

movq	0(%rsi), %rax
mulq	24(%rcx)
addq    %rax, %r14
adcq    %rdx, %r15

movq	8(%rsi), %rax
mulq	16(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq	16(%rsi), %rax
mulq	8(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq	24(%rsi), %rax
mulq	0(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq    40(%rsi), %rax
mulq    64(%rcx)		
movq    %rax, %rbp
movq    %rdx, %rbx    		

movq    48(%rsi), %rax
mulq    56(%rcx)		
addq    %rax, %rbp
adcq    %rdx, %rbx    		

movq    56(%rsi), %rax
mulq    48(%rcx)		
addq    %rax, %rbp
adcq    %rdx, %rbx    		

movq    64(%rsi), %rax
mulq    40(%rcx)		
addq    %rax, %rbp
adcq    %rdx, %rbx    		

movq	$1138, %rax
mulq	%rbp
movq	%rax, %rbp
imul 	$1138, %rbx, %rbx
addq	%rdx, %rbx

movq	0(%rsi), %rax
mulq	32(%rcx)
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	8(%rsi), %rax
mulq	24(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	16(%rsi), %rax
mulq	16(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	24(%rsi), %rax
mulq	8(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	32(%rsi), %rax
mulq	0(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	%r10, 64(%rsp)
movq	%r11, 72(%rsp)

movq	%r12, 80(%rsp)
movq	%r13, 88(%rsp)

movq	%r14, 96(%rsp)
movq	%r15, 104(%rsp)

movq	%rbp, 112(%rsp)	
movq	%rbx, 120(%rsp)

movq    48(%rsi), %rax
mulq    64(%rcx)		
movq    %rax, %r10
movq    %rdx, %r11    		

movq    56(%rsi), %rax
mulq    56(%rcx)		
addq    %rax, %r10
adcq    %rdx, %r11    		

movq    64(%rsi), %rax
mulq    48(%rcx)		
addq    %rax, %r10
adcq    %rdx, %r11

movq	$1138, %rax
mulq	%r10
movq	%rax, %r10
imul 	$1138, %r11, %r11
addq	%rdx, %r11

movq	0(%rsi), %rax
mulq	40(%rcx)
addq    %rax, %r10
adcq    %rdx, %r11

movq	8(%rsi), %rax
mulq	32(%rcx)	
addq    %rax, %r10
adcq    %rdx, %r11

movq	16(%rsi), %rax
mulq	24(%rcx)	
addq    %rax, %r10
adcq    %rdx, %r11

movq	24(%rsi), %rax
mulq	16(%rcx)	
addq    %rax, %r10
adcq    %rdx, %r11

movq	32(%rsi), %rax
mulq	8(%rcx)	
addq    %rax, %r10
adcq    %rdx, %r11

movq	40(%rsi), %rax
mulq	0(%rcx)	
addq    %rax, %r10
adcq    %rdx, %r11

movq    56(%rsi), %rax
mulq    64(%rcx)		
movq    %rax, %r12
movq    %rdx, %r13    		

movq    64(%rsi), %rax
mulq    56(%rcx)		
addq    %rax, %r12
adcq    %rdx, %r13    		

movq	$1138, %rax
mulq	%r12
movq	%rax, %r12
imul 	$1138, %r13, %r13
addq	%rdx, %r13

movq	0(%rsi), %rax
mulq	48(%rcx)
addq    %rax, %r12
adcq    %rdx, %r13

movq	8(%rsi), %rax
mulq	40(%rcx)	
addq    %rax, %r12
adcq    %rdx, %r13

movq	16(%rsi), %rax
mulq	32(%rcx)	
addq    %rax, %r12
adcq    %rdx, %r13

movq	24(%rsi), %rax
mulq	24(%rcx)	
addq    %rax, %r12
adcq    %rdx, %r13

movq	32(%rsi), %rax
mulq	16(%rcx)	
addq    %rax, %r12
adcq    %rdx, %r13

movq	40(%rsi), %rax
mulq	8(%rcx)	
addq    %rax, %r12
adcq    %rdx, %r13

movq	48(%rsi), %rax
mulq	0(%rcx)	
addq    %rax, %r12
adcq    %rdx, %r13

movq    64(%rsi), %rax
mulq    64(%rcx)		
movq    %rax, %r14
movq    %rdx, %r15    		

movq	$1138, %rax
mulq	%r14
movq	%rax, %r14
imul 	$1138, %r15, %r15
addq	%rdx, %r15

movq	0(%rsi), %rax
mulq	56(%rcx)
addq    %rax, %r14
adcq    %rdx, %r15

movq	8(%rsi), %rax
mulq	48(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq	16(%rsi), %rax
mulq	40(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq	24(%rsi), %rax
mulq	32(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq	32(%rsi), %rax
mulq	24(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq	40(%rsi), %rax
mulq	16(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq	48(%rsi), %rax
mulq	8(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq	56(%rsi), %rax
mulq	0(%rcx)	
addq    %rax, %r14
adcq    %rdx, %r15

movq	0(%rsi), %rax
mulq	64(%rcx)
movq    %rax, %rbp
movq    %rdx, %rbx

movq	8(%rsi), %rax
mulq	56(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	16(%rsi), %rax
mulq	48(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	24(%rsi), %rax
mulq	40(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	32(%rsi), %rax
mulq	32(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	40(%rsi), %rax
mulq	24(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	48(%rsi), %rax
mulq	16(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	56(%rsi), %rax
mulq	8(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq	64(%rsi), %rax
mulq	0(%rcx)	
addq    %rax, %rbp
adcq    %rdx, %rbx

movq    mask57, %rdi

movq	%r8, %rax
shrd	$57, %r9, %rax
shrq	$57, %r9
addq	64(%rsp), %rax
adcq	72(%rsp), %r9
andq  	%rdi, %r8

movq	%rax, %rcx
shrd	$57, %r9, %rax
shrq	$57, %r9
addq	80(%rsp), %rax
adcq	88(%rsp), %r9
andq  	%rdi, %rcx

movq	%rax, %rsi
shrd	$57, %r9, %rax
shrq	$57, %r9
addq	96(%rsp), %rax
adcq	104(%rsp), %r9
andq  	%rdi, %rsi

movq	%rax, %rdx
shrd	$57, %r9, %rax
shrq	$57, %r9
addq	112(%rsp), %rax
adcq	120(%rsp), %r9
andq  	%rdi, %rdx

movq    %r8, 64(%rsp)

movq	%rax, %r8
shrd	$57, %r9, %rax
shrq	$57, %r9
addq	%r10, %rax
adcq	%r11, %r9
andq  	%rdi, %r8

movq	%rax, %r10
shrd	$57, %r9, %rax
shrq	$57, %r9
addq	%r12, %rax
adcq	%r13, %r9
andq  	%rdi, %r10

movq	%rax, %r11
shrd	$57, %r9, %rax
shrq	$57, %r9
addq	%r14, %rax
adcq	%r15, %r9
andq  	%rdi, %r11

movq	%rax, %r12
shrd	$57, %r9, %rax
shrq	$57, %r9
addq	%rbp, %rax
adcq	%rbx, %r9
andq  	%rdi, %r12

movq    %rax, %r13
shld	$8, %r13, %r9
andq  	mask56, %r13

movq	%rdx, 72(%rsp)

movq	$569, %rax
mulq	%r9
addq	64(%rsp), %rax
adcq	$0, %rdx

shld	$7, %rax, %rdx
addq	%rdx, %rcx
andq  	%rdi, %rax

movq	72(%rsp), %rdx

movq 	56(%rsp), %rdi

movq   	%rax,  0(%rdi)
movq   	%rcx,  8(%rdi)
movq   	%rsi, 16(%rdi)
movq   	%rdx, 24(%rdi)
movq   	%r8,  32(%rdi)
movq   	%r10, 40(%rdi)
movq   	%r11, 48(%rdi)
movq   	%r12, 56(%rdi)
movq   	%r13, 64(%rdi)

movq 	 0(%rsp), %r11
movq 	 8(%rsp), %r12
movq 	16(%rsp), %r13
movq 	24(%rsp), %r14
movq 	32(%rsp), %r15
movq 	40(%rsp), %rbx
movq 	48(%rsp), %rbp

movq	%r11, %rsp

ret


.p2align 5
.globl gfp512569reduce
gfp512569reduce:

movq 	%rsp, %r11
subq 	$24, %rsp

movq 	%r11,  0(%rsp)
movq 	%r12,  8(%rsp)
movq 	%r13, 16(%rsp)

movq    0(%rdi),   %r8
movq    8(%rdi),   %r9
movq    16(%rdi), %r10
movq    24(%rdi), %r11
movq    32(%rdi), %rax
movq    40(%rdi), %rcx
movq    48(%rdi), %rdx
movq    56(%rdi), %r12
movq    64(%rdi), %r13

movq	%r9, %rsi
shrq 	$57, %rsi
addq	%r10, %rsi
andq	mask57, %r9

movq	%rsi, %r10
shrq 	$57, %rsi
addq	%r11, %rsi
andq	mask57, %r10

movq	%rsi, %r11
shrq 	$57, %rsi
addq	%rax, %rsi
andq	mask57, %r11

movq	%rsi, %rax
shrq 	$57, %rsi
addq	%rcx, %rsi
andq	mask57, %rax

movq	%rsi, %rcx
shrq 	$57, %rsi
addq	%rdx, %rsi
andq	mask57, %rcx

movq	%rsi, %rdx
shrq 	$57, %rsi
addq	%r12, %rsi
andq	mask57, %rcx

movq	%rsi, %r12
shrq 	$57, %rsi
addq	%r13, %rsi
andq	mask57, %rcx

movq	%rsi, %r13
shrq 	$56, %rsi
imul 	$569, %rsi, %rsi
addq	%rsi, %r8
andq	mask56, %r13

movq	%r8, %rsi
shrq 	$57, %rsi
addq	%r9, %rsi
andq	mask57, %r8

movq	%r9, %rsi
shrq 	$57, %rsi
addq	%rsi, %r10
andq	mask57, %r9

movq    %r8,   0(%rdi)
movq    %r9,   8(%rdi)
movq    %r10, 16(%rdi)
movq    %r11, 24(%rdi)
movq    %rax, 32(%rdi)
movq    %rcx, 40(%rdi)
movq    %rdx, 48(%rdi)
movq    %r12, 56(%rdi)
movq    %r13, 64(%rdi)

movq 	 0(%rsp), %r11
movq 	 8(%rsp), %r12
movq 	 16(%rsp), %r13

movq 	%r11, %rsp

ret
