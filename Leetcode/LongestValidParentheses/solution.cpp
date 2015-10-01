// O(n) time
// O(n) space
int longestValidParentheses(string s) {
  int result = 0, last = -1;
  stack<int> c;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '('){
      c.push(i);
    }else{
      if(c.empty()){
        last = i;
      }else{
        c.pop();
        if(c.empty()){
          result = max(result, i - last); 
        }else{
          result = max(result, i - c.top());
        }
      }
    }
  }
  return result;
}
