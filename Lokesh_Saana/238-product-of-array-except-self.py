# https://leetcode.com/problems/product-of-array-except-self/

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if nums.count(0) > 1:
            return [0]*len(nums)

        product = 1
        for i in nums:
            if i != 0:
                product *= i

        if nums.count(0) == 1:
            return [product if i == nums.index(0) else 0 for i in range(len(nums))]
        return [product//i for i in nums]
