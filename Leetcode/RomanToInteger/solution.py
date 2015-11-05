class Solution(object):
    def romanToInt(self, s):
        nums = list();
        for i in range(0, len(s)):
            n = 0
            if s[i] == 'M':
                n  = 1000
            elif s[i] == 'D':
                n = 500
            elif s[i] == 'C':
                n = 100
            elif s[i] == 'L':
                n = 50
            elif s[i] == 'X':
                n = 10
            elif s[i] == 'V':
                n = 5
            elif s[i] == 'I':
                n = 1
            nums.append(n)
        sum = 0
        for i in range(0, len(s)-1):
            if nums[i] < nums[i+1]:
               sum -= nums[i]
            else:
                sum += nums[i]
        return sum + nums[len(s) -1]
        
