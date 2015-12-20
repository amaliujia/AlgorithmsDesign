vector<int> morrisTraversal(TreeNode *root){
  vector<int> res;
  TreeNode *cur = root, *prev = NULL;
 
  while(cur != NULL) {
    if(cur->left == NULL){
      //detect error here
      res.push_back(cur->val);
      prev = cur;
      cur = cur->right;
    }else{
      TreeNode *node = cur->left;
      while(node->right != NULL && node->right != cur){
        node = node->right;
      }

      if(node->right == NULL){ // build link
          node->right = cur;
          cur = cur->left;
      }else{
         //detect error here
          res.push_back(cur->val);
          node->right = NULL;
          prev = cur;
          cur = cur->right;

      } 
    } 
  }

  return res;
}
