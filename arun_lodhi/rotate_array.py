class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i =0
        k =  k%len(nums)
        while True:
            for x in range(-k,0):
                p = nums.pop(x)
                nums.insert(i,p)
                i = i+1
            return nums
