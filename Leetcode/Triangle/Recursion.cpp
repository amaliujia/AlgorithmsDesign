int minimumTotal(vector<vector<int> > &triangle) {
    return recursion(triangle, 0, 0);
}
int recursion(vector<vector<int> > &triangle, int i, int j){
    if(i == triangle.size() - 1)    return triangle[i][j];
        
    int sum1 = recursion(triangle, i + 1, j);
    int sum2 = recursion(triangle, i + 1, j + 1);
        
    return min(sum1, sum2) + triangle[i][j];
}
