class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
         vector<vector<int>> result;
         if(root == NULL)   return result;
         
         bool left = true;
         vector<int> v;
         queue<TreeNode *> q;
         q.push(root);
         q.push(NULL);
         while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node){
                v.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }else{
                if(left){
                    result.push_back(v);
                }else{
                    reverse(v.begin(), v.end());
                    result.push_back(v);
                }
                v.clear();
                left = !left;
                if(q.size() > 0)    q.push(NULL);
            }
         }
         return result;       
    }
};
