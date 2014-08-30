void prim(Graph G, int vcount, int father[]){
    int i,j,k;
    int min;
    int used[MAX_VERTEXES];
    int closedset[MAX_VERTEXES];
    int lowcost[MAX_VERTEXES];
    
    for (i=0; i<vcount; i++) {
        used[i]=0;
        lowcost[i]=G[0][i];
        closedset[i]=0;
    }
    
    used[0]=1;
    min=infinity;
    
    //开始找最小权值的边
    for (i=1; i<vcount; i++) {
        j=0;
        min=infinity;
        
        for (k=1; k<vcount; k++) {
            if (!used[k]&&lowcost[k]<min) {
                j=k;
                min=lowcost[k];
            }
        }
        father[j]=closedset[j];
        used[j]=1;
        for (k=1; k<vcount; k++) {
            if (!used[k]&&G[j][k]<lowcost[k]) {
                lowcost[k]=G[j][k];
                closedset[k]=j;
            }
        }
    }
}
