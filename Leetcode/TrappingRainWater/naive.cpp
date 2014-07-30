// O(n) space
// O(n) time
class Solution {
public:
    int trap(int A[], int n) {
        int result = 0;
        int *left = new int[n]();
        int *right = new int[n]();
        for(i = 1; i < n; i++){
            left[i] = max(left[i - 1], A[i - 1]);
        }
        for(i = n - 2; i >= 0; i--){
            right[i] = max(right[i + 1], A[i + 1]);
        }
        
        for(int i = 0; i < n; i++){
            int height = min(left[i], right[i]);
            if(height > A[i]){
                result += (height - A[i]);
            }
        }
        delete[] left;
        delete[] right;
        return result;
    }
};
