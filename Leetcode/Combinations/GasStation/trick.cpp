class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int j = -1;
        int sum = 0;
        for(int i = 0; i < gas.size(); i++){
            sum += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            if(sum < 0){
                j = i;
                sum = 0;
            }
        }
        
        if(total < 0){
            return -1;
        }else{
            return j + 1;
        }
    }
};
