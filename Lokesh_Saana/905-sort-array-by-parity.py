# https://leetcode.com/problems/sort-array-by-parity/
    
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        index=0
        for i in range(len(nums)):
            if nums[i]%2==0:
                temp=nums[i]
                nums[i]=nums[index]
                nums[index]=temp
                index+=1
        return nums