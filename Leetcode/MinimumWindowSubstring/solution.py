class Solution(object):
    def minWindow(self, s, t):
        if len(s) < len(t):
            return ""
        if len(s) == len(t):
            if s == t:
                return s
                
        stas = dict()
        tlen = 0
        min_len = sys.maxint
        start = 0
        i=0
        j=0
        for c in t:
            tlen += 1
            if c in stas:
                stas[c] += 1
            else:
                stas[c] = 1
   
        while i < len(s) or j < len(s):
            if tlen > 0 and i < len(s):
                if s[i] in stas:
                    stas[s[i]] -= 1
        
                if s[i] in t and stas[s[i]] >= 0:
                    tlen -= 1
                i += 1
            else:
                if tlen == 0 and min_len > i - j:
                    min_len = i - j
                    start = j
                if s[j] in stas:
                    stas[s[j]] += 1
                if s[j] in t and stas[s[j]] > 0:
                    tlen += 1
                j += 1
        
        if min_len == sys.maxint:
            return ""
        return s[start: start+min_len]
