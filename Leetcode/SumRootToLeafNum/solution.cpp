class Solution {
  public:
    int sumNumbers(TreeNode* root) {
      if(root == NULL){
        return 0;
      } 

      vector<int> sums;
      sumN(root, sums, 0);

      int result = 0;
      for(int i : sums){
        result += i;
      }

      return result;
    }

  private:
    void sumN(TreeNode *node, vector<int> &sums, int n){
      n = n * 10 + node->val;

      if(!node->left && !node->right){
        sums.push_back(n);
        return;
      }

      if(node->left){
        sumN(node->left, sums, n); 
      }

      if(node->right){
        sumN(node->right, sums, n); 
      }
    }
};
