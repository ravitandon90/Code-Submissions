def countSubstrings(self, s, t):
    m, n = len(s), len(t)
    
    match = [[0 for _ in range(n+1)] for _ in range(m+1)]
    matchOne = [[0 for _ in range(n+1)] for _ in range(m+1)]
    
    match[0][0] = 0
    
    total = 0
    
    for i in range(1,m+1):
        for j in range(1,n+1):
            if s[i-1] == t[j-1]:
                match[i][j] = 1 + match[i-1][j-1]
                matchOne[i][j] = matchOne[i-1][j-1]
            else:
                match[i][j] = 0
                matchOne[i][j] = 1 + match[i-1][j-1]
                
            total += matchOne[i][j]
            
    return total
