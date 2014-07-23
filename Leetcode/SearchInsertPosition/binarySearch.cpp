class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while(left <= right){
            int index = (left + right) / 2;
            if(A[index] < target)   left = index + 1;
            else    right = index - 1;
        }
        return left;
    }
};
