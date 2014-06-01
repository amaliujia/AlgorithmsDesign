public ArrayList<ArrayList<Integer>> allSubsets(ArrayList<Integer> set, int index){
	ArrayList<ArrayList<Integer>> result;
	if(set.size() == index){
		result = new ArrayList<ArrayList<Integer>>();	
		result.add(new ArrayList<Integer>());	
	}else{
		ArrayList<ArrayList<Integer>> temp = new  ArrayList<ArrayList<Integer>>();
		result = allSubsets(set, index + 1);
		int newItem = set.get(index);
		for(ArrayList<Integer> sub : result){
			ArrayList<integer> newSub = new ArrayList<integer>();
			newSub.addAll(sub);
			newSub.add(newItem);
			temp.add(newSub);			
		}
		result.addAll(temp);	 
	}
	return result;
}  
