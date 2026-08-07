// decomp: module=arm7 addr=0x022d9ffc name=FUN_022d9ffc
// flags: -O4,s -noThumb
//
// Reads the leading halfword of entry `i` of the 0x1c byte record array
// hanging off +0x31c of the global context.

typedef struct Ent9ffc {
    unsigned short f0;
    char pad[0x1a];
} Ent9ffc;

typedef struct Ctx9ffc {
    char pad[0x31c];
    Ent9ffc *f31c;
} Ctx9ffc;

extern Ctx9ffc *G_0380fff4;

unsigned short FUN_022d9ffc(int i)
{
    return G_0380fff4->f31c[i].f0;
}
