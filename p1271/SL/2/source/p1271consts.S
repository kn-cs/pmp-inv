/* Code borrowed from supercop against the work "Kummer strikes back: new DH
   speed records", authored by Bernstein et. al.
   Paper-link: https://link.springer.com/chapter/10.1007/978-3-662-45611-8_17
   Code-link:  https://github.com/floodyberry/supercop/tree/master/crypto_scalarmult/kummer/avx2
*/

.data

.globl mask63
.p2align 4
mask63:   .quad 0x7FFFFFFFFFFFFFFF


