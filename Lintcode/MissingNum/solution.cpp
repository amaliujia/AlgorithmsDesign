class Solution {
  public:
    int findMissing(vector<int> &nums) {
      long long count = 0;
      for(int i = 0; i <= nums.size(); i++){
        count += i;
        count -= nums[i];
      }

      return count;    
    }
};

