class Solution {
  public:
    int minMeetingRooms(vector<Interval>& intervals) {
      if(!intervals.size())
        return 0;
      sort(intervals.begin(), intervals.end(), cmp);
      int n = intervals.size();
      int result = 1;
      priority_queue<int, vector<int>, greater<int> > pq;
      pq.push(intervals[0].end);
      for(int i = 1; i < n; ++ i){
        int start_time = intervals[i].start, end_time = pq.top();
        if(start_time >= end_time){
          pq.pop();
        }
        pq.push(intervals[i].end);
        int c = pq.size();
        result = max(result, c);
      }
      return result;
    }
  private:
    static bool cmp(Interval &inta, Interval &intb){
      if(inta.start == intb.start)
        return inta.end < intb.end;
      return inta.start < intb.start;
    }
};
