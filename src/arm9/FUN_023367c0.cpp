//cpp
// decomp: module=unk_autoload_0 addr=0x023367c0 name=FUN_023367c0
#pragma thumb on

extern "C" {
extern int G_0236a17c[];
extern int FUN_02336228(void);
extern void FUN_02337030(int, int, int, unsigned int, int);
extern void FUN_023371a4(int, int, unsigned int);

void FUN_023367c0(int a, int b, unsigned int n)
{
    int p = FUN_02336228();

    if (G_0236a17c[0] != -1 && n > 0x1c) {
        FUN_02337030(G_0236a17c[0], a, p + b, n, 1);
        return;
    }
    FUN_023371a4(a, p + b, n);
}
}
