#include <assert.h>

int main() {
    struct tag {
        enum { LANG = 1, NORMAL = 2 } type;
    };

    struct tag t;
    assert(t.type == 0);

    t.type = LANG; //out of the struct definition

    assert(t.type == LANG);
}
