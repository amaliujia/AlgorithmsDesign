class Solution {
  public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<int> count(numCourses, 0);

      for(pair<int, int> p : prerequisites){
        count[p.first]++;
      }

      for(int i = 0; i < numCourses; i++){
        int j = 0;
        for(; j < count.size(); j++){
          if(!count[j]){
            break;
          }
        }

        if(j == count.size()){
          return false;
        }

        count[j] = -1;

        for(int z = 0; z < prerequisites.size(); z++){
          if((prerequisites[z].second) == j){
            count[prerequisites[z].first]--;
          }
        }        
      }
      return true;
    }
};
