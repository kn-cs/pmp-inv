/**
 * Copyright (c) 2017 Armando Faz <armfazh@ic.unicamp.br>.
 * Institute of Computing.
 * University of Campinas, Brazil.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as   
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#include "fp25519_x64.h"

void mul_256x256_integer_x64(uint64_t *const c, uint64_t *const a, uint64_t *const b)
{
//#ifdef __BMI2__
//#ifdef __ADX__
	__asm__ __volatile__(
		"   movq      (%1), %%rdx  # A[0]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[0]*B[0]   \n\t"    "  xorl   %%r10d, %%r10d    \n\t"                                      "   movq	%%r8,  (%0)      \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[0]*B[1]   \n\t"    "  adox	 %%r9, %%r10     \n\t"                                      "   movq   %%r10, 8(%0)      \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[0]*B[2]   \n\t"    "  adox	%%r11, %%r12     \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[0]*B[3]   \n\t"    "  adox	%%r13, %%r14     \n\t"                                                                          "   movq    $0, %%rax  \n\t"
																 "  adox	%%rdx, %%rax     \n\t"

		"   movq     8(%1), %%rdx  # A[1]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[1]*B[0]   \n\t"    "  xorl   %%r10d, %%r10d    \n\t"  "   adcx	8(%0),  %%r8   \n\t"    "   movq	 %%r8,  8(%0)    \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[1]*B[1]   \n\t"    "  adox 	 %%r9, %%r10     \n\t"  "   adcx	%%r12, %%r10   \n\t"    "   movq	%%r10, 16(%0)    \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[1]*B[2]   \n\t"    "  adox	%%r11, %%r12     \n\t"  "   adcx	%%r14, %%r12   \n\t"                                        "   movq    $0, %%r8   \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[1]*B[3]   \n\t"    "  adox	%%r13, %%r14     \n\t"  "   adcx	%%rax, %%r14   \n\t"                                        "   movq    $0, %%rax  \n\t"
																 "  adox 	%%rdx, %%rax     \n\t"  "   adcx	 %%r8, %%rax   \n\t"

		"   movq    16(%1), %%rdx  # A[2]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[2]*B[0]   \n\t"    "  xorl   %%r10d, %%r10d    \n\t"  "   adcx   16(%0),  %%r8   \n\t"    "   movq	 %%r8, 16(%0)    \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[2]*B[1]   \n\t"    "  adox	 %%r9, %%r10     \n\t"  "   adcx	%%r12, %%r10   \n\t"    "   movq	%%r10, 24(%0)    \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[2]*B[2]   \n\t"    "  adox	%%r11, %%r12     \n\t"  "   adcx	%%r14, %%r12   \n\t"                                        "   movq    $0, %%r8   \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[2]*B[3]   \n\t"    "  adox	%%r13, %%r14     \n\t"  "   adcx	%%rax, %%r14   \n\t"                                        "   movq    $0, %%rax  \n\t"
																 "  adox	%%rdx, %%rax     \n\t"  "   adcx	 %%r8, %%rax   \n\t"

		"   movq	24(%1), %%rdx  # A[3]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[3]*B[0]   \n\t"    "  xorl   %%r10d, %%r10d    \n\t"  "   adcx   24(%0),  %%r8   \n\t"    "   movq	 %%r8, 24(%0)    \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[3]*B[1]   \n\t"    "  adox	 %%r9, %%r10     \n\t"  "   adcx	%%r12, %%r10   \n\t"    "   movq	%%r10, 32(%0)    \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[3]*B[2]   \n\t"    "  adox	%%r11, %%r12     \n\t"  "   adcx	%%r14, %%r12   \n\t"    "   movq	%%r12, 40(%0)    \n\t"  "   movq    $0, %%r8   \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[3]*B[3]   \n\t"    "  adox	%%r13, %%r14     \n\t"  "   adcx	%%rax, %%r14   \n\t"    "   movq	%%r14, 48(%0)    \n\t"  "   movq    $0, %%rax  \n\t"
																 "  adox	%%rdx, %%rax     \n\t"  "   adcx	 %%r8, %%rax   \n\t"    "   movq	%%rax, 56(%0)    \n\t"
	:
	: "r"  (c), "r" (a), "r"  (b)
	: "memory", "cc", "%rax", "%rdx",
	"%r8",  "%r9", "%r10", "%r11",
	"%r12", "%r13", "%r14"
	);
/*
#else
	__asm__ __volatile__(
		"   movq     (%1), %%rdx  # A[0]                \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[0]*B[0]   \n\t"                                       "   movq	 %%r8,  (%0)  \n\t"
		"   mulx	 8(%2), %%r10, %%rax  # A[0]*B[1]   \n\t"    "   addq	%%r10,  %%r9     \n\t"  "   movq	 %%r9, 8(%0)  \n\t"
		"   mulx	16(%2), %%r12, %%rbx  # A[0]*B[2]   \n\t"    "   adcq	%%r12, %%rax     \n\t"
		"   mulx	24(%2), %%r14, %%rcx  # A[0]*B[3]   \n\t"    "   adcq	%%r14, %%rbx     \n\t"
		"   adcq	   $0, %%rcx                        \n\t"

		"   movq    8(%1), %%rdx  # A[1]                \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[1]*B[0]   \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[1]*B[1]   \n\t"    "   addq	%%r10, %%r9      \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[1]*B[2]   \n\t"    "   adcq	%%r12, %%r11     \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[1]*B[3]   \n\t"    "   adcq	%%r14, %%r13     \n\t"
		"   adcq	   $0, %%rdx                        \n\t"

		"   addq	 %%r8,  8(%0)                       \n\t"
		"   adcq	%%rax,  %%r9                        \n\t"    "    movq	 %%r9, 16(%0)    \n\t"      "   movq	 $0, %%rax    \n\t"
		"   adcq	%%r11, %%rbx                        \n\t"
		"   adcq	%%r13, %%rcx                        \n\t"
		"   adcq	%%rdx, %%rax                        \n\t"

		"   movq   16(%1), %%rdx  # A[2]                \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[2]*B[0]   \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[2]*B[1]   \n\t"    "    addq	%%r10,  %%r9     \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[2]*B[2]   \n\t"    "    adcq	%%r12, %%r11     \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[2]*B[3]   \n\t"    "    adcq	%%r14, %%r13     \n\t"
		"   adcq	   $0, %%rdx                        \n\t"

		"   addq	 %%r8, 16(%0)                       \n\t"
		"   adcq	%%rbx,  %%r9                        \n\t"    "    movq	 %%r9, 24(%0)    \n\t"      "   movq	 $0, %%rbx    \n\t"
		"   adcq	%%r11, %%rcx                        \n\t"
		"   adcq	%%r13, %%rax                        \n\t"
		"   adcq	%%rdx, %%rbx                        \n\t"

		"   movq	24(%1), %%rdx  # A[3]               \n\t"
		"   mulx	  (%2),  %%r8,  %%r9  # A[3]*B[0]   \n\t"
		"   mulx	 8(%2), %%r10, %%r11  # A[3]*B[1]   \n\t"    "    addq	%%r10,  %%r9     \n\t"
		"   mulx	16(%2), %%r12, %%r13  # A[3]*B[2]   \n\t"    "    adcq	%%r12, %%r11     \n\t"
		"   mulx	24(%2), %%r14, %%rdx  # A[3]*B[3]   \n\t"    "    adcq	%%r14, %%r13     \n\t"
		"   adcq     $0, %%rdx                          \n\t"

		"   addq    %%r8, 24(%0)                        \n\t"
		"   adcq	%%rcx,  %%r9                        \n\t"    "    movq	%%r9,  32(%0)    \n\t"   "   movq	 $0, %%rcx    \n\t"
		"   adcq	%%r11, %%rax                        \n\t"    "    movq	%%rax, 40(%0)    \n\t"
		"   adcq	%%r13, %%rbx                        \n\t"    "    movq	%%rbx, 48(%0)    \n\t"
		"   adcq	%%rdx, %%rcx                        \n\t"    "    movq	%%rcx, 56(%0)    \n\t"
	:
	: "r"  (c), "r" (a), "r"  (b)
	: "memory", "cc", "%rax", "%rbx", "%rcx", "%rdx", "%r8",
	"%r9", "%r10", "%r11", "%r12", "%r13", "%r14"
	);
#endif
#else    /* Without BMI2 */
	/**
	* ODO: Multiplications using MULQ instruction.
	**/
//#endif
}

void sqr_256x256_integer_x64(uint64_t *const c, uint64_t *const a)
{
//#ifdef __BMI2__
	__asm__ __volatile__(
		"   movq	 (%1), %%rdx         # A[0]         \n\t"
		"   mulx	%%rdx,  %%r8, %%r9   # A[0]^2       \n\t"
		"   movq	8(%1), %%rdx         # A[1]         \n\t"
		"   mulx	%%rdx, %%r10, %%r11  # A[1]^2       \n\t"
		"   movq	 %%r8,   (%0)                       \n\t"
		"   movq	 %%r9,  8(%0)                       \n\t"
		"   movq	%%r10, 16(%0)                       \n\t"
		"   movq	%%r11, 24(%0)                       \n\t"

		"   movq	16(%1), %%rdx        # A[2]         \n\t"
		"   mulx	%%rdx,  %%r8, %%r9   # A[2]^2       \n\t"
		"   movq	24(%1), %%rdx        # A[3]         \n\t"
		"   mulx	%%rdx, %%r10, %%r11  # A[3]^2       \n\t"
		"   movq	 %%r8, 32(%0)                       \n\t"
		"   movq	 %%r9, 40(%0)                       \n\t"
		"   movq	%%r10, 48(%0)                       \n\t"
		"   movq	%%r11, 56(%0)                       \n\t"

		"   movq	 8(%1), %%rdx         # A[1]        \n\t"
		"   mulx	  (%1), %%r8, %%r9    # A[0]*A[1]   \n\t"
		"   mulx	16(%1), %%r10, %%r11  # A[2]*A[1]   \n\t"
		"   mulx	24(%1), %%rcx, %%r14  # A[3]*A[1]   \n\t"

		"   movq	16(%1), %%rdx         # A[2]        \n\t"
		"   mulx	24(%1), %%r12, %%r13  # A[3]*A[2]   \n\t"
		"   mulx	  (%1), %%rax, %%rdx  # A[0]*A[2]   \n\t"

		" 	addq	%%rax, %%r9       \n\t"
		" 	adcq	%%rdx, %%r10      \n\t"
		" 	adcq	%%rcx, %%r11      \n\t"
		" 	adcq	%%r14, %%r12      \n\t"
		" 	adcq	   $0, %%r13      \n\t"
		" 	movq	   $0, %%r14      \n\t"
		" 	adcq	   $0, %%r14      \n\t"

		" 	movq	  (%1), %%rdx        # A[0]         \n\t"
		" 	mulx	24(%1), %%rax, %%rdx # A[0]*A[3]    \n\t"

		" 	addq	%%rax, %%r10      \n\t"
		" 	adcq	%%rdx, %%r11      \n\t"
		" 	adcq	   $0, %%r12      \n\t"
		" 	adcq	   $0, %%r13      \n\t"
		" 	adcq	   $0, %%r14      \n\t"

		" 	shldq	$1, %%r13, %%r14  \n\t"
		" 	shldq	$1, %%r12, %%r13  \n\t"
		" 	shldq	$1, %%r11, %%r12  \n\t"
		" 	shldq	$1, %%r10, %%r11  \n\t"
		" 	shldq	$1,  %%r9, %%r10  \n\t"
		" 	shldq	$1,  %%r8,  %%r9  \n\t"
		" 	shlq	$1,  %%r8         \n\t"

		" 	addq	 8(%0),  %%r8     \n\t"  " 	movq	 %%r8,  8(%0)  \n\t"
		" 	adcq	16(%0),  %%r9     \n\t"  " 	movq	 %%r9, 16(%0)  \n\t"
		" 	adcq	24(%0), %%r10     \n\t"  " 	movq	%%r10, 24(%0)  \n\t"
		" 	adcq	32(%0), %%r11     \n\t"  " 	movq	%%r11, 32(%0)  \n\t"
		" 	adcq	40(%0), %%r12     \n\t"  " 	movq	%%r12, 40(%0)  \n\t"
		" 	adcq	48(%0), %%r13     \n\t"  " 	movq	%%r13, 48(%0)  \n\t"
		" 	adcq	56(%0), %%r14     \n\t"  " 	movq	%%r14, 56(%0)  \n\t"
	:
	: "r"  (c), "r" (a)
	:  "memory", "cc", "%rax", "%rcx", "%rdx",
	"%r8",  "%r9", "%r10", "%r11",
	"%r12", "%r13", "%r14"
	);
//#else    /* Without BMI2 */
	/**
	* ODO: Multiplications using MULQ instruction.
	**/
//#endif
}

void red_EltFp25519_1w_x64(uint64_t *const c, uint64_t *const a) {

  __asm__ __volatile__(
    "movl    $38, %%edx ;" /* 2*c = 38 = 2^256 */
    
    "mulx 32(%1),  %%r8, %%r10 ;" /* c*C[4] */  
    "xorl %%ebx, %%ebx ;"  
    "adox   (%1),  %%r8 ;"
    
    "mulx 40(%1),  %%r9, %%r11 ;" /* c*C[5] */  
    "adcx %%r10,  %%r9 ;"  "adox  8(%1),  %%r9 ;"

    "mulx 48(%1), %%r10, %%rax ;" /* c*C[6] */  
    "adcx %%r11, %%r10 ;"  "adox 16(%1), %%r10 ;"

    "mulx 56(%1), %%r11, %%rcx ;" /* c*C[7] */  
    "adcx %%rax, %%r11 ;"  "adox 24(%1), %%r11 ;"
    /****************************************/  
    "adcx %%rbx, %%rcx ;"  "adox  %%rbx, %%rcx ;"

    "clc ;"
    "mulx %%rcx, %%rax, %%rcx ;" /* c*C[4] */
    "adcx %%rax,  %%r8 ;"
    "adcx %%rcx,  %%r9 ;"  "movq  %%r9,  8(%0) ;"
    "adcx %%rbx, %%r10 ;"  "movq %%r10, 16(%0) ;"
    "adcx %%rbx, %%r11 ;"  "movq %%r11, 24(%0) ;"
    "mov     $0, %%ecx ;"	  
    "cmovc %%edx, %%ecx ;"	  
    "addq %%rcx,  %%r8 ;"  "movq  %%r8,   (%0) ;"
  :
  : "r" (c), "r" (a)
  : "memory", "cc", "%rax", "%rbx", "%rcx", "%rdx", "%r8", "%r9", "%r10", "%r11"
  );
}

void fred_EltFp25519_1w_x64(uint64_t *const c) {
  __asm__ __volatile__ (
  /* First, obtains a number less than 2^255. */
    "btrq   $63, 24(%0) ;"
    "sbbl %%ecx, %%ecx  ;"
    "andq   $19, %%rcx  ;"
    "addq %%rcx,   (%0) ;"
    "adcq    $0,  8(%0) ;"
    "adcq    $0, 16(%0) ;"
    "adcq    $0, 24(%0) ;"

    "btrq   $63, 24(%0) ;"
    "sbbl %%ecx, %%ecx  ;"
    "andq   $19, %%rcx  ;"
    "addq %%rcx,   (%0) ;"
    "adcq    $0,  8(%0) ;"
    "adcq    $0, 16(%0) ;"
    "adcq    $0, 24(%0) ;"

  /* Then, in case the number fall into [2^255-19, 2^255-1] */
    "cmpq $-19,   (%0)   ;"
    "setaeb %%al         ;"
    "cmpq  $-1,  8(%0)   ;"
    "setzb %%bl          ;"
    "cmpq  $-1, 16(%0)   ;"
    "setzb %%cl          ;"
    "movq 24(%0), %%rdx  ;"
    "addq   $1, %%rdx    ;"
    "shrq  $63, %%rdx    ;"
    "andb %%bl, %%al     ;"
    "andb %%dl, %%cl     ;"
    "test %%cl, %%al     ;"
    "movl  $0, %%eax     ;"
    "movl $19, %%ecx     ;"
    "cmovnz %%rcx, %%rax ;"
    "addq %%rax,   (%0)  ;"
    "adcq    $0,  8(%0)  ;"
    "adcq    $0, 16(%0)  ;"
    "adcq    $0, 24(%0)  ;"
    "btrq   $63, 24(%0)  ;"
  :
  : "r"(c)
  : "memory", "cc", "%rax", "%rbx", "%rcx", "%rdx"
  );
}


void inv_EltFp25519_1w_x64(uint64_t *const pC, uint64_t *const pA)
{
#define sqrn_EltFp25519_1w_x64(a,times)\
    counter = times;\
    while(counter-- > 0)\
    {\
        sqr_EltFp25519_1w_x64(a);\
    }

	EltFp25519_1w_x64 x0, x1, x2;
	uint64_t * T[5];
	uint64_t counter;

	T[0] = x0;
	T[1] = pC; /* x^(-1) */
	T[2] = x1;
	T[3] = x2;
	T[4] = pA; /* x */

	copy_EltFp25519_1w_x64(T[1],pA);
	sqrn_EltFp25519_1w_x64(T[1],1);
	copy_EltFp25519_1w_x64(T[2],T[1]);
	sqrn_EltFp25519_1w_x64(T[2],2);
	mul_EltFp25519_1w_x64(T[0], pA, T[2]);
	mul_EltFp25519_1w_x64(T[1], T[1], T[0]);
	copy_EltFp25519_1w_x64(T[2],T[1]);
	sqrn_EltFp25519_1w_x64(T[2],1);
	mul_EltFp25519_1w_x64(T[0], T[0], T[2]);
	copy_EltFp25519_1w_x64(T[2],T[0]);
	sqrn_EltFp25519_1w_x64(T[2],5);
	mul_EltFp25519_1w_x64(T[0], T[0], T[2]);
	copy_EltFp25519_1w_x64(T[2],T[0]);
	sqrn_EltFp25519_1w_x64(T[2],10);
	mul_EltFp25519_1w_x64(T[2], T[2], T[0]);
	copy_EltFp25519_1w_x64(T[3],T[2]);
	sqrn_EltFp25519_1w_x64(T[3],20);
	mul_EltFp25519_1w_x64(T[3], T[3], T[2]);
	sqrn_EltFp25519_1w_x64(T[3],10);
	mul_EltFp25519_1w_x64(T[3], T[3], T[0]);
	copy_EltFp25519_1w_x64(T[0],T[3]);
	sqrn_EltFp25519_1w_x64(T[0],50);
	mul_EltFp25519_1w_x64(T[0], T[0], T[3]);
	copy_EltFp25519_1w_x64(T[2],T[0]);
	sqrn_EltFp25519_1w_x64(T[2],100);
	mul_EltFp25519_1w_x64(T[2], T[2], T[0]);
	sqrn_EltFp25519_1w_x64(T[2],50);
	mul_EltFp25519_1w_x64(T[2], T[2], T[3]);
	sqrn_EltFp25519_1w_x64(T[2],5);
	mul_EltFp25519_1w_x64(T[1], T[1], T[2]);
#undef sqrn_EltFp25519_1w_x64
}
