bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x / 10 == 0) return true;
        if(reverse(x) != -1) return reverse(x) == x;
    }
    int reverse(int x) {
       int intermedia = 0;
       int result = 0;
       bool isNegative = x < 0 ? true : false;
      if(x > pow(2,31) || x < (-pow(2,31)))
      {
          return -1;
      }
       if(isNegative){
           x = -x;
       }
       
       while(x != 0)
       {
           intermedia = x - x / 10 * 10;
           result = result * 10 + intermedia;
           x = x / 10;
       }
       if(result < 0) {return -1;}
       
       if(isNegative)
       {
          result = -result;
       }
       return result;
    }
