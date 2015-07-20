class Queue {
private:
    stack<int> sa;
    stack<int> sb;
    
    void swapStack(stack<int> &a, stack<int> &b){
        while(!a.empty()){
           int temp = a.top();
           a.pop();
           b.push(temp);
        }
    }
    
public:
    // Push element x to the back of queue.
    void push(int x) {
        sa.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
      if(!sb.empty()){
          sb.pop();
      }else if(!sa.empty()){
          swapStack(sa, sb);
          sb.pop();
      } 
    }

    // Get the front element.
    int peek(void) {
      if(!sb.empty()){
          return sb.top();
      }else if(!sa.empty()){
          swapStack(sa, sb);
          return sb.top();
      }       
    }

    // Return whether the queue is empty.
    bool empty(void) {
      return sa.empty() && sb.empty();  
    }
};
