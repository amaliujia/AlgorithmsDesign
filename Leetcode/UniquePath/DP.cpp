// O(mn) time
// O(n) space
int uniquePaths(int m, int n) {
    vector<int> hash(n, 0);
    hash[0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++){
            hash[j] += hash[j - 1];
        }
    }
    return hash[n - 1];
 
