
class Solution {
  public:
    int minSubArrayLen(int s, vector<int>& nums) {
      if(nums.size() == 0){
        return 0;
      }

      int min = subLen(s, nums, 0, nums.size() - 1);
      return min == INT_MAX ? 0 : min;
    }
  private:
    int subLen(int s, vector<int>& nums, int i, int j){
      if(i == j) {
        if(nums[i] >= s){
          return 1;
        }else{
          return INT_MAX;
        }
      }

      if(i == j + 1){
        if(nums[i] >= s || nums[j] >= s){
          return 1;
        }else if(nums[i] + nums[j] >= s){
          return 2;
        }else{
          return INT_MAX;
        }
      }

      int mid = (i + j) / 2;
      int llen = subLen(s, nums, i, mid);
      int rlen = subLen(s, nums, mid + 1, j);

      int mlen = minArray(s, nums, i, j + 1);

      return min(min(llen, rlen), mlen);
    }

    int minArray(int s, vector<int>& nums, int l, int r) {
      int i = l, j = l;
      int min_len = INT_MAX;
      int total = 0;
      while(j < r ){
        total += nums[j];

        if(total >= s){
          while(i <= j && total >= s){
            min_len = min(min_len, j - i + 1);
            total -= nums[i];
            i++;
          }
          j++;
        }else{
          j++;
        }
      }
      return min_len == INT_MAX ? 0 : min_len;
    }
};
