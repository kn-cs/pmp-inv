/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^266-3) from the paper         |
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

#include"p2663pack.h"

void  gfp2663pack(gfe2663 *uprime, const gfe2663 *u) {
													
	uprime->l[0] = ((u->l[0] & 0x003FFFFFFFFFFFFF));
													
	uprime->l[1] = ((u->l[0] & 0xFFC0000000000000) >> 54) | ((u->l[1] & 0x00000FFFFFFFFFFF) << 10);		
													
	uprime->l[2] = ((u->l[1] & 0xFFFFF00000000000) >> 44) | ((u->l[2] & 0x00000003FFFFFFFF) << 20);
													
	uprime->l[3] = ((u->l[2] & 0xFFFFFFFC00000000) >> 34) | ((u->l[3] & 0x0000000000FFFFFF) << 30);
													
	uprime->l[4] = ((u->l[3] & 0xFFFFFFFFFF000000) >> 24) | ((u->l[4] & 0x00000000000003FF) << 40);
}


void  gfp2663unpack(gfe2663 *u, const gfe2663 *uprime) {
													
	u->l[0] = (uprime->l[0] & 0x003FFFFFFFFFFFFF) | ((uprime->l[1] & 0x00000000000003FF) << 54);

	u->l[1] = ((uprime->l[1] & 0x003FFFFFFFFFFC00) >> 10) | ((uprime->l[2] & 0x00000000000FFFFF) << 44);
													
	u->l[2] = ((uprime->l[2] & 0x003FFFFFFFF00000) >> 20) | ((uprime->l[3] & 0x000000003FFFFFFF) << 34);
													
	u->l[3] = ((uprime->l[3] & 0x003FFFFFC0000000) >> 30) | ((uprime->l[4] & 0x000000FFFFFFFFFF) << 24);

	u->l[4] = ((uprime->l[4] & 0x0003FF0000000000) >> 40);
}
