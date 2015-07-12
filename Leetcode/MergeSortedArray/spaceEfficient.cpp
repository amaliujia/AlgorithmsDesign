void merge(int A[], int m, int B[], int n){
  int pa = m - 1, pb = n -1, pt = m + n - 1;

  while(pa >= 0 && pb >= 0){
    A[pt--] = (A[pa] > B[pb]) ?  A[pa--] : B[pb--]; 
  }

  while(pb >= 0)	A[pt--] = B[pb--];
}
