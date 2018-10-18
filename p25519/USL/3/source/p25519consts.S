/* Constant borrowed from supercop against the work "Sandy2x: New Curve25519 Speed Records" by 
   Tung Chou. 
   Code-link: https://github.com/floodyberry/supercop/blob/master/crypto_scalarmult/curve25519/sandy2x/consts.S
*/

.data

.globl REDMASK51
.p2align 4
REDMASK51:   .quad 0x0007FFFFFFFFFFFF

