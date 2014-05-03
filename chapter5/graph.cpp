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

void initialize_graph(graph *g, bool directed)
{
	g->directed = directed;
	g->nedges = 0;
	g->nvertices = 0;
	int i;
	for(i = 1; i <= MAXV; i++) g->degree[i] = 0;
	for(i = 1; i <= MAXV; i++) g->edges[i] = NULL;
}

void read_graph(graph *g, bool directed)
{
	int x, y;
	int i;

	initialize_graph(g, directed);
	
	scanf("%d %d", &(g->nvertices), &m);

	for(int i = 1; i <= m; i++){
		scanf("%d, %d", &x, &y);
		insert_edge(g, x, y, directed);
	}
}

void insert_edge(graph *g, int x, int y, bool directed)
{
	edgenode *p = malloc(sizeof(edgenode));

	p->weight = NULL;
	p->y = y;
	p->next = g->edges[x];

	g->edges[x] = p;

	g->degree[x]++;

	if(directed == false) insert_edge(g, y, x, true);
	else g->nedges++;
}

void print_graph(graph *g)
{
	int i;
	edgenode *p;
	for(i = 1; i <= g->nvertices; i++){
		printf("%d: ", i);
		p = g->edges[i];
		while(p != NULL){
			printf(" %d", p->y);
			p = p->next;	
		}
		printf("\n");
	}
}
