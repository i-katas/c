#include <assert.h>
int main(void) {
    int a = 1;
    int *p = &a;

    int *b = &*p;

    assert(b == p);
}
