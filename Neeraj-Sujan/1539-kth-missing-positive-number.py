class Solution:
    
    def bruteForce(self, arr, k):
        missing_numbers = []
        
        first_number = arr[0]
        for idx in range(1, first_number):
            missing_numbers.append(idx)
        
        for index in range(0, len(arr)-1):
            if(arr[index+1]  - arr[index] != 1):
                diff = arr[index + 1] - arr[index] - 1
                for idx in range(arr[index]+1, arr[index+1]):
                    missing_numbers.append(idx)
        if len(missing_numbers) >= k:
            return missing_numbers[k-1]
        else:
            return k - len(missing_numbers) + arr[-1]
        
        
    def binary_search(self, arr, k):
        left = 0
        right = len(arr) - 1
        
        while (left <= right):
            middle = left + (right-left)//2
            
            if arr[middle] - middle-1 < k:
                left = middle + 1
            else:
                right = middle - 1
        return left + k
        
            
    
    def findKthPositive(self, arr: List[int], k: int) -> int:
        #return self.bruteForce(arr,k)
        return self.binary_search(arr, k)