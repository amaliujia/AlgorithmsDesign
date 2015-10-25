class Solution(object):
    def canPermutePalindrome(self, s):
        d = dict()
        for i in s:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        
        case = False
        cc = False
        if len(s) % 2 != 0:
            case = True
        
        for i, j in d.iteritems():
            if j % 2 != 0:
               if case == False or cc == True:
                   return False
               else:
                   cc = True
        return True
        
