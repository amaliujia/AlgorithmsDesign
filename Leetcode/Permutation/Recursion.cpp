class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
            return getPermute(num);
        }
private:
    vector<vector<int>> getPermute(vector<int> num){
        vector<vector<int>> result;
        if(num.size() == 0) return result;
        if(num.size() == 1){
            vector<int> temp;
            temp.push_back(num[0]);
            result.push_back(temp);
            return result;
        }
        int last = num.back();
        num.pop_back();
        vector<vector<int>> temp = getPermute(num);
        for(vector<int> v : temp){
            for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
                result.push_back(insert(v, it, last));
            }
            v.push_back(last);
            result.push_back(v);
        }
        return result;
    }
    vector<int> insert(vector<int> num, vector<int>::iterator index, int inserter){
        num.insert(index, inserter);
        return num;
    }
};
