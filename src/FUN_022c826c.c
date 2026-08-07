// decomp: module=arm7 addr=0x022c826c name=FUN_022c826c

// Stores the 16-bit result of FUN_022c8600(v) into the halfword at +0x20 of p.
// Same shape as FUN_022c8254, one slot further along.

#pragma thumb on
extern unsigned short FUN_022c8600(int);
void FUN_022c826c(int p, int v)
{
    *(unsigned short *)(p + 0x20) = FUN_022c8600(v);
}
