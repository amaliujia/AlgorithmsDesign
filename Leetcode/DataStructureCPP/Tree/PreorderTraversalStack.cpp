#include "TreeNode.h"
#include <vector>

class solution{
	public:
		vector<int> preorderTraversal(TreeNode *root){
			if(root == NULL) return NULL;
			vector<int> result;
			TreeNode *p;
			stack<TreeNode *> s;
				
			s.push(root);

			while(!s.empty()){
				p = s.top();
				s.pop();
				result.push_back(p->val);
			
				if(p->right != NULL) s.push(p->right);	
				if(p->left != NULL) s.push(p->left);
			}
			return result; 
		}
};
