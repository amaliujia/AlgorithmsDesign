void printUnsorted(int arr[], int n) {
  int s = -1, e = -1;
  for(int i = 0; i < n - 1; i++){
    if(arr[i] > arr[i+1]){
      s = i;
      break; 
    }  
  }
  
  for(int i = n - 1; i > 0; i--){
    if(arr[i] < arr[i-1]){
      e = i;
      break; 
    }
  }

  if((s == =1 && e == -1) || e < s) {
    return;
  }
  
  int max = getMax(arr, s, e);
  int min = getMin(arr, s, e);
  
  for(int i = 0; i < s; i++){
    if(arr[i] > min){
      s = i;
      break;
    }
  }

  for(int i = n - 1; i >= 0; i--){
    if(arr[i] < max){
      e = i;
      break;
    }
  }

  printf("%d %d\n", s, e);
}
