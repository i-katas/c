#include <assert.h>

int sum(int n, int array[*]); //* is only allowed in function prototype scope

int main(void) {
    int array[4] = {1, 2, 3, 4};

    assert(sum(3, array) == 6);
}

int sum(int n, int array[n]) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += array[i];
    }
    return sum;
}
