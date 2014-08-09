// diagonal binary search
// O(logn!) time (slower than logn)
// O(1) space

int binarySearch(vector<vector<int>> &matrix, int target, bool row, int i, int j){
    int k, q;
    if(row){
        k = 0;
        q = j;
        while(k <= q && (0 <= k <= j) && (0 <= q <= j)){
            int index = (k + q) / 2;
            if(matrix[i][index] == target){
                return 1;
            }
            if(matrix[i][index] > target){
                q = index - 1;
            }else{
                k = index + 1;
            }
        }
        return 0;
    }else{
        int m = matrix.size();
        k = i;
        q = m;
        while(k <= q && (i <= k <= m) && (i <= q <= m)){
            int index = (k + q) / 2;
            if(matrix[index][j] == target){
                return 1;
            }
            if(matrix[index][j] > target){
                q = index - 1;
            }else{
                k = index + 1;
            }
        }
        return 0;
    }
}

    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */

int searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    int result = 0, i = 0, j = n - 1;
    
    while(1){
        if(m == n){
            if(i == m && j == 0){
                break;
            }
        }else if(m > n){
            if(j == 0){
                break;
            }
        }else if(n > m){
            if(i == m){
                break;
            }
        }
        if(matrix[i][j] == target){
            result++;
        }else if(matrix[i][j] > target){
            result += binarySearch(matrix, target, true, i, j);
        }else{
            result += binarySearch(matrix, target, false, i, j);
        }
        i++;
        j--;
    }
    
    if(m == n){
        if(matrix[m][0] == target)
            ++result;
    }else if(m > n){
        result += binarySearch(matrix, target, false, i, j);
    }else{
        result += binarySearch(matrix, target, true, i, j);
    }
    return result;
}

