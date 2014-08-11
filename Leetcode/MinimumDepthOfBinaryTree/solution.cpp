//O(n) time
class Solution {
public:
    int minDepth(TreeNode *root) {
        return minD(root);
    }
private:
    int minD(TreeNode *node){
        if(node == NULL){
            return 0;
        }
        if(node->left == NULL && node->right == NULL)  return 1;
        else if(node->left == NULL)  return (minD(node->right) + 1);
        else if(node->right == NULL)    return (minD(node->left) + 1);
        else    return (min(minD(node->left), minD(node->right)) + 1);
    }
};
