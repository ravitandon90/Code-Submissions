 def isInterleave(s1, s2, s3):
        @lru_cache(None)
        def dyn_prg(i, j, k):
            if i == len(s1) and j == len(s2) and k == len(s3):
                return True
            if k == len(s3):
                return False
            bool_value= False
            if i < len(s1) and s1[i] == s3[k]:
                bool_value = dyn_prg(i + 1, j, k + 1)
            bool_value_sec = False
            if j < len(s2) and s2[j] == s3[k]:
                bool_value_sec = dyn_prg(i, j + 1, k + 1)
            return bool_value or bool_value_sec
        
        return dyn_prg(0, 0, 0)
