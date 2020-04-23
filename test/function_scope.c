#include <assert.h>

int main(void) {
    goto success; //label is avaiable in function scope

    assert(("error", 0));//unreachable

    nested: {
        response:
            return 0;
    }

    success:
        assert(("success", 1));
        goto response;//label is available even if it is in nested-scope
}
