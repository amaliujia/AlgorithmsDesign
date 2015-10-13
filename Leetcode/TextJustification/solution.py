class Solution(object):
    def fullJustify(self, words, maxWidth):
        last = -1
        now = 0
        res_v = list()
        
        while now < len(words):
            res = ""
            cur_len = len(words[now])
            last = now
            now += 1
            while now < len(words) and cur_len + 1 + len(words[now]) <= maxWidth:
                cur_len += 1 + len(words[now])
                now += 1
            
            space = 1
            extra_space = 0
            if now < len(words) and now != last + 1:
                space = (maxWidth - cur_len) / (now - last - 1) + 1
                extra_space = (maxWidth - cur_len) % (now - last - 1)
                
            res = res + words[last]
            last += 1
            while extra_space:
                res = res + " " * (space + 1)
                extra_space -= 1
                res = res + words[last]
                last += 1
            
            while last < now:
                res = res + " " * (space)
                res = res + words[last]
                last += 1
            res = res + (maxWidth - len(res)) * " "
            res_v.append(res)
            
        return res_v
