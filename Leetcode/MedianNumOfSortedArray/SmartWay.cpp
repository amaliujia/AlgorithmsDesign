class Solution {
public:
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int sum = m + n;
    if(sum % 2)
    {
        return findkth(A, m, B, n, sum/2+1);
    }else{
        return (findkth(A, m, B, n, sum/2) + (findkth(A, m, B, n, sum/2+1))) / 2.0;
    }
}

double findkth(int A[], int m, int B[], int n, int k)
{
    int ka,kb;
    if(m > n)
    {
        return findkth(B, n, A, m, k);
    }
    if(m == 0){
        return B[k-1];
    }
    if(k == 1){
        return A[0] < B[0] ? A[0] : B[0]; 
    }
    
    ka = k/2 > m ? m : k/2;
    kb = k - ka;
    
    if(A[ka-1] == B[kb-1]){
        return A[ka-1];
    }else if(A[ka-1] > B[kb-1]){
        return findkth(A, m, B+kb, n-kb, k-kb);   
    }else{
        return findkth(A+ka, m-ka, B, n, k-ka);
    }
    
}
};
