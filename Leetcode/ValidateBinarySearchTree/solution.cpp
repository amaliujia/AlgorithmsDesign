class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidSubBST(root, INT_MIN, INT_MAX);  
    }
private:
    bool isValidSubBST(TreeNode *node, int min, int max){
        if(node == NULL)    return true;
        
        if((min < node->val) && (node->val < max) && 
            isValidSubBST(node->left, min, node->val) &&
            isValidSubBST(node->right, node->val, max)){
                return true;
            }else   return false;
    }
    
};
