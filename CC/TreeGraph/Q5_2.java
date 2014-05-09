/*
	if BST doesn't have duplicate values, we can save BST values by in-order traversal in a array. Then to check if this array is sorted. 
*/

public static int index = 0;

public static void arrayFromBST(TreeNode root, int[] array){
	if(root == null) return null;

	arrayFromBST(root.left. array);
	array[index++] = root.data;
	arrayFRomBST(root.right, array);
}

public static boolean checkBST(TreeNode root){
	int[] array = new int[root.size];
	arrayFromBST(root, array);
	for(int i = 1; i < array.length; i++){
		if(array[i] <= array[i-1]) return false;
	}
	return true;	
}
