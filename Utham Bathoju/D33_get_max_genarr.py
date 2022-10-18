def getMaximumGenerated(n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        nums = [0]*(n+1)
        maxVal = 1
        nums[1]=1
        
        for i in range(2, n+1):
            if i%2 == 0:
                nums[i] = nums[int(i/2)]
            else :
                nums[i] = nums[int(i/2)]+ nums[int(i/2+1)]
            maxVal = max(maxVal, nums[i])
        return maxVal
