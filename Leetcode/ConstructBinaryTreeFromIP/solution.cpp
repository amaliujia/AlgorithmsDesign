class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0 || postorder.size() == 0){
            return NULL;
        }
        
        TreeNode *root = NULL;
        build(inorder, postorder, root, 0, postorder.size() - 1, 0, inorder.size() - 1);
        return root;
    }

    void build(vector<int> &inorder, vector<int> &postorder, TreeNode* &root, int lpos, int rpos, int lposi, int rposi){
       if(rpos < lpos){
           return;
       }
       int valRoot = postorder[rpos];
       int i;
        root = new TreeNode(valRoot);
        root->val = valRoot;
       for(i = lposi; i <= rposi; i++){
           if(valRoot == inorder[i]){
               break;
           }
       }
       
       int leftLen = i - lposi;
       if(i > lposi)   build(inorder, postorder, root->left, lpos, lpos + leftLen - 1,  lposi, i - 1);
       if(i < rposi)   build(inorder, postorder, root->right, lpos + leftLen, rpos - 1, i + 1, rposi);
    }
};
