class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
      if(n == 0){
          return *generate(1, 0);
      }  
      return *generate(1, n);
    }

private:
    vector<TreeNode*>* generate(int start, int end){
       vector<TreeNode*>* v = new vector<TreeNode*>();
       if(start > end){
           v->push_back(NULL);
           return v;
       }
       
       for(int i = start; i <= end; i++){
          vector<TreeNode*>* lv = generate(start, i - 1);
          vector<TreeNode*>* rv = generate(i + 1, end);
          
          for(int j = 0; j < lv->size(); j++){
              for(int k = 0; k < rv->size(); k++){
                 TreeNode *node = new TreeNode(i);
                 node->left = (*lv)[j];
                 node->right = (*rv)[k];
                 v->push_back(node);
              }
          }
          
          delete lv;
          delete rv;
       }
       return v;
    }
};
