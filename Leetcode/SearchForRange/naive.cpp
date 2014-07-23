// O(logn + x), x is equal to the number of target in sorted array.
// x = O(n)
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int index = binarySearch(A, n, target);
        vector<int> result;
        int start = index, end = index;
        if(index != -1){
            while(start >= 0){
                if(((start - 1) >= 0) && (A[start - 1] == target)){
                    start--;
                }else{
                    break;
                }
            }
            while(end <= (n - 1)){
                if(((end + 1) < n) && (A[end + 1] == target)){
                    end++;
                }else{
                    break;
                }                
            }
        }
            result.push_back(start);
            result.push_back(end);
            return result;
    }
    
    int binarySearch(int A[], int n, int target){
        int left = 0, right = n - 1;
        int index;
        while(left <= right){
            index = (left + right) / 2;
            if(A[index] == target)  return index;
            else if(A[index] > target){
                right = index - 1;
            }else{
                left = index + 1;
            }
        }
        return -1;
    }
};
