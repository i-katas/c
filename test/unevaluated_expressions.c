#include <assert.h>
#include <stdalign.h>

int calls = 0;

int fun(int a, int b) {
    return ++calls;
}


int main(void) {
    assert((sizeof(fun(1, 2)), calls == 0));
    assert((alignof(fun(1, 2)), calls == 0));
    assert((_Generic(fun(1, 2), int: 0), calls == 0));
}
