class Solution {
  public:
    int maxArea(vector<int>& height) {
      int i = 0, j = height.size() - 1;
      int area = 0, h = INT_MIN;

      while(i < j){
        h = min(height[i], height[j]);
        area = max(area, (j - i) * h);
        while(i < j && height[i] <= h) i++;
        while(i < j && height[j] <= h) j--;

      }

      return area;
    }
};
