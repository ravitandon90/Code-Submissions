class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        l = []
        l2 = []
        for x  in nums:
            if x%2==0:
                l.append(x)
            else:
                l2.append(x)
        l.sort()
        l.reverse()
        l2.sort()
        l.extend(l2)
        return l
        
