void DFS(Node root) { 
	if(root == null) return; 
	
	visit(root);
	root.visited = true;
	
	foreach(Node n in root.adjacent){
		if(n.visited == false){
			DFS(n);
		}
	}
}
