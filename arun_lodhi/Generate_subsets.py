class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        from itertools import combinations
        l1 = []
        i = 0
        while i<=len(nums):
            comb = combinations(nums,i)
            for x in list(comb):
                l1.append(list(x))
            i = i+1
        return l1
