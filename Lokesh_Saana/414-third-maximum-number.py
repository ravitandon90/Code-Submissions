# https://leetcode.com/problems/third-maximum-number/
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        x = defaultdict(int)
        for i in nums:
            x[i] += 1
        x = sorted(x.items(), key=lambda a: (a[0], a[1]))
        if len(x) < 3:
            return max(x)[0]
        else:
            return x[-3][0]
