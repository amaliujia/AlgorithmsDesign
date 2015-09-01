class Solution {
  public:
    int calculate(string s) {
      stack<int> nums;
      stack<char> ops;

      int num = 0;
      int res = 0;
      s.push_back(')');
      ops.push('+');

      for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
          num = num * 10 + s[i] - '0'; 
        }else if(s[i] == ' '){
          continue;
        }else{ 
          if(!ops.empty()){
            switch(ops.top()){
              case '*':
              case '/':
                num = ops.top() == '*' ? num * nums.top() : nums.top() / num;
                ops.pop();
                nums.pop();
            }
          }

          nums.push(num);
          ops.push(s[i]);
          num = 0;
        }
      }
      ops.pop();
      while(!ops.empty()){
        res += ((ops.top() == '-') ? -nums.top() : nums.top());
        ops.pop();
        nums.pop();
      }

      return res;
    }
};
