int findDuplicate(vector<int>& nums) {
  int i = 1, j = nums.size() - 1;
  int mid;

  while(i < j){
    int count = 0;
    mid = (i + j) / 2;
    for(int z = 0; z < nums.size(); z++){
      if(nums[z] >= i && nums[z] <= mid){
        count++;
      }
    }

    if(count > (mid - i + 1)){
      j = mid;
    }else{
      i = mid + 1;
    }
  }

  return i;
}
