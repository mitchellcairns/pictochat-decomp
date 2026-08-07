// decomp: module=arm7 addr=0x022d8d6c name=FUN_022d8d6c
// flags: -O4,s -noThumb
// size: 0x1c - all code, there is no trailing pool word.

// Unaligned byte fetch done entirely through halfword loads: an odd address is
// read as the halfword one below and shifted down, an even address is read
// directly.  The halfword load is UNSIGNED and the shift is done in `int`,
// which is why the ROM pairs `ldrh` with an ARITHMETIC `asr`.
//
// The redundant `& 0xff` on top of the already-narrowed `v` is real: it is what
// produces the second, unconditional `and r0, r0, #0xff` the ROM carries.

unsigned char FUN_022d8d6c(unsigned int addr)
{
    unsigned char v;

    if (addr & 1) {
        v = (unsigned char)(*(unsigned short *)(addr - 1) >> 8);
    } else {
        v = (unsigned char)*(unsigned short *)addr;
    }
    return (unsigned char)(v & 0xff);
}
