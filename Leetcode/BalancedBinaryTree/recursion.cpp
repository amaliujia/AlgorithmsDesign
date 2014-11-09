bool isBalanced(TreeNode *root){
	if(getNodeDepth(root) == -1)
		return false;
	return true;
}

int getNodeDepth(TreeNode *node){
	if(node == NULL)	return 0;
	
	int lHeight = getNodeDepth(node->left);
	if(lHeight == -1)	return -1;

	int rHeight = getNodeDepth(node->right);
	if(rHeight == -1)	return -1;
		
	if(abs(lHeight - rHeight) > 1){
		return -1;
	}
	return rHeight > lHeight ? rHeight + 1 : lHeight + 1; 			
}
