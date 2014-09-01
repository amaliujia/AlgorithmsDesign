// O(n) time
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int result = 0;
        int inter = 0;
        for(int i = 0; i < n; i++){
            inter = max(0, A[i] + inter);
            result = max(result, A[i] + inter);
        }
        return result;
    }
};
