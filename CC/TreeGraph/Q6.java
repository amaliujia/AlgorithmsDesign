public static TreeNode findNextBST(TreeNode node){
	if(node.parent == null) return null;
	
	if(node.right != null) return node.right;

	if(node.parent.left == node){
		return node.parent;
	}else{
		return findNextBST(node.parent);
	}
}
