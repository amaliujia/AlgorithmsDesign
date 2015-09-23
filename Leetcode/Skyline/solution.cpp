class Solution {
  public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
      vector<pair<int, int>> heights;
      vector<pair<int, int>> result;
      for(auto &b : buildings){
        heights.push_back(pair<int, int>(b[0], -b[2]));
        heights.push_back(pair<int, int>(b[1], b[2]));
      }

      sort(heights.begin(), heights.end());

      multiset<int> heap;
      int cur = 0, pre = 0;
      heap.insert(0);

      for(auto &h : heights){
        if(h.second < 0){
          heap.insert(-h.second);
        }else{
          heap.erase(heap.find(h.second));
        }

        cur = *heap.rbegin();
        if(cur != pre){
          result.push_back(pair<int, int>(h.first, cur));
          pre = cur;
        }
      }

      return result;
    }
};
