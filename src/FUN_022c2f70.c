// decomp: module=arm7 addr=0x022c2f70 name=FUN_022c2f70
// flags: -O4,s -noThumb
//
// Wraps a free-running counter/address into range: values at or above the
// 0x04805f60 threshold get the halfword at +0x3de of the global context
// subtracted off; anything below passes through untouched.

typedef struct Ctx2f70 {
    char pad[0x3de];
    unsigned short f3de;
} Ctx2f70;

extern Ctx2f70 *G_0380fff4;

unsigned int FUN_022c2f70(unsigned int x)
{
    if (x >= 0x04805f60) {
        x -= G_0380fff4->f3de;
    }
    return x;
}
