public class DeepIterator implements Iterator {
  private Stack<Iterator> iterators = new Stack();
  private Iterator curIter = null;
  private Integer curVal = null;
  public void DeepIterator(Iterable iterable) {
    this.iterators.push(iterable.iterator());
  }

  public boolean hasNext() {
     if(curVal != null)
      return true; 

     while(iterators.isEmpty()){
        curIter = iterators.peek();
        if(curIter.hasNext()){
          Object tmp = curIter.next();
          if(tmp instanceof Integer){
            curVal = (Integer)tmp;
            return curVal; 
          }else if(tmp instanceof Iterable){
            this.iterators.push((Iterable)tmp).iterator();
          }else{
            throws new RuntimeException("Unsupported data type");
          }
        }else{
          iterators.pop();   
        }
      }

     return false;
  }

  public Integer next() throws NoSuchElementException{
      if(this.hasNext()){
         Integer tmp = this.curVal;
         this.curVal = null;
         return tmp;
      }

      throws new NoSuchElementException(); 
  }
}
