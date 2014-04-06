    int integerTable[10] = {0,1,2,3,4,5,6,7,8,9};
    int atoi(const char *str) {
    long long result = 0;
    bool isSigned = false;
    bool isNegative = false;
    bool numStart = false;
    
    if(*str == '\0')
    {
        return 0;
    }
    
    while(*str != '\0')
    {
        if(*str == '+' || *str == '-'){
            isSigned = true;
            if(*str == '-'){
                isNegative = true;
            }
            str++;
            if(*str < '0' || *str > '9')
            {
                return 0;
            }
            continue;
        }
        
        if(*str != ' ' && numStart == false && (*str >'9' || *str < '0'))
        {
            return 0;
        }
        
        if(*str >= '0' && *str <= '9'){
            result = result * 10 + integerTable[*str - '0'];
            numStart = true;
        }else if(numStart == true){
            break;
        }
        str++;
    }
    if(result > INT_MAX && isNegative == false)
    {
        return INT_MAX;
    }
    if(result > INT_MAX && isNegative == true)
    {
        return INT_MIN;
    }
    
    if(isSigned == true && isNegative == true)
    {
        result = -result;
    }
    return result;
}
