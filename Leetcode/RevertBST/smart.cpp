class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if(root == NULL){
          return root;
      }
      TreeNode *temp = root->right;
      root->right = root->left;
      invertTree(root->right);
      root->left = temp;
      invertTree(root->left);
      return root;
    }
};
