// decomp: module=arm7 addr=0x022d8d6c name=FUN_022d8d6c
// flags: -noThumb

unsigned char FUN_022d8d6c(unsigned short *p)
{
    unsigned int v;
    if ((int)p & 1)
        v = (unsigned char)(*(unsigned short *)((char *)p - 1) >> 8);
    else
        v = (unsigned char)*p;
    return (unsigned char)v;
}
