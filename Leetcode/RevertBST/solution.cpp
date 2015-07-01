/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      vector<int> v;
      convertBSTtoArray(root, v);
      reverArrays(v);
      return convertArraytoBST(v, 0, v.size() - 1);
    }

private:
    void convertBSTtoArray(TreeNode *root, vector<int>& result){
      if(root == NULL){
        return;
      }

      if(root->left != NULL){
        convertBSTtoArray(root->left, result);
      }
    
      result.push_back(root->val);

      if(root->right != NULL){
        convertBSTtoArray(root->right, result);
      }
    }
    
    void reverseArrays(vector<int>& arr){
        int i = 0;
        int j = arr.size() - 1;
        while(i < j){ 
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
          i++;
          j--;
        }
    }
    
    TreeNode *convertArraytoBST(vector<int> &num, int left, int right){
      if(left > right)
        return NULL;
      
      if(left == right){
        return new TreeNode(num[left]);
      }
      
      int middle = (right - left) / 2 + left;
      TreeNode *root = new TreeNode(num[middle]);
      root->left = convertArraytoBST(num, left, middle - 1);
      root->right = convertArraytoBST(num, middle + 1, right);
      return root;  
    }
};
