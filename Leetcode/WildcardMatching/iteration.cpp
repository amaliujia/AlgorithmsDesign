// O(m+n) time
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *a, *b;
        bool star = false;
        for(a = s, b = p; *a != '\0'; a++, b++){
            switch(*b){
                case '?':
                    break;
                case '*':
                    s = a;
                    p = b;
                    star = true;
                    while(*p == '*'){
                        p++;
                    }
                    if(*p == '\0'){
                        return true;
                    }
                    a = s - 1;
                    b = p - 1;
                    break;
                default:
                    if(*a != *b){
                        if(!star){
                            return false;
                        }
                        s++;
                        a = s - 1;
                        b = p - 1;
                    }
                    break;
            }
        }
        while(*b == '*'){
            b++;
        }
        if(*b != '\0')  return false;
        return true;
    }
};
