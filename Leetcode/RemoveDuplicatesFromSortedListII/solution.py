class Solution(object):
    def removeDuplicates(self, nums):
        i = 0
        j = 0
        cur = -1
        ifSecond = False
        
        while j < len(nums):
            if nums[j] != cur:
                ifSecond = False
                nums[i] = nums[j]
                cur = nums[j]
                i += 1
                j += 1
            elif not ifSecond:
                nums[i] = nums[j]
                ifSecond = True
                i += 1
                j += 1
            else:
                j += 1
        return i
