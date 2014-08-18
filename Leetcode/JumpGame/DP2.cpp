class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 1)  return true;
        vector<int> f(n, 0);
        f[0] = 1;
        int i = 1;
        while(i < n){
            int j = i - 1;
            while(j >= 0){
                if(f[j] == 1 && ((j + A[j]) >= i)){
                    f[i] = 1;
                    break;
                }else{
                    j--;
                }
            }
            if(f[i] == 0)   return false;
            else i++;
        }
        return true;
    }
};
