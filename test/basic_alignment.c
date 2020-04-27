#include <assert.h>
#include <stdalign.h>


int main(void) {
    assert(sizeof(char) == 1);
    assert(alignof(char) == 1);

    assert(sizeof(short) == 2);
    assert(alignof(short) == 2);

    assert(sizeof(int) == 4);
    assert(alignof(int) == 4);

    assert(sizeof(float) == 4);
    assert(alignof(float) == 4);

    assert(sizeof(long) == 8);
    assert(alignof(long) == 8);

    assert(sizeof(double) == 8);
    assert(alignof(double) == 8);

    assert(sizeof(long long) == 8);
    assert(alignof(long long) == 8);

    long long number = 0x12345678;
    char *ptr = (char*) &number;

    //little-endian
    assert(*(ptr + 0) == 0x78);
    assert(*(ptr + 1) == 0x56);
    assert(*(ptr + 2) == 0x34);
    assert(*(ptr + 3) == 0x12);
}
