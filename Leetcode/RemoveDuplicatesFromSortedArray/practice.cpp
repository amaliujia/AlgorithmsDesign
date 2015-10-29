#include <vector>
#include <assert.h>

using namespace std;

int removeDuplicateFromArray(vector<int>& v) {
  int i = 0;
  int j = 0;
  int cur = INT_MAX; 
  
  while (j < v.size()) {
    if (cur != v[j]) {
        cur = v[j];
        v[i] = v[j];
        i++; 
    }
    j++; 
  }

  return i;
}


int main(){
  vector<int> test;
  test.push_back(1);
  test.push_back(1);
  test.push_back(1);
  test.push_back(1);
  test.push_back(2);
  int len = removeDuplicateFromArray(test);
  assert(len == 2);
  assert(test[0] == 1);
  assert(test[1] == 2);
  return 0; 
}
