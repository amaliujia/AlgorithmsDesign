#include <iostream>
using namespace std;

#define MAX_COUNT 100

class stack{
private:
    int stackItem[MAX_COUNT];
    int linkMaxInstructor[MAX_COUNT];
    int maxInstructor;
    int stackTop;
public:
    stack(){maxInstructor=-1;stackTop=-1;}
    void push(int i);
    int pop();
    int MAX();
    bool empty();
};

bool stack::empty(){
    if (stackTop==-1) {
        return true;
    }else{
        return false;
    }
}
int stack::pop(){
   
    if (stackTop<=0) {
        return -10000;
    }
    
    if (maxInstructor>=0) {
        maxInstructor=linkMaxInstructor[stackTop];
    }
    return stackItem[stackTop--];
}
void stack::push(int i){
    stackTop++;
    if (stackTop<MAX_COUNT) {
        stackItem[stackTop]=i;
    }else{
        return;
    }
    
    if (i>MAX()) {
        linkMaxInstructor[stackTop]=maxInstructor;
        maxInstructor=stackTop;
    }else{
        linkMaxInstructor[stackTop]=-1;
    }
}

int stack::MAX(){
    if (maxInstructor>=0) {
        return linkMaxInstructor[maxInstructor];
    }else{
        return -1000;
    }
}



class queue{
private:
    stack a,b;
    
public:
    void insertInQueue(int i);
    int popFromQueue(int i);
    int MAX();
};

void queue::insertInQueue(int i){
    b.push(i);
}

int queue::popFromQueue(int i){
    if (!a.empty()) {
       return a.pop();
    }else{
        while (!b.empty()) {
            a.push(b.pop());
        }
       return a.pop(); 
    }
}

int queue::MAX(){
    if (a.MAX()>=b.MAX()) {
        return a.MAX();
    }else{
        return b.MAX();
    }
}
