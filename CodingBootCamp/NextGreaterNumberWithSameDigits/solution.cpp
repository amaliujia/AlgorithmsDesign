#include <iostream>
#include <string>
using namespace std;

// To execute C++, please define "int main()"

string nextGreaterNum(string s){
  int i;
  for(i = s.size() - 2; i >= 0; i--){
    if(s[i] < s[i+1]){
      break;
    }
  }
  
  if(i < 0){
    return "Not Possible";
  }
  
  char max_c = 'a';
  int index = -1;
  
  for(int j = s.size() - 1; j > i; j--){
    if(s[j] > s[i] && s[j] < max_c){
      max_c = s[j];
      index = j;
    }
  }
  
  char temp = s[i];
  s[i] = max_c;
  s[index] = temp;
  
  // sort the right side of element i.
  
  for(unsigned int j = i + 1; j < s.size(); j++){
    for(unsigned int k = j + 1; k < s.size(); k++){
        if(s[j] > s[k]){
          swap(s[j], s[k]);
        }
    }
  }

  return s;
  
}

int main() {
  string s = "59876";
  
  // expect "65789"
  cout << nextGreaterNum(s)<<endl;
}

