#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Operand{
public:
   virtual void* getData() = 0;
};

class Operator{
public:
  virtual int getNum() = 0;
  virtual Operand* execute(vector<Operand*> ops) = 0; 
};

class Integer : public Operand{
private:
  int data;
public:
  Integer(int d) {
    this->data = d;
  }

  void* getData() {
    return (void *)&data;
  }
};
  
class Addition {
public:
   int getNum(){
    return 2;
   }

   Operand* exectue(vector<Operand*> ops) {
      int sum = 0;
      for(Operand* o : ops){
        sum += *(int *)o->getData();
        delete o; 
      }

      Operand* res = new Integer(sum);
      return res;
   }
};

class Cal{
private:
  stack<Operand*> ops;
  stack<Operator*> opr;
  
  void addOperand(Operand *o){
    this->ops.push(o);
  }    
  
  void addOperator(Operator *o){
    this->opr.push(o);
  }

public:
  void exectue(string input){
    
  } 
};

int main(){
  return 0;
}


