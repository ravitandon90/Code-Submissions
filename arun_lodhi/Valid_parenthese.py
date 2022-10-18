class Solution:
    def isValid(self, s: str) -> bool:
        s1 = list(s)
        l = []
        if s1 != []:
            for x in s1:
                if x in "({[":
                    l.append(x)
                elif x ==')'and l!=[]:
                    n = l.pop()
                    if n=='(':
                        continue
                    else:
                        l.append(x)
                        break
                elif x == ']' and l!=[]:
                    n = l.pop()
                    if n=='[':
                        continue
                    else:
                        l.append(x)
                        break
                elif x == '}' and l!=[]:
                    n = l.pop()
                    if n=='{':
                        continue
                    else:
                        l.append(x)
                        break
                else:
                    l.append(x)
                    break
        if l == []:
            return 'true'
        else:
            return 
