class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int>> result;
		if(!root) return result;
		
		queue<TreeNode *> p, q;
		vector<int> curLevel;
	
		p.push(root);
			
		while(!p.empty()){
			while(!p.empty()){		
				TreeNode *node = p.front();
				p.pop();
				curLevel.push_back(node->val);
				if(node->left != NULL) q.push(node->left);
				if(node->right != NULL) q.push(node->right);
			}
			result.push_back(curLevel);
			curLevel.clear();
			std::swap(q, p);
		}
		return result;
	}	
}
