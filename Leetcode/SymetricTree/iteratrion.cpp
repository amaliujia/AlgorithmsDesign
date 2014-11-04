/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
       if(root == NULL) return true;
        vector<TreeNode *> que;
        que.push_back(root);
        int curlevel = 1;
        while(curlevel > 0){
            for(int i = 0; i < curlevel; i++){
                TreeNode *t = que[i];
                if(t == NULL)   continue;
                que.push_back(t->left);
                que.push_back(t->right);
            }
            int j = 0, z = curlevel - 1;
            while(j < z){
                int l = (que[j] == NULL ? -1 : que[j]->val);
                int r = (que[z] == NULL ? -1 : que[z]->val);
                if(l != r)  return false;
                j++;
                z--;
            }
            que.erase(que.begin(), que.begin() + curlevel);
            curlevel = que.size();
        }
        return true;
    }
};
