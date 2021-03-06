/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^251-9) from the paper         |
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
.globl gfp2519mul
gfp2519mul:

movq   %rsp, %r11
subq   $64, %rsp

movq   %r11,  0(%rsp)
movq   %r12,  8(%rsp)
movq   %r13, 16(%rsp)
movq   %r14, 24(%rsp)
movq   %r15, 32(%rsp)
movq   %rbx, 40(%rsp)
movq   %rbp, 48(%rsp)
movq   %rdi, 56(%rsp)

movq   %rdx, %rcx

movq   0(%rsi), %rax
mulq   0(%rcx)
movq   %rax, %r8
movq   %rdx, %r9

movq   0(%rsi), %rax
mulq   8(%rcx)
movq   %rax, %r10
movq   %rdx, %r11

movq   8(%rsi), %rax
mulq   0(%rcx)
addq   %rax, %r10
adcq   %rdx, %r11

movq   0(%rsi), %rax
mulq   16(%rcx)
movq   %rax, %r12
movq   %rdx, %r13

movq   8(%rsi), %rax
mulq   8(%rcx)
addq   %rax, %r12
adcq   %rdx, %r13

movq   16(%rsi), %rax
mulq   0(%rcx)
addq   %rax, %r12
adcq   %rdx, %r13

movq   0(%rsi), %rax
mulq   24(%rcx)
movq   %rax, %r14
movq   %rdx, %r15

movq   8(%rsi), %rax
mulq   16(%rcx)
addq   %rax, %r14
adcq   %rdx, %r15

movq   16(%rsi), %rax
mulq   8(%rcx)
addq   %rax, %r14
adcq   %rdx, %r15

movq   24(%rsi), %rax
mulq   0(%rcx)
addq   %rax, %r14
adcq   %rdx, %r15

movq   0(%rsi), %rax
mulq   32(%rcx)
movq   %rax, %rbx
movq   %rdx, %rbp

movq   8(%rsi), %rax
mulq   24(%rcx)
addq   %rax, %rbx
adcq   %rdx, %rbp

movq   16(%rsi), %rax
mulq   16(%rcx)
addq   %rax, %rbx
adcq   %rdx, %rbp

movq   24(%rsi), %rax
mulq   8(%rcx)
addq   %rax, %rbx
adcq   %rdx, %rbp

movq   32(%rsi), %rax
mulq   0(%rcx)
addq   %rax, %rbx
adcq   %rdx, %rbp

imul   $144, 8(%rsi), %rax
mulq   32(%rcx)
addq   %rax, %r8
adcq   %rdx, %r9

imul   $144, 16(%rsi), %rax
mulq   24(%rcx)
addq   %rax, %r8
adcq   %rdx, %r9

imul   $144, 24(%rsi), %rax
mulq   16(%rcx)
addq   %rax, %r8
adcq   %rdx, %r9

imul   $144, 32(%rsi), %rax
mulq   8(%rcx)
addq   %rax, %r8
adcq   %rdx, %r9

imul   $144, 16(%rsi), %rax
mulq   32(%rcx)
addq   %rax, %r10
adcq   %rdx, %r11

imul   $144, 24(%rsi), %rax
mulq   24(%rcx)
addq   %rax, %r10
adcq   %rdx, %r11

imul   $144, 32(%rsi), %rax
mulq   16(%rcx)
addq   %rax, %r10
adcq   %rdx, %r11

imul   $144, 24(%rsi), %rax
mulq   32(%rcx)
addq   %rax, %r12
adcq   %rdx, %r13

imul   $144, 32(%rsi), %rax
mulq   24(%rcx)
addq   %rax, %r12
adcq   %rdx, %r13

imul   $144, 32(%rsi), %rax
mulq   32(%rcx)
addq   %rax, %r14
adcq   %rdx, %r15

movq   mask51, %rdx

shld   $13, %r8, %r9
addq   %r9, %r10
adcq   $0, %r11
andq   %rdx, %r8

shld   $13, %r10, %r11
addq   %r11, %r12
adcq   $0, %r13
andq   %rdx, %r10

shld   $13, %r12, %r13
addq   %r13, %r14
adcq   $0, %r15
andq   %rdx, %r12

shld   $13, %r14, %r15
addq   %r15, %rbx
adcq   $0, %rbp
andq   %rdx, %r14

shld   $17, %rbx, %rbp
imul   $9, %rbp, %rbp
addq   %rbp, %r8
andq   mask47, %rbx

movq   %r8, %r9
shrq   $51, %r9
addq   %r9, %r10
andq   %rdx, %r8

movq   %r8,   0(%rdi)
movq   %r10,  8(%rdi)
movq   %r12, 16(%rdi)
movq   %r14, 24(%rdi)
movq   %rbx, 32(%rdi)

movq   0(%rsp),  %r11
movq   8(%rsp),  %r12
movq   16(%rsp), %r13
movq   24(%rsp), %r14
movq   32(%rsp), %r15
movq   40(%rsp), %rbx
movq   48(%rsp), %rbp

movq   %r11, %rsp

ret


.p2align 5
.globl gfp2519reduce
gfp2519reduce:

movq   0(%rdi),   %r8
movq   8(%rdi),   %r9
movq   16(%rdi), %r10
movq   24(%rdi), %r11
movq   32(%rdi), %rcx

movq   %r9,    %rax
shrq   $51,    %rax
addq   %r10,   %rax
andq   mask51,  %r9

movq   %rax,   %r10
shrq   $51,    %rax
addq   %r11,   %rax
andq   mask51, %r10

movq   %rax,   %r11
shrq   $51,    %rax
addq   %rcx,   %rax
andq   mask51, %r11

movq   %rax,   %rcx
shrq   $47,    %rax
addq   %rax,    %r8
shlq   $3, %rax 
addq   %r8,    %rax
andq   mask47, %rcx

movq   %rax,    %r8
shrq   $51,    %rax
addq   %r9,    %rax
andq   mask51,  %r8

movq   %rax,    %r9
shrq   $51,    %rax
addq   %rax,   %r10
andq   mask51,  %r9

movq    %r8,   0(%rdi)
movq    %r9,   8(%rdi)
movq    %r10, 16(%rdi)
movq    %r11, 24(%rdi)
movq    %rcx, 32(%rdi)

ret
