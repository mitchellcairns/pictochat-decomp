// decomp: module=arm7 addr=0x022c5350 name=FUN_022c5350
// flags: -O4,s -noThumb

// Sets the +0x48 flag on the object and kicks off FUN_022c4e28 with interrupts
// masked, restoring the previous IRQ state afterwards.

extern int func_022c6d40(void);          // OS_DisableInterrupts
extern int func_022c6d54(int state);     // OS_RestoreInterrupts
extern void func_022c4e28(void);

void FUN_022c5350(int *p)
{
    int state = func_022c6d40();
    p[0x48 / 4] = 1;
    func_022c4e28();
    func_022c6d54(state);
}
