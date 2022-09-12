class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        l = []
        l2 = []
        l3 = []
        i = 0
        j = 1
        for x in nums:
            count1 = nums.count(x)
            if x not in l:
                l.append(x)
                l2.append(x)
                l2.append(count1)
                l3.append(l2)
                l2 = []
        l3.sort(key = lambda x:x[0])
        l3.reverse()
        l3.sort(key = lambda x: x[1])
        for y in l3:
            for z in range(y[1]):
                l2.append(y[0])
        return l2
