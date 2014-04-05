    int reverse(int x) {
       int intermedia = 0;
       int result = 0;
       bool isNegative = x < 0 ? true : false;
       
	   if(isNegative){
           x = -x;
       }
       
       while(x != 0)
       {
           intermedia = x - x / 10 * 10;
           result = result * 10 + intermedia;
           x = x / 10;
       }
		
	   if(result < 0)
	   {
		   return -1; //overflow, so result becomes negative which is impossible arithmetically.
	   }		

       if(isNegative)
       {
          result = -result;
       }
       return result;
    }
