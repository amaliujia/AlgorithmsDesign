//time complexity: O(nlogn + n) = O(nlogn)
public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int []result = {0,0};
        int []input = new int[]{0,0};
        int []inputtemp = new int[numbers.length];
        int i = 0;
        int j = numbers.length - 1;
        int temp;
        int index1=0;
        int index2=0;
        for(i = 0; i < numbers.length; i++)
        {
            inputtemp[i] = numbers[i];
        }
        java.util.Arrays.sort(numbers);
        for(i=0;i!=j;)
        {
            temp = numbers[i] + numbers[j];
            if(temp > target)
            {
                j--;  
            }else if(temp < target)
            {
                i++;  
            }else{
                input[0] = numbers[i];
                input[1] = numbers[j];
                for(i = 0; i < numbers.length; i++)
                {
                    if(inputtemp[i] == input[0])
                    {
                        index1 = i + 1;
                        break;
                    }
                }
                for(j = 0; j < numbers.length; j++)
                {
                    if(inputtemp[j] == input[1] && j != (index1-1))
                    {
                        index2 = j + 1;
                        break;
                    }
                }
                if(index1 > index2)
                {
                    result[0] = index2;
                    result[1] = index1;
                }else{
                    result[0] = index1;
                    result[1] = index2;
                }
                return result;  
            }
        }
        result[0] = 0;
        result[1] = 0;
        return result;
    }
}
