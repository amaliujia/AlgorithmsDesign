class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL){
            return;
        }
        
        root->next = NULL;
        std::queue<TreeLinkNode *> queFirstLevel;
        std::queue<TreeLinkNode *> queNextLevel;
        queFirstLevel.push(root);
        
        while(!queFirstLevel.empty()){
            TreeLinkNode * pNode = queFirstLevel.front();
            queFirstLevel.pop();
            
            if(pNode->left != NULL){
                queNextLevel.push(pNode->left);
            }
                
            if(pNode->right != NULL){
                queNextLevel.push(pNode->right);
            }
            
            if(!queFirstLevel.empty()){
                pNode->next = queFirstLevel.front();
            }else{
                queFirstLevel.swap(queNextLevel);
            }
        }
    }
};
