class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(subTreeDepth(root) == -1){
            return false;
        }
        return true;
    }
private:
    int subTreeDepth(TreeNode *node){
        if(node == NULL)    return 0;
        int left = subTreeDepth(node->left);
        if(left == -1)  return -1;
        int right = subTreeDepth(node->right);
        if(right == -1) return -1;
        
        if(abs(left - right) > 1){
            return -1;
        }
        return max(left, right) + 1;
    }
};
