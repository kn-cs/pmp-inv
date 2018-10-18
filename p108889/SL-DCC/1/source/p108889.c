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

#include "p108889.h"

#define LIMB0 0xFFFFFFFFFFFFFFA7

void gfp108889inv(gfe108889 *einv,const gfe108889 *e) {

	gfp108889invr(einv,e);
	gfp108889makeunique(einv);
}

void gfp108889invr(gfe108889 *einv, const gfe108889 *e) {

	gfe108889 t,t3,t6,t2_5_0,t2_10_0,t2_20_0,t2_40_0,t2_80_0,t2_160_0,t2_320_0;

	/* 2  */ gfp108889sqr(&t,e); 
	/* 3  */ gfp108889mul(&t3,&t,e);
	/* 6  */ gfp108889sqr(&t6,&t3);  
	/* 12 */ gfp108889sqr(&t,&t6);  
	/* 15 */ gfp108889mul(&t,&t,&t3);
	/* 30 */ gfp108889sqr(&t,&t);

	/* 2^5 - 1       */ gfp108889mul(&t2_5_0,&t,e);

	/* 2^10 - 2^5    */ gfp108889nsqr(&t,&t2_5_0,5);
    	/* 2^10 - 1      */ gfp108889mul(&t2_10_0,&t,&t2_5_0);

    	/* 2^20 - 2^10   */ gfp108889nsqr(&t,&t2_10_0,10);
    	/* 2^20 - 1      */ gfp108889mul(&t2_20_0,&t,&t2_10_0); 

    	/* 2^40 - 2^20   */ gfp108889nsqr(&t,&t2_20_0,20);
    	/* 2^40 - 1      */ gfp108889mul(&t2_40_0,&t,&t2_20_0);

    	/* 2^80 - 2^40   */ gfp108889nsqr(&t,&t2_40_0,40);
    	/* 2^80 - 1      */ gfp108889mul(&t2_80_0,&t,&t2_40_0);

    	/* 2^160 - 2^80  */ gfp108889nsqr(&t,&t2_80_0,80);
    	/* 2^160 - 1     */ gfp108889mul(&t2_160_0,&t,&t2_80_0);

    	/* 2^320 - 2^160 */ gfp108889nsqr(&t,&t2_160_0,160);
    	/* 2^320 - 1     */ gfp108889mul(&t2_320_0,&t,&t2_160_0);

    	/* 2^640 - 2^320 */ gfp108889nsqr(&t,&t2_320_0,320);
    	/* 2^640 - 1     */ gfp108889mul(&t,&t,&t2_320_0);

    	/* 2^960 - 2^320 */ gfp108889nsqr(&t,&t,320);
    	/* 2^960 - 1     */ gfp108889mul(&t,&t,&t2_320_0);

    	/* 2^1040- 2^80  */ gfp108889nsqr(&t,&t,80);
    	/* 2^1040- 1     */ gfp108889mul(&t,&t,&t2_80_0);
 
    	/* 2^1080- 2^40  */ gfp108889nsqr(&t,&t,40);
    	/* 2^1080- 1     */ gfp108889mul(&t,&t,&t2_40_0);

    	/* 2^1081- 2     */ gfp108889sqr(&t,&t);
    	/* 2^1081- 1     */ gfp108889mul(&t,&t,e);

    	/* 2^1088- 2^7   */ gfp108889nsqr(&t,&t,7);
    	/* 2^1088- 97    */ gfp108889mul(&t,&t,&t2_5_0);
    	/* 2^1088- 91    */ gfp108889mul(einv,&t,&t6);
}


void gfp108889makeunique(gfe108889 *h) {

	uchar8  i;
	uint64  u,v;

	u = (h->l[0] >= LIMB0);
	for (i=1; i<LIMBS; ++i) 
		u = u & (h->l[i] == -1ULL);
	v = -u; u = ~v;

        h->l[0]  = (h->l[0] & u) | ((h->l[0] - LIMB0) & v);
	for (i=1; i<LIMBS; ++i) 
        	h->l[i]  = (h->l[i] & u) | (0ULL & v);
}
