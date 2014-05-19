class Solution{
public:
	string countAndSay(int n){
		string s("1");
		while(--n){
			s = nextSequence(s);
		}
		return s;
	}

	string nextSequence(string s){
		stringstream ss;
		int len = s.length();
		for(int i = 0; i < len;){
			int j = i;
			while(((j+1) < len) && (s[j] == s[j+1])){
				j++;
			}
			ss << (j - i + 1) << s[i];
			i = j + 1;
		}
		return ss.str();
	}
};


