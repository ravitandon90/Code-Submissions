class Solution:
    def countVowelStrings(self, n: int) -> int:
        from itertools import combinations_with_replacement
        comb = combinations_with_replacement(["a","e","i","o","u"],n)
        return len(list(comb))
