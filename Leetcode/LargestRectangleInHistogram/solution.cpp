int largestRectangleArea(vector<int> &height){
    stack<int> s;

    int maxArea = 0;
    int i = 0; 
    while(i < height.size()){
        if(s.empty() || height[s.top()] <= height[i]){
            s.push(i++);
        }else{
            int prev = s.top();
            s.pop();
            int area = (s.empty() ? i : (i - s.top() - 1)) * height[prev];
            if(area > maxArea){
                maxArea = area;
            }
        }
    }

    while(!s.empty()){
            int prev = s.top();
            s.pop();
            int area = (s.empty() ? i : (i - s.top() - 1))  * height[prev];
            if(area > maxArea){
                maxArea = area;
            }
    }
    return maxArea;
    }
}
