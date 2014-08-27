// O(n^2) time
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
       int maxheight = INT_MIN;
       for(int i = 0; i < height.size(); i++){
           int left = i - 1;
           int right = i + 1;
           int hei = height[i];
           if(i == 0){
               while(right < height.size() && height[i] >= height[right]){
                   hei += height[i];
                   right++;
               }
           }else if(i == (height.size() - 1)){
               while(left >= 0 && height[i] >= height[left]){
                   hei += height[i];
                   left--;
               }               
           }else{
               while(right < height.size() && height[i] >= height[right]){
                   hei += height[i];
                   right++;
               }
               while(left >= 0 && height[i] >= height[left]){
                   hei += height[i];
                   left--;
               } 
           }
           maxheight = max(maxheight, hei);
       }
       return maxheight;
    }
};
