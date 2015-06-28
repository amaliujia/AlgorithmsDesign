class MinStack {
public:
    void push(int x) {
        elementsStack.push(x);
        if(minElementsStack.empty() || (x <= minElementsStack.top())){
            minElementsStack.push(x);
        }
    }

    void pop() {
        if(elementsStack.size() == 0){
            return;
        }
        int x = elementsStack.top();
        elementsStack.pop();
        if(!minElementsStack.empty() && x == minElementsStack.top()){
            minElementsStack.pop();
        }
    }

    int top() {
        if(elementsStack.size() == 0){
            return 0;
        }
        return elementsStack.top();
    }

    int getMin() {
        if(minElementsStack.size() == 0){
            return 0;
        } 
        return minElementsStack.top();
    }
    
private:
    std::stack<int> minElementsStack;
    std::stack<int> elementsStack;
};
