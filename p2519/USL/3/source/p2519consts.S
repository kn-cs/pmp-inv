/* Constants borrowed from the work "Kummer for genus one over prime order fields" by 
   Sabyasachi Karati and Palash Sarkar.
   Code-link: https://github.com/skarati/KummerLineV02/blob/master/KummerLine2519(81%2C20)/consts.S
*/

.data

.globl REDMASK47
.globl REDMASK51

.p2align 4
REDMASK47:   .quad 0x00007FFFFFFFFFFF
REDMASK51:   .quad 0x0007FFFFFFFFFFFF

