//cpp
// decomp: module=unk_autoload_0 addr=0x0232e6cc name=FUN_0232e6cc
// NOTE: verify with --size 0xc, not the batch's 0x1a - the declared window
// overshoots into the next function (push {r4,r5,r6,lr} at 0x0232e6d8).
// True range is 3 instrs + pad + literal pool word (target addr for bx),
// same adjustor-thunk shape as sibling FUN_0232e94c.
extern "C" {
extern void FUN_0232ec6c(int *);
void FUN_0232e6cc(int *p) {
    FUN_0232ec6c((int *)*p);
}
}
