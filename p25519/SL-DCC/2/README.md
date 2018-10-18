# Implementation of field inversion in the Galois field F(2^255-19).

This implementation corresponds to the paper "Efficient Inversion In (Pseudo-)Mersenne Prime Fields" 
authored by

    Kaushik Nath,  Indian Statistical Institute, Kolkata, India, and   
    Palash Sarkar, Indian Statistical Institute, Kolkata, India.

This package contains the assembly level implementation of inverting a single field element in F(2^255-19) 
using Fermat's Little Theorem. Field elements have "Saturated Limb Representation". The implementation has 
been taken from the work "How to (Pre-)Compute a Ladder Improving the Performance of X25519 and X448" 
authored by Oliveira et al.

Paper-link: https://link.springer.com/chapter/10.1007/978-3-319-72565-9_9
Code-link: https://github.com/armfazh/rfc7748_precomputed/blob/master/src/fp25519_x64.c

There are three directories, namely "include", "source", and "test" in the package. The description of the 
files in each directory are listed below:

include/fp25519_x64.h  	:  contains the datatype definitions and function prototypes.

include/measure.h   	:  contains the timing definition for measuring performance.

source/fp25519_x64.c	:  contains the field multiplication, squaring and FLT-based inversion routines.

test/p25519_test	:  contains the test function.

test/p25519.mak		:  contains the make file.
    
For compiling any of the packages, one needs to use the command "make -f p25519.mak", and execute the generated 
executable file name "p25519_test".

Supported architectures are BROADWELL onwards. 
One needs to change the architecture accordingly in the makefile before compilation. Default provided is Skylake.
