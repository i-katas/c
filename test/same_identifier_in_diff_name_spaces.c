#include <assert.h>

struct A {
    int A;
};

typedef struct A A;

int main(void) {
    struct A a; // struct A
    A typed; // typedef A

    assert(a.A == 0);
    assert(a.A == typed.A); // tag members A

    goto A; // label A
    assert(("should skipped", 0));
    A:
        return 0;
}
