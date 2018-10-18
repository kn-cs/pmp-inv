/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^512-569) from the paper       |
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

#include"p512569pack.h"

void  gfp512569pack89(gfe512569_9L *uprime, const gfe512569_8L *u) {
													
	uprime->l[0] = ((u->l[0] & 0x01FFFFFFFFFFFFFF));								
													
	uprime->l[1] = ((u->l[0] & 0xFE00000000000000) >> 57) | ((u->l[1] & 0x0003FFFFFFFFFFFF) << 7);		
													
	uprime->l[2] = ((u->l[1] & 0xFFFC000000000000) >> 50) | ((u->l[2] & 0x000007FFFFFFFFFF) << 14);		
													
	uprime->l[3] = ((u->l[2] & 0xFFFFF80000000000) >> 43) | ((u->l[3] & 0x0000000FFFFFFFFF) << 21);

	uprime->l[4] = ((u->l[3] & 0xFFFFFFF000000000) >> 36) | ((u->l[4] & 0x000000001FFFFFFF) << 28);

	uprime->l[5] = ((u->l[4] & 0xFFFFFFFFE0000000) >> 29) | ((u->l[5] & 0x00000000003FFFFF) << 35);

	uprime->l[6] = ((u->l[5] & 0xFFFFFFFFFFC00000) >> 22) | ((u->l[6] & 0x0000000000007FFF) << 42);

	uprime->l[7] = ((u->l[6] & 0xFFFFFFFFFFFF8000) >> 15) | ((u->l[7] & 0x00000000000000FF) << 49);

	uprime->l[8] = ((u->l[7] & 0xFFFFFFFFFFFFFF00) >>  8);
}


void  gfp512569pack98(gfe512569_8L *u, const gfe512569_9L *uprime) {									
													
	u->l[0] = ((uprime->l[0] & 0x01FFFFFFFFFFFFFF))       | ((uprime->l[1] & 0x000000000000007F) << 57);		
													
	u->l[1] = ((uprime->l[1] & 0x01FFFFFFFFFFFF80) >>  7) | ((uprime->l[2] & 0x0000000000003FFF) << 50);	
													
	u->l[2] = ((uprime->l[2] & 0x01FFFFFFFFFFC000) >> 14) | ((uprime->l[3] & 0x00000000001FFFFF) << 43);	
													
	u->l[3] = ((uprime->l[3] & 0x01FFFFFFFFE00000) >> 21) | ((uprime->l[4] & 0x000000000FFFFFFF) << 36);

	u->l[4] = ((uprime->l[4] & 0x01FFFFFFF0000000) >> 28) | ((uprime->l[5] & 0x00000007FFFFFFFF) << 29);

	u->l[5] = ((uprime->l[5] & 0x01FFFFF800000000) >> 35) | ((uprime->l[6] & 0x000003FFFFFFFFFF) << 22);

	u->l[6] = ((uprime->l[6] & 0x01FFFC0000000000) >> 42) | ((uprime->l[7] & 0x0001FFFFFFFFFFFF) << 15);

	u->l[7] = ((uprime->l[7] & 0x01FE000000000000) >> 49) | ((uprime->l[8] & 0x00FFFFFFFFFFFFFF) << 8);
}
