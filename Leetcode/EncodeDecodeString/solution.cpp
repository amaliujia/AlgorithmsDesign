class Codec {
  public:

    string encode(vector<string>& strs) {
      string result;
      for(string s : strs){
        result += formatNumber(s.length());
        result += s;
      }
      return result;
    }

    vector<string> decode(string s) {
      int i = 0;
      vector<string> v;
      while(i < s.length()){
        string size_str = s.substr(i, 4);
        int size = stoi(size_str);
        i += 4;
        v.push_back(s.substr(i, size));
        i += size;
      }
      return v;
    }

    string formatNumber(int n) {
      stringstream ss;
      ss << setw(4) << setfill('0') << n;
      return ss.str();
    }
};

