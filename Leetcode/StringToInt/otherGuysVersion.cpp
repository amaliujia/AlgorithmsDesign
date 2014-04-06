/*
	Thanks for code of @feliciafay
	link: http://blog.csdn.net/feliciafay/article/details/17111231
*/

int atoi(const char *str)
{
	long long result = 0;
	int index = 0;
	bool is_positive = true;
	//long long long_int_min_abs = INT_MIN;
	//long_int_min_abs = 0 - INT_MIN;
	while(str[index] == ' '){
		index++;
	}
	if(str[index] == '\0'){
		return 0;
	}
	if(str[index] == '+'){
		is_positive = true;
		index++;
	}else if(str[index] == '-'){
		index++;
	}else if((str[index] - '0' >= 0) && (str[index] - '0' <= 9)){
		is_positive = true;
	}else{
		return 0;
	}

	while((str[index] - '0' >= 0) && (str[index] - '0' <= 9)){
		int digit = str[index] - '0';
		result = result * 10 + digit;
		index++;
		
		if((result > INI_MAX) && (is_positive == true)){
			return INT_MAX;
		}
		if((result > INT_MAX) && (is_positive == false)){
			return INT_MIN;
		}
	}
		
	if(is_positive == false){
		result = -result;
	}
	return result;
}
