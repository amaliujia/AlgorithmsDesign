void quickSort(vector<int>& nums, int i, int j){
  int mid = quickSortUtil(nums, 0, nums.size()-1);   
  quickSort(nums, i, mid-1);
  quickSort(nums, mid+1, j);
}

int quickSortUtil(vector<int>& nums, int i, int j){
  int pivot = nums[j];
  
  int s = i-1;
  int e = i;

  while(e < j-1){
    if(nums[e] < pivot){
      s++;
      swap(nums[s], nums[e]);
    }
    e++;
  }
  
  s++;
  swap(nums[s], nums[j]);
  return s;
}


