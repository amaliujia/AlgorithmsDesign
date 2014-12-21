    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> result;
        
        for(const auto &s : strs){
            string key = s;
            sort(key.begin(), key.end());
            result[key].push_back(s);
        }
        
        vector<string> r;
        //unordered_map<string, vector<string>>::iterator it = result.begin();
          for (auto it = result.cbegin(); it != result.cend(); it++) {
              if (it->second.size() > 1)
                  r.insert(r.end(), it->second.begin(), it->second.end());
            }
        return r;
    }
