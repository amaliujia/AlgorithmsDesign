//worst case: this is a complete binary tree, the depth is n
//so, in worst case, it needs O(2^n) time
// but if we assume this tree has n nodes, then function will call at most 2n,
// so time complexity is O(n)
int maxDepth(TreeNode *root) {
    return recursiveTraverse(root);
}

int recursiveTraverse(TreeNode *node){
    if(node == NULL)    return 0;
    else
		return (max(recursiveTraverse(node->left), recursiveTraverse(node->right)) + 1);
    }
