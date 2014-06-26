class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int bound = (a.length() < b.length()) ? a.length() : b.length();
        for(int i = 0; i < bound; i++){
            if(a[i] == '1' && b[i] == '1'){
                if(carry == 1){
                    result[i] = '1';
                }else{
                    result[i] = '0';
                }
                carry = 1;
            }else if(a[i] == '1' || b[i] == '1'){
                if(carry == 1){
                    result[i] = '0';
                    carry = 1;
                }else{
                    result[i] = '0';
                    carry = 0;
                }                
            }else{
                if(carry == 1){
                    result[i] = '1';
                }else{
                    result[i] = '0';
                }
                carry = 0;
            }
        }
    
        return result;
    }
};
