def partition(self, s):
    res = []
    self.dfs_tracking(s, [], res)
    return res

def dfs_tracking(self, s, path, res):
    if not s:
        res.append(path)
        return
    for i in range(1, len(s)+1):
        if self.is_pal(s[:i]):
            self.dfs_tracking(s[i:], path+[s[:i]], res)
    
def is_pal(self, s):
    return s == s[::-1]
