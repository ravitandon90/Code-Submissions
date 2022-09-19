class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        i = 0
        j = 0
        for x in nums:
            if x==1:
                i = i+1
            else:
                if i>j:
                    j = i
                i =0
        if i>j:
            j = i
            return j
        else:
            return j
