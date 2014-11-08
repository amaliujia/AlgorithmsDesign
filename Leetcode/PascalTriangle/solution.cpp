vector<vector<int>> generate(int numRows){
	vector<vector<int>> result;
	vector<int> v;
	v.push_back(1);
	result.push_back(v);
	if(numRows == 1)	return result;
	
	for(int i = 1; i < numRows; i++){
		vector<int> temp;
		for(int j = 0; j < v.size(); j++){
			if(j == 0)	temp.push_back(v[0]);
			else{
				temp.push_back(v[j - 1] + v[j]);	
			}
			temp.push_back(1);
		}
		result.push_back(temp);
		v = temp;	
	}	
	return result;	
}
