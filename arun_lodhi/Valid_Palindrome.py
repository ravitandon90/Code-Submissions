class Solution:
    def isPalindrome(self, s: str) -> bool:
        s1 = ""
        s2 = s.lower()
        for x in s2:
            if 96<ord(x)<123:
                s1 = s1+x
            elif x in "1234567890":
                s1 = s1+x
        temp = s1
        s4 = "".join(reversed(s1))
        if temp==s4:
            return "true"
        else:
            return
        
