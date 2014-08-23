//O(n) time
//O(n) space
typedef unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>Map;

UndirectedGraphNode *clone(UndirectedGraphNode *graph){
    if(!graph)  return NULL;

    Map map; 
    queue<UndirectedGraphNode *> q;
    q.push(graph);

    UndirectedGraphNode *graphCopy = new UndirectedGraphNode(graph->label);   
    map[graph] = graphCopy; 

    while(!q.empty()){
        UndirectedGraphNode *node = q.front();
        q.pop();
        int n = node->neighbors.size();
        for(int i = 0; i < n; i++){
            UndirectedGraphNode *neighbor = node->neighbors[i];
            if(map.find(neighbor) == map.end()){
                UndirectedGraphNode *p = new UndirectedGraphNode(neighbor->label);
                map[node]->neighbors.push_back(p);
                map[neighbor] = p;
                q.push(neighbor);
            }else{
                map[node]->neighbors.push_back(map[neighbor]); 
            }
        }
    }
    return graphCopy;
}
