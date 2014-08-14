// O(n) time
TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q){
	if(root == NULL)	return NULL;
	if(root == p || root == q)	return root;
	
	TreeNode *left = LCA(root->left, p, q);
	TreeNode *right = LCA(root->right, p, q);

	if(left && right)	return root;
	return left ? left : right;		
}
