/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^832-143) from the paper       |
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
.globl gfp832143nsqr
gfp832143nsqr:

    movq    %rsp, %r11
    subq    $184, %rsp

    movq    %r11,  0(%rsp)
    movq    %r12,  8(%rsp)
    movq    %r13, 16(%rsp)
    movq    %r14, 24(%rsp)
    movq    %r15, 32(%rsp)
    movq    %rbp, 40(%rsp)
    movq    %rbx, 48(%rsp)
    movq    %rdi, 56(%rsp)

    movq    0(%rsi),  %r8
    movq    8(%rsi),  %r9  
    movq    16(%rsi), %r10
    movq    24(%rsi), %r11
    movq    32(%rsi), %r12
    movq    40(%rsi), %r13
    movq    48(%rsi), %r14
    movq    56(%rsi), %r15
    movq    64(%rsi), %rax
    movq    72(%rsi), %rbx
    movq    80(%rsi), %rcx
    movq    88(%rsi), %rbp

    movq    %r8,   0(%rdi)	
    movq    %r9,   8(%rdi)	
    movq    %r10, 16(%rdi)	
    movq    %r11, 24(%rdi)
    movq    %r12, 32(%rdi)
    movq    %r13, 40(%rdi)
    movq    %r14, 48(%rdi)
    movq    %r15, 56(%rdi)
    movq    %rax, 64(%rdi)
    movq    %rbx, 72(%rdi)
    movq    %rcx, 80(%rdi)
    movq    %rbp, 88(%rdi)

    movq    96(%rsi), %rcx
    movq    %rcx, 96(%rdi)

    movq    %rdx, %rbx

    .START:

    subq    $1, %rbx
    movq    %rbx, 176(%rsp)

    xorq    %rdx, %rdx
    movq    0(%rdi), %rdx
    
    mulx    8(%rdi), %r8, %r9

    mulx    16(%rdi), %rcx, %r10
    adcx    %rcx, %r9

    mulx    24(%rdi), %rcx, %r11
    adcx    %rcx, %r10

    mulx    32(%rdi), %rcx, %r12
    adcx    %rcx, %r11

    mulx    40(%rdi), %rcx, %r13
    adcx    %rcx, %r12

    mulx    48(%rdi), %rcx, %r14
    adcx    %rcx, %r13

    mulx    56(%rdi), %rcx, %r15
    adcx    %rcx, %r14
    
    mulx    64(%rdi), %rcx, %rax
    adcx    %rcx, %r15

    mulx    72(%rdi), %rcx, %rbx
    adcx    %rcx, %rax

    mulx    80(%rdi), %rcx, %rsi
    adcx    %rcx, %rbx

    movq    %r8, 64(%rsp)
    mulx    88(%rdi), %rcx, %r8
    adcx    %rcx, %rsi

    movq    %r9, 72(%rsp)
    mulx    96(%rdi), %rcx, %r9
    adcx    %rcx, %r8
    adcq    $0, %r9

    movq    %r10, 80(%rsp)

    xorq    %r10, %r10
    movq    8(%rdi), %rdx
    
    mulx    16(%rdi), %rcx, %rbp
    adcx    80(%rsp), %rcx
    adox    %rbp, %r11
    movq    %rcx, 80(%rsp)

    mulx    24(%rdi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    32(%rdi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    40(%rdi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    48(%rdi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    56(%rdi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax
    
    mulx    64(%rdi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rbx

    mulx    72(%rdi), %rcx, %rbp
    adcx    %rcx, %rbx
    adox    %rbp, %rsi

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %rsi
    adox    %rbp, %r8

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10
    adcq    $0, %r10

    movq    %r11, 88(%rsp)		

    xorq    %r11, %r11
    movq    16(%rdi), %rdx

    mulx    24(%rdi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    32(%rdi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    40(%rdi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    48(%rdi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    56(%rdi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rbx
    
    mulx    64(%rdi), %rcx, %rbp
    adcx    %rcx, %rbx
    adox    %rbp, %rsi

    mulx    72(%rdi), %rcx, %rbp
    adcx    %rcx, %rsi
    adox    %rbp, %r8

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11
    adcq    $0, %r11

    movq    %r12, 96(%rsp)		

    xorq    %r12, %r12
    movq    24(%rdi), %rdx

    mulx    32(%rdi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    40(%rdi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    48(%rdi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rbx

    mulx    56(%rdi), %rcx, %rbp
    adcx    %rcx, %rbx
    adox    %rbp, %rsi
    
    mulx    64(%rdi), %rcx, %rbp
    adcx    %rcx, %rsi
    adox    %rbp, %r8

    mulx    72(%rdi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12
    adcq    $0, %r12

    movq    %r13, 104(%rsp)		

    xorq    %r13, %r13
    movq    32(%rdi), %rdx

    mulx    40(%rdi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rbx

    mulx    48(%rdi), %rcx, %rbp
    adcx    %rcx, %rbx
    adox    %rbp, %rsi

    mulx    56(%rdi), %rcx, %rbp
    adcx    %rcx, %rsi
    adox    %rbp, %r8
    
    mulx    64(%rdi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    72(%rdi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13
    adcq    $0, %r13

    movq    %r14, 112(%rsp)		

    xorq    %r14, %r14
    movq    40(%rdi), %rdx

    mulx    48(%rdi), %rcx, %rbp
    adcx    %rcx, %rsi
    adox    %rbp, %r8

    mulx    56(%rdi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9
    
    mulx    64(%rdi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    72(%rdi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14
    adcq    $0, %r14

    movq    %r15, 120(%rsp)	

    xorq    %r15, %r15
    movq    48(%rdi), %rdx

    mulx    56(%rdi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10
 
    mulx    64(%rdi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    72(%rdi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15
    adcq    $0, %r15
    
    movq    %rax, 128(%rsp)     

    xorq    %rax, %rax
    movq    56(%rdi), %rdx

    mulx    64(%rdi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    72(%rdi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax
    adcq    $0, %rax

    movq    %rbx, 136(%rsp)   

    xorq    %rbx, %rbx
    movq    64(%rdi), %rdx

    mulx    72(%rdi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rbx
    adcq    $0, %rbx

    movq    %rsi, 144(%rsp)

    xorq    %rsi, %rsi
    movq    72(%rdi), %rdx

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rbx

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %rbx
    adox    %rbp, %rsi
    adcq    $0, %rsi

    movq    %r8, 152(%rsp)

    xorq    %r8, %r8
    movq    80(%rdi), %rdx

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %rbx
    adox    %rbp, %rsi

    mulx    96(%rdi), %rcx, %rbp
    adcx    %rcx, %rsi
    adox    %rbp, %r8
    adcq    $0, %r8

    movq    %r9, 160(%rsp)

    movq    88(%rdi), %rdx

    mulx    96(%rdi), %rcx, %r9
    addq    %rcx, %r8
    adcq    $0, %r9

    movq    $0, %rcx

    shld    $1, %r9,  %rcx
    shld    $1, %r8,  %r9
    shld    $1, %rsi, %r8
    shld    $1, %rbx, %rsi
    shld    $1, %rax, %rbx
    shld    $1, %r15, %rax
    shld    $1, %r14, %r15
    shld    $1, %r13, %r14
    shld    $1, %r12, %r13
    shld    $1, %r11, %r12
    shld    $1, %r10, %r11

    movq    160(%rsp), %rdx
    shld    $1, %rdx, %r10
    movq    152(%rsp), %rbp
    shld    $1, %rbp, %rdx
    movq    %rdx, 160(%rsp)
    movq    144(%rsp), %rdx
    shld    $1, %rdx, %rbp
    movq    %rbp, 152(%rsp)
    movq    136(%rsp), %rbp
    shld    $1, %rbp, %rdx
    movq    %rdx, 144(%rsp)
    movq    128(%rsp), %rdx
    shld    $1, %rdx, %rbp
    movq    %rbp, 136(%rsp)
    movq    120(%rsp), %rbp
    shld    $1, %rbp, %rdx
    movq    %rdx, 128(%rsp)
    movq    112(%rsp), %rdx
    shld    $1, %rdx, %rbp
    movq    %rbp, 120(%rsp)
    movq    104(%rsp), %rbp
    shld    $1, %rbp, %rdx
    movq    %rdx, 112(%rsp)
    movq    96(%rsp), %rdx
    shld    $1, %rdx, %rbp
    movq    %rbp, 104(%rsp)
    movq    88(%rsp), %rbp
    shld    $1, %rbp, %rdx
    movq    %rdx, 96(%rsp)
    movq    80(%rsp), %rdx
    shld    $1, %rdx, %rbp
    movq    %rbp, 88(%rsp)
    movq    72(%rsp), %rbp
    shld    $1, %rbp, %rdx
    movq    %rdx, 80(%rsp)
    movq    64(%rsp), %rdx
    shld    $1, %rdx, %rbp
    movq    %rbp, 72(%rsp)
    addq    %rdx, %rdx
    movq    %rdx, 64(%rsp)
   
    xorq    %rdx, %rdx
    movq    0(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    64(%rsp), %rdx
    movq    %rbp, 168(%rsp)
    movq    %rdx, 64(%rsp)

    movq    8(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    72(%rsp), %rbp
    adcx    80(%rsp), %rdx
    movq    %rbp, 72(%rsp)
    movq    %rdx, 80(%rsp)

    movq    16(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    88(%rsp), %rbp
    adcx    96(%rsp), %rdx
    movq    %rbp, 88(%rsp)
    movq    %rdx, 96(%rsp)

    movq    24(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    104(%rsp), %rbp
    adcx    112(%rsp), %rdx
    movq    %rbp, 104(%rsp)
    movq    %rdx, 112(%rsp)

    movq    32(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    120(%rsp), %rbp
    adcx    128(%rsp), %rdx
    movq    %rbp, 120(%rsp)
    movq    %rdx, 128(%rsp)

    movq    40(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    136(%rsp), %rbp
    adcx    144(%rsp), %rdx
    movq    %rbp, 136(%rsp)
    movq    %rdx, 144(%rsp)

    movq    48(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    152(%rsp), %rbp
    adcx    160(%rsp), %rdx
    movq    %rbp, 152(%rsp)
    movq    %rdx, 160(%rsp)

    movq    56(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    %rbp, %r10
    adcx    %rdx, %r11

    movq    64(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    %rbp, %r12
    adcx    %rdx, %r13

    movq    72(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    %rbp, %r14
    adcx    %rdx, %r15

    movq    80(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    %rbp, %rax
    adcx    %rdx, %rbx

    movq    88(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    %rbp, %rsi
    adcx    %rdx, %r8

    movq    96(%rdi), %rdx
    mulx    %rdx, %rbp, %rdx
    adcx    %rbp, %r9
    adcx    %rdx, %rcx

    movq    $143, %rdx

    xorq    %rbp, %rbp
    mulx    160(%rsp), %rbp, %rdi
    movq    %rbp, 160(%rsp)

    mulx    %r10, %r10, %rbp
    adcx    %rdi, %r10

    mulx    %r11, %r11, %rdi
    adcx    %rbp, %r11

    mulx    %r12, %r12, %rbp
    adcx    %rdi, %r12

    mulx    %r13, %r13, %rdi
    adcx    %rbp, %r13

    mulx    %r14, %r14, %rbp
    adcx    %rdi, %r14

    mulx    %r15, %r15, %rdi
    adcx    %rbp, %r15

    mulx    %rax, %rax, %rbp
    adcx    %rdi, %rax

    mulx    %rbx, %rbx, %rdi
    adcx    %rbp, %rbx

    mulx    %rsi, %rsi, %rbp
    adcx    %rdi, %rsi

    mulx    %r8, %r8, %rdi
    adcx    %rbp, %r8

    mulx    %r9, %r9, %rbp
    adcx    %rdi, %r9

    mulx    %rcx, %rcx, %rdi
    adcx    %rbp, %rcx
    adcq    $0, %rdi

    movq    160(%rsp), %rdx

    xorq    %rbp, %rbp
    adcx    168(%rsp), %rdx
    adcx    64(%rsp),  %r10
    adcx    72(%rsp),  %r11
    adcx    80(%rsp),  %r12
    adcx    88(%rsp),  %r13
    adcx    96(%rsp),  %r14
    adcx    104(%rsp), %r15
    adcx    112(%rsp), %rax
    adcx    120(%rsp), %rbx
    adcx    128(%rsp), %rsi
    adcx    136(%rsp), %r8
    adcx    144(%rsp), %r9
    adcx    152(%rsp), %rcx
    adcq    $0, %rdi
 
    imul    $143, %rdi, %rdi

    addq    %rdi, %rdx
    adcq    $0, %r10
    adcq    $0, %r11
    adcq    $0, %r12
    adcq    $0, %r13
    adcq    $0, %r14
    adcq    $0, %r15
    adcq    $0, %rax
    adcq    $0, %rbx
    adcq    $0, %rsi
    adcq    $0, %r8
    adcq    $0, %r9
    adcq    $0, %rcx
    adcq    $0, %rbp

    imul    $143, %rbp, %rbp
    addq    %rbp, %rdx

    movq    56(%rsp), %rdi

    movq    %rdx,  0(%rdi)
    movq    %r10,  8(%rdi)
    movq    %r11, 16(%rdi)
    movq    %r12, 24(%rdi)
    movq    %r13, 32(%rdi)
    movq    %r14, 40(%rdi)
    movq    %r15, 48(%rdi)
    movq    %rax, 56(%rdi)
    movq    %rbx, 64(%rdi)
    movq    %rsi, 72(%rdi)
    movq    %r8,  80(%rdi)
    movq    %r9,  88(%rdi)
    movq    %rcx, 96(%rdi)

    movq    176(%rsp), %rbx
    cmpq    $0, %rbx

    jne .START

    movq    0(%rsp), %r11
    movq    8(%rsp), %r12
    movq    16(%rsp), %r13
    movq    24(%rsp), %r14
    movq    32(%rsp), %r15
    movq    40(%rsp), %rbp
    movq    48(%rsp), %rbx

    movq    %r11, %rsp
 
    ret
