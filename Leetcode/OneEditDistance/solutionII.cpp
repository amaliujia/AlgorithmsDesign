class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        if(m < n){
            return isOneEditDistance(t, s);
        }
        
        if(n < m - 1){
            return false;
        }
        
        bool isModified = false;
        for(int i = 0; i < m; i++){
            if((s[i] != t[i]) && !isModified){
                if(m == n){
                    t[i] = s[i];
                }else{
                    t.insert(i, 1, s[i]);
                }
                isModified = true;
            }
        }
        
        return isModified && s == t;
    }
};
