// O(1) space 
// O(n) time
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)  return 0;
        int i = 1;
        int index = 1;
        int cur = nums[0];
        while(index < n){
            if(A[i] == A[index]){
                index++;
            }else{
                A[i] = A[index];
                cur = A[index];
                i++;
                index++;
            }
        }
        return i;
    }
};
