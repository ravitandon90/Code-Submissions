# https://leetcode.com/problems/permutations-ii/

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        count = {i: 0 for i in nums}
        for i in nums:
            count[i] += 1
        res = []
        perm = []

        def backtrack():
            if len(perm) == len(nums):
                res.append(perm.copy())
                return

            for i in count:
                if count[i] > 0:
                    perm.append(i)
                    count[i] -= 1

                    backtrack()

                    count[i] += 1
                    perm.pop()
        backtrack()
        return res
