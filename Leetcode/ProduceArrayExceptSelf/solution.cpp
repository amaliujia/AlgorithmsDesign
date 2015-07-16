class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> n1(nums.size(), 1);
      vector<int> n2(nums.size(), 1);
      vector<int> re(nums.size(), 1);

      int a = 1;
      n1[0] = 1;
      for(int i = 1; i < nums.size(); i++){
        a = a * nums[i-1];
        n1[i] = a;
      }

      a = 1;
      n2[nums.size() - 1] = 1;
      for(int i = nums.size() - 2; i >= 0; i--){
        a = a * nums[i+1];
        n2[i] = a;
      }     

      for(int i = 0; i < nums.size(); i++){
        re[i] = n1[i] * n2[i];
      }     
      return re; 
    }
};
