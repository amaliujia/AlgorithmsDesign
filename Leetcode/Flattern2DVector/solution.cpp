#include <vector>
#include <iostream>
using namespace std;

class Vector2D {
  private:
    int row;
    int column;
    int pre_row;
    int pre_column;
    vector<vector<int> > v;
  public:
    Vector2D(vector<vector<int> >& vec2d) {
      v = vec2d;
      row = 0;
      column = 0;
    }

    int next() {
      int res = v[row][column];
      pre_row = row;
      pre_column = column;
      column++;
      return res;
    }
    
    void remove() {
      v[pre_row].erase(v[pre_row].begin()+pre_column);  
      row = pre_row;
      column = pre_column;
    }
    
    bool hasNext() {
      while(row != v.size()){
        if(column == v[row].size()){
          row++;
          column = 0;
        }else{
          return true;
        }
      }
      return false;
    }
};

int main(){
  cout << "hello" << endl;
}
