int findKthSmallestInUnsortedArray(vector<int>& nums, int k){
  if(nums.size() < k || k == 0){
    return 0; 
  } 
  
  makeMaxHeap(nums, 0, k - 1); 
  if(nums.size() == k){
    return num[0]; 
  } 
  for(int i = k; i < nums.size(); i++){
    if(nums[0] > nums[i]){
      swap(nums[0], nums[i]);
      makeMaxHeap(nums, 0, k - 1); 
    }
  }
  return nums[0];
}

void heapify(vector<int>& nums, int start, int end){
  for(int i = end; i >= start; i--){
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;
    if(left <= end && nums[left] > nums[largest]){
      largest = left
    }
    if(right <= end && nums[right] > nums[largest]){
      largest = right; 
    }

    if(largest != i){
      swap(nums[largest, i]);
    }
  }
}

// O(n)
void makeMaxHeap(vector<int>& nums, int start, int end){
  for(int i = (end - start) / 2; i >= start; i--)(
    heapify(nums, start, i);
   )  
}
