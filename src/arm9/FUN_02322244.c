// decomp: module=unk_autoload_0 addr=0x02322244 name=FUN_02322244

#pragma thumb on

extern unsigned int G_0238e11c[];

void FUN_02322244(void)
{
    if ((G_0238e11c[0] & 2) == 0) {
        G_0238e11c[0] |= 2;
        G_0238e11c[10] = 1;
    }
}
