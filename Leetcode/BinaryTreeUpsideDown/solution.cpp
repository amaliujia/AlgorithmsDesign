TreeNode* upsideDownBinaryTree(TreeNode* root) {
  if(!root || !root->left){
    return root;
  }      

  TreeNode *cur_left = root->left;
  TreeNode *cur_right = root->right;
  TreeNode *new_root = upsideDownBinaryTree(cur_left);
  cur_left->right = root;
  cur_left->left = cur_right;
  root->left = NULL;
  root->right = NULL;
  return new_root;
}
