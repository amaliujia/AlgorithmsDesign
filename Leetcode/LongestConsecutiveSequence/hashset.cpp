// O(n) time
// but O(n) space

int longestConsecutive(vector<int> &num){
	unordered_set<int> s;
	int maxLen = 1;

  for(auto i : num)
     s.insert(i);

	for(auto i : num){
		auto left = i - 1;
		auto right = i + 1;
		int count = 1;
		unordered_set<int>::iterator it;
		while((it = s.find(left)) != s.end()){
			count++;
			s.erase(*it);
			left--;	
		}
		while((it = s.find(right)) != s.end()){
			count++;
			s.erase(*it);
			right++;
		}
		maxLen = max(count, maxLen); 
	}
	return maxLen;
}
