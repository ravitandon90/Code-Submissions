class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        curr_val = 0
        res = 0
        for ele in nums:
            curr_val = curr_val * ele + ele
            res = max(curr_val, res)
        return res
