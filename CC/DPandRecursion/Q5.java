public ArrayList<String> getPermutations(String str){
	if(str == null) return null;

	ArrayList<String> permutations = new ArrayList<String>();
	if(str.length() == 0){
		permutations.add("");
		return permutations;
	}
	
	char inserter = str.charAt(0);
	ArrayList<String> subset = str.subString(inserter);
	for(String sub : subset){
		for(int i = 0; i <= sub.length(); i++){
			String s = insertCharAt(sub, inserter, i);
			permuations.add(s);
		}
	}
	return permutations;	
}

public String insertCharAt(String sub, char inserter, int i){
	String beginning = sub.subString(0, i);
	String end = sub.subStringh(i);
	return beginning + inserter + end;	
}
