int threeSumClosest(vector<int>& nums, int target) {
  if(nums.size() < 3) return 0;
  sort(nums.begin(), nums.end());

  int cloest = nums[0] + nums[1] + nums[2];
  int f,s,t;
  for(int i = 0; i < nums.size() - 2; i++){
    f = i;
    if(f > 0 && nums[f] == nums[f-1]){
      continue;
    }
    s = i + 1;
    t = nums.size() - 1;
    while(s < t){
      int cur_num = nums[f] + nums[s] + nums[t];
      if(cur_num == target){
        return target;
      }

      if (abs(cur_num - target) < abs(target - cloest)){
        cloest = cur_num;
      }

      if(cur_num > target){
        t--;
        while (t > 0 && t < nums.size() - 1 && nums[t] == nums[t + 1]) {
          t--;
        }
      }
      if(cur_num < target) {
        s++;
        while(s < nums.size() && nums[s] == nums[s - 1]){
          s++;
        }                  
      }
    }
  }
  return cloest;
}
