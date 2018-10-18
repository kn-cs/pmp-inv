/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^383-187) from the paper       |
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

#include "p383187.h"
#include "p383187pack.h"

#define LIMB0 0xFFFFFFFFFFFFFF45

void gfp383187inv(gfe383187_6L *einv, const gfe383187_6L *e) {

	gfe383187_7L e7,einv7;

	gfp383187pack67(&e7,e);
	gfp383187invr(&einv7,&e7);
	gfp383187reduce(&einv7);
	gfp383187pack76(einv,&einv7);
	gfp383187makeunique(einv); 
}


void gfp383187invr(gfe383187_7L *einv, const gfe383187_7L *e) {	

	gfe383187_7L t,t2,t5,t10,t62,t2_5_0,t2_10_0,t2_20_0,t2_40_0,t2_80_0,t2_160_0;

	/* 2  */ gfp383187sqr(&t2,e); 
 	/* 3  */ gfp383187mul(&t,&t2,e); 
	/* 5  */ gfp383187mul(&t5,&t,&t2); 
	/* 10 */ gfp383187sqr(&t10,&t5);
	/* 20 */ gfp383187sqr(&t,&t10);  
	/* 30 */ gfp383187mul(&t,&t,&t10); 

	/* 2^5  -  1     */ gfp383187mul(&t2_5_0,&t,e); 

	/* 2^6  -  2     */ gfp383187sqr(&t62,&t2_5_0);

	/* 2^10 -  2^5   */ gfp383187nsqr(&t,&t62,4);
	/* 2^10 -  1     */ gfp383187mul(&t2_10_0,&t,&t2_5_0);

	/* 2^20 -  2^10  */ gfp383187nsqr(&t,&t2_10_0,10);
	/* 2^20 -  1     */ gfp383187mul(&t2_20_0,&t,&t2_10_0);

	/* 2^40 - 2^20   */ gfp383187nsqr(&t,&t2_20_0,20);
	/* 2^40 - 1      */ gfp383187mul(&t2_40_0,&t,&t2_20_0);

	/* 2^80 -  2^40  */ gfp383187nsqr(&t,&t2_40_0,40); 
	/* 2^80 -  1     */ gfp383187mul(&t2_80_0,&t,&t2_40_0);

	/* 2^160 - 2^80  */ gfp383187nsqr(&t,&t2_80_0,80);
	/* 2^160 - 1     */ gfp383187mul(&t2_160_0,&t,&t2_80_0);

	/* 2^320 - 2^160 */ gfp383187nsqr(&t,&t2_160_0,160);
	/* 2^320 - 1     */ gfp383187mul(&t,&t,&t2_160_0);

	/* 2^360 - 2^40  */ gfp383187nsqr(&t,&t,40);
	/* 2^360 - 1     */ gfp383187mul(&t,&t,&t2_40_0);

	/* 2^370 - 2^10  */ gfp383187nsqr(&t,&t,10);
	/* 2^370 - 1     */ gfp383187mul(&t,&t,&t2_10_0);

	/* 2^375 - 2^5   */ gfp383187nsqr(&t,&t,5);
	/* 2^375 - 1     */ gfp383187mul(&t,&t,&t2_5_0);

	/* 2^383 - 2^8   */ gfp383187nsqr(&t,&t,8);
	/* 2^383 - 194   */ gfp383187mul(&t,&t,&t62);
	/* 2^383 - 189   */ gfp383187mul(einv,&t,&t5);
}


void gfp383187makeunique(gfe383187_6L *h) {

	uchar8  i;
	uint64  u,v;

	u = (h->l[0] >= LIMB0);
	for (i=1; i<LIMBS-1; ++i) 
		u = u & (h->l[i] == -1ULL);
	u = u & (h->l[LIMBS-1] == 0x7FFFFFFFFFFFFFFF);
	v = -u; u = ~v;

        h->l[0]  = (h->l[0] & u) | ((h->l[0] - LIMB0) & v);
	for (i=1; i<LIMBS; ++i) 
        	h->l[i]  = (h->l[i] & u) | (0ULL & v);
}
