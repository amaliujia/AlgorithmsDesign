public static TreeNode findNextBST(TreeNode node){
	if(node.parent == null) return null;
	
	if(node.right != null) return leftMostChild(node.right);
	else{
		TreeNode pre = node;
		TreeNode x = node.parent;
		while(x != null && x.left != node){
			pre = x;
			x = x.parent;
		}
		return x;		
	}
}

public static TreeNode leftMostChild(TreeNode n){
	while(n.left != null)
		n = n.left;
	return n;	
}
