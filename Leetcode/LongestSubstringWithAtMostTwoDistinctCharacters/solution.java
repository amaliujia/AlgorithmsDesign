public class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();

        int i = 0, j = 0;
        int max_len = 0;
        while(j < s.length()){
            if(map.containsKey(s.charAt(j))){
                map.put(s.charAt(j), map.get(s.charAt(j)) + 1);
            }else if(map.size() < 2){
                map.put(s.charAt(j), 1);
            }else{
                max_len = Math.max(max_len, j - i);
                while(i < j && map.size() == 2) {
                    if (map.get(s.charAt(i)) == 1) {
                        map.remove(s.charAt(i));
                    } else {
                        map.put(s.charAt(i), map.get(s.charAt(i)) - 1);
                    }
                    i++;
                }
                map.put(s.charAt(j), 1);
            }
            j++;
        }
        max_len = Math.max(max_len, j - i);
        return max_len;
    }
}
