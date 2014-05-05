public static int treeHeigh(Node root){
	if(root == null) return 0;
	
	return Math.max(treeHeight(root.left, root.right)) + 1;
}

public static boolean ifBalancedTree(Node root){
	if(root == null) return true;

	if(!ifBalancedTree(root.left) || !ifBalancedTree(root.right)){
		return false; 
	}	
	int heightOff = treeHeight(root.left) - treeHeight(root.right);	
	if(Math.abs(heightOff) > 1){
		return false;	
	}
	return true;	
}
