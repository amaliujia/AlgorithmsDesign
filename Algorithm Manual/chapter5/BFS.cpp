bool processed[MAX+1];
bool discovered[MAX+1];
int parent[MAX+1];

initialize_search(graph *g)
{
	int i;			//counter
	
	for(i = 1; i <= g->nvertices; i++){
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

bfs(graph *g, int start)
{
	queue q;					// queue of vertices to visit
	int v;						// current vertex
	int y;						// successor vertex
	edgenode *p;				// temporary pointer

	init_queue(&q);
	enqueue(&q, start);
	discovered[start] = true;

	while(empty_queue(&q) == false){
		v = dequeue(&q);
		// interface
		process_vertex_early(v);
		processed[v] = true;
		p = g->edges[v];
		
		while(p != NULL){
			y = p->y;
			// if vertix's not processed, process edge
			if(processed[y] == false || g->directed){
				// interface
				process_edge(v, y);
			}
			// if not discovered, put q into queue to visit 
			if(discovered[y] == false){
				enqueue(&q, y);
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;
		}
		// interface
		process_vertex_late(v);	
	}
}

find_path(int start, int end, int parents[])
{
	if(start == end || end == -1)	printf("\n%d", start);
	else{
		find_path(start, parents[end], parents);
		printf(" %d", end);
	}
}
