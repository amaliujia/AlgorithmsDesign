
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
      if(num.size() == 0){
          return NULL;
      }
      return convertArray(num, 0, num.size() - 1);
    }
    
private:
    TreeNode *convertArray(vector<int> &num, int left, int right){
        if(left > right)    return NULL;
        
        if(left == right){
            return new TreeNode(num[left]);
        }
        
        int middle = (right - left) / 2 + left;
        TreeNode *root = new TreeNode(num[middle]);
        root->left = convertArray(num, left, middle - 1);
        root->right = convertArray(num, middle + 1, right);
        return root;
    }
};
