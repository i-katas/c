#include <assert.h>

int main(void) {
    typedef struct S {
        int i;
    } S;

    S s = {0};

    int *i = &s.i;

    assert(s.i == 0);
    assert(s.i == *i);

    *i = 3;
    assert(s.i == 3);
}
