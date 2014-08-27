//O(n) time, because two pointers will at most iterate each elements in Stinrg S twice
class Solution {
public:
    string minWindow(string S, string T) {
        if(S.length() == 0 || S.length() < T.length()){
            return "";
        }
        int lenS = S.length(), lenT = T.length();
        int expectCount[256] = {0};
        int appearCount[256] = {0};
        int start = 0, end = 0, len = 0;
        int minLen = INT_MAX, minStart = 0;
        
        for(int i = 0; i < lenT; i++){
            expectCount[T[i]]++;
        }
        
        while(end < lenS){
            if(expectCount[S[end]] > 0){
                if(appearCount[S[end]] <= expectCount[S[end]])
                    len++;
            }
            if(len == lenT){
                while(expectCount[S[start]] == 0 ||
                      appearCount[S[start]] > expectCount[S[start]]){
                          appearCount[S[start]]--;
                		  start++;
				}
                if(minLen > (end - start + 1)){
                    minLen = end - start + 1;
                    minStart = start;
                }
            }
            end++;
        }
		if(minV == INT_MAX)	return "";
        return S.substr(minStart, minLen);
    }
};
