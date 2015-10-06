public class Vector2D {
    private Queue<Iterator<Integer>> queue;
    private Iterator<Integer> current = null;
    public Vector2D(List<List<Integer>> vec2d) {
        queue = new LinkedList<Iterator<Integer>>();
        for(List<Integer> l : vec2d){
            queue.add(l.iterator());
        }
        current = queue.poll();
    }

    public int next() {
        if(!current.hasNext()){
            return -1;
        }
        return current.next();
    }

    public boolean hasNext() {
        if(current == null){
            return false;
        }
        
        while(!current.hasNext()){
            if(queue.isEmpty()){
                return false;
            }else{
                current = queue.poll();
            }
        }
        
        return true;
    }
  
    public void remove() {
      if(current == null) {
        return;
      }
      
      current.remove(); 
    }  
}
