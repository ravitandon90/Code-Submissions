class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(0,len(nums), 2):
            freq = nums[i]
            val = nums[i+1]
            while(freq > 0):
                res.append(val)
                freq -=1
        return res
    
