public int possiblePath(int x, int y){
	return path(x, y);
}

public int path(int x, int y){
	if((x == 0) && (y == 0))
		return 1;
	return paht(x-1, y) + path(x, y-1);
}

// or use binomial expression directly
