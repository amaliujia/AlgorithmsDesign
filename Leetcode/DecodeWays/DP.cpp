int numDecodings(string s){
	if(s.empty() || s[0] == '0')	return 0;
	if(s.length() == 1)	return 1;
	
	int f0 = 0, f1 = 0, f2 = 1;
	f1 = check(s[0]) * check(s[1]) + check(s[0], s[1]);	
	for(int i = 2; i < s.length(); i++){
		if(check(s[i]))	f0 += f1;
		if(check(s[i - 1], s[i]))	f0 += f2;
		if(f0 == 0)	return 0;
		f2 = f1;
		f1 = f0;
		f0 = 0;		
	}
	return f1;
}

int check(char c){
	return (c == '0') ? 0 : 1;
}

int check(char c1, char c2){
	return (c1 == '1' || (c1 == '2' && c2 <= '6')) ? 1 : 0; 
}
