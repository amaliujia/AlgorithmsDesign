class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> dict{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result(1, "");
        for(char c : digits){
            size_t n = result.size();
            size_t m = dict[c - '0'].size();
            
            result.resize(n * m);
            for(int i = 1; i < m; i++){
                copy(result.begin(), result.begin() + n, result.begin() + n * i);
            }
            for(int j = 0; j < m; j++){
                vector<string>::iterator it;
                for(it = result.begin() + j * n; it < result.begin() + (j + 1) * n; it++){
                    *it += dict[c - '0'][j];
                }
            }
        }
        return result;
    }
};
