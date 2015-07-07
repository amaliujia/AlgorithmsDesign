class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
        vector<string> intermediate;
        vector<bool> valid(s.length() + 1, true);
        DFS(0, s, s.length(), result, dict, intermediate, valid);
        return result;
    }
private:
    void DFS(int start, string s, int len, vector<string> &result, unordered_set<string> &dict, vector<string> &intermediate, vector<bool> &valid){
        if(start == len){
            string temp = "";
            for(int i = 0; i < intermediate.size() - 1; i++){
                temp += intermediate[i];
                temp += " ";
            }
            temp += intermediate[intermediate.size() - 1];
            result.push_back(temp);
        }
        
        for(int i = start; i < len; i++){
            string ss = s.substr(start, i - start + 1);
            if(dict.find(ss) != dict.end() && valid[i + 1]){
                intermediate.push_back(ss);
                int judge = result.size();
                DFS(i + 1, s, len, result, dict, intermediate, valid);
                if(judge == result.size()){
                    valid[i + 1] = false;
                }
                intermediate.pop_back();
            }
        }
    }
};
