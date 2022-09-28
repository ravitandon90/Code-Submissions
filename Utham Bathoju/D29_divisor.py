def divisorGame(self, N: int) -> bool:
        bool_arr = [False for i in range(N + 1)] 
        bool_arr[0] = True
        for i in range(1, N + 1):
            for j in range(1, i):
                if i % j == 0 and not bool_arr[i - j]:
                    bool_arr[i] = True
                    break
                   
        return bool_arr[N]
