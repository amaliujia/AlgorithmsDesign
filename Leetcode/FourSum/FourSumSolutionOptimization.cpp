#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector< vector<int> > out_vec;
        if(num.size()<4)
            return out_vec;
        sort(num.begin(),num.end());
        vector<int> result_vec;
        int n = num.size();
        int two_sum, tmp_sum;
        int l,r;
        for(int j = 0; j < num.size() - 3; j++){
            if(j > 0 && num[j] == num[j-1])           
                continue;
            for(int i= j + 1; i< num.size() - 2;i++) {
              if(i > j+1 && num[i] == num[i-1])
                    continue;
               two_sum = target - num[i] - num[j];
               l = i+1;
               r = (int)num.size()-1;
               while(l<r){
                  tmp_sum = num[l]+num[r];
                 if(tmp_sum < two_sum){
                        l++;
                    }else if((tmp_sum > two_sum)) {
                        r--;
                    }else {
                        result_vec.clear();
                        result_vec.push_back(num[j]);
                        result_vec.push_back(num[l]);
                        result_vec.push_back(num[r]);
                        result_vec.push_back(num[i]);
                        sort(result_vec.begin(), result_vec.end());
                        out_vec.push_back(result_vec);
                        l++;
                        r--;
                      while(r<n-1 && num[r] == num[r+1])
                             r--;
                      while(l>i+1 && num[l] == num[l-1])
                             l++;
                  }
              }
            }
        }
        return out_vec;
    }
};
