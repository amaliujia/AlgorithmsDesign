class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
      unordered_set<long long> s;
      for(long long i : nums){
        s.insert(i);   
      }

      vector<string> result;

      for(long long i : nums){
        string t;
        long long right = i + 1;
        unordered_set<long long>::iterator it;
        if((it = s.find(i)) == s.end()){
          continue;
        }

        while((it = s.find(right)) != s.end()){
          s.erase(*it);
          right++;
        }

        if(i + 1 == right){
          t.append(to_string(i)); 
        }else{
          t.append(to_string(i));
          t.append("->");
          t.append(to_string(right - 1));
        }
        result.push_back(t);
      }
      return result;
    }

};
