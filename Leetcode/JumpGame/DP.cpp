class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 0 || n == 1)  return true;
        
    int reach = 0;
    for(int i = 1; i < n; i++){
        reach = max(reach, A[i - 1]) - 1;
        if(reach < 0) return false;
    }
    return reach >= 0;
    }
};
