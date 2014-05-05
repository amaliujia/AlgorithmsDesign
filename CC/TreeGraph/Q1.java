/*
	works but not efficient.
    for each node, we compute its subtree's height, and its subtree's subtree's height, and so on. Obviously we compute heigh of trees to much.So final time complexity is O(n^2).
	A good optimization solution is save height into tree node.Therefore it will be O(n).	
*/

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
