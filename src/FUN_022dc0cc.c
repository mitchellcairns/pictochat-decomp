// decomp: module=arm7 addr=0x022dc0cc name=FUN_022dc0cc
// flags: -O4,s -noThumb
//
// Tail-calls func_037fea24(0, &ctx->f404, 0x20) - a fill/clear of the 0x20
// byte block at +0x404 of the global context.

typedef struct Ctx_c0cc {
    char pad[0x404];
    unsigned char f404[0x20];
} Ctx_c0cc;

extern Ctx_c0cc *G_0380fff4;
extern void func_037fea24(int value, void *dst, unsigned int size);

void FUN_022dc0cc(void)
{
    func_037fea24(0, G_0380fff4->f404, 0x20);
}
