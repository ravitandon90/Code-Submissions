class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []        
        nums1 = set(nums1)
        nums2 = set(nums2)
        for ele1 in nums1:
            for ele2 in nums2:
                if ele1 == ele2:
                    res.append(ele1)
            continue
        return res
