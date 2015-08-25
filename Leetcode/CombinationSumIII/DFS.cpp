class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> result;
      vector<int> temp;
      int sum = 0;
      recursive(result, temp, sum, n, k, 0, 1);
      return result;
    }

  private:
    void recursive(vector<vector<int>>& result, vector<int>& temp, int& sum, int n, int k, int c, int i){
      if(c + 1 == k){
        for(int j = i; j <= 9; j++){
          if(sum + j == n){
            temp.push_back(j);
            result.push_back(temp);
            temp.pop_back();
          }else if(sum + j > n){
            return;
          }
        }
      }else{
        sum += i;
        temp.push_back(i);

        for(int j = i + 1; j <= 9; j++){
          recursive(result, temp, sum, n, k, c + 1, i + 1);      
        }
        sum -= i;
        temp.pop_back();
      }
    }
};
