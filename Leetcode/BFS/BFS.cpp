//O(n) time
//O(n) space
vector<int> levelOrder(TreeNode *root){
	vector<int> result;
	if(root == NULL)	return result;

	priority_queue<int> q;
	q.push(root);
	
	while(!q.empty()){
		TreeNode *node = q.top();
		result.push_back(node->val);
		if(node->left != NULL)	q.push(node->left);
		if(node->right != NULL)	q.push(node->right);
	}
	return result;
}
