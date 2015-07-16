class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;

        int leftHeight = 0;
        int rightHeight = 0;

        TreeNode *pLeft = root;
        while(pLeft) {
            ++leftHeight;
            pLeft = pLeft->left;
        }

        TreeNode *pRight = root;
        while(pRight) {
            ++rightHeight;
            pRight = pRight->right;
        }

        if(leftHeight == rightHeight)
            return pow(2, leftHeight)-1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
