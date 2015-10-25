
TreeNode* constructUtil(vector<int>& inorder, int si, int ei, vector<int> &preorder, int sp, int ep){
  if(si > ei){
    return NULL;
  } 
  
  if(si == ei){
     TreeNode *res = new TreeNode(inorder[si]);
     return res;
  }

  int root_val = preorder[sp];

  int pos = inorder.find(root_val);
  //pos will never be -1.

  TreeNode *leftNode = constructUtil(inorder, si, pos - 1, preorder, sp + 1, sp + pos - si); 
  TreeNode *cur = new TreeNode(root_val);
  TreeNode *rightNode = constructUtil(inorder, pos + 1, ei, preorder, sp + pos - si + 1, ep);

 cur->left = leftNode;
 cur->right = rightNode;
 return cur; 
}

TreeNode* construct(vector<int>& inorder, vector<int>& preorder){
  return constructUtil(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
}
