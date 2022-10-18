class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def Parenthesis(n, O, c, s, ans):
            if(O == n and c == n):
                ans.append(s)
                return
            if(O < n):
                Parenthesis(n, O+1, c, s+"(", ans)
            if(c < O):
                Parenthesis(n, O, c + 1, s+")", ans)

        ans = []
        Parenthesis(n, 0, 0, "", ans)
        return ans
            
