
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector< vector<int> > out_vec;
        if(num.size()<3)
            return out_vec;
        sort(num.begin(),num.end());
        vector<int> result_vec;
        int n = num.size();
        for(int i=0;i<num.size();i++) {
            if(i>0 && num[i] == num[i-1])
                continue;
            int two_sum=0-num[i];
            int l=i+1;
            int r=(int)num.size()-1;
            while(l<r){
                int tmp_sum = num[l]+num[r];
                if(tmp_sum<two_sum){
                    l++;
                }else if((tmp_sum>two_sum)) {
                    r--;
                }else {
                    result_vec.clear();
                    result_vec.push_back(-two_sum);
                    result_vec.push_back(num[l]);
                    result_vec.push_back(num[r]);
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
        return out_vec;
    }
};

