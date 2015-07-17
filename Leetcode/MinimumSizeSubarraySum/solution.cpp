class Solution {
  public:
    int minSubArrayLen(int s, vector<int>& nums) {
      int i = 0, j = 0;
      int min_len = INT_MAX;
      int total = 0;
      while(j < nums.size()){
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
