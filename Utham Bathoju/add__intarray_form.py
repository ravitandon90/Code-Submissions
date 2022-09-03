class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        res = ""
        for i in num:
            res = res + str(i)
        temp = int(res) + k
        res_list =[int(i) for i in str(temp)]
        return res_list
       
