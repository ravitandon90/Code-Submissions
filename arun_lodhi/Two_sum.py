class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l = []
        j = 0
        l1 = len(nums)
        while j<l1:
            for x in range(j+1,l1):
                a = nums[j]+nums[x]
                if a == target:
                    l.append(j)
                    l.append(x)
                    return l
            j = j+1
