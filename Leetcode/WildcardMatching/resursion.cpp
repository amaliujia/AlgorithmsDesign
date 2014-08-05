/* 
	O(n! * m!) time
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
      return innerMatch(s, p);  
    }
    
	bool innerMatch(const char *a, const char *b){
		 if((*a == '\0' && *b != '\0') || (*a != '\0' && *b == '\0')){
		     return false;
		 }
    
		if(*a == '\0' && *b == '\0'){
			 return true;
		 }
    
		if(*b == '?'){
			 return innerMatch(a + 1, b + 1);
		}
    
		if(*b != '*'){
			 if(*a != *b){
			     return false;
			}else{
				 return innerMatch(a + 1, b + 1);
			}
		}
    
		int offset = 0;
    
		while(1){
		 if(innerMatch(a + offset, b + 1)){
		     return true;
		 }else{
		     offset++;
		     if(*(a + offset) == '\0' && *(b + 1) != '\0'){
	             return false;
		     }
        }
    }
	 return false;
 }
};
