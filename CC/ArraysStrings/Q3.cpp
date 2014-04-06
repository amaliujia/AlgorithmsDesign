#include <map>

int stringPermutation(char *s, char *t)
{
    
    map<char,int> m;
    while(*s != '\0')
    {
        m[*s] = 1;
        s++;
    }
    while(*t != '\0')
    {
        if(m.find(*t) == m.end()){
            return 0;
        }
        t++;
    }
    return 1;
}
