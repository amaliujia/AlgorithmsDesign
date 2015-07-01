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
    int kthSmallest(TreeNode* root, int k) {
        int n = 1;
        int result = -1;
        getkthSmallest(root, n, k, result);
        return result;
    }
    
private:
    void getkthSmallest(TreeNode* root, int& n, int k, int& result){
        if(root == NULL){
            return;
        }
        
        if(root->left != NULL){
            getkthSmallest(root->left, n, k, result);   
        }
        
        n++;
        
        if((n - 1) == k){
            result = root->val;
            return;
        }
        
        if((n - 1) > k){
            return;
        }
        
        if(root->right != NULL){
           getkthSmallest(root->right, n, k, result); 
        }
    }
};
