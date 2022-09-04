# https://leetcode.com/problems/container-with-most-water/

class Solution:
    def maxArea(self, height: List[int]) -> int:
        Max = 0
        l = 0
        r = len(height)-1
        while l < r:
            if (min(height[l], height[r])*(r-l)) > Max:
                Max = (min(height[l], height[r])*(r-l))
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return Max
