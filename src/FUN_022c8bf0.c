// decomp: module=arm7 addr=0x022c8bf0 name=FUN_022c8bf0
// flags: -O4,s
//
// Publishes a word-aligned buffer into the global descriptor at 0x0380581c:
// records the base and base+0x10, then snapshots the first four words.

#pragma thumb on

typedef struct Desc8bf0 {
    unsigned int f0;
    unsigned int *f4;
    unsigned int *f8;
    unsigned int fc;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
} Desc8bf0;

extern Desc8bf0 G_0380581c;

void FUN_022c8bf0(unsigned int addr)
{
    unsigned int *p = (unsigned int *)(addr & ~3u);

    G_0380581c.f4 = p;
    G_0380581c.f8 = p + 4;
    G_0380581c.fc = p[0];
    G_0380581c.f10 = p[1];
    G_0380581c.f14 = p[2];
    G_0380581c.f18 = p[3];
}
