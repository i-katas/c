#include <assert.h>

struct Node {
    struct Node *next;
};


int main(void) {
    struct Node next;
    struct Node head = { &next };

    assert(&next);
    assert(head.next == &next);
}
