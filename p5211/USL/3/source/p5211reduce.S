/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^521-1) from the paper         |
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

.data

.globl mask57
.globl mask58

.p2align 4
mask57:	.quad 0x01FFFFFFFFFFFFFF
mask58:	.quad 0x03FFFFFFFFFFFFFF

.p2align 5
.globl gfp5211reduce
gfp5211reduce:

movq	%rsp, %r11
subq	$40, %rsp

movq 	%r11,  0(%rsp)
movq 	%r12,  8(%rsp)
movq 	%r13, 16(%rsp)
movq 	%r14, 24(%rsp)
movq 	%r15, 32(%rsp)

movq 	0(%rdi), %r8
movq 	8(%rdi), %r9
movq 	16(%rdi), %r10
movq 	24(%rdi), %r11
movq 	32(%rdi), %r12
movq 	40(%rdi), %r13
movq 	48(%rdi), %r14
movq 	56(%rdi), %r15
movq 	64(%rdi), %rsi

movq 	mask58, %rax

movq	%r8, %rdx
shrq	$58, %rdx
addq	%r9, %rdx
andq	%rax, %r8

movq	%rdx, %r9
shrq	$58, %rdx
addq	%r10, %rdx
andq	%rax, %r9

movq	%rdx, %r10
shrq	$58, %rdx
addq	%r11, %rdx
andq	%rax, %r10

movq	%rdx, %r11
shrq	$58, %rdx
addq	%r12, %rdx
andq	%rax, %r11

movq	%rdx, %r12
shrq	$58, %rdx
addq	%r13, %rdx
andq	%rax, %r12

movq	%rdx, %r13
shrq	$58, %rdx
addq	%r14, %rdx
andq	%rax, %r13

movq	%rdx, %r14
shrq	$58, %rdx
addq	%r15, %rdx
andq	%rax, %r14

movq	%rdx, %r15
shrq	$58, %rdx
addq	%rsi, %rdx
andq	%rax, %r15

movq	%rdx, %rsi
shrq	$57, %rdx
addq	%r8, %rdx
andq	mask57, %rsi

movq	%rdx, %r8
shrq	$58, %rdx
addq	%rdx, %r9
andq	%rax, %r8

movq 	%r8,   0(%rdi)
movq 	%r9,   8(%rdi)
movq 	%r10, 16(%rdi)
movq 	%r11, 24(%rdi)
movq 	%r12, 32(%rdi)
movq 	%r13, 40(%rdi)
movq 	%r14, 48(%rdi)
movq 	%r15, 56(%rdi)
movq 	%rsi, 64(%rdi)

movq 	 0(%rsp), %r11
movq 	 8(%rsp), %r12
movq 	16(%rsp), %r13
movq 	24(%rsp), %r14
movq 	32(%rsp), %r15

mov 	%r11, %rsp

ret

