class solution{
public:
	vector<int> postorderTraversal(TreeNode *root){
		vector<int> result;
		const TreeNode *cur, *pre;
		stack<const TreeNode *> s;

		cur = root;
	
		do{
			while(cur != NULL){
				s.push(cur);
				cur = cur->left;
			}
			pre = NULL;
			while(!s.empty()){
				cur = s.top();
				s.pop();
				if(cur->right == pre){
					result.push_back(cur->val);
					pre = cur;
				}else{
					s.push(cur);
					cur = cur->right;
					break;
				}	
			}

		}while(!s.empty());
		return result;
	}
};

