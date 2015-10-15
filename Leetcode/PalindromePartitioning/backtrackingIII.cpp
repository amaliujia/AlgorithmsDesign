vector<vector><string>> partition(string s){
	vector<vector<string>> result;
	vector<string>path;
	DFS(s, path, result, 0, 1);	
	return result;
}

// s[0, prev - 1] is palindrome   
// prev indicates position between s[prev - 1], s[prev - 1], the same as start   
void DFS(string &s, vector<string> &path, vector<vector<string>> &result, size_t prev, size_t start){
	if(start == s.size()){ // at the end of string
		if(isPalindrome(s, prev, start - 1)){
			path.push_back(s.substr(prev, start-prev));
			result.push_back(path);
			path.pop_back();
		}
		return;	
	}
	DFS(s, path, result, prev, start + 1);
	if(isPalindrome(s, prev, start - 1)){
		//try to cut off
		path.push_back(s.substr(prev, start - prev));
		DFS(s, path, result, start, start + 1);
		path.pop_back();	
	}	
}

bool isPalindrome(const string &s, int start, int end){
	while(s[start] == s[end]){
		start++;
		end--;
	}
	return start >= end;
}

