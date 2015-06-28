class Stack {
public:
    Stack(){
        quetop = -1;
    }

    // Push element x onto stack.
    void push(int x) {
        que1.push(x);
        quetop = x;
    }

    // Removes the element on top of the stack.
    void pop(void) {
        topOfQue(que1, que2);
        if(!que1.empty()){
            que1.pop();
            quetop = -1;
        }
        transferQuetoQue(que2, que1);
    }

    // Get the top element.
    int top(void) {
        return quetop;
    }

    // Return whether the stack is empty.
    bool empty(void) {
        return que1.empty();
    }
    
private:
    std::queue<int> que1;
    std::queue<int> que2;
    int quetop;
    
    void transferQuetoQue(queue<int> &q1, queue<int> &q2){
        while(!q1.empty()){
            int a = q1.front();
            quetop = a;
            q1.pop();
            q2.push(a);
        }
    }
    
    void topOfQue(queue<int> &q1, queue<int> &q2){
        while(!q1.empty() && q1.size() > 1){
            int a = q1.front();
            q1.pop();
            q2.push(a);
        }
    }
};
