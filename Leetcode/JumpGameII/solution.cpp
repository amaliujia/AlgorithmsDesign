// O(n!) time in best case
// O(n!) is slower than O(n^2) 
    int jump(int A[], int n) {
            if(n == 0)  return 0;
            if(A[0] > n)   return 1;
            
            int closest = n - 1;
            int min = 0;
            for(int i = n - 1; i > 0; i--){
                for(int j = i - 1; j >= 0; j--){
                    if(A[j] + j >= i){
                        closest = j;
                    }
                }
                i = closest + 1;
                min++;
            }
            return min;
        }
