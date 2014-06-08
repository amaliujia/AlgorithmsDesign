class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        vector<int> empty;
        result.push_back(empty);
        for(int i = 0; i < S.size(); i++){
            vector<int> temp;
            int size = result.size();
            for(int j = 0; j < size; j++){
                temp = result[j];
                temp.push_back(S[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};

