class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        x2=""
        for x in num:
            x1=str(x)
            x2=x2+x1
        x3=int(x2)+(k)
        l1=[]
        x4=str(x3)
        for y in x4:
            y2=int(y)
            l1.append(y2)
        return l1
