class Solution(object):
    def shortestWordDistance(self, words, word1, word2):
        last = -1
        i = 0
        min_len = len(words)
        same = word1 == word2
        for i in xrange(len(words)):
            if words[i] in [word1, word2]:
                if last != -1 and (same or words[last] != words[i]):
                    min_len = min(min_len, i - last);
                last = i

        return min_len
