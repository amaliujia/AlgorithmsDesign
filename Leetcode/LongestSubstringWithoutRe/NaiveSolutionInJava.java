/*
	naive verison, time complexityO(n^2)
*/
import java.util.Hashtable;
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = 0;
        int count = 0;
        Hashtable<Object,Object> table = new Hashtable<Object,Object>();
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = i; j < s.length(); j++)
            {
                if(table.get(s.charAt(j)) == null)
                {
                    table.put(s.charAt(j), 1);
                    count++;
                }else{
                    break;
                }
            }
            if(count > len) len = count;
            count = 0;
            table.clear();
        }
      return len;
    }
}
