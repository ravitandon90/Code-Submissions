class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        y = ''
        for x in digits:
            x = str(x)
            y = y+x
        n = int(y)+1
        o = str(n)
        return list(o)
