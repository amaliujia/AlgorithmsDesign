vector<vector<int>> permute(vector<int> &num){
	vector<vector<int>> permutations;
	vector<int> empty;
	getPermute(permutations, num, empty, num.size());
	return permutations;
}

void getPermute(vector<vector<int>> &permutations, vector<int> &num, vector<int> &v, int level){
	if(level == 0){
		permutations.push_back(v);
		return;	
	}
	int n = num.size();	
	for(auto i : num){
		auto pos = find(v.begin(), v.end(), i);
		if(pos == v.end()){
			v.push_back(i);
			getPermute(permutations, num, v, level - 1);
			v.pop_back();
		}
	}
} 
