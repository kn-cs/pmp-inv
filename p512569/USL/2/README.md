# Implementation of field inversion in the Galois field F(2^512-569).

This implementation corresponds to the paper "Efficient Inversion In (Pseudo-)Mersenne Prime Order Fields" 
authored by

    Kaushik Nath,  Indian Statistical Institute, Kolkata, India, and   
    Palash Sarkar, Indian Statistical Institute, Kolkata, India.

This package contains the assembly level implementation of inverting a single field element in F(2^512-569) 
using Fermat's Little Theorem. Field elements have "Unsaturated Limb Representation", and reduction algorithm
used is one similar to reduceUSLB, followed by one extra iteration to manage overfull situations. This
implementation actually runs slower than the one that uses the generic reduction algorithm reduceUSL. 

There are three directories, namely "include", "source", and "test" in the package. The description of the 
files in each directory are listed below:

include/datatype.h  	:  contains the datatype definitions.

include/measure.h   	:  contains the timing definition for measuring performance.

include/p512569.h    	:  contains the function prototypes for field arithmetic.

include/p512569pack.h   :  contains the function prototypes for packing and unpacking.

source/p512569.c	:  contains the FLT-based inversion routine and some other utilities.

source/p512569pack.c	:  contains the packing and unpacking routines.

source/p512569mul.S	:  contains the assembly source for field multiplication.

source/p512569nsqr.S	:  contains the assembly source for n-times feedback field squaring.

source/p512569consts.S	:  contains the assembly constants.

test/p512569_test.c	:  contains the test function.
test/p512569.mak	:  contains the make file.
    
For compiling any of the packages, one needs to use the command "make -f p512569.mak", and execute the generated 
executable file name "p512569_test".

One needs to change the architecture accordingly in the makefile before compilation. Default provided is Skylake.
