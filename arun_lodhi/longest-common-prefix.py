class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        t= 0
        s = ""
        for x in range(len(min(strs,key = len))):
            count =  0
            for y in strs:
                if strs[0][x]==y[x]:
                    count = count+1
                else:
                    break
            if count==len(strs):
                t = t+1
                count = 0
                continue
            else:
                break
        if t==0:
            return s
        else:
            s = strs[0][0:t]
            return s
                
