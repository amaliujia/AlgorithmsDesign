class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int count = 0;
        vector<vector<int>> result;
        vector<int> v;
        dfs(root, sum, count, result, v);
        return result;
    }
    
    void dfs(TreeNode* root, int sum, int& count, vector<vector<int>>& result,
             vector<int>& v){
        if(root == NULL){
            return;
        }    
        
        count += root->val;
        v.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL && sum == count){
            result.push_back(v);
        }else{
            dfs(root->left, sum, count, result, v);
            dfs(root->right, sum, count, result, v);
        }
        count -= root->val;
        v.pop_back();
    }
}
