//O(n) time
//O(n) space
class Solution {
public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode *>list;
        vector<int> numbers;
        inorderTraversal(root, list, numbers);
        sort(numbers.begin(), numbers.end());
        for(int i = 0; i < numbers.size(); i++){
            list[i]->val = numbers[i];
        }
    }
private:
    void inorderTraversal(TreeNode *node, vector<TreeNode *> &list, vector<int> &numbers){
        if(node == NULL)    return;
        inorderTraversal(node->left, list, numbers);
        list.push_back(node);
        numbers.push_back(node->val);
        inorderTraversal(node->right, list, numbers);
    }

};
