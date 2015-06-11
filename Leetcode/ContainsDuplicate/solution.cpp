class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique;
        for(auto item : nums){
            if(unique.find(item) != unique.end()){
                return true;
            }else{
                unique.insert(item);
            }
        }
        return false;
    }
};
