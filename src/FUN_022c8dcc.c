// decomp: module=arm7 addr=0x022c8dcc name=FUN_022c8dcc
// flags: -O4,s

// Releases every node on the list hanging off +0x3c of p - each is handed to
// FUN_022c83d0, the chain is followed through the next pointer at +0x50 - then
// clears the head.

#pragma thumb on
extern void FUN_022c83d0(void *);
void FUN_022c8dcc(int p)
{
    char *n = *(char **)(p + 0x3c);
    while (n != 0) {
        FUN_022c83d0(n);
        n = *(char **)(n + 0x50);
    }
    *(char **)(p + 0x3c) = 0;
}
