class Solution(object):
    def findStrobogrammatic(self, n):
        single_com = ["1", "0" , "8"]
        two_com = ["69","96","11", "88", "00"]
        if n == 1:
            return single_com
        if n == 2:
            return two_com
            
        new = []    
        if n % 2 == 0:
            res = self.findStrobogrammatic(n - 2)
            for r in res:
                for c in two_com:
                    new.append(r[0:len(r)//2] + c + r[len(r)//2:])
        else:
            res = self.findStrobogrammatic(n - 1)
            for r in res:
                for c in single_com:
                   new.append(r[0:len(r)//2] + c + r[len(r)//2:])
        return new
        
    def strobogrammaticInRange(self, low, high):
        i = len(low)
        res = []
        while i <= len(high):
            res.extend(self.findStrobogrammatic(i))
            i += 1
        count = 0
        for t in res:
            if int(t) < int(low) or int(t) > int(high) or (len(t) > 1 and t[0] == '0'):
                continue
            count += 1
        return count
