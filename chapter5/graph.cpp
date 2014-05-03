#define MAXV 1000

typedef struct{
	int y;						//adjacency info
	int weight;					//edge weight, if any
	struct edgenode *next;		//next edge in list
}edgenode;


typedef struct{
	edgnode *edges[MAXV+1];			//vertexs
	int degree[MAXV+1]				//degree of every vertex
	int nvertices;					//number of vertices in graph
	int nedges;						//number of edges in graph
	bool directed;					//if the graph is directed
}graph;
