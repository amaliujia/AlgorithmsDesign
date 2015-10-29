#include <vector>
using namespace std;

void getZeroOne(vector<int>& vec){
  if(vec.size() < 2){
    return;
  }
  int count[2];
  count[0] = 0;
  count[1] = 0;

  int i = 0;
  int j = -1;
  int cur = 1 - vec[i];
  count[vec[i]] = 1; 
  // 0110000111
  // cur is the number we are trying to find to put it on the right side 
  while(j < vec.size()){
    j++;
    count[vec[j]]++; 
     
    if(vec[j] == cur){
      // find one that should put on the right side
      if(count[0] == count[1]){ // say 0011
        //print
        while(vec[i] != cur){
           count[1-cur]--;
           i++;
        } 
      }
    }else{
      if(count[cur] == 0){// 00 this case
        count[1-cur]++; 
      }else{ //000110 this case
        while(vec[i] != cur){
             count[1-cur]--;
             i++;

             if(count[0] == count[1]){
              //print
             }
        }        

       cur = vec[j]; 
      } 
    } 
  } 
}
