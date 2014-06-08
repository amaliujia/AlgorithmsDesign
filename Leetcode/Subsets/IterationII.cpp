class Solution {
public:
vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> result;
    vector<int> empty;
    result.push_back(empty);
    for(int i = 0; i < S.size(); i++){
        vector<vector<int>> temp;
        vector<vector<int>>::iterator it;
        for(it = result.begin(); it != result.end(); it++){
            temp.push_back(*it);
        }
        for(it = temp.begin(); it != temp.end(); it++){
            (*it).push_back(S[i]);
            result.push_back(*it);
        }
    }
    return result;
}
};

