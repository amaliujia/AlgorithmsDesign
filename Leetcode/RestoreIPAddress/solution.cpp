class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.size() > 12) {
            return result;
        }
        vector<string> cur;
        backtracking(result, s, 0, cur);
        return result;
    }
    
private:
    void backtracking(vector<string>& v, string s, int count, vector<string>& cur){
        if(s == "" && count == 4){
            string builder = "";
            for(int i = 0; i < cur.size() - 1; i++){
                builder += cur[i];
                builder += ".";
            }
            
            builder += cur[cur.size() - 1];
            v.push_back(builder);
            return;
        }else if(s == "" || count == 4){
            return;
        }
        
        for(int i = 0; i < s.size(); i++){
            int now = stoi(s.substr(0, i + 1));
            if(now > 255){
                return;
            }
            
            cur.push_back(s.substr(0, i + 1));
            backtracking(v, s.substr(i + 1), count + 1, cur);
            cur.pop_back();
            
            if(s[0] == '0'){
                return;
            }
        }
    }
};
