/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^1088-89) from the paper       |
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
.globl gfp108889mul
gfp108889mul:

    movq    %rsp, %r11
    subq    $264, %rsp

    movq    %r11,  0(%rsp)
    movq    %r12,  8(%rsp)
    movq    %r13, 16(%rsp)
    movq    %r14, 24(%rsp)
    movq    %r15, 32(%rsp)
    movq    %rbp, 40(%rsp)
    movq    %rbx, 48(%rsp)
    movq    %rdi, 56(%rsp)
    
    movq    %rdx, %rbx
    
    xorq    %rdx, %rdx
    movq    0(%rbx), %rdx    

    mulx    0(%rsi), %r8, %r9 
    mulx    8(%rsi), %rcx, %r10		
    adcx    %rcx, %r9

    mulx    16(%rsi), %rcx, %r11	
    adcx    %rcx, %r10 

    mulx    24(%rsi), %rcx, %r12	
    adcx    %rcx, %r11 

    mulx    32(%rsi), %rcx, %r13	
    adcx    %rcx, %r12 

    mulx    40(%rsi), %rcx, %r14	
    adcx    %rcx, %r13 

    mulx    48(%rsi), %rcx, %r15	
    adcx    %rcx, %r14

    mulx    56(%rsi), %rcx, %rax
    adcx    %rcx, %r15

    mulx    64(%rsi), %rcx, %rdi
    adcx    %rcx, %rax

    movq    %r8, 64(%rsp)
    mulx    72(%rsi), %rcx, %r8
    adcx    %rcx, %rdi

    movq    %r9, 72(%rsp)
    mulx    80(%rsi), %rcx, %r9
    adcx    %rcx, %r8

    movq    %r10, 80(%rsp)
    mulx    88(%rsi), %rcx, %r10
    adcx    %rcx, %r9

    movq    %r11, 88(%rsp)
    mulx    96(%rsi), %rcx, %r11
    adcx    %rcx, %r10

    movq    %r12, 96(%rsp)
    mulx    104(%rsi), %rcx, %r12
    adcx    %rcx, %r11

    movq    %r13, 104(%rsp)
    mulx    112(%rsi), %rcx, %r13
    adcx    %rcx, %r12

    movq    %r14, 112(%rsp)
    mulx    120(%rsi), %rcx, %r14
    adcx    %rcx, %r13

    movq    %r15, 120(%rsp)
    mulx    128(%rsi), %rcx, %r15
    adcx    %rcx, %r14
    adcq    $0, %r15

    movq    %rax, 128(%rsp)

    xorq    %rax, %rax
    movq    8(%rbx), %rdx
   
    mulx    0(%rsi), %rcx, %rbp
    adcx    72(%rsp), %rcx
    adox    80(%rsp), %rbp
    movq    %rcx, 72(%rsp)
    movq    %rbp, 80(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    80(%rsp), %rcx
    adox    88(%rsp), %rbp
    movq    %rcx, 80(%rsp)
    movq    %rbp, 88(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    88(%rsp), %rcx
    adox    96(%rsp), %rbp
    movq    %rcx, 88(%rsp)
    movq    %rbp, 96(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    96(%rsp), %rcx
    adox    104(%rsp), %rbp
    movq    %rcx, 96(%rsp)
    movq    %rbp, 104(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    104(%rsp), %rcx
    adox    112(%rsp), %rbp
    movq    %rcx, 104(%rsp)
    movq    %rbp, 112(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    112(%rsp), %rcx
    adox    120(%rsp), %rbp
    movq    %rcx, 112(%rsp)
    movq    %rbp, 120(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    120(%rsp), %rcx
    adox    128(%rsp), %rbp
    movq    %rcx, 120(%rsp)
    movq    %rbp, 128(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    128(%rsp), %rcx
    adox    %rbp, %rdi
    movq    %rcx, 128(%rsp)
    
    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax
    adcq    $0, %rax

    movq    %rdi, 136(%rsp)

    xorq    %rdi, %rdi
    movq    16(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    80(%rsp), %rcx
    adox    88(%rsp), %rbp
    movq    %rcx, 80(%rsp)
    movq    %rbp, 88(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    88(%rsp), %rcx
    adox    96(%rsp), %rbp
    movq    %rcx, 88(%rsp)
    movq    %rbp, 96(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    96(%rsp), %rcx
    adox    104(%rsp), %rbp
    movq    %rcx, 96(%rsp)
    movq    %rbp, 104(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    104(%rsp), %rcx
    adox    112(%rsp), %rbp
    movq    %rcx, 104(%rsp)
    movq    %rbp, 112(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    112(%rsp), %rcx
    adox    120(%rsp), %rbp
    movq    %rcx, 112(%rsp)
    movq    %rbp, 120(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    120(%rsp), %rcx
    adox    128(%rsp), %rbp
    movq    %rcx, 120(%rsp)
    movq    %rbp, 128(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    128(%rsp), %rcx
    adox    136(%rsp), %rbp
    movq    %rcx, 128(%rsp)
    movq    %rbp, 136(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    136(%rsp), %rcx
    adox    %rbp, %r8
    movq    %rcx, 136(%rsp)
    
    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi
    adcq    $0, %rdi

    movq    %r8, 144(%rsp)

    xorq    %r8, %r8
    movq    24(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    88(%rsp), %rcx
    adox    96(%rsp), %rbp
    movq    %rcx, 88(%rsp)
    movq    %rbp, 96(%rsp)
   
    mulx    8(%rsi), %rcx, %rbp
    adcx    96(%rsp), %rcx
    adox    104(%rsp), %rbp
    movq    %rcx, 96(%rsp)
    movq    %rbp, 104(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    104(%rsp), %rcx
    adox    112(%rsp), %rbp
    movq    %rcx, 104(%rsp)
    movq    %rbp, 112(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    112(%rsp), %rcx
    adox    120(%rsp), %rbp
    movq    %rcx, 112(%rsp)
    movq    %rbp, 120(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    120(%rsp), %rcx
    adox    128(%rsp), %rbp
    movq    %rcx, 120(%rsp)
    movq    %rbp, 128(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    128(%rsp), %rcx
    adox    136(%rsp), %rbp
    movq    %rcx, 128(%rsp)
    movq    %rbp, 136(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    136(%rsp), %rcx
    adox    144(%rsp), %rbp
    movq    %rcx, 136(%rsp)
    movq    %rbp, 144(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    144(%rsp), %rcx
    adox    %rbp, %r9
    movq    %rcx, 144(%rsp)
    
    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10			

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11			

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8
    adcq    $0, %r8

    movq    %r9, 152(%rsp)		

    xorq    %r9, %r9
    movq    32(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    96(%rsp), %rcx
    adox    104(%rsp), %rbp
    movq    %rcx, 96(%rsp)
    movq    %rbp, 104(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    104(%rsp), %rcx
    adox    112(%rsp), %rbp
    movq    %rcx, 104(%rsp)
    movq    %rbp, 112(%rsp)
  
    mulx    16(%rsi), %rcx, %rbp
    adcx    112(%rsp), %rcx
    adox    120(%rsp), %rbp
    movq    %rcx, 112(%rsp)
    movq    %rbp, 120(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    120(%rsp), %rcx
    adox    128(%rsp), %rbp
    movq    %rcx, 120(%rsp)
    movq    %rbp, 128(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    128(%rsp), %rcx
    adox    136(%rsp), %rbp
    movq    %rcx, 128(%rsp)
    movq    %rbp, 136(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    136(%rsp), %rcx
    adox    144(%rsp), %rbp
    movq    %rcx, 136(%rsp)
    movq    %rbp, 144(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    144(%rsp), %rcx
    adox    152(%rsp), %rbp
    movq    %rcx, 144(%rsp)
    movq    %rbp, 152(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    152(%rsp), %rcx
    adox    %rbp, %r10
    movq    %rcx, 152(%rsp)
    
    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9
    adcq    $0, %r9

    movq    %r10, 160(%rsp)   

    xorq    %r10, %r10
    movq    40(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    104(%rsp), %rcx
    adox    112(%rsp), %rbp
    movq    %rcx, 104(%rsp)
    movq    %rbp, 112(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    112(%rsp), %rcx
    adox    120(%rsp), %rbp
    movq    %rcx, 112(%rsp)
    movq    %rbp, 120(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    120(%rsp), %rcx
    adox    128(%rsp), %rbp
    movq    %rcx, 120(%rsp)
    movq    %rbp, 128(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    128(%rsp), %rcx
    adox    136(%rsp), %rbp
    movq    %rcx, 128(%rsp)
    movq    %rbp, 136(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    136(%rsp), %rcx
    adox    144(%rsp), %rbp
    movq    %rcx, 136(%rsp)
    movq    %rbp, 144(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    144(%rsp), %rcx
    adox    152(%rsp), %rbp
    movq    %rcx, 144(%rsp)
    movq    %rbp, 152(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    152(%rsp), %rcx
    adox    160(%rsp), %rbp
    movq    %rcx, 152(%rsp)
    movq    %rbp, 160(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    160(%rsp), %rcx
    adox    %rbp, %r11
    movq    %rcx, 160(%rsp)
    
    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10
    adcq    $0, %r10

    movq    %r11, 168(%rsp) 

    xorq    %r11, %r11
    movq    48(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    112(%rsp), %rcx
    adox    120(%rsp), %rbp
    movq    %rcx, 112(%rsp)
    movq    %rbp, 120(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    120(%rsp), %rcx
    adox    128(%rsp), %rbp
    movq    %rcx, 120(%rsp)
    movq    %rbp, 128(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    128(%rsp), %rcx
    adox    136(%rsp), %rbp
    movq    %rcx, 128(%rsp)
    movq    %rbp, 136(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    136(%rsp), %rcx
    adox    144(%rsp), %rbp
    movq    %rcx, 136(%rsp)
    movq    %rbp, 144(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    144(%rsp), %rcx
    adox    152(%rsp), %rbp
    movq    %rcx, 144(%rsp)
    movq    %rbp, 152(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    152(%rsp), %rcx
    adox    160(%rsp), %rbp
    movq    %rcx, 152(%rsp)
    movq    %rbp, 160(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    160(%rsp), %rcx
    adox    168(%rsp), %rbp
    movq    %rcx, 160(%rsp)
    movq    %rbp, 168(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    168(%rsp), %rcx
    adox    %rbp, %r12
    movq    %rcx, 168(%rsp)
    
    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11
    adcq    $0, %r11

    movq    %r12, 176(%rsp)	
    
    xorq    %r12, %r12
    movq    56(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    120(%rsp), %rcx
    adox    128(%rsp), %rbp
    movq    %rcx, 120(%rsp)
    movq    %rbp, 128(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    128(%rsp), %rcx
    adox    136(%rsp), %rbp
    movq    %rcx, 128(%rsp)
    movq    %rbp, 136(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    136(%rsp), %rcx
    adox    144(%rsp), %rbp
    movq    %rcx, 136(%rsp)
    movq    %rbp, 144(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    144(%rsp), %rcx
    adox    152(%rsp), %rbp
    movq    %rcx, 144(%rsp)
    movq    %rbp, 152(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    152(%rsp), %rcx
    adox    160(%rsp), %rbp
    movq    %rcx, 152(%rsp)
    movq    %rbp, 160(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    160(%rsp), %rcx
    adox    168(%rsp), %rbp
    movq    %rcx, 160(%rsp)
    movq    %rbp, 168(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    168(%rsp), %rcx
    adox    176(%rsp), %rbp
    movq    %rcx, 168(%rsp)
    movq    %rbp, 176(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    176(%rsp), %rcx
    adox    %rbp, %r13
    movq    %rcx, 176(%rsp)
  
    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12
    adcq    $0, %r12
   
    movq    %r13, 184(%rsp)

    xorq    %r13, %r13
    movq    64(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    128(%rsp), %rcx
    adox    136(%rsp), %rbp
    movq    %rcx, 128(%rsp)
    movq    %rbp, 136(%rsp)
   
    mulx    8(%rsi), %rcx, %rbp
    adcx    136(%rsp), %rcx
    adox    144(%rsp), %rbp
    movq    %rcx, 136(%rsp)
    movq    %rbp, 144(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    144(%rsp), %rcx
    adox    152(%rsp), %rbp
    movq    %rcx, 144(%rsp)
    movq    %rbp, 152(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    152(%rsp), %rcx
    adox    160(%rsp), %rbp
    movq    %rcx, 152(%rsp)
    movq    %rbp, 160(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    160(%rsp), %rcx
    adox    168(%rsp), %rbp
    movq    %rcx, 160(%rsp)
    movq    %rbp, 168(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    168(%rsp), %rcx
    adox    176(%rsp), %rbp
    movq    %rcx, 168(%rsp)
    movq    %rbp, 176(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    176(%rsp), %rcx
    adox    184(%rsp), %rbp
    movq    %rcx, 176(%rsp)
    movq    %rbp, 184(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    184(%rsp), %rcx
    adox    %rbp, %r14
    movq    %rcx, 184(%rsp)

    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13
    adcq    $0, %r13
  
    movq    %r14, 192(%rsp)

    xorq    %r14, %r14
    movq    72(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    136(%rsp), %rcx
    adox    144(%rsp), %rbp
    movq    %rcx, 136(%rsp)
    movq    %rbp, 144(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    144(%rsp), %rcx
    adox    152(%rsp), %rbp
    movq    %rcx, 144(%rsp)
    movq    %rbp, 152(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    152(%rsp), %rcx
    adox    160(%rsp), %rbp
    movq    %rcx, 152(%rsp)
    movq    %rbp, 160(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    160(%rsp), %rcx
    adox    168(%rsp), %rbp
    movq    %rcx, 160(%rsp)
    movq    %rbp, 168(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    168(%rsp), %rcx
    adox    176(%rsp), %rbp
    movq    %rcx, 168(%rsp)
    movq    %rbp, 176(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    176(%rsp), %rcx
    adox    184(%rsp), %rbp
    movq    %rcx, 176(%rsp)
    movq    %rbp, 184(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    184(%rsp), %rcx
    adox    192(%rsp), %rbp
    movq    %rcx, 184(%rsp)
    movq    %rbp, 192(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    192(%rsp), %rcx
    adox    %rbp, %r15
    movq    %rcx, 192(%rsp)

    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14
    adcq    $0, %r14

    movq    %r15, 200(%rsp)

    xorq    %r15, %r15
    movq    80(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    144(%rsp), %rcx
    adox    152(%rsp), %rbp
    movq    %rcx, 144(%rsp)
    movq    %rbp, 152(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    152(%rsp), %rcx
    adox    160(%rsp), %rbp
    movq    %rcx, 152(%rsp)
    movq    %rbp, 160(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    160(%rsp), %rcx
    adox    168(%rsp), %rbp
    movq    %rcx, 160(%rsp)
    movq    %rbp, 168(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    168(%rsp), %rcx
    adox    176(%rsp), %rbp
    movq    %rcx, 168(%rsp)
    movq    %rbp, 176(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    176(%rsp), %rcx
    adox    184(%rsp), %rbp
    movq    %rcx, 176(%rsp)
    movq    %rbp, 184(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    184(%rsp), %rcx
    adox    192(%rsp), %rbp
    movq    %rcx, 184(%rsp)
    movq    %rbp, 192(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    192(%rsp), %rcx
    adox    200(%rsp), %rbp
    movq    %rcx, 192(%rsp)
    movq    %rbp, 200(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    200(%rsp), %rcx
    adox    %rbp, %rax
    movq    %rcx, 200(%rsp)

    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15
    adcq    $0, %r15

    movq    %rax, 208(%rsp)

    xorq    %rax, %rax
    movq    88(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    152(%rsp), %rcx
    adox    160(%rsp), %rbp
    movq    %rcx, 152(%rsp)
    movq    %rbp, 160(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    160(%rsp), %rcx
    adox    168(%rsp), %rbp
    movq    %rcx, 160(%rsp)
    movq    %rbp, 168(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    168(%rsp), %rcx
    adox    176(%rsp), %rbp
    movq    %rcx, 168(%rsp)
    movq    %rbp, 176(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    176(%rsp), %rcx
    adox    184(%rsp), %rbp
    movq    %rcx, 176(%rsp)
    movq    %rbp, 184(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    184(%rsp), %rcx
    adox    192(%rsp), %rbp
    movq    %rcx, 184(%rsp)
    movq    %rbp, 192(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    192(%rsp), %rcx
    adox    200(%rsp), %rbp
    movq    %rcx, 192(%rsp)
    movq    %rbp, 200(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    200(%rsp), %rcx
    adox    208(%rsp), %rbp
    movq    %rcx, 200(%rsp)
    movq    %rbp, 208(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    208(%rsp), %rcx
    adox    %rbp, %rdi
    movq    %rcx, 208(%rsp)

    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax
    adcq    $0, %rax

    movq    %rdi, 216(%rsp)

    xorq    %rdi, %rdi
    movq    96(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    160(%rsp), %rcx
    adox    168(%rsp), %rbp
    movq    %rcx, 160(%rsp)
    movq    %rbp, 168(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    168(%rsp), %rcx
    adox    176(%rsp), %rbp
    movq    %rcx, 168(%rsp)
    movq    %rbp, 176(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    176(%rsp), %rcx
    adox    184(%rsp), %rbp
    movq    %rcx, 176(%rsp)
    movq    %rbp, 184(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    184(%rsp), %rcx
    adox    192(%rsp), %rbp
    movq    %rcx, 184(%rsp)
    movq    %rbp, 192(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    192(%rsp), %rcx
    adox    200(%rsp), %rbp
    movq    %rcx, 192(%rsp)
    movq    %rbp, 200(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    200(%rsp), %rcx
    adox    208(%rsp), %rbp
    movq    %rcx, 200(%rsp)
    movq    %rbp, 208(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    208(%rsp), %rcx
    adox    216(%rsp), %rbp
    movq    %rcx, 208(%rsp)
    movq    %rbp, 216(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    216(%rsp), %rcx
    adox    %rbp, %r8
    movq    %rcx, 216(%rsp)

    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi
    adcq    $0, %rdi

    movq    %r8, 224(%rsp)

    xorq    %r8, %r8
    movq    104(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    168(%rsp), %rcx
    adox    176(%rsp), %rbp
    movq    %rcx, 168(%rsp)
    movq    %rbp, 176(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    176(%rsp), %rcx
    adox    184(%rsp), %rbp
    movq    %rcx, 176(%rsp)
    movq    %rbp, 184(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    184(%rsp), %rcx
    adox    192(%rsp), %rbp
    movq    %rcx, 184(%rsp)
    movq    %rbp, 192(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    192(%rsp), %rcx
    adox    200(%rsp), %rbp
    movq    %rcx, 192(%rsp)
    movq    %rbp, 200(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    200(%rsp), %rcx
    adox    208(%rsp), %rbp
    movq    %rcx, 200(%rsp)
    movq    %rbp, 208(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    208(%rsp), %rcx
    adox    216(%rsp), %rbp
    movq    %rcx, 208(%rsp)
    movq    %rbp, 216(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    216(%rsp), %rcx
    adox    224(%rsp), %rbp
    movq    %rcx, 216(%rsp)
    movq    %rbp, 224(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    224(%rsp), %rcx
    adox    %rbp, %r9
    movq    %rcx, 224(%rsp)

    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8
    adcq    $0, %r8

    movq    %r9, 232(%rsp)

    xorq    %r9, %r9
    movq    112(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    176(%rsp), %rcx
    adox    184(%rsp), %rbp
    movq    %rcx, 176(%rsp)
    movq    %rbp, 184(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    184(%rsp), %rcx
    adox    192(%rsp), %rbp
    movq    %rcx, 184(%rsp)
    movq    %rbp, 192(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    192(%rsp), %rcx
    adox    200(%rsp), %rbp
    movq    %rcx, 192(%rsp)
    movq    %rbp, 200(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    200(%rsp), %rcx
    adox    208(%rsp), %rbp
    movq    %rcx, 200(%rsp)
    movq    %rbp, 208(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    208(%rsp), %rcx
    adox    216(%rsp), %rbp
    movq    %rcx, 208(%rsp)
    movq    %rbp, 216(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    216(%rsp), %rcx
    adox    224(%rsp), %rbp
    movq    %rcx, 216(%rsp)
    movq    %rbp, 224(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    224(%rsp), %rcx
    adox    232(%rsp), %rbp
    movq    %rcx, 224(%rsp)
    movq    %rbp, 232(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    232(%rsp), %rcx
    adox    %rbp, %r10
    movq    %rcx, 232(%rsp)

    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9
    adcq    $0, %r9

    movq    %r10, 240(%rsp)

    xorq    %r10, %r10
    movq    120(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    184(%rsp), %rcx
    adox    192(%rsp), %rbp
    movq    %rcx, 184(%rsp)
    movq    %rbp, 192(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    192(%rsp), %rcx
    adox    200(%rsp), %rbp
    movq    %rcx, 192(%rsp)
    movq    %rbp, 200(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    200(%rsp), %rcx
    adox    208(%rsp), %rbp
    movq    %rcx, 200(%rsp)
    movq    %rbp, 208(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    208(%rsp), %rcx
    adox    216(%rsp), %rbp
    movq    %rcx, 208(%rsp)
    movq    %rbp, 216(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    216(%rsp), %rcx
    adox    224(%rsp), %rbp
    movq    %rcx, 216(%rsp)
    movq    %rbp, 224(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    224(%rsp), %rcx
    adox    232(%rsp), %rbp
    movq    %rcx, 224(%rsp)
    movq    %rbp, 232(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    232(%rsp), %rcx
    adox    240(%rsp), %rbp
    movq    %rcx, 232(%rsp)
    movq    %rbp, 240(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    240(%rsp), %rcx
    adox    %rbp, %r11
    movq    %rcx, 240(%rsp)

    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r11
    adox    %rbp, %r12

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10
    adcq    $0, %r10

    movq    %r11, 248(%rsp)

    xorq    %r11, %r11
    movq    128(%rbx), %rdx
    
    mulx    0(%rsi), %rcx, %rbp
    adcx    192(%rsp), %rcx
    adox    200(%rsp), %rbp
    movq    %rcx, 192(%rsp)
    movq    %rbp, 200(%rsp)
    
    mulx    8(%rsi), %rcx, %rbp
    adcx    200(%rsp), %rcx
    adox    208(%rsp), %rbp
    movq    %rcx, 200(%rsp)
    movq    %rbp, 208(%rsp)
    
    mulx    16(%rsi), %rcx, %rbp
    adcx    208(%rsp), %rcx
    adox    216(%rsp), %rbp
    movq    %rcx, 208(%rsp)
    movq    %rbp, 216(%rsp)

    mulx    24(%rsi), %rcx, %rbp
    adcx    216(%rsp), %rcx
    adox    224(%rsp), %rbp
    movq    %rcx, 216(%rsp)
    movq    %rbp, 224(%rsp)

    mulx    32(%rsi), %rcx, %rbp
    adcx    224(%rsp), %rcx
    adox    232(%rsp), %rbp
    movq    %rcx, 224(%rsp)
    movq    %rbp, 232(%rsp)

    mulx    40(%rsi), %rcx, %rbp
    adcx    232(%rsp), %rcx
    adox    240(%rsp), %rbp
    movq    %rcx, 232(%rsp)
    movq    %rbp, 240(%rsp)

    mulx    48(%rsi), %rcx, %rbp
    adcx    240(%rsp), %rcx
    adox    248(%rsp), %rbp
    movq    %rcx, 240(%rsp)
    movq    %rbp, 248(%rsp)

    mulx    56(%rsi), %rcx, %rbp
    adcx    248(%rsp), %rcx
    adox    %rbp, %r12
    movq    %rcx, 248(%rsp)

    mulx    64(%rsi), %rcx, %rbp
    adcx    %rcx, %r12
    adox    %rbp, %r13

    mulx    72(%rsi), %rcx, %rbp
    adcx    %rcx, %r13
    adox    %rbp, %r14

    mulx    80(%rsi), %rcx, %rbp
    adcx    %rcx, %r14
    adox    %rbp, %r15

    mulx    88(%rsi), %rcx, %rbp
    adcx    %rcx, %r15
    adox    %rbp, %rax

    mulx    96(%rsi), %rcx, %rbp
    adcx    %rcx, %rax
    adox    %rbp, %rdi

    mulx    104(%rsi), %rcx, %rbp
    adcx    %rcx, %rdi
    adox    %rbp, %r8

    mulx    112(%rsi), %rcx, %rbp
    adcx    %rcx, %r8
    adox    %rbp, %r9

    mulx    120(%rsi), %rcx, %rbp
    adcx    %rcx, %r9
    adox    %rbp, %r10

    mulx    128(%rsi), %rcx, %rbp
    adcx    %rcx, %r10
    adox    %rbp, %r11
    adcq    $0, %r11

    movq    200(%rsp), %rbx
    movq    208(%rsp), %rsi

    movq    $89, %rdx

    xorq    %rcx, %rcx
    mulx    %rbx, %rbx, %rcx
    movq    %rbx, 256(%rsp)

    mulx    %rsi, %rsi, %rbp
    adcx    %rcx, %rsi     

    mulx    216(%rsp), %rbx, %rcx
    adcx    %rbp, %rbx
    movq    %rbx, 216(%rsp)

    mulx    224(%rsp), %rbx, %rbp
    adcx    %rcx, %rbx
    movq    %rbx, 224(%rsp)

    mulx    232(%rsp), %rbx, %rcx
    adcx    %rbp, %rbx
    movq    %rbx, 232(%rsp)

    mulx    240(%rsp), %rbx, %rbp
    adcx    %rcx, %rbx
    movq    %rbx, 240(%rsp)

    mulx    248(%rsp), %rbx, %rcx
    adcx    %rbp, %rbx
    movq    %rbx, 248(%rsp)
    movq    256(%rsp), %rbx

    mulx    %r12, %r12, %rbp
    adcx    %rcx, %r12

    mulx    %r13, %r13, %rcx
    adcx    %rbp, %r13

    mulx    %r14, %r14, %rbp
    adcx    %rcx, %r14

    mulx    %r15, %r15, %rcx
    adcx    %rbp, %r15

    mulx    %rax, %rax, %rbp
    adcx    %rcx, %rax

    mulx    %rdi, %rcx, %rdi
    adcx    %rcx, %rbp

    mulx    %r8, %r8, %rcx
    adcx    %rdi, %r8

    mulx    %r9, %r9, %rdi  
    adcx    %rcx, %r9

    mulx    %r10, %r10, %rcx
    adcx    %rdi, %r10

    mulx    %r11, %r11, %rdi  
    adcx    %rcx, %r11
    adcq    $0, %rdi

    xorq    %rcx, %rcx
    movq    216(%rsp), %rdx
    movq    224(%rsp), %rcx

    adcx    64(%rsp),  %rbx
    adcx    72(%rsp),  %rsi
    adcx    80(%rsp),  %rdx
    adcx    88(%rsp),  %rcx

    movq    %rsi, 216(%rsp)
    movq    %rdx, 224(%rsp)
    movq    %rcx, 256(%rsp)
    movq    232(%rsp), %rsi
    movq    240(%rsp), %rdx
    movq    248(%rsp), %rcx
    adcx    96(%rsp),  %rsi
    adcx    104(%rsp), %rdx
    adcx    112(%rsp), %rcx

    adcx    120(%rsp), %r12
    adcx    128(%rsp), %r13
    adcx    136(%rsp), %r14
    adcx    144(%rsp), %r15
    adcx    152(%rsp), %rax
    adcx    160(%rsp), %rbp
    adcx    168(%rsp), %r8
    adcx    176(%rsp), %r9
    adcx    184(%rsp), %r10
    adcx    192(%rsp), %r11
    adcq    $0, %rdi
   
    imul    $89, %rdi, %rdi

    addq    %rdi, %rbx
    movq    216(%rsp), %rdi
    adcq    $0, %rdi
    movq    %rdi, 216(%rsp)
    movq    224(%rsp), %rdi
    adcq    $0, %rdi
    movq    %rdi, 224(%rsp)
    movq    256(%rsp), %rdi
    adcq    $0, %rdi
    movq    %rdi, 256(%rsp)
    adcq    $0, %rsi
    adcq    $0, %rdx
    adcq    $0, %rcx
    adcq    $0, %r12
    adcq    $0, %r13
    adcq    $0, %r14
    adcq    $0, %r15
    adcq    $0, %rax
    adcq    $0, %rbp
    adcq    $0, %r8
    adcq    $0, %r9
    adcq    $0, %r10
    adcq    $0, %r11
    movq    $0, %rdi
    adcq    $0, %rdi

    imul    $89, %rdi, %rdi
    addq    %rdi, %rbx

    movq    56(%rsp), %rdi

    movq    %rbx,  0(%rdi)
    movq    216(%rsp),%rbx
    movq    %rbx,  8(%rdi)
    movq    224(%rsp),%rbx
    movq    %rbx, 16(%rdi)
    movq    256(%rsp),%rbx
    movq    %rbx, 24(%rdi)
    movq    %rsi, 32(%rdi)
    movq    %rdx, 40(%rdi)
    movq    %rcx, 48(%rdi)
    movq    %r12, 56(%rdi)
    movq    %r13, 64(%rdi)
    movq    %r14, 72(%rdi)
    movq    %r15, 80(%rdi)
    movq    %rax, 88(%rdi)
    movq    %rbp, 96(%rdi)
    movq    %r8, 104(%rdi)
    movq    %r9, 112(%rdi)
    movq    %r10,120(%rdi)
    movq    %r11,128(%rdi)

    movq    0(%rsp), %r11
    movq    8(%rsp), %r12
    movq    16(%rsp), %r13
    movq    24(%rsp), %r14
    movq    32(%rsp), %r15
    movq    40(%rsp), %rbp
    movq    48(%rsp), %rbx

    movq    %r11, %rsp
 
    ret
