/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^256-2^32-977) from the paper  |
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

#include "p25632977.h"
#include "p25632977pack.h"

#define LIMB0 0xFFFFFFFEFFFFFC2F

void gfp25632977inv(gfe25632977_4L *einv, const gfe25632977_4L *e) {

	gfe25632977_5L e5,einv5;

	gfp25632977pack45(&e5,e);
	gfp25632977invr(&einv5,&e5);
	gfp25632977reduce(&einv5);  
	gfp25632977pack54(einv,&einv5);
	gfp25632977makeunique(einv);
}

/* The following code for field inversion has been borrowed from the web link 
   https://github.com/bitcoin/bitcoin/blob/master/src/secp256k1/src/field_impl.h
*/

void gfp25632977invr(gfe25632977_5L *r, const gfe25632977_5L *a) {

	gfe25632977_5L x2, x3, x6, x9, x11, x22, x44, x88, x176, x220, x223, t1;

    	int j;

    	/** The binary representation of (p - 2) has 5 blocks of 1s, with lengths in
     	*  { 1, 2, 22, 223 }. Use an addition chain to calculate 2^n - 1 for each block:
     	*  [1], [2], 3, 6, 9, 11, [22], 44, 88, 176, 220, [223]
     	*/

    	gfp25632977sqr(&x2, a);
    	gfp25632977mul(&x2, &x2, a);

    	gfp25632977sqr(&x3, &x2);
    	gfp25632977mul(&x3, &x3, a);

    	x6 = x3;
    	for (j=0; j<3; j++) {
        	gfp25632977sqr(&x6, &x6);
    	}
    	gfp25632977mul(&x6, &x6, &x3);

	x9 = x6;
    	for (j=0; j<3; j++) {
        	gfp25632977sqr(&x9, &x9);
    	}
    	gfp25632977mul(&x9, &x9, &x3);

    	x11 = x9;
    	for (j=0; j<2; j++) {
        	gfp25632977sqr(&x11, &x11);
    	}
    	gfp25632977mul(&x11, &x11, &x2);

    	x22 = x11;
    	for (j=0; j<11; j++) {
        	gfp25632977sqr(&x22, &x22);
    	}
    	gfp25632977mul(&x22, &x22, &x11);

    	x44 = x22;
    	for (j=0; j<22; j++) {
        	gfp25632977sqr(&x44, &x44);
    	}
    	gfp25632977mul(&x44, &x44, &x22);

    	x88 = x44;
    	for (j=0; j<44; j++) {
        	gfp25632977sqr(&x88, &x88);
    	}
    	gfp25632977mul(&x88, &x88, &x44);

    	x176 = x88;
    	for (j=0; j<88; j++) {
        	gfp25632977sqr(&x176, &x176);
    	}
    	gfp25632977mul(&x176, &x176, &x88);

    	x220 = x176;
    	for (j=0; j<44; j++) {
        	gfp25632977sqr(&x220, &x220);
    	}
    	gfp25632977mul(&x220, &x220, &x44);

    	x223 = x220;
    	for (j=0; j<3; j++) {
        	gfp25632977sqr(&x223, &x223);
    	}
    	gfp25632977mul(&x223, &x223, &x3);

    	/* The final result is then assembled using a sliding window over the blocks. */

    	t1 = x223;
    	for (j=0; j<23; j++) {
        	gfp25632977sqr(&t1, &t1);
    	}
    	gfp25632977mul(&t1, &t1, &x22);
    	for (j=0; j<5; j++) {
        	gfp25632977sqr(&t1, &t1);
    	}
    	gfp25632977mul(&t1, &t1, a);
    	for (j=0; j<3; j++) {
        	gfp25632977sqr(&t1, &t1);
    	}
    	gfp25632977mul(&t1, &t1, &x2);
    	for (j=0; j<2; j++) {
        	gfp25632977sqr(&t1, &t1);
    	}
    	gfp25632977mul(r, a, &t1);
}


void gfp25632977makeunique(gfe25632977_4L *h) {

	uchar8  i;
	uint64  u,v;

	u = (h->l[0] >= LIMB0);
	for (i=1; i<LIMBS-1; ++i) 
		u = u & (h->l[i] == -1ULL);
	u = u & (h->l[LIMBS-1] == 0xFFFFFFFFFFFFFFFF);
	v = -u; u = ~v;

        h->l[0]  = (h->l[0] & u) | ((h->l[0] - LIMB0) & v);
	for (i=1; i<LIMBS; ++i) 
        	h->l[i]  = (h->l[i] & u) | (0ULL & v);
}
