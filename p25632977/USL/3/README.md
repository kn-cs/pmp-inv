# Implementation of field inversion in the Galois field F(2^256-2^32-977).

This implementation corresponds to the paper "Efficient Inversion In (Pseudo-)Mersenne Prime Order Fields" 
authored by

    Kaushik Nath,  Indian Statistical Institute, Kolkata, India, and   
    Palash Sarkar, Indian Statistical Institute, Kolkata, India.

This package contains the assembly level implementation of inverting a single field element in F(2^256-2^32-977) 
using Fermat's Little Theorem. Field elements have "Unsaturated Limb Representation", and the assemblies for
multiplication and squaring has been taken from the following link.

Code-link: https://github.com/bitcoin/bitcoin/blob/master/src/secp256k1/src/field_5x52_asm_impl.h

There are three directories, namely "include", "source", and "test" in the package. The description of the 
files in each directory are listed below:

include/datatype.h  		:  contains the datatype definitions.

include/measure.h   		:  contains the timing definition for measuring performance.

include/p25632977.h    		:  contains the function prototypes for field arithmetic.

include/p25632977pack.h   	:  contains the function prototypes for packing and unpacking.

source/p25632977.c		:  contains the FLT-based inversion routine and some other utilities.

source/p25632977pack.c		:  contains the packing and unpacking routines.

source/p25632977mul.c		:  contains the assembly source for field multiplication.

source/p25632977sqr.c		:  contains the assembly source for n-times feedback field squaring.

source/p25632977reduce.S	:  contains the assembly for final reduction.

test/p25632977_test		:  contains the test function.
test/p25632977.mak		:  contains the make file.
    
For compiling any of the packages, one needs to use the command "make -f p25632977.mak", and execute the generated 
executable file name "p25632977_test".

One needs to change the architecture accordingly in the makefile before compilation. Default provided is Skylake.
