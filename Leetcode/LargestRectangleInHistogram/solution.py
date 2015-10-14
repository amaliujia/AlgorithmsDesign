class Solution(object):
    def largestRectangleArea(self, height):
        stack = list()
        max_area = 0
        i = 0
        while i < len(height):
            if len(stack) == 0 or height[i] >= height[stack[-1]]:
                stack.append(i)
                i += 1
            else:
                last = stack.pop()
                if len(stack) == 0:
                    max_area = max(max_area, i * height[last])
                else:
                    max_area = max(max_area, (i - stack[-1] - 1) * height[last])
        
        while len(stack) > 0:
            last = stack.pop()
            if len(stack) == 0:
                max_area = max(max_area, i * height[last])
            else:
                max_area = max(max_area, (i - stack[-1] - 1) * height[last])      
        return max_area
