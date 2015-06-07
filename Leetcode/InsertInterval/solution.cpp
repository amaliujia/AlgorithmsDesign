class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        
        int new_start = newInterval.start;
        int new_end = newInterval.end;
        
        int i;
        for(i = 0; i < intervals.size(); i++){
            Interval val = intervals[i];
            if(val.end < newInterval.start){
                result.push_back(val);
            }else if(val.start > newInterval.end){
                break;
            }else{
            
                if(val.start <= new_start){
                    new_start = val.start;
                 }
            
                if(val.end >= new_end){
                    new_end = val.end;
                }
            }
        }
        
        Interval merge(new_start, new_end);
        result.push_back(merge);
        
        for(i; i < intervals.size(); i++){
            result.push_back(intervals[i]);
        }
        return result;
    }
};
