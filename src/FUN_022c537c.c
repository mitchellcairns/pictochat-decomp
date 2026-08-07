// decomp: module=arm7 addr=0x022c537c name=FUN_022c537c
// flags: -O4,s -noThumb

// Walks the singly linked list hanging off +0x24 of the scheduler block at
// 0x03804f68 (chained through +0x4c) and returns the first node whose state
// word at +0x48 is 1, or NULL if the list runs out.

typedef struct Node {
    char pad[0x48];
    unsigned int state;
    struct Node *next;
} Node;

typedef struct Sched {
    char pad[0x24];
    Node *head;
} Sched;

extern Sched G_03804f68;

Node *FUN_022c537c(void)
{
    Node *cur = G_03804f68.head;
    while (cur != 0 && cur->state != 1) {
        cur = cur->next;
    }
    return cur;
}
