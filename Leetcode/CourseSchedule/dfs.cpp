class Solution {
  public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites); 

      vector<bool> visited(graph.size(), false);
      vector<bool> prunning(graph.size(), false);

      for(int i = 0; i < numCourses; i++){

        if(!prunning[i] && dfs(graph, i, visited, prunning)){
          return false;
        }          
      }
      return true;
    }

  private:
    bool dfs(vector<unordered_set<int>>& graph, int curNode, vector<bool>& visited, vector<bool>& prunning){
      if(visited[curNode]){
        return true;
      }

      if(prunning[curNode]){
        return false;
      }

      prunning[curNode] = true;

      visited[curNode] = true;
      unordered_set<int> edges = graph[curNode];
      for(auto e : edges){
        if(dfs(graph, e, visited, prunning)){
          return true;
        }
      }

      visited[curNode] = false;
      return false;
    }

    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites){
      vector<unordered_set<int>> graph;
      for(int i = 0; i < numCourses; i++){
        unordered_set<int> edge;
        graph.push_back(edge);
      }

      for(auto p : prerequisites){
        graph[p.second].insert(p.first);
      }

      return graph;
    }
};
