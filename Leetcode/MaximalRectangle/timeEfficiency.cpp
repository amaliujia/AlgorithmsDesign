int maximalRectangle(vector<vector<char>> &matrix){
    if(matrix.size() == 0)  return 0;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> height;
    int maxArea = 0;
    for(int i = 0; i < m; i++){
        vector<int> v;
        height.push_back(v);
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == '0'){
                height[i].push_back(0);
            }else{
                // for none-first row, the cur_rec height is height + upper neighbor 
                int val = i == 0 ? 1 : height[i - 1][j] + 1;
                height[i].push_back(val);
            }
        }
    }
    for(int i = 0; i < m; i++){
        int area = largestRectangleArea(height[i]);
        if(area > maxArea){
            maxArea = area;
        }
    }
    return maxArea;
}

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
