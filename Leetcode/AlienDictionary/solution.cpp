// cannot handle the case of ['z', 'z'], print empty rather than 'z'
//
// DFS approach: O(V);
class Solution {
  class Graph{
    private:
      int V;
      vector<vector<int>> edges;
      set<char> dict;

    public:
      Graph(int v){
        V = v;
        for(int i = 0; i < V; i++){
          vector<int> vec(V, 0);
          edges.push_back(vec);
        }
      }

      void addEdge(char i, char j){
        edges[i - 'a'][j - 'a'] = 1;
        if(dict.find(i) == dict.end()){
          dict.insert(i);
        }

        if(dict.find(j) == dict.end()){
          dict.insert(j);
        }
      }

      void topologicalSortUtil(stack<char>& s, vector<bool>& visited, int cur){
        visited[cur] = true;

        for(int i = 0; i < V; i++){
          if(edges[cur][i] == 1 && !visited[i]){
            topologicalSortUtil(s, visited, i);
          }
        }

        s.push(cur + 'a');
      }

      string topologicalSort(){
        stack<char> s;
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
          if(!visited[i] && dict.find('a' + i) != dict.end()){
            topologicalSortUtil(s, visited, i);
          }
        }

        string result;
        while(!s.empty()){
          result += s.top();
          s.pop();
        }
        return result;
      }
  };   

  public:
  string alienOrder(vector<string>& words) {
    Graph g(26);
    for(int i = 0; i < words.size(); i++){
      for(int j = i+1; j < words.size(); j++){
        int min_len = min(words[i].length(), words[j].length());
        for(int z = 0; z < min_len; z++){
          if(words[i][z] != words[j][z]){
            g.addEdge(words[i][z], words[j][z]);
            break;
          }                  
        }
      }
    }

    return g.topologicalSort();
  }
};
