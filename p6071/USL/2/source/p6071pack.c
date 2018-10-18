/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^607-1) from the paper         |
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

#include"p6071pack.h"

void  gfp6071pack(gfe6071 *uprime, const gfe6071 *u) {
													
	uprime->l[0] = ((u->l[0] & 0x1FFFFFFFFFFFFFFF));
													
	uprime->l[1] = ((u->l[0] & 0xE000000000000000) >> 61) | ((u->l[1] & 0x03FFFFFFFFFFFFFF) << 3);
													
	uprime->l[2] = ((u->l[1] & 0xFC00000000000000) >> 58) | ((u->l[2] & 0x007FFFFFFFFFFFFF) << 6);		
													
	uprime->l[3] = ((u->l[2] & 0xFF80000000000000) >> 55) | ((u->l[3] & 0x000FFFFFFFFFFFFF) << 9);

	uprime->l[4] = ((u->l[3] & 0xFFF0000000000000) >> 52) | ((u->l[4] & 0x0001FFFFFFFFFFFF) << 12);

	uprime->l[5] = ((u->l[4] & 0xFFFE000000000000) >> 49) | ((u->l[5] & 0x00003FFFFFFFFFFF) << 15);

	uprime->l[6] = ((u->l[5] & 0xFFFFC00000000000) >> 46) | ((u->l[6] & 0x000007FFFFFFFFFF) << 18);

	uprime->l[7] = ((u->l[6] & 0xFFFFF80000000000) >> 43) | ((u->l[7] & 0x000000FFFFFFFFFF) << 21);

	uprime->l[8] = ((u->l[7] & 0xFFFFFF0000000000) >> 40) | ((u->l[8] & 0x0000001FFFFFFFFF) << 24);

	uprime->l[9] = ((u->l[8] & 0xFFFFFFE000000000) >> 37) | ((u->l[9] & 0x000000007FFFFFFF) << 27);
}


void  gfp6071unpack(gfe6071 *u, const gfe6071 *uprime) {									
													
	u->l[0] = ((uprime->l[0] & 0x1FFFFFFFFFFFFFFF))       | ((uprime->l[1] & 0x0000000000000007) << 61);		
													
	u->l[1] = ((uprime->l[1] & 0x1FFFFFFFFFFFFFF8) >>  3) | ((uprime->l[2] & 0x000000000000003F) << 58);
													
	u->l[2] = ((uprime->l[2] & 0x1FFFFFFFFFFFFFC0) >>  6) | ((uprime->l[3] & 0x00000000000001FF) << 55);	
													
	u->l[3] = ((uprime->l[3] & 0x1FFFFFFFFFFFFE00) >>  9) | ((uprime->l[4] & 0x0000000000000FFF) << 52);

	u->l[4] = ((uprime->l[4] & 0x1FFFFFFFFFFFF000) >> 12) | ((uprime->l[5] & 0x0000000000007FFF) << 49);

	u->l[5] = ((uprime->l[5] & 0x1FFFFFFFFFFF8000) >> 15) | ((uprime->l[6] & 0x000000000003FFFF) << 46);

	u->l[6] = ((uprime->l[6] & 0x1FFFFFFFFFFC0000) >> 18) | ((uprime->l[7] & 0x00000000001FFFFF) << 43);

	u->l[7] = ((uprime->l[7] & 0x1FFFFFFFFFE00000) >> 21) | ((uprime->l[8] & 0x0000000000FFFFFF) << 40);

	u->l[8] = ((uprime->l[8] & 0x1FFFFFFFFF000000) >> 24) | ((uprime->l[9] & 0x0000000007FFFFFF) << 37);

	u->l[9] = ((uprime->l[9] & 0x03FFFFFFF8000000) >> 27);
}
