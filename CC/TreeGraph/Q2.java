public enum State{
	undiscoverd, discovered, processed;
}

public static boolean BFS(Graph g, Node start, Node target){
	LinkedList<Node> q = new LinkedList<Node>();

	for(Node n : g.getNodes()){
		s.state = State.undiscovered;
	}
	start.state = discovered;
	q.add(start);
	Node u;
	
	while(!q.isEmpty()){
		u = q.removeFirst();
		if(u != null){
			for(Node v : u.getAdjacent()){
				if(v.state == State.undiscovered){
					if(v == target)
						return true;
					else{
						q.add(v);
						v.state = State.discovered;
					}
				}
			}
			u.state = State.processed;
		}
	}
	return false;	
}
