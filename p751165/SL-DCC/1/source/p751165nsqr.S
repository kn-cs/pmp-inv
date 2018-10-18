/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^751-165) from the paper       |
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
.globl gfp751165nsqr
gfp751165nsqr:

    movq    %rsp, %r11
    subq    $168, %rsp

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

    movq    %rdx, %rbx

    .START:

    subq    $1, %rbx
    movq    %rbx, 160(%rsp)

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
    adcq    $0, %r8			

    movq    %r9, 72(%rsp)

    xorq    %r9, %r9
    movq    8(%rdi), %rdx
    
    mulx    16(%rdi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

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
    adcq    $0, %r9

    movq    %r10, 80(%rsp)

    xorq    %r10, %r10
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
    adcq    $0, %r10

    movq    %r11, 88(%rsp)

    xorq    %r11, %r11
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
    adcq    $0, %r11

    movq    %r12, 96(%rsp)

    xorq    %r12, %r12
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
    adcq    $0, %r12

    movq    %r13, 104(%rsp)

    xorq    %r13, %r13
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
    adcq    $0, %r13

    movq    %r14, 112(%rsp)

    xorq    %r14, %r14
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
    adcq    $0, %r14	
    
    movq    %r15, 120(%rsp)

    xorq    %r15, %r15
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
    adcq    $0, %r15	

    movq    %rax, 128(%rsp)

    xorq    %rax, %rax
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
    adcq    $0, %rax

    movq    %rbx, 136(%rsp)

    xorq    %rbx, %rbx
    movq    72(%rdi), %rdx

    mulx    80(%rdi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    88(%rdi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rbx
    adcq    $0, %rbx

    movq    80(%rdi), %rdx

    mulx    88(%rdi), %rcx, %rbp
    addq    %rcx, %rbx
    adcq    $0, %rbp

    movq    $0, %rcx

    shld    $1, %rbp, %rcx
    shld    $1, %rbx, %rbp
    shld    $1, %rax, %rbx
    shld    $1, %r15, %rax
    shld    $1, %r14, %r15
    shld    $1, %r13, %r14
    shld    $1, %r12, %r13
    shld    $1, %r11, %r12
    shld    $1, %r10, %r11
    shld    $1, %r9,  %r10
    shld    $1, %r8,  %r9
    shld    $1, %rsi, %r8
    movq    136(%rsp), %rdx
    shld    $1, %rdx, %rsi
    movq    %rsi, 144(%rsp)
    movq    128(%rsp), %rsi
    shld    $1, %rsi, %rdx
    movq    %rdx, 136(%rsp)
    movq    120(%rsp), %rdx
    shld    $1, %rdx, %rsi
    movq    %rsi, 128(%rsp)
    movq    112(%rsp), %rsi
    shld    $1, %rsi, %rdx
    movq    %rdx, 120(%rsp)
    movq    104(%rsp), %rdx
    shld    $1, %rdx, %rsi
    movq    %rsi, 112(%rsp)
    movq    96(%rsp), %rsi
    shld    $1, %rsi, %rdx
    movq    %rdx, 104(%rsp)
    movq    88(%rsp), %rdx
    shld    $1, %rdx, %rsi
    movq    %rsi, 96(%rsp)
    movq    80(%rsp), %rsi
    shld    $1, %rsi, %rdx
    movq    %rdx, 88(%rsp)
    movq    72(%rsp), %rdx
    shld    $1, %rdx, %rsi
    movq    %rsi, 80(%rsp)
    movq    64(%rsp), %rsi
    shld    $1, %rsi, %rdx
    addq    %rsi, %rsi 
    movq    %rdx, 72(%rsp)
    movq    %rsi, 64(%rsp)
   
    xorq    %rdx, %rdx
    movq    0(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    64(%rsp), %rdx
    movq    %rdx, 64(%rsp)
    movq    %rsi, 152(%rsp)

    movq    8(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    72(%rsp), %rsi
    adcx    80(%rsp), %rdx
    movq    %rsi, 72(%rsp)
    movq    %rdx, 80(%rsp)

    movq    16(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    88(%rsp), %rsi
    adcx    96(%rsp), %rdx
    movq    %rsi, 88(%rsp)
    movq    %rdx, 96(%rsp)

    movq    24(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    104(%rsp), %rsi
    adcx    112(%rsp), %rdx
    movq    %rsi, 104(%rsp)
    movq    %rdx, 112(%rsp)

    movq    32(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    120(%rsp), %rsi
    adcx    128(%rsp), %rdx
    movq    %rsi, 120(%rsp)
    movq    %rdx, 128(%rsp)

    movq    40(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    136(%rsp), %rsi
    adcx    144(%rsp), %rdx
    movq    %rsi, 136(%rsp)
    movq    %rdx, 144(%rsp)

    movq    48(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    %rsi, %r8
    adcx    %rdx, %r9

    movq    56(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    %rsi, %r10
    adcx    %rdx, %r11

    movq    64(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    %rsi, %r12
    adcx    %rdx, %r13

    movq    72(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    %rsi, %r14
    adcx    %rdx, %r15

    movq    80(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    %rsi, %rax
    adcx    %rdx, %rbx

    movq    88(%rdi), %rdx
    mulx    %rdx, %rsi, %rdx
    adcx    %rsi, %rbp
    adcx    %rdx, %rcx

    movq    twoe17x165, %rdx    		

    xorq    %rdi, %rdi
    mulx    %r8, %r8, %rdi

    mulx    %r9, %r9, %rsi
    adcx    %rdi, %r9     

    mulx    %r10, %r10, %rdi
    adcx    %rsi, %r10

    mulx    %r11, %r11, %rsi
    adcx    %rdi, %r11

    mulx    %r12, %r12, %rdi
    adcx    %rsi, %r12

    mulx    %r13, %r13, %rsi
    adcx    %rdi, %r13

    mulx    %r14, %r14, %rdi
    adcx    %rsi, %r14

    mulx    %r15, %r15, %rsi
    adcx    %rdi, %r15

    mulx    %rax, %rax, %rdi
    adcx    %rsi, %rax

    mulx    %rbx, %rbx, %rsi
    adcx    %rdi, %rbx

    mulx    %rbp, %rbp, %rdi
    adcx    %rsi, %rbp

    mulx    %rcx, %rcx, %rsi
    adcx    %rdi, %rcx
    adcq    $0, %rsi

    xorq    %rdx, %rdx
    adcx    152(%rsp), %r8
    adcx    64(%rsp),  %r9
    adcx    72(%rsp),  %r10
    adcx    80(%rsp),  %r11
    adcx    88(%rsp),  %r12
    adcx    96(%rsp),  %r13
    adcx    104(%rsp), %r14
    adcx    112(%rsp), %r15
    adcx    120(%rsp), %rax
    adcx    128(%rsp), %rbx
    adcx    136(%rsp), %rbp
    adcx    144(%rsp), %rcx
    adcq    $0, %rsi
   
    shld    $17, %rcx, %rsi
    imul    $165, %rsi, %rsi
    andq    mask47, %rcx

    addq    %rsi, %r8
    adcq    $0, %r9
    adcq    $0, %r10
    adcq    $0, %r11
    adcq    $0, %r12
    adcq    $0, %r13
    adcq    $0, %r14
    adcq    $0, %r15
    adcq    $0, %rax
    adcq    $0, %rbx
    adcq    $0, %rbp
    adcq    $0, %rcx

    movq    56(%rsp), %rdi

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
    movq    %rbp, 80(%rdi)
    movq    %rcx, 88(%rdi)

    movq    160(%rsp), %rbx
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
