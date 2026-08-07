// decomp: module=arm7 addr=0x022da108 name=FUN_022da108
// flags: -noThumb
// size: 0x20 - includes the trailing pool word.

// Returns the halfword at +0x16 of record `i` of the 0x1c-byte table hanging
// off +0x31c of the ARM7 state block.

unsigned short FUN_022da108(int i)
{
    int t = *(int *)(*(int *)0x0380fff4 + 0x31c);
    return *(unsigned short *)(t + i * 0x1c + 0x16);
}
