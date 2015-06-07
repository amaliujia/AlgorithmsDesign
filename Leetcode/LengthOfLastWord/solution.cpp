class Solution {
public:
    int lengthOfLastWord(string s) {
        int end;
        for (end = s.length() - 1; end >= 0 && !isalpha(s[end]); end--);
        if(end == -1){ 
            return 0;
        }
        int begin;
        for (begin = end; begin >= 0 && isalpha(s[begin]); begin--);
        return end - begin;       
    }
};
