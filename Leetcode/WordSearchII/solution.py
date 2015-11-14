class Solution(object):
    def findWords(self, board, words):
        trie = Trie()
        for w in words: trie.insert(w)
        Solution.res = set()
        for i in xrange(len(board)):
            for j in xrange(len(board[i])):
                visited = set()
                self.search(board, trie.root, visited, (i,j), "")
        return list(Solution.res)

    def search(self, board, trie, visited, idx, s):
        i, j = idx[0], idx[1]
        if (i < 0) or (j < 0) or (i >= len(board)) or (j >= len(board[i])): return
        cur = board[i][j]
        if cur in trie.neighbors:
            if trie.neighbors[cur].word:
                Solution.res.add(s + cur)
            visited.add(idx)
            if (i+1, j) not in visited:
                self.search(board, trie.neighbors[cur], visited, (i+1, j), s + cur)
            if (i-1, j) not in visited:
                self.search(board, trie.neighbors[cur], visited, (i-1, j), s + cur)
            if (i, j+1) not in visited:
                self.search(board, trie.neighbors[cur], visited, (i, j+1), s + cur)
            if (i, j-1) not in visited:
                self.search(board, trie.neighbors[cur], visited, (i, j-1), s + cur)
            visited.remove(idx)
        else:
            return


class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.val = ""
        self.word = False
        self.neighbors = {}

class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        child = self.root
        for i in xrange(len(word)):
            s = word[i]
            if s not in child.neighbors:
                child.neighbors[s] = TrieNode()
            child = child.neighbors[s]
        child.word = True

    def search(self, word):
        child = self.root
        for i in xrange(len(word)):
            s = word[i]
            if s in child.neighbors:
                child = child.neighbors[s]
            else:
                return False
        return child.word

    def startsWith(self, prefix):
        child = self.root
        for i in xrange(len(prefix)):
            s = prefix[i]
            if s in child.neighbors:
                child = child.neighbors[s]
            else:
                return False
        return True    
