//time complexity: O(n^2)
public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int []result = {0,0};
        for(int i = 0; i < numbers.length;i++)
        {
            for(int j = i + 1; j < numbers.length; j++)
            {
                if(target == (numbers[i] + numbers[j]))
                {
                    //System.out.println("index1="+i+", index2="+j);
                    result[0] = i + 1;
                    result[1] = j + 1;
                    return result;
                }
            }
        }
        return result;
    }
}
