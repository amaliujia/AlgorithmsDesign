// assume every node has a pointer to its parent

int height(Node *n){
	int height = 0;
	while(n){
		height++;
		p = p->parent;
	}
	return height;
}

Node *LCA(Node *p, Node *q){
	int h1 = height(p);
	int h2 = height(q);
	if(h1 > h2){
		swap(h1, h2);
		swap(p, q);
	}
	int h = h2 - h1;
	for(int i = 0; i < h; i++){
		q = q->parent;
	}
	while(p & q){
		if(p == q)	return p;
		p = p->parent;
		q = q->parent;	
	}
	return NULL;	
}


