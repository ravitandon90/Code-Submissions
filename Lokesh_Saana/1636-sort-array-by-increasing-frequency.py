# https://leetcode.com/problems/sort-array-by-increasing-frequency/

from collections import defaultdict


class Solution:
    def frequencySort(self, nums):
        freq = defaultdict(int)
        for i in nums:
            freq[i] += 1

        x = sorted(freq.items(), key=lambda i: (i[1], -i[0]))
        res = []
        for i, j in x:
            for _ in range(j):
                res.append(i)
        return res
