public class WordDistance {
    private HashMap<String, List<Integer>> dict;
    public WordDistance(String[] words) {
        dict = new HashMap<String, List<Integer>>();
        for(int i = 0; i < words.length; i++){
            if(dict.containsKey(words[i])){
                dict.get(words[i]).add(i);   
            }else{
                ArrayList<Integer> arr = new ArrayList<Integer>();
                arr.add(i);
                dict.put(words[i], arr);
            }
        }
    }

    public int shortest(String word1, String word2) {
       List<Integer> l1 = dict.get(word1);
       List<Integer> l2 = dict.get(word2);
       
       int min_dis = Integer.MAX_VALUE;
       for(Integer i : l1){
           for(Integer j : l2){
               min_dis = Math.min(Math.abs(j - i), min_dis);
           }
       }
       return min_dis;
    }
}

