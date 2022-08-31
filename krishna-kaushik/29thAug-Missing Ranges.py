class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        # Add -1 to lower for the edge case, then check if current - previous >= 2
        
        ranges_list = []
        prev = lower - 1
        for i in range(len(nums) + 1):
            if i == len(nums):
                curr = upper + 1
            else:
                curr = nums[i]
            if curr - prev == 2:
                ranges_list.append(f"{prev + 1}")
            elif curr - prev > 2:
                ranges_list.append(f"{prev + 1}->{curr - 1}")
            prev = curr
        return ranges_list