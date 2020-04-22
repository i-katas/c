#include <assert.h>

int main() {
    char *foobar = "foo" "bar";

    assert(foobar == "foobar");
    return 0;
}
