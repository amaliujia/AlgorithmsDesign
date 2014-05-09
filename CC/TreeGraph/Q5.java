public static int last = Integer.MIN_VALUE;

public static boolean checkBinarySearchTree(TreeNode root){
	if(root == null) return true;

	if(!checkBinarySearchTree(root.left)) return false;
	
	if(root.data <= last) return false;
	last = root.data;

	if(!checkBinarySearchTree(root.right)) return false;	

		
}
