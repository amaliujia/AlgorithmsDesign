// O(2^n)

vector<vector<int>> subsets(vector<int> &S){
	vector<vector<int>> result;
	vector<int> empty;
	solver(result, S, v, 0);	
	return result;
}

void solver(vector<vector<int>> result, vector<int> &S, vector<int> &v, int pos){
	result.push_back(v);
	
	int n = S.size();	
	for(int i = pos; i < n; i++){
		v.push_back(S[i]);
		solver(result, S, v, pos + 1);
		v.pop_back();	
	}	
} 
