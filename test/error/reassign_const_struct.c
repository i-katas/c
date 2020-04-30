int main(void) {
    typedef struct {
        int i;
    } S;

    const S s = {0};
    S s1 = {1};

    s = s1; // error
}
