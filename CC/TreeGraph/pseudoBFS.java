void BFS(Node root)
{
	Queue queue = new Queue();
	root.visited = true;
	visit(root);
	queue.enqueue(root);

	while(!queue.empty()){
		Node r = queue.dequeue();

		foreach(Node n in r.adjacent){
			if(n.visited == false){
				visit(n);
				n.visited = true;
				queue.enqueue(n);
		}
	}
}	
