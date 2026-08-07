// decomp: module=arm7 addr=0x022d6c8c name=FUN_022d6c8c
// flags: -O4,s -noThumb

// Initialises a 12-byte record: both word fields to -1, the halfword at +8 to
// zero and the halfword at +0xa to the supplied value.

void FUN_022d6c8c(int *p, unsigned short v)
{
    p[0] = -1;
    p[1] = -1;
    *(unsigned short *)((char *)p + 8) = 0;
    *(unsigned short *)((char *)p + 0xa) = v;
}
