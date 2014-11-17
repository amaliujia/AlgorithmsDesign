// O(n) time
class Solution {
public:
    void sortColors(int A[], int n) {
        int s1 = 0;
        int s2 = 0;
        int s3 = n - 1;
        while(s2 <= s3){
            if(A[s2] == 0){
                swap(A[s1], A[s2]);
                s1++;
                s2++;
            }else if(A[s2] == 1){
                s2++;
            }else{
                swap(A[s2], A[s3]);
                s3--;
            }
        }
    }
};
