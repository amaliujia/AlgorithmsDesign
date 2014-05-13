/*
	time complexity O(nlogn)
	space complexity O(logn), size of values array is a constant.
*/
public int findDepth(TreeNode root){
	if(root == null) return 0;

	return 1 + Math.max(findDepth(root.left), findDepth(root.right));
}

public void solution(TreeNode root, int sum){
	int depth = findDepth(root);
	int[] values = new int[depth];
	findSum(root, values, sum, 0);	
}

public void findSum(TreeNode root, int[] values, int sum, int level){
	if(root == null) return;

	values[level] = root.data;

	int temp = 0;
	for(int i = level; i >= 0; i--){
		temp += values[i];
		if(temp == sum){
			printPath(valuse, i, level);
		}	
	}

	findSum(root.left, values, sum, level+1);
	findSum(root.right, values, sum, level+1);
}


public void printPath(int[] values, int start, int end){
	for(int i = start, i <= end; i++){
		System.out.print(values[i] + " ");
	}
	System.out.println();
} 

