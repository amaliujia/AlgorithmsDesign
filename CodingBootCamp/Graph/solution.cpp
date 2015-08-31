#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph{
  private:
    int V; //number of node
    vector<vector<int>> edges;
    bool isCyclicUtil(int v, bool *visited, bool *recStack);
  public:
    Graph(int v);  
    void addEdge(int start_node, int end_node);
    void BFS(int s); // print BFS travesal from given node s.
    void DFS(int s);
    bool isCyclic();
};

bool Graph::isCyclicUtil(int v, bool *visited, bool *recStack){
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


bool Graph::isCyclic(){
  bool *visited = new bool[V];
  bool *recStack = new bool[V];
  
  for(int i = 0; i < V; i++){
    visited[i] = false;
    recStack[i] = false;
  }
  
  for(int i = 0; i < V; i++){
    if(isCyclicUtil(i, visited, recStack)){
      return true;
    }
  }
  return false;
}


Graph::Graph(int v){
  this->V = v;
  for(int i = 0; i < V; i++){
    edges.push_back(vector<int>());
  }
}

void Graph::addEdge(int start_node, int end_node){
  this->edges[start_node].push_back(end_node);
}

void Graph::DFS(int s){
  stack<int> q;
  vector<bool> visited(V, false);

  q.push(s);

  while(!q.empty()){
    int cur = q.top();
    q.pop();

    visited[cur] = true;
    cout << cur << " ";

    for(int neighbor : edges[cur]){
      if(visited[neighbor]){
        continue;
      }

      q.push(neighbor);
    }
  } 
}

void Graph::BFS(int s){
  queue<int> q;
  vector<bool> visited(V, false);

  q.push(s);

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    visited[cur] = true;
    cout << cur << " ";

    for(int neighbor : edges[cur]){
      if(visited[neighbor]){
        continue;
      }

      q.push(neighbor);
    }
  }
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.BFS(2);
  return 0;
}

