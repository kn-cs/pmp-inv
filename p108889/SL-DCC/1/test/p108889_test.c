/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^1088-89) from the paper       |
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

#include <stdio.h>
#include <math.h>
#include "datatype.h"
#include "p108889.h"
#include "measure.h"

#define change_input(x,y,z)  {x.l[0] = y.l[0]^z.l[0];}
#define FILE stdout
void print_elem(const gfe108889 *);

int main() {
	
	gfe108889 e = {0xFFFFFFFFFFFFFFA6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	
	//gfe108889 e = {0xFFFFFFFFFFFFFFA5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	//gfe108889 e = {0,0x4000000000000000,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//gfe108889 e = {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  
	//gfe108889 e = {128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
	//gfe108889 e = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	//gfe108889 e = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
	//gfe108889 e = {222222222222222,22,222,2222,22222,222222,22222222,222222222,2,2,2,2,2,2,2,2,2};
	//gfe108889 e = {0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0};  
        
	gfe108889 einv;

	fprintf(FILE,"\nComputations for p108889 using Saturated Limb Representation and Two Independent Carry Chains:\n");
	fprintf(FILE,"==============================================================================================\n\n");
	
	fprintf(FILE,"The field element is:\t\t"); print_elem(&e);  
	gfp108889inv(&einv,&e);
	fprintf(FILE,"The found inverse is:\t\t"); print_elem(&einv);  

	gfe108889 t;
	gfp108889mul(&t,&e,&einv); gfp108889makeunique(&t);
	fprintf(FILE,"The cross check value is:\t"); print_elem(&t);  

	fprintf(FILE,"Computing CPU-cycles. It will take some time. Please wait!\n\n");
	MEASURE_TIME({gfp108889inv(&einv,&e);change_input(e,einv,e);});
	fprintf(FILE,"CPU-cycles for a single field-inversion is:%6.0lf\n\n", ceil(((get_median())/(double)(N))));
	
	return 0;
}


void print_elem(const gfe108889 *e){

	uchar8  i;

	for (i=LIMBS-1; i>0; --i) 
		fprintf(FILE,"%16llX ",e->l[i]);
	fprintf(FILE,"%16llX \n\n",e->l[0]);
}