TreeNode *Delete(TreeNode *root, int data){
	if(root == NULL)	return root;
	else if(data < root->data)	root->left = Delete(root->left, data);
	else if(data > root->data)	root->right = Delete(root->right, data);
	else{
		//case 1: No child
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}else if(root->left == NULL){ //case 2: one child
			TreeNode *temp = root;
			root = root->right;
			delete temp;
			return root;
		}else if(root->right == NULL){
			TreeNode *temp = root;
			root = root->left;
			delete temp;
			return root;
		}else{ //case 3: two children
			TreeNode *temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);			
			return root;
		}
	}
	return root;				
}
