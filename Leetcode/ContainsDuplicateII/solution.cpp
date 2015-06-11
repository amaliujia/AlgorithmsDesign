class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> kElement;
        for(int i = 0; i < nums.size(); i++){
            if(kElement.find(nums[i]) != kElement.end()){
                return true;
            }
            kElement.insert(nums[i]);
            if(i >= k){
                kElement.erase(nums[i-k]);
            }
        }
        return false;
    }
};
