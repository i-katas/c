#include <assert.h>

int main(void) {
    int a = 1;

    assert(a++ == 1);
    assert(a == 2);

    assert(--a == 1);
    assert(a == 1);
}
