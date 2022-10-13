class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        l1 = []
        i=0
        j=1
        while i<len(nums):
            i2 = nums[i]
            while i2!=0:
                l1.append(nums[j])
                i2 = i2-1
            i =i+2
            j = j+2
        return l1
