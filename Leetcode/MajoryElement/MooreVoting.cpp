class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major_num = 0;
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[major_num]){
                count++;
            }else{
                count--;
            }
            
            if(count == 0){
                major_num = i;
                count = 1;
            }
        }
        return nums[major_num];
    }
};
