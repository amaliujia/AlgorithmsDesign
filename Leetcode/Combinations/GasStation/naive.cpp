class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 1){
            return 0;
        }
       //reprocessing.
       vector<int> s;
       for(int i = 0; i < gas.size(); i++){
           s.push_back(gas[i] - cost[i]);
       }
        
       int curStart;
       int curLeft;
       bool flag;
       
       for(int i = 0; i < gas.size(); i++){
            curStart = i;
            curLeft = 0;  
            flag = false;
            
            for(int j = curStart; j < gas.size(); j++){
                if(curLeft + s[j] < 0){
                    flag = true;
                    break;
                }     
            }
            
            if(flag){
                continue;
            }
            
            for(int j = 0; j < curStart; j++){
                   if(curLeft + s[j] < 0){
                    flag = true;
                    break;
                }              
            }
            
            if(flag){
                continue;
            }
       }
       
       if(flag){
           return -1;
       }else{
           return curStart;
       }
       
    }
};
