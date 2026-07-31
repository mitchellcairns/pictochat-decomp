//cpp
// decomp: module=unk_autoload_0 addr=0x02332e70 name=FUN_02332e70
extern "C" void FUN_02332e70(unsigned char *dst, int c, unsigned int n) {
    unsigned int val = (unsigned char)c;

    if (n >= 0x20) {
        {
            unsigned int misalign = (unsigned int)(-(int)(unsigned int)dst) & 3;
            if (misalign != 0) {
                n -= misalign;
                do {
                    *dst++ = (unsigned char)val;
                } while (--misalign != 0);
            }
        }

        if (val != 0) {
            val |= (val << 24) | (val << 16) | (val << 8);
        }

        {
            unsigned int nblk = n >> 5;
            if (nblk != 0) {
                do {
                    unsigned int *p = (unsigned int *)dst;
                    p[0] = val;
                    p[1] = val;
                    p[2] = val;
                    p[3] = val;
                    p[4] = val;
                    p[5] = val;
                    p[6] = val;
                    dst += 32;
                    p[7] = val;
                } while (--nblk != 0);
            }
        }

        {
            unsigned int nword = (n & 0x1f) >> 2;
            if (nword != 0) {
                do {
                    *(unsigned int *)dst = val;
                    dst += 4;
                } while (--nword != 0);
            }
        }

        n &= 3;
    }

    if (n != 0) {
        do {
            *dst++ = (unsigned char)val;
        } while (--n != 0);
    }
}
