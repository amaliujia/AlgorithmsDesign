class Solution {
public:
    int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if( n < 2 ) return 0;
    int maxE = *max_element(nums.begin(),nums.end());
    int minE = *min_element(nums.begin(),nums.end());

    int len = maxE - minE;
    if( len <= 1 ) return len;
    vector<int> buck_max(n, INT_MIN);
    vector<int> buck_min(n, INT_MAX);
    int c = ceil((maxE - minE) * 1.0 / (nums.size() - 1));
    for(int i = 0; i < n; i++) {
        // note the divide and multiply order and the double cast
        // it's used to avoid the overflow and underflow during calculation
        //int index = ceil((double)( nums[i] - minE )  / len * ( n - 1 ));
        int index = (nums[i] - minE) / c;
        buck_max[index] = max(buck_max[index], nums[i]);
        buck_min[index] = min(buck_min[index], nums[i]);
    }

    int gap = 0, pre = buck_max[0];
    for(int i = 1; i < n; i++) {
        if( buck_min[i] == INT_MAX ) continue;
        gap = max(gap, buck_min[i] - pre);
        pre = buck_max[i];
    }
    return gap;
    }
};
