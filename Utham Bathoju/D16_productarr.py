class Solution:
    def productExceptSelf(self, nums:List[int]) -> List[int]:
        if len(nums) == 1:
            return nums
        res = [1] * len(nums)
        pre_compute =1
        for i in range(0, len(nums)):
            res[i] = pre_compute
            pre_compute *= nums[i]
        
        post_compute = 1
        for i in range(len(nums)-1, -1, -1):
            res[i] *= post_compute
            post_compute *= nums[i]
        return res
