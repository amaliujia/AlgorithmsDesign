char *strStr(char *haystack, char *needle) {
	if(haystack == NULL || needle == NULL)	return NULL;
    if((*haystack == '\0') && (*needle == '\0'))  return "";
        
    int lenHaystack = 0, lenNeedle = 0;
    char *p = haystack;
    char *q = needle;
        
    while(*p != '\0'){
		lenHaystack++;
        p++;
    }
    while(*q != '\0'){
        lenNeedle++;
         q++;
    }
    while(*haystack != '\0'){
         p = haystack;
         q = needle;
         while((*q == *p) && (*q != '\0') && (*p != '\0')){
             q++;
             p++;
         }
         if(*q == '\0')  return haystack;
         if(*p == '\0')  return NULL;
            
         haystack++;
    }
    return NULL;
}
