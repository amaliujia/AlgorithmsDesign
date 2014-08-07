// O(logn + m) time for n * m matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = m;
        while(i <= j){
            int index = (i + j) / 2;
            if(index >= m || index < 0){
                return false;   
            }
            vector<int> temp = matrix[index];
            if(target < temp[0]){
                j = index - 1;
            }else if(target > temp[n - 1]){
                i = index + 1;
            }else{
                for(int k = 0; k < n; k++){
                    if(temp[k] == target){
                        return true;
                    }
                }
                return false;
            }
        }
        
        return false;
    }
};
