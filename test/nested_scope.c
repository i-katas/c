#include <assert.h>

int main(void) {
    int a = 1;

    {
        int a = 2;
        a++;
        assert(a == 3);
    }

    assert(a==1);
}
