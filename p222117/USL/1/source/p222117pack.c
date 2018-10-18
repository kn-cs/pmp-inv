/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^222-117) from the paper       |
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

#include"p222117pack.h"


void  gfp222117pack(gfe222117 *uprime, const gfe222117 *u) {
													
	uprime->l[0] = u->l[0] & 0x00FFFFFFFFFFFFFF;								
													
	uprime->l[1] = ((u->l[0] & 0xFF00000000000000) >> 56) | ((u->l[1] & 0x0000FFFFFFFFFFFF) <<  8);		
													
	uprime->l[2] = ((u->l[1] & 0xFFFF000000000000) >> 48) | ((u->l[2] & 0x000000FFFFFFFFFF) << 16);		
													
	uprime->l[3] = ((u->l[2] & 0xFFFFFF0000000000) >> 40) | ((u->l[3] & 0x000000003FFFFFFF) << 24);
}


void  gfp222117unpack(gfe222117 *u, const gfe222117 *uprime) {									
													
	u->l[0] = (uprime->l[0] & 0x00FFFFFFFFFFFFFF) | ((uprime->l[1] & 0x00000000000000FF) << 56);
													
	u->l[1] = ((uprime->l[1] & 0x00FFFFFFFFFFFF00) >>  8) | ((uprime->l[2] & 0x000000000000FFFF) << 48);	
													
	u->l[2] = ((uprime->l[2] & 0x00FFFFFFFFFF0000) >> 16) | ((uprime->l[3] & 0x0000000000FFFFFF) << 40);	
													
	u->l[3] = ((uprime->l[3] & 0x003FFFFFFF000000) >> 24);
}
