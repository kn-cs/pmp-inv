/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^255-19) from the paper        |
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

#include<stdio.h>
#include<math.h>
#include"fp25519_x64.h"
#include"measure.h"

#define change_input(x,y,z)  {x[0] = y[0]^z[0];}
#define FILE stdout
#define LIMBS 4
void print_elem(const uint64_t *);

int main() {
	
	uint64_t e[4] = {0xFFFFFFFFFFFFFFEC,-1,-1,0x7FFFFFFFFFFFFFFF};
		
	// other test data
	//uint64_t e[4] = {0xFFFFFFFFFFFFFFEB,-1,-1,0x7FFFFFFFFFFFFFFF};
	//uint64_t e[4] = {0xFFFFFFFFFFFFFFEA,-1,-1,0x7FFFFFFFFFFFFFFF};
	//uint64_t e[4] = {0xFFFFFFFFFFFFFFA9,-1,-1,0x7FFFFFFFFFFFFFFF};
	//uint64_t e[4] = {1,0,0,0};
	//uint64_t e[4] = {0,0,1,0};
	//uint64_t e[4] = {2,0,2,0};
	//uint64_t e[4] = {3,2,5,5};

	uint64_t einv[4];

	fprintf(FILE,"\nComputations for p25519 using Saturated Limb Representation and Two Independent Carry Chains:\n");
	fprintf(FILE,"=============================================================================================\n\n");
	
	fprintf(FILE,"The field element is:\t\t"); print_elem(e);  
	inv_EltFp25519_1w_x64(einv,e);
	fprintf(FILE,"The found inverse is:\t\t"); print_elem(einv);  

	uint64_t t[4];
	mul_EltFp25519_1w_x64(t,e,einv); fred_EltFp25519_1w_x64(t); //gfp25519makeunique(t);
	fprintf(FILE,"The cross check value is:\t"); print_elem(t);

	fprintf(FILE,"Computing CPU-cycles. It will take some time. Please wait!\n\n");
	MEASURE_TIME({inv_EltFp25519_1w_x64(einv,e);change_input(e,einv,e);});
	fprintf(FILE,"CPU-cycles for a single field-inversion is:%6.0lf\n\n", ceil(((get_median())/(double)(N))));  
	
	return 0;
}


void print_elem(const uint64_t *e){

	unsigned char i;

	for (i=LIMBS-1; i>0; --i) 
		fprintf(FILE,"%16lX ",e[i]);
	fprintf(FILE,"%16lX \n\n",e[0]);
}
