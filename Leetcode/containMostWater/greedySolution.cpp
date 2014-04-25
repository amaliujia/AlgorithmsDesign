/*
	This is a sort of greedy alogrithm. We all find local optimal solution and assume it is the global optimal solution.
	This solution need O(n) time.
*/    

int maxArea(vector<int> &height) {
        if(height.size() < 2) return 0;
        if(height.size() == 2) return height[0] < height[1] ? height[0] : height[1];
        //int maxL = 0, maxR = height.size() - 1;
        int maxWater = 0, temp;
        int i = 0, j = height.size() - 1;
        while(i < j){
            temp = height[i] < height[j] ? height[i] * (j - i) : height[j] * (j - i);
            if(maxWater < temp) maxWater = temp;
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxWater;
    }
