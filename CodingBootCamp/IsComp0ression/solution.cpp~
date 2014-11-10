// input of this function will be two string, one is uncompressed, another is compressed. I need to determine if second one comes from first one.

// for expample: 
// sailing -> s6   true
// sailing -> 6g true

bool isCompression(string s1, string s2){
	if(s1.length() == 0 && s2.length() == 0)	return true;
	if(s1.length() == 0 || s2.length() == 0)	return false;

	int i = 0;
	int j = 0;
	while(i < s2.length()){
		if('0' < s2[i] && s[2] < '9'){
			j + = s2[i] - '0' + 1;
		}else{
			if(s1[j] != s2[i]){
				return false;
			}else{
				i++;
				j++;
			}
		}
	}
	if(j < s1.length())	return false;
	return true;
}
