class Solution {
 public:
    int rob(vector<int>& nums) {
      if(nums.size() == 0){
        return 0;
      }

      if(nums.size() == 1){
        return nums[0];
      }

      if(nums.size() == 2){
        return max(nums[0], nums[1]);
      }

      vector<int> n1;
      for(int i = 0; i < nums.size() - 1; i++){
        n1.push_back(nums[i]);
      }
      int c1 = linearRob(n1);

      vector<int> n2;
      for(int i = 1; i < nums.size(); i++){
        n2.push_back(nums[i]);
      }
      int c2 = linearRob(n2);
      return max(c1, c2);
    }
 private:
    int linearRob(vector<int>& nums){
      if(nums.size() == 0){
        return 0;
      }

      if(nums.size() == 1){
        return nums[0];
      }

      if(nums.size() == 2){
        return max(nums[0], nums[1]);
      }

      int t1 = nums[0];
      int t2 = max(nums[0], nums[1]);

      for(int i = 2; i < nums.size(); i++){
        int temp = max(t2, t1 + nums[i]);
        t1 = t2;
        t2 = temp;
      }
      return t2;
    }
};
