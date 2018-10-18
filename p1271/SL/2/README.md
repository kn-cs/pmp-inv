# Implementation of field inversion in the Galois field F(2^127-1).

This implementation corresponds to the paper "Efficient Inversion In (Pseudo-)Mersenne Prime Order Fields" 
authored by

    Kaushik Nath,  Indian Statistical Institute, Kolkata, India, and   
    Palash Sarkar, Indian Statistical Institute, Kolkata, India.

This package contains the assembly level implementation of inverting a single field element in F(2^127-1) 
using Fermat's Little Theorem. Field elements have "Saturated Limb Representation". The assemblies for
multiplication and squaring has been taken from the work "Kummer strikes back: new DH speed records", 
authored by Bernstein et. al.

Paper-link: https://link.springer.com/chapter/10.1007/978-3-662-45611-8_17

Code-link: https://github.com/floodyberry/supercop/tree/master/crypto_scalarmult/kummer/avx2

There are three directories, namely "include", "source", and "test" in the package. The description of the 
files in each directory are listed below:

include/datatype.h  	:  contains the datatype definitions.

include/measure.h   	:  contains the timing definition for measuring performance.

include/p1271.h    	:  contains the function prototypes.

source/p1271.c		:  contains the FLT-based inversion routine and some other utilities.

source/p1271mul.S	:  contains the assembly source for field multiplication.

source/p1271nsqr.S	:  contains the assembly source for n-times feedback field squaring.

source/p1271consts.S	:  contains the assembly constants.

test/p1271_test.c	:  contains the test function.

test/p1271.mak		:  contains the make file.
    
For compiling any of the packages, one needs to use the command "make -f p1271.mak", and execute the generated 
executable file name "p1271_test".

One needs to change the architecture accordingly in the makefile before compilation. Default provided is Skylake.
