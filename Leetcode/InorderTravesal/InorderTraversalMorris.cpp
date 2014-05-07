class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<const TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *gun;
        while(cur != NULL){
            if(cur->left == NULL){
                result.push_back(cur->val);
                cur = cur->right;
            }else{
                gun = cur->left;
                while(gun->right != NULL && gun->right != cur){
                    gun = gun->right;
                }
                
                if(gun->right == NULL){
                    gun->right = cur;
                    cur = cur->left;
                }else{
                    result.push_back(cur->val);
                    gun->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
