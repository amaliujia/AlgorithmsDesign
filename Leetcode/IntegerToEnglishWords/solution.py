class Solution(object):
    def numberToWords(self, num):
        dic = { 0:'Zero', 1: 'One', 2: 'Two', 3: "Three", 4: 'Four', 5: 'Five', 6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine',10: 'Ten', 11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen', 15:'Fifteen', 16: 'Sixteen',17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen', 20: 'Twenty', 30: 'Thirty', 40: 'Forty', 50: 'Fifty',60: 'Sixty', 70: 'Seventy', 80: 'Eighty', 90: 'Ninety', 100: 'Hundred', 1000: 'Thousand', 1000000: 'Million', 1000000000: 'Billion'}
         
        res = ""
        if num < 20:
             res += dic[num]
             return res
        elif num < 100:
             res += dic[num / 10 * 10]
             num %= 10
        elif num < 1000:
             res += dic[num / 100] +  " " + dic[100]
             num %= 100
        elif 1000 <= num and num < 1000000:
             res += self.numberToWords(num / 1000) +  " " + dic[1000]
             num %= 1000
        elif 1000000 <= num and num < 1000000000:
             res += self.numberToWords(num / 1000000) +  " " + dic[1000000]
             num %= 1000000
        else:
             res += self.numberToWords(num / 1000000000) +  " " + dic[1000000000]
             num %= 1000000000
    
        if num:
            res += " " + self.numberToWords(num)
        return res
        
