/*
	O(nlogn) time

*/

class TreeNode{
	int val;
	TreeNode Left;
	TreeNode right;

	public TreeNode(int value){
		val = value;
	}
}

public static TreeNode BinarySearchTree(ArrayList list){
	TreeNode root;
	DivideConque(list, 0, list.size()-1, root);
	return root;		
}

public static void DivideConque(ArrayList list, int begin, int end, TreeNode inter){
	if(begin > end) return;

	int middle = (begin + end) / 2;

	inter = new TreeNode(list.get(middle));

	DivideConque(list, begin, middle-1, inter.left);
	DivideConque(list, middle+1, end, inter.right);	
}
