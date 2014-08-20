//O(n^2) time
int longestIncreasingSubsequence(vector<int> nums) {
    vector<int> f(nums.size(), 1);
    for(int i = 1; i < nums.size(); i++){
        for(int j = i - 1; j >= 0; j--){
            if(nums[i] >= nums[j]){
                f[i] = max(f[i], f[j]);
            }
        }
    }
    int maximum = f[0];
    for(int i = 1; i < nums.size(); i++){
        if(f[i] > maximum){
            maximum = f[i];
        }
    }
    return maximum;
}
