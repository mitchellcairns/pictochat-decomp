// decomp: module=arm7 addr=0x022d8bfc name=FUN_022d8bfc
// flags: -noThumb
// size: 0x20 - matches only when the two trailing pool words are included;
// Ghidra's cached 0x18 stops at `bx ip` (see notes/pictochat-layout.md).

// Tail-call thunk: hands the sub-block at +0x634 of the ARM7 state block
// (pointed to by 0x0380fff4) to the external routine at 0x037fe090.
//
// The offset is emitted as two adds (#0x234 then #0x400) because 0x634 is not
// encodable as a single rotated ARM immediate, and the call is a tail call, so
// with -interworking it goes out as `ldr ip, =FUN_037fe090` / `bx ip` rather
// than a bl relocation.

extern void FUN_037fe090(void *);
void FUN_022d8bfc(void)
{
    FUN_037fe090((void *)(*(int *)0x0380fff4 + 0x634));
}
