class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> bst;
        
        for(int i = 0; i < nums.size(); i++){
            if(bst.size() == k + 1){
                bst.erase(bst.find(nums[i - k - 1]));
            }
            
            auto iter = bst.lower_bound(nums[i]);
            if((iter != bst.end()) && (abs(*iter - nums[i]) <= k)){
                return true;
            }
            
            auto iteru = bst.upper_bound(nums[i]);
            if((iteru != bst.begin()) &&  (abs(*(--iteru) - nums[i]) <= k)){
                return true;
            }
            bst.insert(nums[i]);
        }
        return false;
    }
};
