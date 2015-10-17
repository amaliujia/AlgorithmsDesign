// 
class Solution {
public:
    int countPrimes(int n) {
        if(n < 3){
            return 0;
        }
        int count = 0;
        //int visited[n];
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            visited[i] = i;
        }
        
        visited[0] = -1;
        visited[1] = -1;
        for(int i = 2; i < n;  i++){
            if(visited[i] != -1){
                int j = 2;
                while(i * j < n){
                    visited[i * j] = -1;
                    j++;
                }
            }
        }      
        
        for(int i = 0; i < n; i++){
            if(visited[i] != -1){
                count++;
            }
        }
        
        return count;
    }
};
