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


void gfp2519invr(gfe2519_5L *einv,const gfe2519_5L *e) {	

	gfe2519_5L t,t2,t3,t5,t10,t2_5_0,t2_10_0,t2_20_0,t2_40_0,t2_80_0;
								
	/* 2  */ gfp2519sqr(&t2,e); 
	/* 3  */ gfp2519mul(&t3,&t2,e);
	/* 5  */ gfp2519mul(&t5,&t3,&t2);
	/* 10 */ gfp2519sqr(&t10,&t5);
	/* 20 */ gfp2519sqr(&t,&t10);
	/* 30 */ gfp2519mul(&t,&t,&t10);

	/* 2^5   -  1     */ gfp2519mul(&t2_5_0,&t,e);

	/* 2^10  -  2^5   */ gfp2519nsqr(&t,&t2_5_0,5);
	/* 2^10  -  1     */ gfp2519mul(&t2_10_0,&t,&t2_5_0);

	/* 2^20  -  2^10  */ gfp2519nsqr(&t,&t2_10_0,10);
	/* 2^20  -  1     */ gfp2519mul(&t2_20_0,&t,&t2_10_0);

	/* 2^40  -  2^20  */ gfp2519nsqr(&t,&t2_20_0,20);
	/* 2^40  -  1     */ gfp2519mul(&t2_40_0,&t,&t2_20_0);

	/* 2^80  -  2^40  */ gfp2519nsqr(&t,&t2_40_0,40);
	/* 2^80  -  1     */ gfp2519mul(&t2_80_0,&t,&t2_40_0);

	/* 2^160 -  2^80  */ gfp2519nsqr(&t,&t2_80_0,80);
	/* 2^160 -  1     */ gfp2519mul(&t,&t,&t2_80_0);

	/* 2^240 -  2^80  */ gfp2519nsqr(&t,&t,80);
	/* 2^240 -  1     */ gfp2519mul(&t,&t,&t2_80_0);

	/* 2^245 -  2^5   */ gfp2519nsqr(&t,&t,5);
	/* 2^245 -  1     */ gfp2519mul(&t,&t,&t2_5_0);

	/* 2^247 -  2^2   */ gfp2519nsqr(&t,&t,2);
	/* 2^247 -  1     */ gfp2519mul(&t,&t,&t3);

	/* 2^251 -  2^4   */ gfp2519nsqr(&t,&t,4);
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