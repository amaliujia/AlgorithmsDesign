// O(1) space 
// O(n) time
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)  return 0;
        int i = 0;
        int index = 0;
        int len = 1;
        while(index < n){
            if(A[i] == A[index]){
                index++;
            }else{
                A[i + 1] = A[index];
                i++;
                index++;
                len++;
            }
        }
        return len;
    }
};
