# Implementation of field inversion in the Galois field F(2^255-19).

This implementation corresponds to the paper "Efficient Inversion In (Pseudo-)Mersenne Prime Order Fields" 
authored by

    Kaushik Nath,  Indian Statistical Institute, Kolkata, India, and   
    Palash Sarkar, Indian Statistical Institute, Kolkata, India.

This package contains the assembly level implementation of inverting a single field element in F(2^255-19) 
using Fermat's Little Theorem. Field elements have "Saturated Limb Representation" and computations are 
done using "Two Independent Carry Chains".

There are three directories, namely "include", "source", and "test" in the package. The description of the 
files in each directory are listed below:

include/datatype.h  	:  contains the datatype definitions.

include/measure.h   	:  contains the timing definition for measuring performance.

include/p25519.h    	:  contains the function prototypes.

source/p25519.c		:  contains the FLT-based inversion routine and some other utilities.

source/p25519mul.S	:  contains the assembly source for field multiplication.

source/p25519nsqr.S	:  contains the assembly source for n-times feedback field squaring.

source/p25519consts.S	:  contains the assembly constants.

test/p25519_test.c	:  contains the test function.

test/p25519.mak		:  contains the make file.
    
For compiling any of the packages, one needs to use the command "make -f p25519.mak", and execute the generated 
executable file name "p25519_test".

Supported architectures are BROADWELL onwards. 
One needs to change the architecture accordingly in the makefile before compilation. Default provided is Skylake.
