// decomp: module=arm7 addr=0x022d7cf0 name=FUN_022d7cf0
// flags: -O4,s -noThumb

// Programs the halfword register at 0x0480803c with `v` and caches half of it
// at +0x354 of the ARM7 state block pointed to by 0x0380fff4.  Always reports
// success.

typedef struct Arm7State {
    char pad[0x354];
    unsigned short half;   // +0x354
} Arm7State;

int FUN_022d7cf0(unsigned int v)
{
    (*(Arm7State **)0x0380fff4)->half = (unsigned short)(v >> 1);
    *(volatile unsigned short *)0x0480803c = (unsigned short)v;
    return 0;
}
