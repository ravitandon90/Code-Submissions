class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        l = list(s)
        l.reverse()
        l1 = ''.join(l)
        if s==l1:
            return 'true'
        else:
            return
