class Solution {
private: TreeNode *newroot = NULL;
public:
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        if(newroot != NULL){
            newroot->left = NULL;
            newroot->right = root;
        }
        newroot = root;
        TreeNode *right = root->right;
        flatten(root->left);
        flatten(right);
    }
};
