// O(nlogn)
class Solution {
public:
    int maxSubArray(int A[], int n) {
       return divideAndConque(A, 0, n - 1);
    }
private:
    int divideAndConque(int A[], int left, int right){
        if(left > right)    return INT_MIN;
        if(left == right)   return A[left];
        
        int mid = (left + right) / 2;
        int leftResult = divideAndConque(A, left, mid);
        int rightResult = divideAndConque(A, mid + 1, right);
        int r = max(leftResult, rightResult);
     
        int sum = 0, lmid = 0;
        for(int i = mid - 1; i >= left; i--){
            sum += A[i];
            if(sum > lmid) lmid = sum;
        }
        sum = 0;
        int rmid = 0;
        for(int i = mid + 1; i <= right; i++){
            sum += A[i];
            if(sum > rmid)  rmid = sum;
        }
        r = max(r, rmid + lmid + A[mid]);
        return r;
    }
};
