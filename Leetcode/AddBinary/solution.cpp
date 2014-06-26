ss Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int bound = (a.length() > b.length()) ? a.length() : b.length();
        for(int i = 0; i < bound; i++){
            int ia = i < a.size() ? a[i] - '0' : 0;
            int ib = i < b.size() ? b[i] - '0' : 0;
            int c = (ia + ib + carry) % 2;
            carry = (ia + ib + carry) / 2;
            result.insert(result.begin(), c + '0');
        }
        if(carry == 1)  result.insert(result.begin(), '1');
        return result;
    }
};
