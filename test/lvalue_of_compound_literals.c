#include <assert.h>

int main(void) {
    int *p = (int*) &(int[]){3, 2};

    assert(*p == 3);
    assert(*(p + 1) == 2);
}
