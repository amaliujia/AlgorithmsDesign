/*
	check hight and check balanced can run at the same time, because condition that determine if a tree is balanced is about height. 
	
	O(n) time(recursive structure)
	O(h) space(every node needs constant space, but nodes in each height is a function f(h). So total space is O(h), h is tree height) 
*/

public static int checkHeight(TreeNode root){
	if(root == null) return 0;

	int leftHeight = checkHeight(root.left);
	if(leftHeight == -1)	return -1;

	int rightHeight = checkHeight(root.right);
	if(rightHeight == -1)	return -1;

	int heightOff = leftHeight - rightHeight;
	if(Math.abs(heightOff) > 1){
		return -1;
	}else{
		return Math.max(leftHeight, rightHeight) + 1;
	}
}

public static boolean isBalanced(Node root){
	if(checkHeight(root) == -1){
		return false;
	}else{
		return true;
	}
}	
