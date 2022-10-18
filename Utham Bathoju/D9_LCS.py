class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        maxlen = 1
        tmpcount = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                tmpcount += 1
                if maxlen < tmpcount:
                    maxlen = tmpcount
            else:
                tmpcount = 1
        return maxlen
