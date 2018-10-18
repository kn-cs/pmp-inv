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

#include "p751165.h"

#define LIMB0 0xFFFFFFFFFFFFFF5B

void gfp751165inv(gfe751165 *einv,const gfe751165 *e) {

	gfp751165invr(einv,e);
	gfp751165reduce(einv);
	gfp751165makeunique(einv);
}

void gfp751165invr(gfe751165 *einv, const gfe751165 *e) {

	gfe751165 t,t3,t12,t15,t62,t2_6_0,t2_8_0,t2_16_0,t2_32_0,t2_64_0,t2_128_0,t2_256_0;

	/* 2  */ gfp751165sqr(&t,e);
	/* 3  */ gfp751165mul(&t3,&t,e);
   	/* 12 */ gfp751165nsqr(&t12,&t3,2);
    	/* 15 */ gfp751165mul(&t15,&t12,&t3);
    	/* 30 */ gfp751165sqr(&t,&t15);

    	/* 2^5 - 1       */ gfp751165mul(&t,&t,e); 

    	/* 2^6 - 2       */ gfp751165sqr(&t62,&t);
    	/* 2^6 - 1       */ gfp751165mul(&t2_6_0,&t62,e); 

    	/* 2^8 - 2^2     */ gfp751165nsqr(&t,&t2_6_0,2);
    	/* 2^8 - 1       */ gfp751165mul(&t2_8_0,&t,&t3); 

    	/* 2^16 - 2^8    */ gfp751165nsqr(&t,&t2_8_0,8); 
    	/* 2^16 - 1      */ gfp751165mul(&t2_16_0,&t,&t2_8_0); 

    	/* 2^32 - 2^16   */ gfp751165nsqr(&t,&t2_16_0,16);
    	/* 2^32 - 1      */ gfp751165mul(&t2_32_0,&t,&t2_16_0);

    	/* 2^64 - 2^32   */ gfp751165nsqr(&t,&t2_32_0,32);
    	/* 2^64 - 1      */ gfp751165mul(&t2_64_0,&t,&t2_32_0);

    	/* 2^128 - 2^64  */ gfp751165nsqr(&t,&t2_64_0,64);
    	/* 2^128 - 1     */ gfp751165mul(&t2_128_0,&t,&t2_64_0);

    	/* 2^256 - 2^128 */ gfp751165nsqr(&t,&t2_128_0,128);
    	/* 2^256 - 1     */ gfp751165mul(&t2_256_0,&t,&t2_128_0);

    	/* 2^512 - 2^256 */ gfp751165nsqr(&t,&t2_256_0,256);
    	/* 2^512 - 1     */ gfp751165mul(&t,&t,&t2_256_0);

    	/* 2^640 - 2^128 */ gfp751165nsqr(&t,&t,128);
    	/* 2^640 - 1     */ gfp751165mul(&t,&t,&t2_128_0);
 
    	/* 2^704 - 2^64  */ gfp751165nsqr(&t,&t,64);
    	/* 2^704 - 1     */ gfp751165mul(&t,&t,&t2_64_0);

    	/* 2^736 - 2^32  */ gfp751165nsqr(&t,&t,32);
    	/* 2^736 - 1     */ gfp751165mul(&t,&t,&t2_32_0);

    	/* 2^742 - 2^6   */ gfp751165nsqr(&t,&t,6);
    	/* 2^742 - 1     */ gfp751165mul(&t,&t,&t2_6_0);

    	/* 2^743 - 2     */ gfp751165sqr(&t,&t);
    	/* 2^743 - 1     */ gfp751165mul(&t,&t,e);

    	/* 2^751 - 2^8   */ gfp751165nsqr(&t,&t,8);
    	/* 2^751 - 194   */ gfp751165mul(&t,&t,&t62);
    	/* 2^751 - 179   */ gfp751165mul(&t,&t,&t15);
    	/* 2^751 - 167   */ gfp751165mul(einv,&t,&t12);
}


void gfp751165makeunique(gfe751165 *h) {

	uchar8  i;
	uint64  u,v;

	u = (h->l[0] >= LIMB0);
	for (i=1; i<LIMBS-1; ++i) 
		u = u & (h->l[i] == -1ULL);
	u = u & (h->l[LIMBS-1] == 0x7FFFFFFFFFFF);
	v = -u; u = ~v;

        h->l[0]  = (h->l[0] & u) | ((h->l[0] - LIMB0) & v);
	for (i=1; i<LIMBS; ++i) 
        	h->l[i]  = (h->l[i] & u) | (0ULL & v);
}
