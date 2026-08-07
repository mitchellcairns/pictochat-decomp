// decomp: module=arm7 addr=0x022c77a0 name=FUN_022c77a0
// flags: -O4,s

// Clears the start bit of sound channel `ch`'s SOUNDxCNT and sets its hold bit
// when the low bit of `hold` is set.

#pragma thumb on
void FUN_022c77a0(int ch, int hold)
{
    unsigned int *p = (unsigned int *)(0x04000400 + ch * 16);
    unsigned int v = *p & 0x7fffffff;
    if (hold & 1) v |= 0x8000;
    *p = v;
}
