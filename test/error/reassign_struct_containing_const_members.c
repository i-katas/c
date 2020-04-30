int main(void) {
    typedef struct {
        const int i;
    } S;

    S s = {0};
    S s1 = {1};

    s = s1; // error
}
