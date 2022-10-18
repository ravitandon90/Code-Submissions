class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j =0
        c = nums.count(0)
        i = 0
        while c!=j:
            if nums[i]==0:
                nums.pop(i)
                i =i
                j = j+1
            else:
                i = i+1
        for x in range(c):
            nums.append(0)
        return nums
