class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> trial;
        getCombination(n, k, 1, trial, result);
        return result;
    }
private:
    void getCombination(int n, int k, int level,
                        vector<int> &trial,
                        vector<vector<int>> &result){
        if(trial.size() == k){
            result.push_back(trial);
            return;
        }
        
        for(int i = level; i <= n; i++){
            trial.push_back(i);
            getCombination(n, k, i + 1, trial, result);
            trial.pop_back();
        }
    }
};
