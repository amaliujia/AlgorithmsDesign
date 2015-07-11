class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k <= 0){
            return;
        }
        
        while(k > nums.size()){
            k--;
            rotate(nums, 1);
        }
        
        vector<int> temp;
        
        for(int i = 0; i < nums.size() - k; i++){
          temp.push_back(nums[i]);  
        }
        
        int offset = 0;
        for(int i= nums.size() - k; i < nums.size(); i++){
            nums[offset++] = nums[i];
        }
        
        offset = 0;
        for(int i = k; i < nums.size(); i++){
            nums[i] = temp[offset++];
        }
    }
};
