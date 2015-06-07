class Solution {
	public:
		int findMin(vector<int>& nums) {
			if(nums.size() == 0){
				return 0;
			}
			int left = 0;
			int right = nums.size() - 1;

			while(left < right){
				if(nums[left] < nums[right]){
					return nums[left];
				}

				int mid = (right + left)  / 2;

				if(nums[mid] < nums[right]){
					right = mid;
				}else{
					left = mid + 1;
				}
			}

			return nums[left];
		}
};
