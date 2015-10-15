class Solution(object):
    def partition(self, s):
        res = list()
        cur = list()
        self.DFS(s, cur, res)
        return res
    
    def DFS(self, s, cur, res):
        if len(s) == 0:
            l = list(cur)
            res.append(l)
            return
        for i in range(1, len(s)+1):
            if self.ifPalin(s[0:i]):
                cur.append(s[0:i])
                self.DFS(s[i:], cur, res)
                cur.pop()
    
    def ifPalin(self, s):
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                break
            i += 1
            j -= 1
        
        return i >= j
