class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      stack<int> operands;

      for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] == "+" ||
            tokens[i] == "-" ||
            tokens[i] == "*" ||
            tokens[i] == "/"){
          int left_op = operands.top();
          operands.pop();
          int right_op = operands.top();
          operands.pop();

          if(tokens[i] == "+"){
            operands.push(left_op + right_op);                   
          }

          if(tokens[i] == "-"){
            operands.push(right_op - left_op);                   
          }

          if(tokens[i] == "*"){
            operands.push(left_op * right_op);                   
          }

          if(tokens[i] == "/"){
            operands.push(right_op / left_op);                   
          }
        }else {
          operands.push(stoi(tokens[i]));
        }
      }
      return operands.top();
    }
};
