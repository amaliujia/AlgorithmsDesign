public static boolean checkBinarySearchTree(TreeNode root){
	if(root == null) return true;
	
	if(root.left != null){
		if(root.left.value >= root.vaule) return false;
	}

	if(root.right != null){
		if(root.right.value <= root.value) return false;
	}

	return checkBinarySearchTree(root.left) && checkBinarySearchTree(root.right)
}
