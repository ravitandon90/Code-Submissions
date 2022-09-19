class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        l1 = []
        for x in nums:
            c = 1
            if x not in l1 and nums !=[]:
                l1.append(x)
                c = nums.count(x)
                if c<2:
                    return x
