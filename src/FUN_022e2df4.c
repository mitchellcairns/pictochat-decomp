// decomp: module=arm7 addr=0x022e2df4 name=FUN_022e2df4
// flags: -O4,s -noThumb

// Spins on the status word returned by func_022e2e34: whenever bit 5 is set it
// services it through func_022e2e40 and re-reads, and it only returns once a
// read comes back with neither bit 5 nor bit 0 set.
//
// Both callees are ARM->Thumb veneers parked immediately after this function
// (0x022e2e34 -> 0x03802a20, 0x022e2e40 -> 0x03802f00); per the veneer rule the
// externs name the veneer addresses, which is what the BLs actually encode.

extern void FUN_022e2e34(volatile unsigned int *status);
extern void FUN_022e2e40(void);

void FUN_022e2df4(void)
{
    volatile unsigned int status;
    volatile unsigned int *slot = &status;

    for (;;) {
        FUN_022e2e34(slot);
        if (status & 0x20) {
            FUN_022e2e40();
        } else if ((status & 1) == 0) {
            return;
        }
    }
}
