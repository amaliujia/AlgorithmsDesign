public ArrayList<ArrayList<Integer>> getSubByIteration(ArrayList<Integer> set){
	ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
	int count = 1 << set.size();
	for(int i = 0; i < count; i++){
		ArrayList<Integer> temp = nextSub(i, set);
		result.add(temp);
	}
	return result;
}

public ArrayList<Integer> nextSub(int x,ArrayList<Integer> set){
	ArrayList<Integer> temp = new ArrayList<Integer>();
	int index = 0;
	for(int i = x; i > 0; i >> 1){
		if(i & 1 == 1){
			temp.add(set.get(index));	
		}
		index++;
	}
	return temp;
}
