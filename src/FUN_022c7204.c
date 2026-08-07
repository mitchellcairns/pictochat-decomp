// decomp: module=arm7 addr=0x022c7204 name=FUN_022c7204
// flags: -noThumb

// Atomic exchange: swaps `v` into the word at `p` and returns the previous
// contents.
//
// HAND-ASM PRIMITIVE: byte-faithful asm-block match, same policy as the IRQ /
// ARMProcessorMode primitives already in src/arm7/. ARM's `swp` has no C
// spelling and mwcc emits no intrinsic for it, so the asm block IS the faithful
// source - this was assembly in the original, not compiler output. NOT a
// transcription of a disassembly dump.

asm int FUN_022c7204(int v, int *p)
{
    swp r0, r0, [r1]
    bx lr
}
