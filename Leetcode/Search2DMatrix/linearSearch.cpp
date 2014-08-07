// O(n) time
// o(n) space
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            vector<int> temp = matrix[i];
            for(int j = 0;j < n; j++){
                if(target == temp[j]){
                    return true;
                }
            }
        }
        return false;
    }
};
