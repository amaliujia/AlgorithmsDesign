class Graph{
  int V;
  vector<vector<int>> edges;

  void topologicalSortUtil(stack<int>& s, vector<bool>& visited, int cur){
    visited[cur] = true;

    for(int i = 0; i < this->edges[cur].size(); i++){
      if(!visited[i]){
        topologicalSortUtil(s, visited, i);
      }
    }
    s.push(cur);
  }

  bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack){
    if(!visited[v]){
      visited[v] = true;
      recStack[v] = true;

      for(int next : edges[v]){

        if(recStack[next]){
          return true;
        }

        if(!visited[next] && isCyclicUtil(next, visited, recStack)){
          return true;
        }
      }
    }

    recStack[v] = false;
    return false;
  }

  public:
  Graph(int v){
    this->V = v;
    for(int i = 0; i < v; i++){
      vector<int> vec;
      this->edges.push_back(vec);
    }
  }             

  void addEdge(int i, int j){
    this->edges[i].push_back(j);
  }

  void topologicalSort(vector<int>& res){
    vector<bool> visited(V, false);
    stack<int> s;

    for(int i = 0; i < this->V; i++){
      if(!visited[i]){
        this->topologicalSortUtil(s, visited, i);
      }
    }

    while(!s.empty()){
      res.push_back(s.top());
      s.pop();
    }
  } 


  bool isCyclic(){
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for(int i = 0; i < V; i++){
      if(isCyclicUtil(i, visited, recStack)){
        return true;
      }
    }
    return false;
  }
};

class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
      Graph graph(numCourses);
      for(auto& p : prerequisites){
        graph.addEdge(p.second, p.first);
      }

      vector<int> res;
      if(graph.isCyclic()){
        return res;
      }
      graph.topologicalSort(res);
      return res;
    }

};
