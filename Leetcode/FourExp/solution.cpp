#include <iostream>
using namespace std;

bool ifFour(int a){
  bool hasOne = false; 
  while(a != 0){
    if((a & 0x01) == 1){
       if(hasOne){
          return false; 
       }else{
        hasOne = true;
       }
    }
    a = a >> 1;
    if((a&0x01) == 1){
      return false;
    } 
    a = a >> 1;
  } 

  return hasOne; 
}

int main(){
  int test = 0;
  cout << "num: ";
  cin >> test;
  if(ifFour(test)){
      cout << "Yes it is!" << endl;
  }else{
      cout << "No...." << endl;
  }
  return 0;
}
