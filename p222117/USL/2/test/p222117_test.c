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

#include<stdio.h>
#include<math.h>
#include"datatype.h"
#include"p222117.h"
#include"p222117pack.h"
#include"measure.h"

#define change_input(x,y,z)  {x.l[0] = y.l[0]^z.l[0];}
#define FILE stdout
void print_elem(const gfe222117 *);

int main() {
	
	gfe222117 e = {0xFFFFFFFFFFFFFF8A,-1,-1,0x3FFFFFFF};
	
	//gfe222117 e = {0xFFFFFFFFFFFFFF89,-1,-1,0x3FFFFFFF};
	//gfe222117 e = {0xFFFFFFFFFFFFFF88,-1,-1,0x3FFFFFFF};
	//gfe222117 e = {0xFFFFFFFFFFFFFF87,-1,-1,0x3FFFFFFF};
	//gfe222117 e = {2,2,2,2};
	//gfe222117 e = {2,0,0,0};
	//gfe222117 e = {2,0,2,0};
	//gfe222117 e = {3,2,5,5};

	gfe222117 einv;

	fprintf(FILE,"\nComputations for p222117 using Unsaturated Limb Representation:\n");
	fprintf(FILE,"===============================================================\n\n");
	
	fprintf(FILE,"The field element is:\t\t"); print_elem(&e);  
	gfp222117inv(&einv,&e);
	fprintf(FILE,"The found inverse is:\t\t"); print_elem(&einv);  

	gfe222117 t,t1,t2,t3;
	gfp222117pack(&t1,&e); gfp222117pack(&t2,&einv);
	gfp222117mul(&t3,&t2,&t1); gfp222117reduce(&t3);
	gfp222117unpack(&t,&t3); gfp222117makeunique(&t); 
	printf("The cross check value is:\t"); print_elem(&t);

	fprintf(FILE,"Computing CPU-cycles. It will take some time. Please wait!\n\n");
	MEASURE_TIME({gfp222117inv(&einv,&e);change_input(e,einv,e);});
	fprintf(FILE,"CPU-cycles for a single field-inversion is:%6.0lf\n\n", ceil(((get_median())/(double)(N))));
	
	return 0;
}


void print_elem(const gfe222117 *e){

	uchar8  i;

	for (i=LIMBS-1; i>0; --i) 
		fprintf(FILE,"%16llX ",e->l[i]);
	fprintf(FILE,"%16llX \n\n",e->l[0]);
}
