#include <iostream>
using namespace std;

void QuickSort(int arr[], int start, int end){
  int pivot = arr[start];
  
  int i = start, j = end;
  while(true){
    while(i < j && arr[j] > pivot){
      j--;
    } 
    
    if(i == j){
      arr[i] = pivot;
      break;
    }else{
      swap(arr[i], arr[j]);
    }
    
    while(i < j && arr[i] < pivot){
      i++;
    }
    
    if(i == j){
      arr[i] = pivot;
      break;
    }else{
      swap(arr[i], arr[j]);
    }
  }
  
  return;
}

int main() {
  int arr[5] = {5,4,3,2,1};
  QuickSort(arr, 0, 4);
  
  for(int i = 0; i < 5; i++){
    cout << arr[i] << " ";
  }
}

