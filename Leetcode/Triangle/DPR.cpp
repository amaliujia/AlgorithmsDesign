// O(n^2) time, n is the average number of elements for each level.
// O(n^2) spave, n is the number of elements of triangle.
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		int numRow = triangle.size();
		vector<vector<int> > ibuffer;
		ibuffer.resize(numRow);
		for (int i=0; i<numRow; ++i)
			ibuffer[i].resize(numRow);
			
        return recursion(triangle, 0, 0, ibuffer);
    }
private:
    int recursion(vector<vector<int> > &triangle, int i, int j, vector<vector<int>> &buffer){
        if(i == triangle.size() - 1)    return triangle[i][j];
        
        int sum1, sum2;
        if(buffer[i + 1][j] != NULL){
            sum1 = buffer[i + 1][j];
        }else{
            sum1 = recursion(triangle, i + 1, j, buffer);
        }
        if(buffer[i + 1][j + 1] != NULL){
            sum2 = buffer[i + 1][j + 1];
        }else{
            sum2 = recursion(triangle, i + 1, j + 1, buffer);
        }
        
        buffer[i][j] = min(sum1, sum2) + triangle[i][j];
        return min(sum1, sum2) + triangle[i][j];
    }
};
