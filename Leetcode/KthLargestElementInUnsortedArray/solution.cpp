class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size()){
            return 0;
        }
    
        if(k == 0){
            return 0; 
        }
        
        priority_queue<int, vector<int>, greater<int> > min_heap; 
        
        for(int i = 0; i < nums.size(); i++){
            if(min_heap.size() < k){
                min_heap.push(nums[i]);
            }else if(min_heap.top() < nums[i]){
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        return min_heap.top();
    }
};
