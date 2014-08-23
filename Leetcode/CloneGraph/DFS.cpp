// O(n) time;
// O(n) space;
typedef unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>Map;

UndirectedGraphNode *clone(UndirectedGraphNode *graph){
	if(!graph)	return	NULL;

	UndirectedGraphNode *graphCopy = new UndirectedGraphNode(graph->label);
	stack<UndirectedGraphNode *> s;
	Map map;
	s.push(graph);
	map[graph] = graphCopy;

	while(!s.empty()){
		UndirectedGraphNode *node = s.top();
		s.pop();
		int n = node->neighbors.size();
		for(int i = 0; i < n; i++){
			UndirectedGraphNode *p = node->neighbors[i];
			if(map.find(p) == map.end()){
				UndirectedGraphNode *copy = new UndirectedGraphNode(p->label);					map[p] = copy;
				map[node]->neighbors.push_back(copy);		
				s.push(p);
			}else{
				map[node]->neighbors.push_back(map[p]);
			}
		}	
	}
	return graphCopy; 
}
