class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int n : nums){
            unordered_map<int, int>::iterator iter = count.find(n);
            if(iter == count.end()){
                pair<int, int> p(n, 1);
                count.insert(p);    
            }else{
              iter->second++;
            }
        }
        
        int max = -1;
        int i = -1;
        unordered_map<int, int>::iterator iter;
        for(iter = count.begin(); iter != count.end(); iter++){
           if(iter->second > max){
               i = iter->first;
               max = iter->second;
           } 
        }
        
        return i;
    }
};
