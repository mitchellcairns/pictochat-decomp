// decomp: module=arm7 addr=0x022c0d90 name=FUN_022c0d90
// flags: -O4,s -noThumb
// size: 0xb8 - 0xac of code plus the three trailing pool words (0x0380fff4,
// 0x01000010 and 0x0000ffff).

// The ARM7 main loop: never returns. Each pass drains one message from the
// queue at +0x308 of the state block (posting it on with FUN_022c0fb4 when the
// receive reports one), then, with IRQs 0x01000010 masked off, walks the
// halfword table at the head of the block from the cursor at +0x10. Entries
// equal to 0xffff are skipped by bumping the cursor; the first real entry is
// translated by FUN_022c0f00 into a slot index at +0x14, whose handler in the
// 8-byte-per-entry table at +0xc0 is called indirectly, after which the slot
// index is parked back at 0xffff.
//
// NOTE (lever 5): r0 is untouched between the FUN_022c48a4 and FUN_022c486c
// calls, so the mask-off returns the token the restore consumes - declared as
// such here. FUN_022c573c is declared returning int for this call site (it is
// declared void in src/arm7/FUN_022c0f78.c); the bl reloc is wildcarded so
// only this site's shape matters.

typedef struct Handler {
    void (*fn)(void);
    void *arg;
} Handler;

typedef struct Ctx {
    unsigned short tab[8]; /* 0x000 */
    unsigned short idx;    /* 0x010 */
    unsigned short cur;    /* 0x012 */
    unsigned short sel;    /* 0x014 */
    char pad016[0xaa];     /* 0x016 */
    Handler tbl[8];        /* 0x0c0 */
    char pad100[0x208];    /* 0x100 */
    void *queue;           /* 0x308 */
} Ctx;

extern int FUN_022c573c(void *queue, void *out, int flag);
extern void FUN_022c0fb4(void *msg);
extern unsigned int FUN_022c48a4(unsigned int mask);
extern unsigned int FUN_022c486c(unsigned int mask);
extern unsigned short FUN_022c0f00(unsigned short entry);

void FUN_022c0d90(void)
{
    void *msg;
    unsigned int token;
    unsigned short n;
    Ctx *b;

    b = *(Ctx **)0x0380fff4;
    b->idx = 0;
    b->sel = 0;

    for (;;) {
        if (FUN_022c573c((*(Ctx **)0x0380fff4)->queue, &msg, 0) != 0) {
            FUN_022c0fb4(&msg);
        }

        token = FUN_022c48a4(0x01000010);
        n = b->idx;
        b->cur = n;

        if (b->tab[n] == 0xffff) {
            b->idx = b->idx + 1;
            FUN_022c486c(token);
        } else {
            FUN_022c486c(token);
            b->sel = FUN_022c0f00(b->cur);
            b->tbl[b->sel].fn();
            b->sel = 0xffff;
        }
    }
}
