#include "p1271.h"

/* Routine borrowed from supercop against the work "Kummer strikes back: new DH
   speed records", authored by Bernstein et. al.
   Paper-link: https://link.springer.com/chapter/10.1007/978-3-662-45611-8_17
   Code-link:  https://github.com/floodyberry/supercop/tree/master/crypto_scalarmult/kummer/avx2/gfe.c
*/
void gfp1271inv(gfe1271 *einv, const gfe1271 *e) {

	gfe1271 x2,x3,x12,x15,x30,t;
	gfe1271 x_5_0,x_10_0,x_20_0,x_40_0,x_80_0,x_120_0,x_125_0;

 	/* 2   */ gfp1271sqr(&x2,e); 
  	/* 3   */ gfp1271mul(&x3,&x2,e);           
  	/* 12  */ gfp1271nsqr(&x12,&x3,2);         
  	/* 15  */ gfp1271mul(&x15,&x12,&x3);        
  	/* 30  */ gfp1271sqr(&x30,&x15);           

  	/* 2^5   -  1    */  gfp1271mul(&x_5_0,&x30,e);
  
  	/* 2^10  -  2^5  */  gfp1271nsqr(&t,&x_5_0,5); 
  	/* 2^10  -  1    */  gfp1271mul(&x_10_0,&t,&x_5_0);

  	/* 2^20  -  2^10 */  gfp1271nsqr(&t,&x_10_0,10);     
  	/* 2^20  -  1    */  gfp1271mul(&x_20_0,&t,&x_10_0); 

  	/* 2^40  -  2^20 */  gfp1271nsqr(&t,&x_20_0,20);   
  	/* 2^40  -  1    */  gfp1271mul(&x_40_0,&t,&x_20_0);     

  	/* 2^80  -  2^40 */  gfp1271nsqr(&t,&x_40_0,40);     
  	/* 2^80  -  1    */  gfp1271mul(&x_80_0,&t,&x_40_0);     

  	/* 2^120 -  2^40 */  gfp1271nsqr(&t,&x_80_0,40);    
  	/* 2^120 -  1    */  gfp1271mul(&x_120_0,&t,&x_40_0);   

  	/* 2^125 -  2^5  */  gfp1271nsqr(&t,&x_120_0,5);     
 	/* 2^125 -  1    */  gfp1271mul(&x_125_0,&t,&x_5_0);    

  	/* 2^127 -  2^2  */  gfp1271nsqr(&t,&x_125_0,2);     
  	/* 2^127 -  3    */  gfp1271mul(einv,&t,e);
}
