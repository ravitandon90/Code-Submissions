# https://leetcode.com/problems/shifting-letters/submissions/

class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        temp = 0
        s = list(s)
        for i in range(len(s)-1, -1, -1):
            temp += shifts[i]
            temp %= 26
            if (temp > ord('z')-ord(s[i])):
                s[i] = chr(ord(s[i])+temp-26)
            else:
                s[i] = chr(ord(s[i])+temp)
        return ''.join(s)
