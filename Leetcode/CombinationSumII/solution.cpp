// O(n!) time

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        vector<int>cur;
        solver(num, result, target, cur, 0);
        return result;      
    }
        void solver(vector<int> &candidates, vector<vector<int>> &result, int target, vector<int> &cur, int start){
        if(target == 0){
            result.push_back(cur);
            return;
        }
        int previous = -1;
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] > target)  return;
            
            if(previous == candidates[i])   continue;
            previous = candidates[i];
            
            cur.push_back(candidates[i]);
            solver(candidates, result, target - candidates[i], cur, i + 1);
            cur.pop_back();
        } 
    }
};
