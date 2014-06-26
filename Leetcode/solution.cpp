class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0 || inorder.size() == 0){
            return NULL;
        }

        TreeNode *root = NULL;
        build(preorder, inorder, root, 0, inorder.size() - 1, 0, inorder.size() - 1);
        return root;        
    }
    
    void build(vector<int> &preorder, vector<int> &inorder, TreeNode* &root, int lpos, int rpos, int lposi, int rposi){
       if(rpos < lpos){
           return;
       }
       int valRoot = preorder[lpos];
       int i;
        root = new TreeNode(valRoot);
        root->val = valRoot;
       for(i = lposi; i <= rposi; i++){
           if(valRoot == inorder[i]){
               break;
           }
       }

       int leftLen = i - lposi;
       if(i > lposi)   build(preorder, inorder, root->left, lpos + 1, lpos + leftLen,  lposi, i - 1);
       if(i < rposi)   build(preorder, inorder, root->right, lpos + leftLen + 1, rpos, i + 1, rposi);
    }
};
