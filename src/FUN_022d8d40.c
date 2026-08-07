// decomp: module=arm7 addr=0x022d8d40 name=FUN_022d8d40
// flags: -O4,s -noThumb

// Writes one byte through 16-bit accesses only (the backing memory is
// halfword-addressable): read-modify-write the containing halfword, putting the
// value in the high half for an odd address and in the low half for an even one.

void FUN_022d8d40(unsigned char *p, unsigned int v)
{
    if ((unsigned int)p & 1) {
        unsigned short *h = (unsigned short *)(p - 1);
        *h = (unsigned short)((*h & 0xff) | (v << 8));
    } else {
        unsigned short *h = (unsigned short *)p;
        *h = (unsigned short)((*h & 0xff00) | (v & 0xff));
    }
}
