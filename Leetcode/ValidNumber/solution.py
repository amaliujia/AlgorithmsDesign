class Solution(object):
    def isNumber(self, s):
        i = 0
        num = False
        while i < len(s) and s[i] == ' ':
            i += 1
        if i < len(s) and (s[i] == '+' or s[i] == '-'):
            i += 1
        while i < len(s) and s[i].isdigit():
            i += 1
            num = True
        
        if i < len(s) and (s[i] == '.'):
            i += 1       
        while i < len(s) and s[i].isdigit():
            i += 1
            num = True       
        if i < len(s) and (s[i] == 'e' or s[i] == 'E') and num:
            num = False
            i += 1
            if i < len(s) and (s[i] == '+' or s[i] == '-'):
                i += 1
       
        while i < len(s) and s[i].isdigit():
            i += 1
            num = True
        while i < len(s) and s[i] == ' ':
            i += 1           
        return num == True and i == len(s)
