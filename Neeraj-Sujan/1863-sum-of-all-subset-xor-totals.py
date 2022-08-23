from typing import * 

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        res = []
        ans = 0
        self.backtrack(res, [], nums, 0)
        for sub in res:
            if len(sub) > 0:
                temp = 0
                for num in sub:
                    temp ^= num
                ans+=temp
        return ans
    
    
    
    def backtrack(self,res, temp, nums, start):
        res.append(temp[:])
        for i in range(start, len(nums)):
            temp.append(nums[i])
            self.backtrack(res, temp, nums, i + 1)
            temp.pop() # Backtrack

if __name__ == "__main__":
    soln = Solution()
    nums = [1,3]
    print(soln.subsetXORSum(nums))