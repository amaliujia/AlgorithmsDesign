// double n complexity
class Solution {
public:
    void reverseWords(string &s) {
        string ss;
        int i = s.length() - 1;
        while(i >= 0){
             while(s[i] == ' ' && i >= 0){
                i--;   
             }
            if(i < 0) break;
            if(ss.length() != 0){
                ss.push_back(' ');
            }
            string temp;
            while(s[i] != ' ' && i >= 0){
                temp.push_back(s[i]);
                i--;
            }
            reverse(temp.begin(), temp.end());
            ss.append(temp);
        }
    	s = ss;
	}
};
