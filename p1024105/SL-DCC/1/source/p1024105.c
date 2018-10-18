/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^1024-105) from the paper      |
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

#include "p1024105.h"

#define LIMB0 0xFFFFFFFFFFFFFF97

void gfp1024105inv(gfe1024105 *einv,const gfe1024105 *e) {

	gfp1024105invr(einv,e);
	gfp1024105makeunique(einv);
}

void gfp1024105invr(gfe1024105 *einv, const gfe1024105 *e) {

	gfe1024105 t,t2,t3,t5,t20,t2_8_0,t2_16_0,t2_32_0,t2_64_0,t2_128_0,t2_256_0;

	/* 2  */ gfp1024105sqr(&t2,e);
	/* 3  */ gfp1024105mul(&t3,&t2,e); 
	/* 5  */ gfp1024105mul(&t5,&t3,&t2);
   	/* 20 */ gfp1024105nsqr(&t20,&t5,2);
	/* 40 */ gfp1024105sqr(&t,&t20);
    	/* 60 */ gfp1024105mul(&t,&t,&t20);

    	/* 2^6 - 1       */ gfp1024105mul(&t,&t,&t3);

    	/* 2^8 - 2^2     */ gfp1024105nsqr(&t,&t,2);
    	/* 2^8 - 1       */ gfp1024105mul(&t2_8_0,&t,&t3);

    	/* 2^16 - 2^8    */ gfp1024105nsqr(&t,&t2_8_0,8);
    	/* 2^16 - 1      */ gfp1024105mul(&t2_16_0,&t,&t2_8_0);

    	/* 2^32 - 2^16   */ gfp1024105nsqr(&t,&t2_16_0,16);
    	/* 2^32 - 1      */ gfp1024105mul(&t2_32_0,&t,&t2_16_0);

    	/* 2^64 - 2^32   */ gfp1024105nsqr(&t,&t2_32_0,32);
    	/* 2^64 - 1      */ gfp1024105mul(&t2_64_0,&t,&t2_32_0);

    	/* 2^128 - 2^64  */ gfp1024105nsqr(&t,&t2_64_0,64);
    	/* 2^128 - 1     */ gfp1024105mul(&t2_128_0,&t,&t2_64_0);

    	/* 2^256 - 2^128 */ gfp1024105nsqr(&t,&t2_128_0,128);
    	/* 2^256 - 1     */ gfp1024105mul(&t2_256_0,&t,&t2_128_0);

    	/* 2^512 - 2^256 */ gfp1024105nsqr(&t,&t2_256_0,256);
    	/* 2^512 - 1     */ gfp1024105mul(&t,&t,&t2_256_0);

    	/* 2^768 - 2^256 */ gfp1024105nsqr(&t,&t,256);
    	/* 2^768 - 1     */ gfp1024105mul(&t,&t,&t2_256_0);
 
    	/* 2^896 - 2^128 */ gfp1024105nsqr(&t,&t,128);
    	/* 2^896 - 1     */ gfp1024105mul(&t,&t,&t2_128_0);

    	/* 2^960 - 2^64  */ gfp1024105nsqr(&t,&t,64);
    	/* 2^960 - 1     */ gfp1024105mul(&t,&t,&t2_64_0);

    	/* 2^992 - 2^32  */ gfp1024105nsqr(&t,&t,32);
    	/* 2^992 - 1     */ gfp1024105mul(&t,&t,&t2_32_0);

    	/* 2^1008- 2^16  */ gfp1024105nsqr(&t,&t,16);
    	/* 2^1008- 1     */ gfp1024105mul(&t,&t,&t2_16_0);

    	/* 2^1016- 2^8   */ gfp1024105nsqr(&t,&t,8);
    	/* 2^1016- 1     */ gfp1024105mul(&t,&t,&t2_8_0);

    	/* 2^1017- 2     */ gfp1024105sqr(&t,&t);
    	/* 2^1017- 1     */ gfp1024105mul(&t,&t,e);

    	/* 2^1024- 2^7   */ gfp1024105nsqr(&t,&t,7);
    	/* 2^1024- 108   */ gfp1024105mul(&t,&t,&t20);
    	/* 2^1024- 107   */ gfp1024105mul(einv,&t,e);
}


void gfp1024105makeunique(gfe1024105 *h) {

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
