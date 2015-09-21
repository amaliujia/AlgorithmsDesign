/*
	the longestPalindrome by Dynamic programming.
	time complexity(n^2)
	space compexity(n^2)
*/

string longestPalindromeDP(string s) {
	int len = s.length();
	int maxLen = 1;
	int maxStringStart = 0;
	bool table[1000][1000] = { false };
	
  for(int i = 0; i < len-1; i++){
		table[i][i] = true; 
	}

	for(int i = 0; i <len-2; i++){
		if(s[i] == s[i+1]){
			table[i][i+1] = true;
			maxStringStart = i;
			maxLen = 2;
		}
	}

	for(int len = 3; len <= n; len++){
		for(int i = 0; i < n-len+1; i++){
			int j = i+len-1;
			if(s[i] == s[j] && table[i+1][j-1] == true){
				table[i][j] = true;
				maxStringStart = i;
				maxLen = len;
			}
		}
	}
	return s.substr(maxStringStart, maxLen);
}
