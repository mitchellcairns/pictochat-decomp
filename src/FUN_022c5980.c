// decomp: module=arm7 addr=0x022c5980 name=FUN_022c5980
// flags: -O4,s -noThumb
typedef struct Node {
    char pad[0x10];
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Queue {
    char pad[0x6c];
    Node *head;
    Node *tail;
} Queue;

void FUN_022c5980(Queue *q, Node *node) {
    Node *tail = q->tail;
    if (tail == 0) {
        q->head = node;
    } else {
        tail->next = node;
    }
    node->prev = tail;
    node->next = 0;
    q->tail = node;
}
