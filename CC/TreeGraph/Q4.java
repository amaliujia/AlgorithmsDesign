public static void levelList(int level, ArrayList<LinkedList<TreeNode>> lists, TreeNode root){
	if(root == null) return;

	LinkedList<TreeNode> list;

	if(level == lists.size()){
		list = new LinkedList<TreeNode>();
		lists.add(list);
	}else{
		list = lists.get(level);
	}

	list.add(root);
	levelList(level+1, lists, root.left);
	levelList(level+1, lists, root.right);
}

public static ArrayList<LinkedList<TreeNode>> levelsList(TreeNode root){
	ArrayList<LinkedList<TreeNode>> lists = new ArrayList<LinkedList<TreeNode>>();
	levelList(0, lists, root);
	return roots;
}
