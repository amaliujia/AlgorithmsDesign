class Solution {
  public:
    bool hasPathSum(TreeNode* root, int sum) {
      int count = 0;
      return dfs(root, sum, count);
    }

    bool dfs(TreeNode* root, int sum, int& count){
      if(root == NULL){
        return false;
      }    

      count += root->val;
      if(root->left == NULL && root->right == NULL && sum == count){
        return true;
      }

      bool result = dfs(root->left, sum, count);
      if(result)  return result;
      result = dfs(root->right, sum, count);
      if(result)  return result;

      count -= root->val;
      return false;
    }
};
