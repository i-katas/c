#include <assert.h>

int main(void) {
    int array[] = {1, 2, 3};

    int *first = &array[0];

    *first = 5;
    assert(array[0] == 5);
    assert(array[1] == 2);
    assert(array[2] == 3);
}
