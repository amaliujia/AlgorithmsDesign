class Solution {
  public:
    bool canAttendMeetings(vector<Interval>& intervals) {
      sort(intervals.begin(), intervals.end(), 
          [](const Interval& interval1, const Interval& interval2){
          return interval1.start < interval2.start;
          });

      if(intervals.size() == 0){
        return true;
      }
      int end = intervals[0].end;

      for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].start < end){
          return false;
        }
        end = intervals[i].end;
      }

      return true;
    }
};
