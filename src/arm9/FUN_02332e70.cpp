//cpp
// flags: -thumb
// decomp: module=unk_autoload_0 addr=0x02332e70 name=FUN_02332e70
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was hand-written assembly in the original SDK/runtime (memset/byte-fill primitive).
extern "C" void FUN_02332e70(unsigned char *dst, int c, unsigned int n);
extern "C" asm void FUN_02332e70(unsigned char *dst, int c, unsigned int n)
{
    push    {r4, r5}
    lsl     r1, r1, #24
    lsr     r1, r1, #24
    cmp     r2, #32
    blo     _02332ece
    neg     r4, r0
    mov     r3, #3
    and     r4, r3
    beq     _02332e90
    lsl     r3, r1, #24
    sub     r2, r2, r4
    lsr     r3, r3, #24
_02332e88:
    strb    r3, [r0]
    add     r0, r0, #1
    sub     r4, r4, #1
    bne     _02332e88
_02332e90:
    cmp     r1, #0
    beq     _02332ea0
    lsl     r4, r1, #24
    lsl     r3, r1, #16
    lsl     r5, r1, #8
    orr     r3, r4
    orr     r3, r5
    orr     r1, r3
_02332ea0:
    lsr     r4, r2, #5
    beq     _02332ebc
_02332ea4:
    str     r1, [r0]
    str     r1, [r0, #4]
    str     r1, [r0, #8]
    str     r1, [r0, #12]
    str     r1, [r0, #16]
    str     r1, [r0, #20]
    str     r1, [r0, #24]
    mov     r3, r0
    add     r0, #32
    str     r1, [r3, #28]
    sub     r4, r4, #1
    bne     _02332ea4
_02332ebc:
    mov     r3, #31
    and     r3, r2
    lsr     r3, r3, #2
    beq     _02332eca
_02332ec4:
    stmia   r0!, {r1}
    sub     r3, r3, #1
    bne     _02332ec4
_02332eca:
    mov     r3, #3
    and     r2, r3
_02332ece:
    cmp     r2, #0
    beq     _02332ede
    lsl     r1, r1, #24
    lsr     r1, r1, #24
_02332ed6:
    strb    r1, [r0]
    add     r0, r0, #1
    sub     r2, r2, #1
    bne     _02332ed6
_02332ede:
    pop     {r4, r5}
    bx      lr
}
