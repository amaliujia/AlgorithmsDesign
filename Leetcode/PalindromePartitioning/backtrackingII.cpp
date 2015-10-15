// O(2^n) time
class Solution {
public:
    vector<vector<string>> partition(string s) {
          vector<vector<string>> result;
          vector<string> v;
          backtracking(s, s.length(), v, result);
          return result;
    }
private:
    void backtracking(string s, int size, vector<string> &v, vector<vector<string>> &result){
        if(size <= 0){
            result.push_back(v);
            return;
        }        
        int n = s.length();
        for(int i = 1; i < n; i++){
            if(isPalindrome(s.substr(0, i))){
                v.push_back(s.substr(0, i));
                backtracking(s.substr(i, n - i), size - i - 1, v, result);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(string s){
        if(s.length() <= 2) return true;
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};
