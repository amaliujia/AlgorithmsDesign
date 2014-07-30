// O(1) space
class Solution {
public:
    int trap(int A[], int n) {
        int result = 0;
        int max = -1, maxIndex = 0;
        for(int i = 0; i < n; i++){
            if(A[i] > max){
                maxIndex = i;
            }
        }
        for(int i = 0, peak = 0; i < maxIndex; i++){
            if(A[i] > peak){
                peak = A[i] ;
            }else{
                result += (peak - A[i]);
            }
        }
        for(int i = n - 1, top = 0; i > maxIndex; i--){
            if(A[i] > top){
                top = A[i];
            }else{
                result += (top - A[i]);
            }
        }        
        
        return result;
    }
};
