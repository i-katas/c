#include <assert.h>

int main(void) {
    int a = 1;
    int *p = &a;
    int **pp = &p;
    int ***ppp = &pp;
    //int ***p3 = &(&p); //error

    assert((void*)pp != (void*)p);
    assert((void*)ppp != (void*)pp);
    assert((void*)ppp != (void*)p);
    assert(*p == 1);
    assert(*pp == p);
    assert(*ppp == pp);
    assert(**ppp == p);
    assert(***ppp == 1);
}
