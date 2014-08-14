// O(n^2) time worst case(degenerate tree)
// O(n) time best case(balanced tree), becase every count will just traverse half nodes of last traversal, and it keep searching log(n) time. So the worse case for balanced search tree is to traverse every node once.

TreeNode *LCA(TreeNode *root, TreeNode *left, TreeNode *right){
	if(root == NULL)	return NULL;
	if(root == left || root == right)	return root;
	int c = countNode(root->right, left, right);
	if(c == 1){
		return root;
	}else if(c == 2){
		return LCA(root->right, left, right);
	}else{
		return LCA(root->left, left, right);
	}	
}

int countNode(TreeNode *root, TreeNode *left, TreeNode *right){
	if(root == NULL)	return 0;
	int c = countNode(root->left, left, right) +
			countNode(root->right, left, right);
	if(root == left || root == right)
		return 1 + c;
	return c;	
}
