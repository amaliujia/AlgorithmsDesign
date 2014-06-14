class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		int numRow = triangle.size();
		vector<int> ibuffer;
		ibuffer.resize(numRow);
		
		for(int i = 0; i < numRow; i++){
		    ibuffer[i] = triangle[numRow - 1][i];
		}
		
		for(int i = numRow - 2; i >= 0; i--){
		    for(int j = 0; j < triangle[i].size(); j++){
		        ibuffer[j] = min(ibuffer[j] + triangle[i][j], ibuffer[j + 1] + triangle[i][j]);
		    }
		}
		
        return ibuffer[0];
    }
};

