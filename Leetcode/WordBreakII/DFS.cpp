// O(2^n)
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
        vector<string> intermediate;
        DFS(s, result, dict, intermediate);
        return result;
    }
private:
    void DFS(string s, vector<string> &result, unordered_set<string> &dict, vector<string> &intermediate){
        if(s == ""){
            string temp = "";
            for(int i = 0; i < intermediate.size() - 1; i++){
                temp += intermediate[i];
                temp += " ";
            }
            temp += intermediate[intermediate.size() - 1];
            result.push_back(temp);
        }
        
        for(int i = 1; i < s.length(); i++){
            if(dict.find(s.substr(0, i)) != dict.end()){
                intermediate.push_back(s.substr(0, i));
                DFS(s.substr(i, s.length() - i), result, dict, intermediate);
                intermediate.pop_back();
            }
        }
    }
};
