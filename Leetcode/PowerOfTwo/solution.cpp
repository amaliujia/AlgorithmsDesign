class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool oneFlag = false;
        while(n != 0){
            if(n & 0x01 == 0x01){
                if(oneFlag){
                    return false;
                }
                oneFlag = true;
            }
            n = n >> 1;
        }
        
        if(oneFlag){
            return true;
        }else{
            return false;
        }
    }
};
