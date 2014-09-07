class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != (s1.size() + s2.size())) return false;
        int m = s1.size() + 1;
        int n = s2.size() + 1;
        
        bool f[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                f[i][j] = false;
            }
        }
        f[0][0] = true;
		// suppose s2 = "", match s1 and s3
        for(int i = 1; i < m; i++){
            if((s1[i - 1] == s3[i - 1]))
              f[i][0] = true;
            else
                break;
        }
		// suppose s1 = "", match s2 and s3
        for(int j = 1; j < n; j++){
            if(s2[j - 1] == s3[j - 1])
                f[0][j] = true;
            else
                break;
        }
       	//if s1[i - 1] == s3[i + j - 1], then f[i][j] = true if s1-1 and s2 match s3 - 1. The same to s2[i - 1] 
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                f[i][j] = ((s1[i - 1] == s3[i + j - 1]) && f[i - 1][j]) ||
                          ((s2[j - 1] == s3[i + j - 1]) && f[i][j - 1]);
            }
        }
        return f[s1.size()][s2.size()];
   
    }
};
