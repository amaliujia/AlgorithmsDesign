// Naive way: O(n^2) time to each eacy pair
// more smarter way, sort it first, and then use two pointer from head and tail to scan.
// Most efficient is to use hashtable

// assume there are no duplicates in array
vector<int> twoSum(vector<int> &number, int target){
	unordered_map<int, int> table;
	vector<int> result;	
	for(int i = 0; i < number.size(); i++){
		table[target - number[i]] = i;
	}
	for(int i = 0; i < number.size(); i++){
		if(table[target - num[i]]){
			result.push_back(i + 1);
			result.push_back(table[target - num[i]]);
			break;
		}			
	}	
	return result;	
}


//assume there exits duplicates 
