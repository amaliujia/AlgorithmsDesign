def AJokerDeck(deck):
  index = deck.index('a')
  if index == 53:
    deck.remove('a')
    index = 1
    deck.insert(1, 'a') 
  else:
    deck[index], deck[index+1] = deck[index+1],deck[index]

def BJokerDeck(deck):
   index = deck.index('b')
   if index == 53 or index == 52:
     deck.remove('b')
     index = (index + 2) % 53
     deck.insert(index,'b')
   else:
     deck[index], deck[index+1],deck[index+2] = deck[index+1],deck[index+2],deck[index]


def ThreeWayPatition(deck):
  index_A = deck.index('a')
  index_B = deck.index('b')
  if index_A > index_B:
    index_A, index_B = index_B, index_A

  deck_A = list()
  deck_B = list()
  if index_A > 0:
    deck_A = deck[0:index_A]
  if index_B < 53:
    deck_B = deck[index_B+1:]

  res = deck_B + deck[index_A:index_B+1] + deck_A
  return res

def Toggle(deck):
  if deck[-1] != 'a' or deck[-1] != 'b':
     deck_A = deck[0:deck[-1]]
     deck_B = deck[deck[-1]:]
     res = deck_B[0:1] + deck_A + deck_B[1:]
     return res

def Toggle2(deck):
  if deck[-1] != 'a' or deck[-1] != 'b':
     deck_A = deck[0:deck[-1]]
     deck_B = deck[deck[-1]:]
     res = deck_B[0:len(deck_B) - 1] + deck_A + deck_B[len(deck_B) - 1:]
     return res

deck = list()
for i in range(1, 53):
  deck.append(i)

deck.append('a')
deck.append('b')

AJokerDeck(deck)
BJokerDeck(deck)
BJokerDeck(deck)
deck = ThreeWayPatition(deck)
deck = Toggle2(deck)
print deck
