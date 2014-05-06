class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<const TreeNode*> s;
        const TreeNode *cur = root;
        
        while(!s.empty() || cur != NULL){
            if(cur != NULL){
                s.push(cur);
                cur = cur->left;
            }else{
                cur = s.top();
                s.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};
