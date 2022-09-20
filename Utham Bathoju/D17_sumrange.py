class NumArray:
    def __init__(self, nums):
        self.arr = [0] * len(nums)
        self.BIT = [0] * (len(nums) + 1)
        for i, n in enumerate(nums): self.update(i, n)
        self.sumRange = lambda i, j: self.Sum(j + 1) - self.Sum(i)

    def update(self, i, val):
        diff, self.arr[i] = val - self.arr[i], val
        i += 1
        while i < len(self.BIT):
            self.BIT[i] += diff
            i += (i & -i)

    def Sum(self, k):
        res = 0
        while k:
            res += self.BIT[k]
            k -= (k & -k)
        return res
