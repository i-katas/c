#include <assert.h>

int main(void) {
    int a; 
    
    assert(("uninitialized variable", a != 0));
    assert(&a == &a);
}
