class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        if len(nums) == 1:
            return nums
        odd_list = []
        even_list = []
        for i in range(0, len(nums)):
            if nums[i] % 2 == 0:
                even_list.append(nums[i])
            else:
                odd_list.append(nums[i])
            
        return even_list + odd_list
        
        
