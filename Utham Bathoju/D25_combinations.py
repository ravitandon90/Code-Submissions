def combine(self, n: int, k: int) -> List[List[int]]:
        lst = []
        for i in range(n):
            lst.append(i+1)
        combination = list(combinations(lst,k))
        return combination
