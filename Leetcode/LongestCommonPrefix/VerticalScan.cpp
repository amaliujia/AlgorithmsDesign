/*
	assume length of longest common prefix is m and n is the number of strings.
	Then O(mn) time.	
*/
string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty())    return "";
        string result = "";
        int i, j;
        for(i = 0; i < strs[0].size(); i++){
            for(j = 1; j < strs.size(); j++){
                if(strs[0][i] != strs[j][i]){
                    break;  
                }
            }
            if(j == strs.size())    result += strs[0][i];
            else                    break;
        }
        return result;
}
