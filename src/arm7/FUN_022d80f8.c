// decomp: module=arm7 addr=0x022d80f8 name=FUN_022d80f8
// flags: -O4,s -noThumb
// size: 0x24 - the stated 0x20 excludes the trailing pool word (0x04808094).

// Polls the DSi wifi register at 0x04808094; if bit 15 is clear the work is
// handed to a routine living in ARM7 WRAM.

// The `bl` resolves to 0x037c8430 - a WRAM address, so this is a call into
// code that was copied there at runtime rather than a normal .text symbol.
// The name below is a placeholder for that address; match.py wildcards the
// relocation slot, so it is NOT evidence the callee has been identified.
extern void FUN_037c8430(void);

void FUN_022d80f8(void)
{
    if ((*(volatile unsigned short *)0x04808094 & 0x8000) == 0) {
        FUN_037c8430();
    }
}
