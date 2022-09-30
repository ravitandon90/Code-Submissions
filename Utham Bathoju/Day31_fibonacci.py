 def fib(self, n: int) -> int:
        if n==0 or n==1:
            return n
        
        dp0, dp1 = 0, 1 # base case: i-2, i-1 when i=2
        for i in range(2,n+1):
            dp = dp0 + dp1
            # update i-2 and i-1 cases for next round
            dp0 = dp1
            dp1 = dp
        return dp
