def twoEggDrop(n):
    @lru_cache(None)
    def dp(n, x):
        if x == 1 or n <= 1:
            return n
        
        res = float("inf")
        
        for i in range(1,n+1):
            res = min(res, 1 + max(dp(i-1, x-1), dp(n-i, x)))
            
        return res
    
    return dp(n, 2)
