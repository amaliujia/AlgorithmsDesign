public static boolean checkBST(TreeNode root){
	return checkSingleNode(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
}

public static boolean checkSingleNode(TreeNode root, int min, int max){
	if(root == null) return true;

	if(root.data <= min || root.data > max) return false;

	if(!(checkSingleNode(root.left, min, root.data) && checkSingleNode(root.right, root.data, max))) return false; 

	return true;
}
