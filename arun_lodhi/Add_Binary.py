class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a1 = ''.join(reversed(a))
        b1 = ''.join(reversed(b))
        i = 1
        s = 0
        s1 =0
        j=1
        for x in str(a1):
            if int(x)==1:
                s = s+ 1*i
                i = i*2
            else:
                i = i*2
        for y in str(b1):
            if int(y)==1:
                s1 = s1+1*j
                j = j*2
            else:
                j = j*2
        s3 = s+s1
        return (bin(s3)[2:])
