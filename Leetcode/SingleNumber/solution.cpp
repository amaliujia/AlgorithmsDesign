int singleNumber(int A[], int n) {
    int x = 0;
    for(size_t i = 0; i < n; i++){
        x ^= A[i];
    }
    return x;
}
