// O(n^4) time
int maximalRectangle(vector<vector<char>> &matrix){
	if(matrix.size() == 0)	return 0;

	int maxArea = 0;
	int m = matrix.size();
	int n = matrix[0].size();

 	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			int area = maxRectangleOnPoint(matrix,
											i, j);
			if(area > maxArea){
				maxArea = area;
			}	
		}	
	}
	return maxArea;	
}

int maxRectangleOnPoint(vector<vector<char>> &matrix, 
									int row, int col)
{
    //number
    int minWidth = INT_MAX;
    int maxArea = 0; 

    //row and column of matrix 
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = row; i < m && matrix[i][col] == '1'; i++){
        int width = 0;
        int j = col;
        while(j < n && matrix[i][j] == '1'){    
            width++;
            j++;
        }
        if(width < minWidth){
            minWidth = width; 
        }

        int area = (i - row + 1) * minWidth;
        if(area > maxArea){
            maxArea = area;
        }
    }
    return maxArea;
}
}
