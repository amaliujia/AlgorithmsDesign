class Solution {
  public:
    int closestValue(TreeNode* root, double target) {
      TreeNode *cur = root;
      int result = cur->val;
      int successor = INT_MAX;
      while(cur){
        if(abs(cur->val - target) < abs(result - target)){
          result = cur->val;
        }

        cur = (cur->val > target) ? cur->left : cur->right;
      }
      return result;
    }
};
