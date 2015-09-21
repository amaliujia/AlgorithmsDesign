class Solution {
  public:
    bool isPalindrome(int x) {
      if(x < 0){
        return false;
      }else if(x / 10 == 0){
        return true;
      }else if(reverse(x) != -1){
        return reverse(x) == x;
      }else{
        return false;
      }
    }

    int reverse(int x){
      if(x > pow(2,31) || x < (-pow(2,31)-1)){   
        return -1;
      }

      int intermediate = 0;
      while(x != 0){
        int c = x % 10;
        x = x / 10;
        intermediate = intermediate * 10 + c;
      }

      return intermediate;
    }

};
