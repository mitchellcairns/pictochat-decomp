// decomp: module=arm7 addr=0x022da71c name=FUN_022da71c
// flags: -O4,s -noThumb

// Command 1 handler: tags the reply block, rejects a state above 1 with 5,
// otherwise hands the current state to FUN_037c6220 and, if it is still 1,
// runs the teardown at FUN_022d81b8.

extern void FUN_037c6220(int state);
extern void FUN_022d81b8(void);

typedef struct Req71c {
    char pad[0x10];
    unsigned short f10;
} Req71c;

typedef struct Rep71c {
    char pad[2];
    unsigned short f2;
} Rep71c;

int FUN_022da71c(Req71c *req, Rep71c *rep)
{
    rep->f2 = 1;
    if (req->f10 > 1) {
        return 5;
    }
    FUN_037c6220(req->f10);
    if (req->f10 == 1) {
        FUN_022d81b8();
    }
    return 0;
}
