int largestRectangleArea(vector<int> &height){
	// define tow stacks, one for heights and the other for indexes
	stack<int> heights;
	stack<int> index;

	int heightMax = 0;

	for(int i = 0; i < height.size(); i++){
		//case 1, the height is larger thus can be candidate of rec start
		if(heights.empty() || height[i] > heights.top()){
			heights.push(height[i]);
			index.push(i);
		}else if(heights.top() > height[i]){
			int lastindex = 0;
			while(!heights.empty() && heights.top() > height[i]){
				int h = heights.top();
				int lastindex = index.top();
				heights.pop();
				index.pop();
				int temp = h * (i - lastindex);
				if(temp > heightMax){
					heightMax = temp;
				}	
			}
			heights.push(height[i]);
			index.push(lastindex); // this is not i but last index, becasue for curr histo, left side histos whose height are smaller can also be a part of rectangle
		}
	}
	
	while(!heights.empty()){
		int temp = heights.pop() * (height.size() - index.top());
		heights.pop();
		index.pop();
        if(temp > heightMax){
            heightMax = temp;
        }			
	}
	return heightMax;
}
