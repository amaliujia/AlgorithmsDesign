vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> result;
    if(root == NULL)    return result;
    
    queue<TreeNode *> curQue;
    queue<TreeNode *> nextQue;

    curQue.push(root);
    vector<int> v;
    while(!curQue.empty()){ 
        TreeNode *pNode = curQue.front();
        curQue.pop();
        if(pNode->left != NULL) nextQue.push(pNode->left); 
        if(pNode->right != NULL) nextQue.push(pNode->right);
        v.push_back(pNode->val);
        if(curQue.empty()){
            result.push_back(v);
            v.clear();
            while(!nextQue.empty()){
                curQue.push(nextQue.front());
                nextQue.pop();
            }
        }
    }
    return result;        
    }
}
