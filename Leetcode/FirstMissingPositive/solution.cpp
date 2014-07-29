nt firstMissingPositive(int A[], int n) {
        int i = 0;
        for(; i < n; ){
            if (A[i] <= 0 || A[i] == i+1 || A[i] > n || A[i] == A[A[i]-1]) 
                i++;
            else
                swap(A[i], A[A[i] - 1]);
        }
        for(i = 0; i < n; i++){
            if(A[i] != (i + 1)){
                break;
            }
        }
        return i + 1;
    }
