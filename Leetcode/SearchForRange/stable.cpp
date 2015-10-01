// O(logn) time
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int low = binarySearchLowBound(A, n, target);
        int upper = binarySearchUpperBound(A, n, target);
        if(low == n || A[low] != target){
            return vector<int> {-1, -1};
        }else{
            return vector<int> {low, upper - 1};
        }
    }
    
    int binarySearchLowBound(int A[], int n, int target){
        int left = 0, right = n - 1;
        int index;
        while(left <= right){
            index = (left + right) / 2;
            if(A[index] < target)   left = index + 1;
            else right = index - 1;
        }
        return left;
    }
    int binarySearchUpperBound(int A[], int n, int target){
        int left = 0, right = n - 1;
        int index;
        while(left <= right){
            index = (left + right) / 2;
            if(A[index] <= target)   left = index + 1;
            else right = index - 1;
        }
        return right;
    }
};
