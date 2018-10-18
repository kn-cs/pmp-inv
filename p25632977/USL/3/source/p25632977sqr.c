
/* Code for field squaring has been customized after borrowing the code from the web link 
   https://github.com/bitcoin/bitcoin/blob/master/src/secp256k1/src/field_5x52_asm_impl.h
*/

#include "datatype.h"
#include "p25632977.h"

void gfp25632977sqr(gfe25632977_5L *r, const gfe25632977_5L *a) {

/**
 * Registers: rdx:rax = multiplication accumulator
 *            r9:r8   = c
 *            rcx:rbx = d
 *            r10-r14 = a0-a4
 *            r15     = M (0xfffffffffffff)
 *            rdi     = r
 *            rsi     = a / t?
 */

  gfe25632977_5L tmp1, tmp2, tmp3;

__asm__ __volatile__(
    "movq 0(%%rsi),%%r10\n"
    "movq 8(%%rsi),%%r11\n"
    "movq 16(%%rsi),%%r12\n"
    "movq 24(%%rsi),%%r13\n"
    "movq 32(%%rsi),%%r14\n"
    "movq $0xfffffffffffff,%%r15\n"

    /* d = (a0*2) * a3 */
    "leaq (%%r10,%%r10,1),%%rax\n"
    "mulq %%r13\n"
    "movq %%rax,%%rbx\n"
    "movq %%rdx,%%rcx\n"
    /* d += (a1*2) * a2 */
    "leaq (%%r11,%%r11,1),%%rax\n"
    "mulq %%r12\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* c = a4 * a4 */
    "movq %%r14,%%rax\n"
    "mulq %%r14\n"
    "movq %%rax,%%r8\n"
    "movq %%rdx,%%r9\n"
    /* d += (c & M) * R */
    "andq %%r15,%%rax\n"
    "movq $0x1000003d10,%%rdx\n"
    "mulq %%rdx\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* c >>= 52 (%%r8 only) */
    "shrdq $52,%%r9,%%r8\n"
    /* t3 (tmp1) = d & M */
    "movq %%rbx,%%rsi\n"
    "andq %%r15,%%rsi\n"
    "movq %%rsi,%q1\n"
    /* d >>= 52 */
    "shrdq $52,%%rcx,%%rbx\n"
    "xorq %%rcx,%%rcx\n"
    /* a4 *= 2 */
    "addq %%r14,%%r14\n"
    /* d += a0 * a4 */
    "movq %%r10,%%rax\n"
    "mulq %%r14\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* d+= (a1*2) * a3 */
    "leaq (%%r11,%%r11,1),%%rax\n"
    "mulq %%r13\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* d += a2 * a2 */
    "movq %%r12,%%rax\n"
    "mulq %%r12\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* d += c * R */
    "movq %%r8,%%rax\n"
    "movq $0x1000003d10,%%rdx\n"
    "mulq %%rdx\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* t4 = d & M (%%rsi) */
    "movq %%rbx,%%rsi\n"
    "andq %%r15,%%rsi\n"
    /* d >>= 52 */
    "shrdq $52,%%rcx,%%rbx\n"
    "xorq %%rcx,%%rcx\n"
    /* tx = t4 >> 48 (tmp3) */
    "movq %%rsi,%%rax\n"
    "shrq $48,%%rax\n"
    "movq %%rax,%q3\n"
    /* t4 &= (M >> 4) (tmp2) */
    "movq $0xffffffffffff,%%rax\n"
    "andq %%rax,%%rsi\n"
    "movq %%rsi,%q2\n"
    /* c = a0 * a0 */
    "movq %%r10,%%rax\n"
    "mulq %%r10\n"
    "movq %%rax,%%r8\n"
    "movq %%rdx,%%r9\n"
    /* d += a1 * a4 */
    "movq %%r11,%%rax\n"
    "mulq %%r14\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* d += (a2*2) * a3 */
    "leaq (%%r12,%%r12,1),%%rax\n"
    "mulq %%r13\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* u0 = d & M (%%rsi) */
    "movq %%rbx,%%rsi\n"
    "andq %%r15,%%rsi\n"
    /* d >>= 52 */
    "shrdq $52,%%rcx,%%rbx\n"
    "xorq %%rcx,%%rcx\n"
    /* u0 = (u0 << 4) | tx (%%rsi) */
    "shlq $4,%%rsi\n"
    "movq %q3,%%rax\n"
    "orq %%rax,%%rsi\n"
    /* c += u0 * (R >> 4) */
    "movq $0x1000003d1,%%rax\n"
    "mulq %%rsi\n"
    "addq %%rax,%%r8\n"
    "adcq %%rdx,%%r9\n"
    /* r[0] = c & M */
    "movq %%r8,%%rax\n"
    "andq %%r15,%%rax\n"
    "movq %%rax,0(%%rdi)\n"
    /* c >>= 52 */
    "shrdq $52,%%r9,%%r8\n"
    "xorq %%r9,%%r9\n"
    /* a0 *= 2 */
    "addq %%r10,%%r10\n"
    /* c += a0 * a1 */
    "movq %%r10,%%rax\n"
    "mulq %%r11\n"
    "addq %%rax,%%r8\n"
    "adcq %%rdx,%%r9\n"
    /* d += a2 * a4 */
    "movq %%r12,%%rax\n"
    "mulq %%r14\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* d += a3 * a3 */
    "movq %%r13,%%rax\n"
    "mulq %%r13\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* c += (d & M) * R */
    "movq %%rbx,%%rax\n"
    "andq %%r15,%%rax\n"
    "movq $0x1000003d10,%%rdx\n"
    "mulq %%rdx\n"
    "addq %%rax,%%r8\n"
    "adcq %%rdx,%%r9\n"
    /* d >>= 52 */
    "shrdq $52,%%rcx,%%rbx\n"
    "xorq %%rcx,%%rcx\n"
    /* r[1] = c & M */
    "movq %%r8,%%rax\n"
    "andq %%r15,%%rax\n"
    "movq %%rax,8(%%rdi)\n"
    /* c >>= 52 */
    "shrdq $52,%%r9,%%r8\n"
    "xorq %%r9,%%r9\n"
    /* c += a0 * a2 (last use of %%r10) */
    "movq %%r10,%%rax\n"
    "mulq %%r12\n"
    "addq %%rax,%%r8\n"
    "adcq %%rdx,%%r9\n"
    /* fetch t3 (%%r10, overwrites a0),t4 (%%rsi) */
    "movq %q2,%%rsi\n"
    "movq %q1,%%r10\n"
    /* c += a1 * a1 */
    "movq %%r11,%%rax\n"
    "mulq %%r11\n"
    "addq %%rax,%%r8\n"
    "adcq %%rdx,%%r9\n"
    /* d += a3 * a4 */
    "movq %%r13,%%rax\n"
    "mulq %%r14\n"
    "addq %%rax,%%rbx\n"
    "adcq %%rdx,%%rcx\n"
    /* c += (d & M) * R */
    "movq %%rbx,%%rax\n"
    "andq %%r15,%%rax\n"
    "movq $0x1000003d10,%%rdx\n"
    "mulq %%rdx\n"
    "addq %%rax,%%r8\n"
    "adcq %%rdx,%%r9\n"
    /* d >>= 52 (%%rbx only) */
    "shrdq $52,%%rcx,%%rbx\n"
    /* r[2] = c & M */
    "movq %%r8,%%rax\n"
    "andq %%r15,%%rax\n"
    "movq %%rax,16(%%rdi)\n"
    /* c >>= 52 */
    "shrdq $52,%%r9,%%r8\n"
    "xorq %%r9,%%r9\n"
    /* c += t3 */
    "addq %%r10,%%r8\n"
    /* c += d * R */
    "movq %%rbx,%%rax\n"
    "movq $0x1000003d10,%%rdx\n"
    "mulq %%rdx\n"
    "addq %%rax,%%r8\n"
    "adcq %%rdx,%%r9\n"
    /* r[3] = c & M */
    "movq %%r8,%%rax\n"
    "andq %%r15,%%rax\n"
    "movq %%rax,24(%%rdi)\n"
    /* c >>= 52 (%%r8 only) */
    "shrdq $52,%%r9,%%r8\n"
    /* c += t4 (%%r8 only) */
    "addq %%rsi,%%r8\n"
    /* r[4] = c */
    "movq %%r8,32(%%rdi)\n"
: "+S"(a), "=m"(tmp1), "=m"(tmp2), "=m"(tmp3)
: "D"(r)
: "%rax", "%rbx", "%rcx", "%rdx", "%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15", "cc", "memory"
);
}
