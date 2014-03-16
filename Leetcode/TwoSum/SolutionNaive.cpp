
class Solution{
 Public:
     std::vector<int> twoSum(std::vector<int> &numbers, int target)
     {
           std::vector<int> out_res;
           out_res.clear();
           int index1 = -1;
           int index2 = -1;
           for( int i = 0; i < numbers.size() - 1; i++)
                 int j = 0;
                 for( j = i + 1; j < numbers.size(); j++)
                 {
                         if(numbers[i] + numbers[j] == target)
                         {
                                   index1 = i + 1;
                                   index2 = j + 1;
                                   out_res.push_back(index1);
                                   out_res.push_back(index2);
                                   return out_res;
                          }
                 }
               out_res.resize(2, 0);
               return out_res;
     }
};

