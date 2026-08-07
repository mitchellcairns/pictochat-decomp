// decomp: module=arm7 addr=0x022c857c name=FUN_022c857c

// Initialises the 6-byte header at p: bytes 0..3 to {0, 0x10, 0, 1} and the
// halfword at +4 to zero.

#pragma thumb on
void FUN_022c857c(unsigned char *p)
{
    p[0] = 0;
    p[2] = 0;
    p[3] = 1;
    p[1] = 0x10;
    *(unsigned short *)(p + 4) = 0;
}
