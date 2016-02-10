#!/usr/bin/python
# By Steve Hanov, 2011. Released to the public domain
# Editted by Rui Wang, 2016. Add Swap to this algorithm

# note (Rui Wang): Steve Hanov wrote this trie based edit distance
# solving approach. This verison supports only delete, insert and replace.
# Rui's version, instead, add one more operations, swap, whose cost is still
# 1, but can be applied when align xy with yx.
import time
import sys

DICTIONARY = "/usr/share/dict/words";
TARGET = sys.argv[1]
MAX_COST = int(sys.argv[2])

# Keep some interesting statistics
NodeCount = 0
WordCount = 0

# The Trie data structure keeps a set of words, organized with one node for
# each letter. Each node has a branch for each letter that may follow it in the
# set of words.
class TrieNode:
    def __init__(self):
        self.word = None
        self.children = {}

        global NodeCount
        NodeCount += 1

    def insert( self, word ):
        node = self
        for letter in word:
            if letter not in node.children:
                node.children[letter] = TrieNode()

            node = node.children[letter]

        node.word = word

# read dictionary file into a trie
trie = TrieNode()
for word in open(DICTIONARY, "rt").read().split():
    WordCount += 1
    trie.insert( word )

print "Read %d words into %d nodes" % (WordCount, NodeCount)

# The search function returns a list of all words that are less than the given
# maximum distance from the target word
def search( word, maxCost ):

    # build first row
    currentRow = range( len(word) + 1 )

    results = []

    # recursively search each branch of the trie
    for letter in trie.children:
        searchRecursive(trie.children[letter], letter, None, word, currentRow,
            None results, maxCost )

    return results

# This recursive helper is used by the search function above. It assumes that
# the previousRow has been filled in already.
def searchRecursive(node, letter, pletter, word, previousRow, ppreviousRow, results, maxCost ):

    columns = len( word ) + 1
    currentRow = [ previousRow[0] + 1 ]

    # Build one row for the letter, with a column for each letter in the target
    # word, plus one for the empty string at column 0
    for column in xrange( 1, columns ):

        insertCost = currentRow[column - 1] + 1
        deleteCost = previousRow[column] + 1

        if word[column - 1] != letter:
            replaceCost = previousRow[ column - 1 ] + 1
        else:
            replaceCost = previousRow[ column - 1 ]

        if column > 1 and ppreviousRow != None:
            if word[column - 1] == letter and word[column - 2] == pletter:
                swapCost = ppreviousRow[column - 2]
            else if word[column - 1] == pletter and word[column - 2] == letter:
                swapCost = ppreviousRow[column - 2] + 1
            else:
                # just set a impossbile value here. No word will larget than
                # 1024
                swapCost = 1024

        currentRow.append( min( insertCost, deleteCost, replaceCost, swapCost ) )

    # if the last entry in the row indicates the optimal cost is less than the
    # maximum cost, and there is a word in this trie node, then add it.
    if currentRow[-1] <= maxCost and node.word != None:
        results.append( (node.word, currentRow[-1] ) )

    # if any entries in the row are less than the maximum cost, then
    # recursively search each branch of the trie
    if min( currentRow ) <= maxCost:
        for next_letter in node.children:
            searchRecursive( node.children[next_letter], next_letter, letter, word, currentRow, previousRow
                results, maxCost )

start = time.time()
results = search( TARGET, MAX_COST )
end = time.time()

for result in results: print result

print "Search took %g s" % (end - start)
