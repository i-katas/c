#include <assert.h>
#include <stdalign.h>
#include <string.h>
#include <stdlib.h>

#define DISABLE_PADDING __attribute__((packed))


struct NoPadding {
    char c;
    int i;
    double d;
} DISABLE_PADDING;


int get_int(char *ptr) {
    return *ptr | *(ptr + 1) << 8 | *(ptr + 2) << 16 | *(ptr + 3) << 24;
}


double get_double(char *ptr) {
    double value = 0;
    return *(double *)memcpy(&value, ptr, sizeof(typeof(value)));
}


int main(void) {
    struct NoPadding s = {'a', 0x12345678, 100.23};
    assert(sizeof(s) == 13);
    assert(alignof(s) == 1);

    char *ptr = (char*) &s;

    assert(*ptr == 'a');
    assert(get_int(ptr + 1) == 0x12345678);
    assert(get_double(ptr + 5) == 100.23);
}
