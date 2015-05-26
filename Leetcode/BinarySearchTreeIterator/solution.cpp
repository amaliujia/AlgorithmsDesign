class BSTIterator {
private:
    TreeNode* cur;
    std::stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root) {
        cur = NULL;
        getLeftPath(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ((cur != NULL && cur->right != NULL) || !s.empty());
    }

    /** @return the next smallest number */
    int next() {
        if(cur != NULL && cur->right != NULL){
            getLeftPath(cur->right); 
        }
        if(!s.empty()){
            cur = s.top();
            s.pop();
        }
        return cur->val;
    }
    
private:
    void getLeftPath(TreeNode *root){
        if(root == NULL){
            return;
        }
        TreeNode *n = root;
        s.push(n);
        while(n->left != NULL){
            s.push(n->left);
            n = n->left;
        }
    }
};
