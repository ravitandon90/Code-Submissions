# https://leetcode.com/problems/range-sum-query-mutable/

import numpy as np


class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = np.array([0]+nums)
        self.x = np.zeros(len(nums)+1, dtype=int)
        for i in range(1, len(self.nums)):
            self.x[i] = self.nums[i]+self.x[i-1]

    def update(self, index: int, val: int) -> None:
        self.x[index+1:] -= (self.nums[index+1] - val)
        self.nums[index+1] = val

    def sumRange(self, left: int, right: int) -> int:
        return self.x[right+1] - self.x[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
