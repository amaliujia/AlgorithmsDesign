class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k <= 0){
            return;
        }
        
        while(k > nums.size()){
            k--;
            leftRotateByOne(nums);
        }
        
        for(int i = 0; i < nums.size() - k; i++){
            leftRotateByOne(nums);
        }
    }
    
private:
    void leftRotateByOne(vector<int> &nums){
        int temp = nums[0];
        for(int i = 0; i < nums.size() - 1; i++){
            nums[i] = nums[i + 1];
        }
        nums[nums.size() - 1] = temp;
    }
};
