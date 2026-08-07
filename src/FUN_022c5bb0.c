// decomp: module=arm7 addr=0x022c5bb0 name=FUN_022c5bb0
// flags: -O4,s -noThumb

// Unlinks `n` from a doubly linked list and returns the (possibly updated)
// tail pointer: removing the last element moves the tail back to n->prev.
// n->prev is deliberately re-read for the second half - the store through the
// first branch may alias it, so the ROM cannot reuse the value in r3.

typedef struct Node {
    struct Node *next;   // +0x00
    struct Node *prev;   // +0x04
} Node;

Node *FUN_022c5bb0(Node *tail, Node *n)
{
    if (n->prev != 0)
        n->prev->next = n->next;

    if (n->next == 0)
        tail = n->prev;
    else
        n->next->prev = n->prev;

    return tail;
}
