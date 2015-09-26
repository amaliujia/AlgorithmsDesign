/*
	support word size * number of word = m;
	length of S is n;
	So need O(m) space, O(nm) time.
*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int wordSize = L[0].length();
        int wordsSize = wordSize * L.size();
        int i, j;
        vector<int> result;
        
        if(S.length() < wordsSize){
          return result;
        }
        unordered_map<string, int> wordCount;
        
        for(i = 0; i < L.size(); i++){
           wordCount[L[i]]++;
        }
        
        unordered_map<string, int> count;
        for(i = 0; i <= S.length() - wordsSize; i++){
            count.clear();
            for(j = 0; j < L.size(); j++){
                string c = S.substr(i + j * wordSize, wordSize);
                if(wordCount.find(c) != wordCount.end()){
                    count[c]++;
                    if(wordCount[c] < count[c]){
                        break;
                    }
                }else{
                    break;
                }
            }

            if(j == L.size()){
                result.push_back(i);
            }
        }
        return result;
    }
};
