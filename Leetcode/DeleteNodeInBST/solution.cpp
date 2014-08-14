// Mathematical expectancy O(logn)
// But worse case O(n) 
TreeNode deleteNode(TreeNode *root, int val){
	TreeNode dummyNode;
	dummyNode.left = root,
	findAndDelete(&dummyNode, dummyNode.left, val);
	return dumyNode.left; 	
}

void findAndDelete(TreeNode *parent, TreeNode *node, int val){
	if(node == NULL)
		return;
	if(node->val == val){
		deleteAndReconstructe(parent, node);	
	}else if(node->val < val){
		findAndDelete(node, node->right, val);	
	}else{
		findAndDelete(node, node->left, val);
	}
}

void deleteAndReconstructe(TreeNode *parent, TreeNode *node){
	if(node->left == NULL){
		if(parent->right == node){
			parent->right = node->right;
		}else{
			parent->left = node->right;			
		}
	}else{
		TreeNode *maxNodeParent = node;
		TreeNode *maxNode = node->left;	

		//find the maximum ndoe in the left sub tree
		while(maxNode->right != NULL){
			maxNodeParent = maxNode;
			maxNode = maxNode->right;
		}
		if(maxNodeParent->left == maxNode){
			maxNodeParent->left = maxNode->left;
		}else{
			maxNodeParent->right = maxNode->left;
		}
		//move to node
		maxNode->left = node->left;
		maxNode->right = node->right;
		if(parent->left == node){
			parent->left = maxNode;
		}else{
			parent->right = maxNode;
		}
	}		
}
