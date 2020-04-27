#include <assert.h>
#include <stdalign.h>
#define DISABLE_PADDING __attribute__((packed))

struct NoPadding {
    char c;
    int i;
    double d;
} DISABLE_PADDING;

int main(void) {
    struct NoPadding s = {'a', 0x12345678, 100.23};
    assert(sizeof(s) == 13);
    assert(alignof(s) == 1);

    char *ptr = (char*) &s;

    assert(*ptr == 'a');
    int value = *(ptr + 1) | *(ptr + 2) << 8 | *(ptr + 3) << 16 | *(ptr + 4) << 24;
    assert(value == 0x12345678);
}
