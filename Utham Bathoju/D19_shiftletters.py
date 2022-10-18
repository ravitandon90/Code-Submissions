class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        f_shift = list(accumulate(shifts[::-1]))[::-1]
        
        res_list = list(s)
        
        for i in range(len(res_list)):
            midval = ord(res_list[i]) + f_shift[i]%26
            if midval > 122:
                midval = midval - 26
            
            res_list[i] = chr(midval)
        
        return ''.join(res_list)

        
