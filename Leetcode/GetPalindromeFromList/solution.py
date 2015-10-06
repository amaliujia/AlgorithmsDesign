def checkPalindrome(word):
    i = 0
    j = len(word) - 1
    while i < j:
        if word[i] != word[j]:
            return False
        i += 1
        j -= 1
    return True

# abc
# cba   cba. cb. c.  .cba .ba a
def matchingPalindrome(words):
    dict = set()
    res = set()
    for word in words:
        dict.add(word)
    
    for word in words:
        res_word = word[::-1]
        
        for i in xrange(1, len(res_word) + 1):
          new_word = res_word[0:i] + word
          if res_word[0:i] in dict and checkPalindrome(new_word):
            res.add(new_word) 
          
          new_word = word + res_word[i-1:]
          if (res_word[i-1:]) in dict and checkPalindrome(new_word):
            res.add(new_word)
    print res
    

words = ["abc", "ba", "cba", "bc"]
matchingPalindrome(words)
