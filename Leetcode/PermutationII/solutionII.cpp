class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> res;
      res.push_back(nums);

      if(nums.size() == 1){
        return res;
      }

      while(nextPermutation(nums)){
        res.push_back(nums);
      }
      return res;
    }

  private:
    bool nextPermutation(vector<int> &nums){
      int i = nums.size() - 2;
      while(i >= 0){
        if(nums[i] >= nums[i+1]){
          i--;
        }else{
          break;
        }
      }

      if(i == -1){
        return false;
      }

      int j = i+1;
      while(j < nums.size()){
        if(nums[j] < nums[i]){
          break;
        }else{
          j++;
        }
      }

      j = j - 1;
      swap(nums[i], nums[j]);
      reverse(nums.begin() + i + 1, nums.end());
      return true;
    }
};
