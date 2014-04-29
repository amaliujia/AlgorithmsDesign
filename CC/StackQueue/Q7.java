/*
	O(n^2) time
	O(n) space	
*/

static public void sortStack(Stack<Integer> orign, Stack<Integer> target)
{	
	if(target.isEmpty) target.push(orign.pop);
	Integer registor;	
	while(!orign.isEmpty()){
		registor = orign.pop();
		while(!target.isEmpty() && registor < target.peak()){
			orign.push(target.pop());
		}
		target.push(registor);
	}
}
