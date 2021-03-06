/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^896-213) from the paper       |
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

#include "p896213.h"

#define LIMB0 0xFFFFFFFFFFFFFF2B

void gfp896213inv(gfe896213 *einv,const gfe896213 *e) {

	gfp896213invr(einv,e);
	gfp896213makeunique(einv);
}

void gfp896213invr(gfe896213 *einv, const gfe896213 *e) {

	gfe896213 t,t2,t3,t20,t40,t2_8_0,t2_16_0,t2_32_0,t2_64_0,t2_128_0,t2_256_0;

	/* 2  */ gfp896213sqr(&t2,e);
	/* 3  */ gfp896213mul(&t3,&t2,e); 
	/* 5  */ gfp896213mul(&t,&t3,&t2);
   	/* 20 */ gfp896213nsqr(&t20,&t,2);
	/* 40 */ gfp896213sqr(&t40,&t20);
    	/* 60 */ gfp896213mul(&t,&t40,&t20); 

    	/* 2^6 - 1       */ gfp896213mul(&t,&t,&t3);

    	/* 2^8 - 2^2     */ gfp896213nsqr(&t,&t,2);
    	/* 2^8 - 1       */ gfp896213mul(&t2_8_0,&t,&t3);

    	/* 2^16 - 2^8    */ gfp896213nsqr(&t,&t2_8_0,8);
    	/* 2^16 - 1      */ gfp896213mul(&t2_16_0,&t,&t2_8_0);

    	/* 2^32 - 2^16   */ gfp896213nsqr(&t,&t2_16_0,16);
    	/* 2^32 - 1      */ gfp896213mul(&t2_32_0,&t,&t2_16_0);

    	/* 2^64 - 2^32   */ gfp896213nsqr(&t,&t2_32_0,32);
    	/* 2^64 - 1      */ gfp896213mul(&t2_64_0,&t,&t2_32_0);

    	/* 2^128 - 2^64  */ gfp896213nsqr(&t,&t2_64_0,64);
    	/* 2^128 - 1     */ gfp896213mul(&t2_128_0,&t,&t2_64_0);

    	/* 2^256 - 2^128 */ gfp896213nsqr(&t,&t2_128_0,128);
    	/* 2^256 - 1     */ gfp896213mul(&t2_256_0,&t,&t2_128_0);

    	/* 2^512 - 2^256 */ gfp896213nsqr(&t,&t2_256_0,256);
    	/* 2^512 - 1     */ gfp896213mul(&t,&t,&t2_256_0);

    	/* 2^768 - 2^256 */ gfp896213nsqr(&t,&t,256);
    	/* 2^768 - 1     */ gfp896213mul(&t,&t,&t2_256_0);
 
    	/* 2^832 - 2^64  */ gfp896213nsqr(&t,&t,64);
    	/* 2^832 - 1     */ gfp896213mul(&t,&t,&t2_64_0);

    	/* 2^864 - 2^32  */ gfp896213nsqr(&t,&t,32);
    	/* 2^864 - 1     */ gfp896213mul(&t,&t,&t2_32_0);

    	/* 2^880 - 2^16  */ gfp896213nsqr(&t,&t,16);
    	/* 2^880 - 1     */ gfp896213mul(&t,&t,&t2_16_0);

    	/* 2^888 - 2^8   */ gfp896213nsqr(&t,&t,8);
    	/* 2^888 - 1     */ gfp896213mul(&t,&t,&t2_8_0);

    	/* 2^896 - 2^8   */ gfp896213nsqr(&t,&t,8);
    	/* 2^896 - 216   */ gfp896213mul(&t,&t,&t40);
    	/* 2^896 - 215   */ gfp896213mul(einv,&t,e);
}


void gfp896213makeunique(gfe896213 *h) {

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
