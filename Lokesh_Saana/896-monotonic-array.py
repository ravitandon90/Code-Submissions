# https://leetcode.com/problems/monotonic-array/

class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        inc=0
        dec=0
        for i in range(len(nums)-1):
            if nums[i]>nums[i+1]:
                dec=1
            if nums[i]<nums[i+1]:
                inc=1
            if inc==1 and dec==1:
                return False
        if inc==1 and dec==1:
                return False
        return True
        