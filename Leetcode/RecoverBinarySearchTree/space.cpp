class Solution {
  public:
    void recoverTree(TreeNode* root) {
      TreeNode *first_err = NULL, *second_err = NULL;
      stack<TreeNode*> s;
      TreeNode *cur = root;
      int prev = INT_MIN;
      TreeNode *prev_n = NULL;
      while(cur != NULL || !s.empty()){
        if(cur == NULL){
          cur = s.top();
          s.pop();
          if(cur->val < prev){
            if(!first_err){
              first_err = prev_n;
              second_err = cur;
            }else{
              second_err = cur;
            }
          }

          prev = cur->val;
          prev_n = cur;
          cur = cur->right;
        }else{
          s.push(cur);
          cur = cur->left;
        }
      }
      if(first_err && second_err){
        swap(first_err->val, second_err->val);
      }
    }
};
