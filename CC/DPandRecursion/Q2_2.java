public ArrayList<Path> robotPath(int x, int y){
	ArrayList<Path> path= new ArrayList<Path>();
	return getPath(x, y, path);
} 
public boolean getPath(int x, int y, ArrayList<Path> path){
	if(x == 0 && y == 0){
		return true;
	}
	boolean OK = false;
	if(x >= 1 && isFree(x-1, y)){
		OK = getPath(x-1, y, path);
	}
	if(!OK && && y >= 1 && isFree(x, y-1)){
		OK = getPath(x, y-1, path);
	}
	if(OK){
		Path p = new Path(x, y);
		path.add(p);	
	}
	return OK;
}

public class Path{
public:
	Path(int a, int b) {x = a; y = b;}
private:
	int x;
	int y;
}
