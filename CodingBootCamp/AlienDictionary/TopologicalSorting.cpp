class Graph {
private:
  int V;
  vector<vector<int>> edges; 
public:
  Graph(int v){
    V = v;
    for(int i = 0; i < V; i++){
       
    }
  }
  void addEdge(int v, int w) {
    edges[v].push_back(w);
  } 
};
