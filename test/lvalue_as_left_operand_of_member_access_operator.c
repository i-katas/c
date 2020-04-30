#include <assert.h>


int main(void) {
    typedef struct S {
        int i;
    } S;

    S s;

    assert(s.i == 0);
}
