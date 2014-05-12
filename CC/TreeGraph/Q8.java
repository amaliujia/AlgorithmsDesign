/*
	n is the number of node in big tree
	m is the number in small tree
	k is number of occurance of small tree's root in big tree

	worst case: O(n + km). Adding n is because we have to traverse all nodes in big tree. km is each time we find one occurance of small root in big tree, we need to traverse every node in small tree.

	As for space, there is no doubt that it should be O(log(n) + log(m))
*/

public boolean checkSubTree(TreeNode *big, TreeNode *small){
	if(!small) return true;

	return subTree(big, small);
}	

public boolean subTree(TreeNode *big, TreeNode *small){
	if(!big) return false;

	if(big.data == small.data){
		if(match(big,small)) return true;
	}

	return (subTree(big.left, small) || subTree(big.right, small)); 
}

public boolean match(TreeNode *n1, TreeNode *n2){
	if(n1 == null && n2 == null) return true;

	if(n1 == null || n2 == null) return false;

	if(n1.data != n2.data) return false;

	return (match(n1.left, n2.left) && match(n1.right), n2.right); 
}
