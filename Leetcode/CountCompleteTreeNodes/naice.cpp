class Solution {
public:
    int countNodes(TreeNode* root) {
        count = 0;
        countT(root);
        return count;
    }
private:
    int count;
    void countT(TreeNode* root){
        if(root == NULL){
            return;
        }
        count++;
        countT(root->left);
        countT(root->right);
    }
};
