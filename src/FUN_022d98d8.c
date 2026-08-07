// decomp: module=arm7 addr=0x022d98d8 name=FUN_022d98d8
// flags: -O4,s -noThumb
//
// Installs a handler for the 0x01000000 interrupt source and then enables it.

extern void func_037c8f18(unsigned int mask, void *handler);
extern void func_037c904c(unsigned int mask);

void FUN_022d98d8(void)
{
    func_037c8f18(0x01000000, (void *)0x037f9614);
    func_037c904c(0x01000000);
}
