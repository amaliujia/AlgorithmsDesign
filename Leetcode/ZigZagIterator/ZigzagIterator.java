public class ZigzagIterator {
  private Iterator iter_f;
  private Iterator iter_s;
  public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
    iter_f = v1.iterator();
    iter_s = v2.iterator();
  }

  public int next() {
    Integer res = (Integer)iter_f.next();
    if(iter_s.hasNext()){
      Iterator tmp = iter_f;
      iter_f = iter_s;
      iter_s = tmp;            
    }
    return res;
  }

  public boolean hasNext() {
    if(!iter_f.hasNext() && !iter_s.hasNext()){
      return false;
    }

    if(!iter_f.hasNext()){
      Iterator tmp = iter_f;
      iter_f = iter_s;
      iter_s = tmp;
    }

    return true;
  }
}
