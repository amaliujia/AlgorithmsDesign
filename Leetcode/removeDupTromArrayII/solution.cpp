class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) return 0;
        
        int index = 0;
        int flag = 1;
        for(int i = 1; i < n; i++){
            if(A[index] == A[i]){
                if( flag == 1){
                    flag++;
                    A[++index] = A[i];
                }
            }else{
                flag = 1;
                A[++index] = A[i];
            }
        }
        return index + 1;
    }
};
