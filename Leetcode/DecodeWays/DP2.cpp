class Solution {
public:
    int numDecodings(string s) {
		if(s.empty() || s[0] == '0')	return 0;
		if(s.length() == 1)	return 1;
	
		vector<int> f(s.length(), 0);
		f[0] = 1;
		f[1] = check(s[0]) * check(s[1]) + check(s[0], s[1]);
			
		for(int i = 2; i < s.length(); i++){
			if(check(s[i])){
				f[i] = f[i - 1];	
			}

			if(check(s[i - 1], s[i])){
				f[i] += f[i - 2];	
			}	
		}
		return f[s.length() - 1]; 
	}
	
	int check(char c){
		return c == '0' ? 0 : 1;
	}

	int checkTwo(char a, char b){
		if(a == '0')	return 0;
		if(a == '1')	return 1;
		if(a == '2' && b <= '6')	return 1;
	}
};
