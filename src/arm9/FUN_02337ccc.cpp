//cpp
// decomp: module=unk_autoload_0 addr=0x02337ccc name=FUN_02337ccc
#pragma thumb on

extern "C" {
extern unsigned char G_0233aa54[];

unsigned short FUN_02337ccc(int v)
{
    int kind;
    unsigned char c;

    if (v < -0x2d3) {
        v = -0x2d3;
    } else if (v > 0) {
        v = 0;
    }

    c = G_0233aa54[v + 0x2d3];

    if (v < -0xf0) {
        kind = 3;
    } else if (v < -0x78) {
        kind = 2;
    } else if (v < -0x3c) {
        kind = 1;
    } else {
        kind = 0;
    }
    return (unsigned short)((kind << 8) | c);
}
}
