/*
+-----------------------------------------------------------------------------+
| This code corresponds to the Galois field F(2^521-1) from the paper         |
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
#include "p5211.h"
#include "p5211pack.h"
#include "measure.h"

#define change_input(x,y,z)  {x[0] = y[0]^z[0];}
#define FILE stdout
void print_elem(type64 *e);

int main() {
	
	type64 e[9] = {0xFFFFFFFFFFFFFFFE,-1,-1,-1,  -1,-1,-1,-1,0x1FF};
	
	//type64 e[9] = {0xFFFFFFFFFFFFFFFD,-1,-1,-1,  -1,-1,-1,-1,0x1FF};
	//type64 e[9] = {1,0,0,0,0,0,0,0,0};
	//type64 e[9] = {2,0,0,0,0,0,0,0,0};
	//type64 e[9] = {1,1,1,1,1,1,1,1,1};
	//type64 e[9] = {2,2,2,2,2,2,2,2,2};

	type64 einv[9];

	fprintf(FILE,"\nComputations for p5211 using Unsaturated Limb Representation:\n");
	fprintf(FILE,"=============================================================\n\n");
	
	fprintf(FILE,"The field element is:\t\t"); print_elem(e);  
	gfp5211inv(einv,e); 
	fprintf(FILE,"The found inverse is:\t\t"); print_elem(einv);  

	type64 t[9],t1[9],t2[9],t3[9];
	gfp5211pack(t1,e); gfp5211pack(t2,einv);
	gmul(t2,t1,t3); gfp5211reduce(t3);
	gfp5211unpack(t,t3);
	printf("The cross check value is:\t"); print_elem(t);

	fprintf(FILE,"Computing CPU-cycles. It will take some time. Please wait!\n\n");
	MEASURE_TIME({gfp5211inv(einv,e);change_input(e,einv,e);});
	fprintf(FILE,"CPU-cycles for a single field-inversion is:%6.0lf\n\n", ceil(((get_median())/(double)(N))));
	
	return 0;
}


void print_elem(type64 *e){

	uchar8  i;

	for (i=LIMBS-1; i>0; --i) 
		fprintf(FILE,"%16lX ",e[i]);
	fprintf(FILE,"%16lX \n\n",e[0]);
}
