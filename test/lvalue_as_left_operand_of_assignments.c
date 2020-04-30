#include <assert.h>


int main(void) {
    int a = 1;

    a = 2; // assignment
    assert(a == 2);

    a += 3; // compound assginment
    assert(a == 5);
}
