# Implementation of field inversion in the Galois field F(2^521-1).

This implementation corresponds to the paper "Efficient Inversion In (Pseudo-)Mersenne Prime Order Fields" 
authored by

    Kaushik Nath,  Indian Statistical Institute, Kolkata, India, and   
    Palash Sarkar, Indian Statistical Institute, Kolkata, India.

This package contains the assembly level implementation of inverting a single field element in F(2^521-1) 
using Fermat's Little Theorem. Field elements have "Unsaturated Limb Representation". The "c" source code
has been borrowed from the work "Faster ECC over F(2^521-1)", authored by Robert Granger and Michael Scott.

Paper link: https://link.springer.com/chapter/10.1007/978-3-662-46447-2_24

Code-link: http://indigo.ie/~mscott/ws521.cpp and http://indigo.ie/~mscott/ed521.cpp

There are three directories, namely "include", "source", and "test" in the package. The description of the 
files in each directory are listed below:

include/datatype.h  	:  contains the datatype definitions.

include/measure.h   	:  contains the timing definition for measuring performance.

include/p5211.h    	:  contains the function prototypes for field arithmetic.

include/p5211pack.h   	:  contains the function prototypes for packing and unpacking.

source/p5211.c		:  contains the FLT-based inversion routine and some other utilities.

source/p5211pack.c	:  contains the packing and unpacking routines.

source/p5211reduce.S	:  contains the assembly for final reduction.

test/p5211_test.c	:  contains the test function.

test/p5211.mak		:  contains the make file.
    
For compiling any of the packages, one needs to use the command "make -f p5211.mak", and execute the generated 
executable file name "p5211_test".

One needs to change the architecture accordingly in the makefile before compilation. Default provided is Skylake.
