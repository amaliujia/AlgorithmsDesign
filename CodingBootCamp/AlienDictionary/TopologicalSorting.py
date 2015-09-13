class Graph:
  V = 0
  edges = []

  def __init__(self, v):
    self.V = v
    for i in range(0, self.V):
      self.edges.append(list())

  def add_edge(self, v, w):
    self.edges[v].append(w)

  def topological_sort_util(self, i, visited, stack):
    visited[i] = True

    for j in self.edges[i]:
      if visited[j] != True:
          self.topological_sort_util(j, visited, stack)
    stack.append(i)

  def topological_sort(self):
    stack = list()
    visited = list()

    for i in range(0, self.V):
      visited.append(False)

    for i in range(0, self.V):
      if visited[i] == False:
        self.topological_sort_util(i, visited, stack)


    print stack
   
def print_order(words, v):
  g = Graph(v)

  for i in range(0, len(words) - 1):
    word1 = words[i]
    word2 = words[i+1]
    for j in range(0, min(len(word1), len(word2))):
      if word1[j] != word2[j]:
        g.add_edge(ord(word1[j]) - ord('a'), ord(word2[j]) - ord('a'))
        break
  g.topological_sort()


if __name__ == "__main__":
  words = ["caa", "aaa", "aab"]
  print_order(words, 3)  
