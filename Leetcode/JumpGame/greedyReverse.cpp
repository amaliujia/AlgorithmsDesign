class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 0)  return false;
        
        int step = n - 1;
        for(int i = n - 2; i >= 0; i--){
            if(i + A[i] >= step){
                step = i;
            }
        }
        return step == 0;
    }
};
