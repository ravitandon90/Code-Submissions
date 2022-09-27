class Solution(object):
    def isMonotonic(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if nums == sorted(nums) or nums == sorted(nums, reverse=True):
            return True 
        return False
