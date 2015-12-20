#include <iostream>
using namespace std;

int log(int a, int b){
  if(a == 0 && b != 0) return -1;
  if(a == 0 && b == 0) return 0; 

  int s = 0;
  int e = b;
  int cur = 1;
  while(cur < b){
    n++;
    cur *= a;
  } 

  if(cur == b){
    return n;
  }else{
    return -1;
  }
}

int main(){
  cout << log(2,8) << endl;
}
