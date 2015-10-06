def kEditDistance(word1, word2, k):
    if word1 == word2 or abs(len(word1) - len(word2)) > k:
        return False

    if len(word1) < len(word2):
        return kEditDistance(word2, word1, k)

    o_w1 = len(word1)
    o_w2 = len(word2)
    c = 0
    for i in xrange(0, len(word1)):
        if i == len(word2):
            word2.append(word1[i])
        elif word1[i] != word2[i]:
            c += 1
            if len(word1) == len(word2):
                word2[i] = word1[i]
            else:
                word2.insert(i, word1[i])
    if c <= k and word1 == word2:
        return True
    return False
