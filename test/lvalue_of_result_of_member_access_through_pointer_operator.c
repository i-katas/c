#include <assert.h>

int main(void) {
    typedef struct S {
        int i;
    } S;

    S *p = &(S){0};
    assert(p->i == 0);

    int *i = &p->i;
    assert(p->i == *i);

    *i = 2;
    assert(p->i == 2);
}
