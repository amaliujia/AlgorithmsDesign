class Solution(object):
    def findStrobogrammatic(self, n):
        single_com = ["1", "0" , "8"]
        two_com = ["69","96","11", "88", "00"]
        if n == 1:
            return single_com
        if n == 2:
            return two_com[0:len(two_com)-1]
            
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
        res = []
        for i in new:
            if len(i) > 1 and i[0] == '0':
                continue
            res.append(i)
        return res
