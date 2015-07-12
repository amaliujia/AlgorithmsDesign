int compare(const Interval &a, const Interval &b){
  if(a.start == b.start){
    return a.end < b.end;
  }
  return a.start < b.start;
}

class Solution {
  public:
    vector<Interval> merge(vector<Interval>& intervals) {
      vector<Interval> result;
      if(intervals.size() == 0){
        return result;
      }

      sort(intervals.begin(), intervals.end(), compare);

      int curr = 0;
      int end_now = intervals[0].end;

      for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].start <= end_now && intervals[i].end > end_now){
          end_now = intervals[i].end;
        }else if(intervals[i].start > end_now){
          Interval var(intervals[curr].start, end_now);
          result.push_back(var); 

          curr = i;
          end_now = intervals[i].end;
        }
      }

      Interval var(intervals[curr].start, end_now);
      result.push_back(var);

      return result;
    }
};
