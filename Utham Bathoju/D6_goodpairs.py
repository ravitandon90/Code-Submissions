class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        int_dict = {}
        if len(nums) <=1:
            return 0
        unq_flag = True
        for ele in nums:
            if ele not in int_dict:
                int_dict[ele] = 1
            else:
                unq_flag = False
                int_dict[ele] += 1
                
        if unq_flag:
            return 0
        
        res = 0
        for idx, val in int_dict.items():
            res += val * (val - 1) // 2
        
        return res
