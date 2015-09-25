class Solution {
  public:
    int myAtoi(string str) {
      if(str.length() == 0){
        return 0;
      }

      int res = 0, flag = 1, start = 0;

      while(start < str.length() && str[start] == ' '){
        start++;
      }

      if(str[start] == '-'){
        flag = -1;
        start++;
      }else if(str[start] == '+'){
        start++;
      }
      int i = start;
      for(; isdigit(str[i]) && i<str.length(); i++){
        int digit = str[i] - '0';
        if((res > INT_MAX / 10) || res * 10 > INT_MAX - digit) {
          if(flag == -1) return INT_MIN;
          return INT_MAX;
        }

        res = res*10+(int)(str[i]-'0');
      }

      return flag*res;
    }
};
