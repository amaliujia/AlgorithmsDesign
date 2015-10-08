class Solution(object):
    def maxProduct(self, nums):
        if len(nums) == 0:
            return
        res = nums[0]
        maxN, minN = res, res
        
        for i in range(1, len(nums)):
            temp = maxN
            maxN = max(nums[i], max(maxN * nums[i], minN * nums[i]))
            minN = min(nums[i], min(temp * nums[i], minN * nums[i]))
            res = max(res, maxN)
        
        return res
