class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero_cnt = nums.count(0)
        if not zero_cnt:
            return
        #1,3,12
        nums[:] = [ele for ele in nums if ele!=0]
        # 1,3,12,0,0
        nums.extend([0] * zero_cnt)
