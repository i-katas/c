#include <assert.h>
#include <string.h>

int main(void) {
    char *p = (char*)&"test";

    assert(strcmp(p, "test") == 0);
}
