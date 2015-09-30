class Solution {
  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);    
    }
  private:
    TreeNode *constructTree(vector<int>& preorder, int i, int j, vector<int>& inorder, int x, int y){
      if(i > j){
        return NULL;
      }

      TreeNode *root = new TreeNode(preorder[i]);

      int mid;
      for(mid = x; mid <= y; mid++){
        if(inorder[mid] == preorder[i]){
          break;
        }
      }

      int left_tree_size = mid - x;
      root->left = constructTree(preorder, i + 1, i + left_tree_size, inorder, x, mid - 1);
      root->right = constructTree(preorder, i + left_tree_size + 1, j, inorder, mid + 1, y);
      return root;
    }
};
