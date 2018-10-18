/*
The source code has been borrowed from the paper "Faster ECC over F(2^521-1)" 
authored by Robert Granger and Michael Scott.
Paper-link: https://link.springer.com/chapter/10.1007/978-3-662-46447-2_24
Code-link: http://indigo.ie/~mscott/ws521.cpp and http://indigo.ie/~mscott/ed521.cpp
*/

#include "datatype.h"
#include "p5211.h"
#include "p5211pack.h"

//int sc=0;
//int mc=0;

void gfp5211inv(type64 *einv, type64 *e) {

	type64 e9[9];
	
	gfp5211pack(e9,e); 
	ginv(e9); 
        gfp5211reduce(e9);
        gfp5211unpack(einv,e9);
}


// w=x
void gcopy(type64 *x,type64 *w) {

	w[0]=x[0];
	w[1]=x[1];
	w[2]=x[2];
	w[3]=x[3];
	w[4]=x[4];
	w[5]=x[5];
	w[6]=x[6];
	w[7]=x[7];
	w[8]=x[8];
}


// z=x^2
// Note t0=r8|r9, t1=r10|r11, t2=r12|r13, t3=r14|r15
void gsqr(type64 *x,type64 *z) {

        int sc=0;
	type128 t0,t1,t2;

	sc++;
	t1=2*((type128)x[0]*x[8]+(type128)x[1]*x[7]+(type128)x[2]*x[6]+(type128)x[3]*x[5])+(type128)x[4]*x[4];
	t0=((type64) t1)&bot58bits;
	t2=4*((type128)x[1]*x[8]+(type128)x[2]*x[7]+(type128)x[3]*x[6]+(type128)x[4]*x[5])+(type128)x[0]*x[0]+2*(t1>>58);
	z[0]=((type64) t2)&bot58bits;
	t1=4*((type128)x[2]*x[8]+(type128)x[3]*x[7]+(type128)x[4]*x[6])+2*((type128)x[0]*x[1]+(type128)x[5]*x[5])+(t2>>58);
	z[1]=((type64) t1)&bot58bits;
	t2=4*((type128)x[3]*x[8]+(type128)x[4]*x[7]+(type128)x[5]*x[6])+2*(type128)x[0]*x[2]+(type128)x[1]*x[1]+(t1>>58);
	z[2]=((type64) t2)&bot58bits;
	t1=4*((type128)x[4]*x[8]+(type128)x[5]*x[7])+2*((type128)x[0]*x[3]+(type128)x[1]*x[2]+(type128)x[6]*x[6])+(t2>>58);
	z[3]=((type64) t1)&bot58bits;
	t2=4*((type128)x[5]*x[8]+(type128)x[6]*x[7])+2*((type128)x[0]*x[4]+(type128)x[1]*x[3])+(type128)x[2]*x[2]+(t1>>58);
	z[4]=((type64) t2)&bot58bits;
	t1=4*(type128)x[6]*x[8]+2*((type128)x[0]*x[5]+(type128)x[1]*x[4]+(type128)x[2]*x[3]+(type128)x[7]*x[7])+(t2>>58);
	z[5]=((type64) t1)&bot58bits;
	t2=4*(type128)x[7]*x[8]+2*((type128)x[0]*x[6]+(type128)x[1]*x[5]+(type128)x[2]*x[4])+(type128)x[3]*x[3]+(t1>>58);
	z[6]=((type64) t2)&bot58bits;
	t1=2*((type128)x[0]*x[7]+(type128)x[1]*x[6]+(type128)x[2]*x[5]+(type128)x[3]*x[4]+(type128)x[8]*x[8])+(t2>>58);
	z[7]=((type64) t1)&bot58bits;
	t0+=(t1>>58);
	z[8]=((type64)t0)&bot58bits;
	z[0]+=2*(type64)(t0>>58);
}

// z=x*y
// Note t0=r8|r9, t1=r10|r11, t2=r12|r13, t3=r14|r15
void gmul(type64 *x,type64 *y,type64 *z) {

        int mc=0;

	type128 t0 = (type128)x[0]*y[0] + (type128)x[1]*y[1] + (type128)x[2]*y[2] + (type128)x[3]*y[3] + (type128)x[4]*y[4];
	type128 t2,t3;
	type128 t5=(type128)x[5]*y[5];
	type128 t6=(type128)x[6]*y[6];
	type128 t7=(type128)x[7]*y[7];
	type128 t8=(type128)x[8]*y[8];
	type128 t1=t5+t6+t7+t8;

	mc++;
	t2=t0+t1-(type128)(x[0]-x[8])*(y[0]-y[8])-(type128)(x[1]-x[7])*(y[1]-y[7])
		-(type128)(x[2]-x[6])*(y[2]-y[6])-(type128)(x[3]-x[5])*(y[3]-y[5]);
	t0+=4*t1;

	type64 st1=((type64) t2)&bot58bits;

	t3=t0-(type128)(x[4]-2*x[5])*(y[4]-2*y[5])-(type128)(x[3]-2*x[6])*(y[3]-2*y[6])
	-(type128)(x[2]-2*x[7])*(y[2]-2*y[7])-(type128)(x[1]-2*x[8])*(y[1]-2*y[8])+2*(t2>>58);
	z[0]=((type64) t3)&bot58bits;

	t0-=2*t5;
	t2=t0-(type128)(x[0]-x[1])*(y[0]-y[1])-(type128)(x[4]-2*x[6])*(y[4]-2*y[6])
		-(type128)(x[2]-2*x[8])*(y[2]-2*y[8])-(type128)(x[3]-2*x[7])*(y[3]-2*y[7])+(t3>>58);
	z[1]=((type64) t2)&bot58bits;

	t0-=t5;
	t3=t0-(type128)(x[0]-x[2])*(y[0]-y[2])-(type128)(x[5]-2*x[6])*(y[5]-2*y[6])
		-(type128)(x[3]-2*x[8])*(y[3]-2*y[8])-(type128)(x[4]-2*x[7])*(y[4]-2*y[7])+(t2>>58);
	z[2]=((type64) t3)&bot58bits;

	t0-=2*t6;
	t2=t0-(type128)(x[0]-x[3])*(y[0]-y[3])-(type128)(x[1]-x[2])*(y[1]-y[2])
		-(type128)(x[4]-2*x[8])*(y[4]-2*y[8])-(type128)(x[5]-2*x[7])*(y[5]-2*y[7])+(t3>>58);
	z[3]=((type64) t2)&bot58bits;

	t0-=t6;
	t3=t0-(type128)(x[0]-x[4])*(y[0]-y[4])-(type128)(x[1]-x[3])*(y[1]-y[3])
		-(type128)(x[5]-2*x[8])*(y[5]-2*y[8])-(type128)(x[6]-2*x[7])*(y[6]-2*y[7])+(t2>>58);
	z[4]=((type64) t3)&bot58bits;

	t0-=2*t7;
	t2=t0-(type128)(x[0]-x[5])*(y[0]-y[5])-(type128)(x[1]-x[4])*(y[1]-y[4])
		-(type128)(x[2]-x[3])*(y[2]-y[3])-(type128)(x[6]-2*x[8])*(y[6]-2*y[8])+(t3>>58);
	z[5]=((type64) t2)&bot58bits;

	t0-=t7;
	t3=t0-(type128)(x[0]-x[6])*(y[0]-y[6])-(type128)(x[1]-x[5])*(y[1]-y[5])
		-(type128)(x[2]-x[4])*(y[2]-y[4])-(type128)(x[7]-2*x[8])*(y[7]-2*y[8])+(t2>>58);
	z[6]=((type64) t3)&bot58bits;

	t0-=2*t8;
	t2=t0-(type128)(x[0]-x[7])*(y[0]-y[7])-(type128)(x[1]-x[6])*(y[1]-y[6])
		-(type128)(x[2]-x[5])*(y[2]-y[5])-(type128)(x[3]-x[4])*(y[3]-y[4])+(t3>>58);
	z[7]=((type64) t2)&bot58bits;

	st1+=((type64)(t2>>58));
	z[8]=st1&bot58bits;
	z[0]+=2*(st1>>58);
}

//
// Inverse x = 1/x = x^(p-2) mod p
// 13 muls, 520 sqrs
//
void ginv(type64 *x) {

        int i;
	type64 x127[9],w[9],t[9],z[9];

	gsqr(x,x127);       // x127=x^2
	gmul(x127,x,t);     // t=x^3
	gsqr(t,x127);       // x127=x^6
	gmul(x127,x,w);     // w=x^7
	gsqr(w,x127);       // 
	gsqr(x127,t);  
	gsqr(t,x127);       // x127=x^56
	gcopy(x127,t);		// t=x^56
	gmul(w,t,x127);     // x127=x^63    
	gsqr(x127,t);
	gmul(t,x,x127);     // x127=x^127

	gsqr(x127,t);
	gmul(t,x,z);        // z=x^255

	gcopy(z,w);
	for (i=0;i<4;i++) {

		gsqr(z,t);
		gsqr(t,z);
	}         
	gmul(z,w,t);        // z=z16       
  
	gcopy(t,w);
	for (i=0;i<8;i++) {

		gsqr(t,z);
		gsqr(z,t);
	}	    
	gmul(t,w,z);        // z=z32      

	gcopy(z,w);
	for (i=0;i<16;i++) {
		gsqr(z,t);
		gsqr(t,z);
	}    
	gmul(z,w,t);        // z=z64      

	gcopy(t,w);
	for (i=0;i<32;i++) {
		gsqr(t,z);
		gsqr(z,t);
	}    
	gmul(t,w,z);        // z=z128     

	gcopy(z,w);
	for (i=0;i<64;i++) {
		gsqr(z,t);
		gsqr(t,z);
	}    
	gmul(z,w,t);		// z=z256       

	gcopy(t,w);
	for (i=0;i<128;i++) {
		gsqr(t,z);
		gsqr(z,t);
	}    
	gmul(t,w,z);		// z=z512        

	gsqr(z,t);
	gsqr(t,z);
	gsqr(z,t);
	gsqr(t,z);
	gsqr(z,t);
	gsqr(t,z);
	gsqr(z,t);
	gmul(t,x127,z);
	gsqr(z,t);
	gsqr(t,z);
	gmul(z,x,t);
	gcopy(t,x);
}
