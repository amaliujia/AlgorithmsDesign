// At most m + n step
// So O(m + n) time
	/**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
       
            while(i <= (m - 1) && j >= 0){
                if(matrix[i][j] > target){
                    j--;
                }else if(matrix[i][j] < target){
                    i++;  
                }else{
                    return 1;
                }
            }
            return 0;
    }