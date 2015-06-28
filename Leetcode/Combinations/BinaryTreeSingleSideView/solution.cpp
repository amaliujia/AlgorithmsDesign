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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if(root == NULL){
            return result;
        }
       
        std::queue<TreeNode *> queFirstLevel;
        std::queue<TreeNode *> queNextLevel;
        queFirstLevel.push(root);
        
        while(!queFirstLevel.empty()){
            TreeNode * pNode = queFirstLevel.front();
            queFirstLevel.pop();
            
            if(pNode->left != NULL){
                queNextLevel.push(pNode->left);
            }
                
            if(pNode->right != NULL){
                queNextLevel.push(pNode->right);
            }
            
            if(queFirstLevel.empty()){
                result.push_back(pNode->val);
                queFirstLevel.swap(queNextLevel);
            }
        } 
        return result;
    }
};
