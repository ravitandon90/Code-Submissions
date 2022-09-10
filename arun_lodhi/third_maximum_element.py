class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        l = []
        for x in nums:
            if x not in l:
                l.append(x)
        l.sort()
        if  len(l)>=3:
            return l[-3]
        else:
            return l[-1]
