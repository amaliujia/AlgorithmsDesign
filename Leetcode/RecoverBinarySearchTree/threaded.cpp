// O(n) time
// O(1) space

void recoverTree(TreeNode *root){
  TreeNode *f1 = NULL, *f2 = NULL;
  TreeNode *curr, *pre, *parent = NULL;

  if(root == NULL)
    return;
  bool found = false;
  curr = root;

  while(cur != NULL){
    if(cur->left == NULL){
      if(parent && parent->val > cur->val){
        if(!found){
          f1 = parent;
          found = true;
        }
        f2 = cur;
      }
      parent = cur;
      cur = cur->right;			
    }else{
      pre = cur->left;
      while(pre->left != NULL && pre->right != current)
        pre = pre->right;
      if(pre->right == NULL){
        pre->right = cur;
        cur = cur->left;
      }else{
        pre->right = NULL;
        if(parent->val > cur->val){
          if(!found){
            f1 = parent;
            found = true;
          }
          f2 = cur;	
        }
        parent = cur;
        cur = cur->right;
      }
    }
  }

  if(f1 && f2){
    swap(f1->val, f2->val);
  }	
}
