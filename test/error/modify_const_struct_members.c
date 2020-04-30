int main(void) {
    typedef struct S {
        int i;
    } S;

    const S s = {1};
    
    s.i = 2; //error
}
