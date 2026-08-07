// decomp: module=arm7 addr=0x022c8150 name=FUN_022c8150
// flags: -O4,s

// Arms a request block: clears the status byte at +1, copies the 12-byte
// descriptor at `src` into +0x38, stashes the user word at +0x44 and hands the
// block to the submit routine at 0x022c864c.  Always reports success.

#pragma thumb on

typedef struct Desc12 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
} Desc12;

extern void FUN_022c864c(void *req, int arg);

int FUN_022c8150(void *req, const Desc12 *src, int user, int arg)
{
    unsigned char *p = (unsigned char *)req;
    p[1] = 0;
    *(Desc12 *)(p + 0x38) = *src;
    *(int *)(p + 0x44) = user;
    FUN_022c864c(req, arg);
    return 1;
}
