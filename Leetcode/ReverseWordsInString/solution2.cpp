string reverseWords(string &s){
	string result;
	int i = s.length() - 1;

	while(i >= 0){
		while(s[i] == ' ' && i >= 0){
			i--;
		}
		if(i < 0){
			break;
		}
		
		if(result.length() != 0){
			result.push_back(' ');
		}
		string temp;
		while(s[i] != ' ' && i >= 0){
			temp.push_back(s[i]);
			i--;
		}
		reverse(temp.begin(), temp.end());
		result.append(temp);	
	}
	return result;
}
