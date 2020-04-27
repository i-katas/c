#include <assert.h>
#include <stdalign.h>

/**
 * S Memory aligment:
 * | b | b | b | b | b | b | b | b |
 * | c | - | - | - | i | i | i | i |
 */
struct S {
    double b;
    char c; 
    int i; 
};

/**
 * S1 Memory aligment:
 * | c | - | - | - | - | - | - | - |
 * | b | b | b | b | b | b | b | b |
 * | i | i | i | i | - | - | - | - |
 */
struct S1 {
    char c; 
    double b;
    int i; 
};

/**
 * S2 Memory aligment:
 * | c | - | - | - | i | i | i | i |
 * | b | b | b | b | b | b | b | b |
 */
struct S2 {
    char c; 
    int i; 
    double b;
};

int main(void) {
    struct S s = {5.0, 'a', 10};
    double *pb = (double*) &s;
    char *pc = (char*)(pb + 1);
    int *pi = (int*)(pc + 4);

    assert(*pb == 5.0);
    assert(*pc == 'a');
    assert(("start padding", *(pc + 1) == 0));
    assert(("padding", *(pc + 2) == 0));
    assert(("end padding", *(pc + 3) == 0));
    assert(("start int alignment", *(pc + 4) != 0));
    assert(*pi == 10);
    assert(sizeof(s) == 16);
    assert(alignof(s) == 8);

    struct S1 s1 = {'b', 100.0, 66};
    char *pc1 = (char*) &s1;
    double *pb1 = (double*)(pc1 + 8);
    int *pi1 = (int*)(pb1 + 1);
    assert(*pc1 == 'b');
    assert(*pb1 == 100.0);
    assert(*pi1 == 66);
    assert(sizeof(s1) == 24);
    assert(alignof(s1) == 8);

    struct S2 s2;
    assert(sizeof(s2) == 16);
    assert(alignof(s2) == 8);
}
