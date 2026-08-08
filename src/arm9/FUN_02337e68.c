// decomp: module=unk_autoload_0 addr=0x02337e68 name=FUN_02337e68
extern unsigned char G_023c3440[];

unsigned char FUN_02337e68(int i, int a, int b)
{
    unsigned char *p = G_023c3440 + i * 0xc;
    *(unsigned int *)(p + 0) = a;
    *(unsigned int *)(p + 4) = b;
    p[8] = p[8] + 1;
    return p[8];
}
