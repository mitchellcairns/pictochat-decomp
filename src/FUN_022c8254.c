// decomp: module=arm7 addr=0x022c8254 name=FUN_022c8254

// Stores the 16-bit result of FUN_022c8600(v) into the halfword at +0x1e of p.

#pragma thumb on
extern unsigned short FUN_022c8600(int);
void FUN_022c8254(int p, int v)
{
    *(unsigned short *)(p + 0x1e) = FUN_022c8600(v);
}
