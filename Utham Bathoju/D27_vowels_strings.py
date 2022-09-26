class Solution:
    def countVowelStrings(self, n: int) -> int:
        vowels = ['a','e','i','o','u']
        dp_dict = {}
        def vowel_resolver(vowels,n,m,index):
            nonlocal dp_dict
            if((m,index) in dp_dict):
                return dp_dict[(m,index)]
            if(m == n):
                return 1
            res = 0
            for i in range(len(vowels)):
                if(i >= index):
                    res += backtracking(vowels,n,m+1,i)
            
            dp_dict[(m,index)] = res
            return res
        
        return vowel_resolver(vowels,n,0,0)
