/*
	time complexity: O(n^2)
	space complexity: O(1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return 0;
        string longest = search(s, 0, 0);
        string cursor;
        for(int i = 0; i < n-1; i++){
            cursor = search(s, i, i);
            if(cursor.length() > longest.length()){
                longest = cursor;
            }
        }
        for(int i = 0; i < n-1; i++){
            cursor = search(s, i, i+1);
            if(cursor.length() > longest.length()){
                longest = cursor;
            }           
        }
        return longest;
    }
    
    string search(string s, int a, int b){
        int l = a, r = b;
        int len = s.length();
        while(l >= 0 && r <= len-1 && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
};
