int candy(vector<int> &ratings) {
	const int n = ratings.size();
	vector<int> increment(n);

	for(int i = 1, inc = 1; i < n; i++){
		if(rating[i] > ratings[i - 1]){
			increment[i] = max(inc++, increment[i]);
		}else{
			inc = 1;
		}
	}

	for(int i = n - 2, inc = 1; i >= 0; i--){
		if(ratings[i] > ratings[i + 1]){
			increment[i] = max(inc++, increment[i]);
		}else
			inc = 1;	
	}
	return accmulate(&increment[0], &increment[0] + n, n); 
}
