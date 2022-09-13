class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        v1 = [0]*26
        v2 = [0]*26

        for i in ransomNote:
            v1[ord(i)-ord('a')] += 1

        for i in magazine:
            v2[ord(i)-ord('a')] += 1
        
        for i in range(26):
            if v1[i] > v2[i]:
                return False
        return True
