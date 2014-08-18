class Solution {
public:
    int jump(int A[], int n) {
        if(n == 1)  return 0;
        if(A[0] > n)   return 1;
        vector<int> f(n, INT_MAX);
        f[0] = 0;
        int i = 1;
        while(i < n){
            int j = i - 1;
            while(j >= 0){
                if((j + A[j]) >= i){
                    f[i] = min(f[i], f[j]);
                }
                j--;
            }
            f[i]++;
            i++;
        }
        return f[n - 1];
    }
};
