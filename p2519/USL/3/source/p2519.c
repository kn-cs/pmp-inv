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

#include "p2519.h"
#include "p2519pack.h"

#define LIMB0 0xFFFFFFFFFFFFFFF7

void gfp2519inv(gfe2519_4L *einv, const gfe2519_4L *e) {

	gfe2519_5L e5,einv5;

	gfp2519pack45(&e5,e);
	gfp2519invr(&einv5,&e5); 
        gfp2519reduce(&einv5); 
	gfp2519pack54(einv,&einv5);
	gfp2519makeunique(einv); 
}


/* Routine borrowed from the work "Kummer for genus one over prime order fields" by 
   Sabyasachi Karati and Palash Sarkar.
   Code-link: https://github.com/skarati/KummerLineV02/blob/master/KummerLine2519(81%2C20)/kummer.h
*/
void gfp2519invr(gfe2519_5L *einv,const gfe2519_5L *e) {	

	gfe2519_5L t,t2,t4,t5,t9,t11;
	gfe2519_5L t_5_0,t2_10_0,t2_15_0,t2_30_0,t2_31_1;
	gfe2519_5L t_32_2,t2_62_1,t2_63_2,t2_124_1,t2_125_2;		
										
	/* 2  */ gfp2519sqr(&t2,e);
	/* 4  */ gfp2519sqr(&t4,&t2);
	/* 5  */ gfp2519mul(&t5,e,&t4);
	/* 8  */ gfp2519sqr(&t,&t4);
	/* 9  */ gfp2519mul(&t9,e,&t);
	/* 11 */ gfp2519mul(&t11,&t2,&t9);
	/* 22 */ gfp2519sqr(&t,&t11);

	/* 2^5   -  1     */ gfp2519mul(&t2_5_0,&t9,&t);

	/* 2^6   -  2^1   */ gfp2519sqr(&t2_10_0,&t2_5_0);

	/* 2^10  -  2^5   */ gfp2519nsqr(&t2_10_0,&t2_10_0,4);
	/* 2^10  -  1     */ gfp2519mul(&t2_10_0,&t2_5_0,&t2_10_0);

	/* 2^11  -  2^1   */ gfp2519sqr(&t2_15_0,&t2_10_0);
	/* 2^15  -  2^5   */ gfp2519nsqr(&t2_15_0,&t2_15_0,4);
	/* 2^15  -  1     */ gfp2519mul(&t2_15_0,&t2_5_0,&t2_15_0);

	/* 2^16  -  2^1   */ gfp2519sqr(&t2_30_0,&t2_15_0);
	/* 2^30  -  2^15  */ gfp2519nsqr(&t2_30_0,&t2_30_0,14);
	/* 2^30  -  1     */ gfp2519mul(&t2_30_0,&t2_15_0,&t2_30_0);

	/* 2^31  -  2^1   */ gfp2519sqr(&t2_31_1,&t2_30_0);
	/* 2^32  -  2^2   */ gfp2519sqr(&t2_32_2,&t2_31_1);
	/* 2^33  -  2^3   */ gfp2519sqr(&t,&t2_32_2);
	/* 2^62  -  2^32  */ gfp2519nsqr(&t,&t,29);
	/* 2^62  -  2^2   */ gfp2519mul(&t,&t2_32_2,&t);
	/* 2^62  -  2^1   */ gfp2519mul(&t2_62_1,&t2,&t);
	/* 2^63  -  2^2   */ gfp2519sqr(&t2_63_2,&t2_62_1);
	/* 2^64  -  2^3   */ gfp2519sqr(&t,&t2_63_2);
	/* 2^124 -  2^63  */ gfp2519nsqr(&t,&t,60);
	/* 2^124 -  2^2   */ gfp2519mul(&t,&t2_63_2,&t);
	/* 2^124 -  2^1   */ gfp2519mul(&t2_124_1,&t2,&t);
	/* 2^125 -  2^2   */ gfp2519sqr(&t2_125_2,&t2_124_1);
	/* 2^126 -  2^3   */ gfp2519sqr(&t,&t2_125_2);
	/* 2^248 -  2^125 */ gfp2519nsqr(&t,&t,122);
	/* 2^248 -  2^2   */ gfp2519mul(&t,&t,&t2_125_2);
	/* 2^248 -  2^1   */ gfp2519mul(&t,&t,&t2);
	/* 2^251 -  2^4   */ gfp2519nsqr(&t,&t,3);
	/* 2^251 -  11    */ gfp2519mul(einv,&t,&t5);
}


void gfp2519makeunique(gfe2519_4L *h) {

	uchar8  i;
	uint64  u,v;

	u = (h->l[0] >= LIMB0);
	for (i=1; i<LIMBS-1; ++i) 
		u = u & (h->l[i] == -1ULL);
	u = u & (h->l[LIMBS-1] == 0x07FFFFFFFFFFFFFF);
	v = -u; u = ~v;

        h->l[0]  = (h->l[0] & u) | ((h->l[0] - LIMB0) & v);
	for (i=1; i<LIMBS; ++i) 
        	h->l[i]  = (h->l[i] & u) | (0ULL & v);
}
