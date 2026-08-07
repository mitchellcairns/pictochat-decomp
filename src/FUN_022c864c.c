// decomp: module=arm7 addr=0x022c864c name=FUN_022c864c
// flags: -O4,s

// Resets a timer/animation record: seeds the countdown at +0x10 with
// -0x16980, clears the phase byte and both counters, stores the caller's
// callback context at +0x34 and turns the record's two low control bits on.

#pragma thumb on

typedef struct Rec864c {
    char pad0[2];
    unsigned char f2;
    unsigned char f3;
    char pad4[0x10 - 4];
    int f10;
    char pad14[0x2e - 0x14];
    unsigned short f2e;
    unsigned short f30;
    char pad32[2];
    int f34;
} Rec864c;

void FUN_022c864c(Rec864c *r, int ctx)
{
    r->f10 = -0x16980;
    r->f2 = 0;
    r->f34 = ctx;
    r->f30 = 0;
    r->f2e = 0;
    r->f3 |= 2;
    r->f3 = (unsigned char)((r->f3 & ~1) | 1);
}
