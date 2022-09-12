from itertools import combinations
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        l1 = []
        comb = combinations(range(1,n+1),k)
        for x in list(comb):
            l1.append(x)
        return l1
