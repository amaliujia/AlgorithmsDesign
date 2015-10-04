class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ret;
        stack<TreeNode *> in_stack;
        stack<TreeNode *> res_stack;
        vector<int> in;
        vector<int> res;
        
        TreeNode *cur = root;
        while(cur || !in_stack.empty()){
            if(cur){
                in_stack.push(cur);
                cur = cur->left;
            }else if(!in_stack.empty()){
                cur = in_stack.top();
                in_stack.pop();
                
                if(cur->val > target){
                    break;
                }
                in.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        cur = root;
        while(cur || !res_stack.empty()){
            if(cur) {
                res_stack.push(cur);
                cur = cur->right;
            }else if(!res_stack.empty()){
                cur = res_stack.top();
                res_stack.pop();
                if(cur->val <= target){
                    break;
                }
                res.push_back(cur->val);
                cur = cur->left;
            }
        }
    
        while(k-- > 0){
            if(in.size() == 0){
                ret.push_back(res.back());
                res.pop_back();
            }else if(res.size() == 0){
                ret.push_back(in.back());
                in.pop_back();
            }else if(abs(in.back() - target) < abs(res.back() - target)){
                ret.push_back(in.back());
                in.pop_back();
            }else{
                ret.push_back(res.back());
                res.pop_back();            
            }
        }
        return ret;
    }
};
