class Solution {
public:
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int sum = m + n;
    if(sum % 2)
    {
        return findkth(A, m, B, n, sum/2+1);
    }
}

double findkth(int A[], int m, int B[], int n, int k)
{
    
}
};
