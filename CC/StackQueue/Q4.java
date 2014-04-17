/*
	pseudocode
	
	HanMove(n, Tower orign, Tower buffer, Tower destination){
		if(n <= 0) return;
		
		HanMove(n-1, orign, destination, buffer);
	
		HanMoveOne(orign, destination);

		HanMove(n-1, buffer, destination, orign);
		
		return
	}
*/

public class solution{
	public static void main(String[] args){

	}

	public static void HanMove(int n, Tower orign, Tower buffer, Tower destination){
		if(n > 0){
			HanMove(n-1, orign, destination, buffer);
			HanMoveOne(orign, destination);
			HanMove(n-1, buffer, destination, orign);
		}
	}

	public static void HanMoveOne(Tower orign, Tower destination){
		int d = orign.pop();
		destination.add(d);	
	}
}


public class Tower throws Exception{
	private Stack<Integer> position;
	private int index;	
	public Tower(int i){
		position = new Stack<Integer>();
		index = 1;
	}

	public int index(){
		return index;
	}

	public void add(int d){
		position.push(d);
	}

	public int pop(){
		if(isEmpty()) return -1;
		else return position.pop();
	}

	public boolean isEmpty(){
		return position.isEmpty();
	}
}
