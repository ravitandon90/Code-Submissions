class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        def mergesort(index_pair):
            if len(index_pair) < 2:
                return index_pair
            
            mid = len(index_pair) // 2
            left, right = mergesort(index_pair[:mid]), mergesort(index_pair[mid:])
            
            merge = []
            i = j = 0
            while i < len(left) and j < len(right):
                if left[i][1] + j >= right[j][1]:
                    merge.append(right[j])
                    j += 1
                else:
                    # we increment the offset when we merge it
                    left[i][1] += j
                    merge.append(left[i])
                    i += 1
            
            while i < len(left):
                left[i][1] += j # now j == len(right)
                merge.append(left[i])
                i += 1
            
            while j < len(right):
                merge.append(right[j])
                j += 1
            
            return merge
        
        index_pair = list(map(list, enumerate(index))) 
        merge = mergesort(index_pair)

        ans = [0] * len(nums)
        for orig_idx, new_idx in merge:
            ans[new_idx] = nums[orig_idx]
        
        return ans
