/*
	Average time: O(m + n);
	O(m + n) space	
*/
void merge(int A[], int m, int B[], int n) {
	if(n == 0)  return;
    if(m == 0){
		for(int i = 0; i < n; i++){
            A[i] = B[i];
        }
        return;
	}
        
    int container[m+n];
        
    mergeTwoArray(container, m, n, A, B);
        
    for(int i = 0; i < (m + n); i++){
        A[i] = container[i];
    }
}
    
void mergeTwoArray(int container[], int m, int n, int A[], int B[]){
	int i = 0, j = 0;
    int index = 0;
        
    while((i < m) && (j < n)){
        	if(A[i] < B[j]){
                container[index++] = A[i++];
            }else{
                container[index++] = B[j++];
            }
        }
    while(i < m)    container[index++] = A[i++];
    while(j < n)    container[index++] = B[j++];
}
