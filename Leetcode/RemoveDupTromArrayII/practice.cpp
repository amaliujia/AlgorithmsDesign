#include <vector>
#include <assert.h>

using namespace std;

int RemoveDuplicateFromArrayTwo(vector<int>& n, int c){
  if (c <= 0) return 0;
  int i = 0, j = 0, cur = INT_MAX;
  int occur = 0; 
  while (j < n.size()) {
    if (n[j] == cur && occur < c) {
       n[i] = n[j];
       i++;
       occur++; 
    } else if (n[j] != cur) {
        n[i] = n[j];
        occur = 1;
        cur = n[j];
        i++;
    } 
    j++; 
  }

  return i;
}


int main() {
  vector<int> test;
  test.push_back(1);
  test.push_back(2);
  test.push_back(2);
  test.push_back(2);
  test.push_back(2);
  test.push_back(3);
  test.push_back(3);
  test.push_back(3);
  int len = RemoveDuplicateFromArrayTwo(test, 3);

  assert(len == 7);
  assert(test[0] == 1);
  assert(test[3] == 2);
  assert(test[6] == 3);
  return 0;
}
