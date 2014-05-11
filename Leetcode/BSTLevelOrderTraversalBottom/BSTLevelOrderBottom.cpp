class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        subLevelOrder(root, 1, result);
        std::reverse(result.begin(), result.end());
        return result;
    }
    
    void subLevelOrder(TreeNode *root, int level, vector<vector<int> > &v){
        if(!root){
            return;
        }
        
        if(level > v.size()){
            v.push_back(vector<int>());
        }
        
        v[level-1].push_back(root->val);
        subLevelOrder(root->left, level+1, v);
        subLevelOrder(root->right, level+1, v);
    }
};
