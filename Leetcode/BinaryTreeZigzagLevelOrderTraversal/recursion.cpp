//O(n) time
//O(n) space

vector<vector<int> > zigzagLevelOrder(TreeNode *root){
	vector<vector<int>> result;
	traverse(root, 1, result, true);
	return result;	
}

void traverse(TreeNode *node, int level, vector<vector<int>> &result,
			  bool left)
{
	if(node == NULL)	return;	

	if(level > result.size()){
		result.push_back(vector<int>());
	}

	if(left){
		result[level - 1].push_back(node->val);
	}else{
		result[level - 1].insert(result[level - 1].begin(), node->val);
	}
	
	traverse(node->left, level + 1, result, !left);
	traverse(node->right, level + 1, result, !left);
}
