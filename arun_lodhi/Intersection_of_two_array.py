class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        l1 = []
        for x in nums1:
            if x in nums2:
                if x not in l1:
                    l1.append(x)
        return l1
