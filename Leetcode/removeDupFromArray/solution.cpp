/*
	O(n) time
	O(1) space
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) return 0;
        
        int index = 0;
        for(int i = 1; i < n; i++){
            if(A[index] != A[i]){
                A[++index] = A[i];
            }
        }
        return index + 1;
    }
};
