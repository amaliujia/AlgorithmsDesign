class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int>cur;
        solver(candidates, result, target, cur, 0);
        return result;
    }
    void solver(vector<int> &candidates, vector<vector<int>> &result, int target, vector<int> &cur, int start){
        if(target == 0){
            result.push_back(cur);
            return;
        }
        
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] > target)  return;
    
            cur.push_back(candidates[i]);
            solver(candidates, result, target - candidates[i], cur, i);
            cur.pop_back();
        } 
    }
};
