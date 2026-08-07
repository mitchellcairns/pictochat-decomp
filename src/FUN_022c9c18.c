// decomp: module=arm7 addr=0x022c9c18 name=FUN_022c9c18
// flags: -O4,s
//
// Teardown: hands the two 8-word tables at 0x038069bc / 0x038069dc to
// FUN_022c7c8c, re-registers slot 7 with the Thumb callback at 0x03801b38
// (the pool word carries the Thumb bit), then clears the flag word at
// 0x03805838.
//
// Note: the two tables are adjacent (0x038069bc + 0x20 == 0x038069dc), but
// the ROM materialises both from their own pool words, so they must be two
// separate objects in the source - writing the second as a constant offset
// off the first collapses to `adds r1, r0, #0` and drops a pool word.

#pragma thumb on

extern unsigned int G_038069bc[8];
extern unsigned int G_038069dc[8];
extern unsigned int G_03805838;

extern void FUN_022c7c8c(unsigned int *a, unsigned int *b, int n);
extern void FUN_022c73a0(int slot, void *fn);

void FUN_022c9c18(void)
{
    FUN_022c7c8c(G_038069bc, G_038069dc, 8);
    FUN_022c73a0(7, (void *)0x03801b39);
    G_03805838 = 0;
}
