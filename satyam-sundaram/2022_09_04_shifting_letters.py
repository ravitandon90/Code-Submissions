class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        c = 0
        ans = [i for i in shifts]
        for i in range(len(s)-1, -1, -1):
            c = (c + shifts[i]) % 26
            ans[i] = chr(ord('a') + (ord(s[i])-ord('a') + c)%26)
        return "".join(ans)
