def partition(s):
    res = []
    dfs_tracking(s, [], res)
    return res

def dfs_tracking(s, path, res):
    if not s:
        res.append(path)
        return
    for i in range(1, len(s)+1):
        if is_pal(s[:i]):
            dfs_tracking(s[i:], path+[s[:i]], res)
    
def is_pal(self, s):
    return s == s[::-1]
