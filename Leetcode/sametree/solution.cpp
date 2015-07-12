class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      return recursiveTree(p, q);
    }
  private:
    bool recursiveTree(TreeNode *p, TreeNode *q){
      if(p == NULL && q == NULL){
        return true;
      } 

      if(p == NULL || q == NULL){
        return false;
      }

      if(p->val != q->val){
        return false;
      }

      if(!recursiveTree(p->left, q->left)){
        return false;
      }

      if(!recursiveTree(p->right, q->right)){
        return false;
      }
      return true;
    }
};
