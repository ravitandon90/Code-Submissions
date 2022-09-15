class Solution:

    def partition(self, s: str) -> List[List[str]]:
        if len(s) == 0:
            return []
        if len(s) == 1:
            return [s]

        def ispal(s: str) -> bool:
            # return s == s[::-1]
            l, r = 0, len(s)-1
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True

        ans = [] if not ispal(s) else [[s]]
        for size in range(1, len(s)):
            if ispal(s[:size]):
                for rest in self.partition(s[size:]):
                    ans.append([s[:size], *rest])
        return ans