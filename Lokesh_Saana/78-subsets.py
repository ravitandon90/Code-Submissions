# https://leetcode.com/problems/subsets/
class Solution:
    def subsets(self, nums):
        ind = 0
        n = len(nums)
        res = []

        def func(ind, temp):
            if (ind == n):
                res.append(temp.copy())
                return
            temp.append(nums[ind])
            func(ind+1, temp)
            temp.pop()
            func(ind+1, temp)

        func(ind, [])
        return res
