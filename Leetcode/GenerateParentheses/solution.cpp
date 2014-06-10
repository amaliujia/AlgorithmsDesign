class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateBranch(n, 0, 0, "", result);
        return result;
    }
private:
    void generateBranch(int n, int l, int r, string constructor, vector<string> &result){
        if(l == n){
            result.push_back(constructor.append(n - r, ')'));
            return;
        }
        generateBranch(n, l + 1, r, constructor + '(', result);
        if(r < l){
            generateBranch(n, l, r + 1, constructor + ')', result);
        }
    }
};
