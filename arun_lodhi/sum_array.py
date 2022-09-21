class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        L = []
        i = 0
        j =  0
        while i<len(nums):
            j = j+nums[i]
            L.append(j)
            i = i+1
        return L
            
