/*
	Find the longest substring without repeating from given string
*/
int lengthOfLongestSubstring(string s) {
        unsigned long limit = s.length();
        if(limit == 0) return 0;
        int maxLenth = 0;
        bool exit[256] = {false};
        int start = 0;
        int end = 0;
        int len = 0;
        while(end < limit)
        {
            if(exit[s[end]] == false)
            {
                exit[s[end]] = true;
                len++;
                end++;
            }else{
                maxLenth = max(maxLenth, len);
                while(s[start] != s[end]){
                    exit[s[start]] = false;
                    start++;
                }
                start++;
                len = end - start + 1;
                end++;
            }
        }
        maxLenth = max(maxLenth, len);
        return maxLenth;
