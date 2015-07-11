class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() == 1){
            return false;
        }
        
        for(int i = 0; i < nums.size(); i++){
            int j;
            int bound = 0;
            
            if(nums.size() < (i+k+1)){
                bound = nums.size();
            }else{
                bound = i+k+1;
            }
            for(j = i + 1; j < bound; j++){
                if(abs(nums[i] - nums[j]) > t){
                    continue;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};
