//O(n) time
//O(logn) space
class Solution {
public:
    int maxSum;
    int maxPathSum(TreeNode *root) {
        if(root == NULL)    return 0;
        maxSum = INT_MIN;
        DSF(root);
        return maxSum;
    }
private:
    int DSF(TreeNode *root){
        if(root == NULL)    return 0;
        int val = root->val, maxLeft = 0, maxRight = 0;
        
        maxLeft = DSF(root->left);
        if(maxLeft > 0){
            val += maxLeft;
        }
        
        maxRight = DSF(root->right);
        if(maxRight > 0){
            val += maxRight;
        }
        
        if(val > maxSum)    maxSum = val;
        return max(root->val, max((root->val + maxLeft), (root->val + maxRight)));
    }
};
