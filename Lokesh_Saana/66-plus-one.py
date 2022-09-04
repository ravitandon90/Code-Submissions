# https://leetcode.com/problems/plus-one/

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        x = list(str(int(''.join(map(str, digits)))+1))
        return map(int, x)
