// decomp: module=arm7 addr=0x022c5628 name=FUN_022c5628
// flags: -noThumb

// setjmp-style CPU context save. Writes CPSR to ctx[0], then drops into SVC
// mode (0xd3 = SVC with IRQ/FIQ masked) purely to sample the *supervisor* sp
// into ctx+0x44 before restoring the caller's mode, stores r0-lr over
// ctx+0x04..ctx+0x40 with the resume value pre-seeded to 1, patches the resume
// address into ctx+0x40, and returns 0 on the save path.
//
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This was assembly in the
// original - mrs/msr, a bank-switching mode change and an stm of the whole
// register file have no C spelling at all, so the asm block *is* the faithful
// source. Counts as matched under the asm-primitive policy (see
// src/arm7/_ZN3IRQ10DisableAllEv_022c6d6c.cpp), not a byte transcription.

asm int FUN_022c5628(void *ctx)
{
    add     r1, r0, #0
    mrs     r2, cpsr
    str     r2, [r1], #4
    mov     r0, #0xd3
    msr     cpsr_c, r0
    str     sp, [r1, #0x40]
    msr     cpsr_c, r2
    mov     r0, #1
    stmia   r1, {r0-lr}
    add     r0, pc, #8
    str     r0, [r1, #0x3c]
    mov     r0, #0
    bx      lr
}
