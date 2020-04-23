#include <assert.h>
#include <string.h>

int main() {
    char *foobar = "foo" "bar";

    assert(!strcmp(foobar, "foobar"));
    return 0;
}
