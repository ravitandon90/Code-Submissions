class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        l1 = []
        l2 = nums
        for x in range(len(nums)):
            l1.insert(index[x] , nums[x])
        return l1
