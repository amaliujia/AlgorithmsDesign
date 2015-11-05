class Solution(object):
    def intToRoman(self, num):
        cha = ["M", "CM", 'D',"CD", 'C', "XC", 'L',"XL", 'X',"IX" ,'V', "IV", 'I']
        val = [1000, 900, 500, 400, 100, 90, 50,40, 10, 9, 5, 4, 1]
        
        res = ""
        
        for i in range(0, len(cha)):
            res += (num / val[i]) * cha[i]
            num = num % val[i]
        return res
