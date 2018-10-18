/* Code borrowed from the work "Kummer for genus one over prime order fields" by 
   Sabyasachi Karati and Palash Sarkar.
   Code-link: https://github.com/skarati/KummerLineV02/blob/master/KummerLine2663(260%2C139)/consts.S
*/

.data

.globl REDMASK50
.globl REDMASK54

.p2align 4
REDMASK50:   .quad 0x3FFFFFFFFFFFF
REDMASK54:   .quad 0x3FFFFFFFFFFFFF

