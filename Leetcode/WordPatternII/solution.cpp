public class Solution {
  Map<Character, String> mapping = new HashMap<Character, String>();
  Set<String> set = new HashSet<String>();
  public boolean wordPatternMatch(String pattern, String str) {
    if(pattern.isEmpty() && str.isEmpty()) 
      return true;
    if(pattern.isEmpty() || str.isEmpty())
      return false;

    if(mapping.containsKey(pattern.charAt(0))){
      String pa = mapping.get(pattern.charAt(0));
      if(str.length() < pa.length() || !str.substring(0, pa.length()).equals(pa)){
        return false;
      }
      if(wordPatternMatch(pattern.substring(1),str.substring(pa.length()))) return true; 
    }else{
      for(int i = 1; i <= str.length(); i++){
        if(set.contains(str.substring(0, i))) continue;
        mapping.put(pattern.charAt(0), str.substring(0, i));
        set.add(str.substring(0, i));

        if(wordPatternMatch(pattern.substring(1), str.substring(i))){
          return true;
        }

        set.remove(str.substring(0,i));
        mapping.remove(pattern.charAt(0));
      }
    }
    return false;
  }
}
